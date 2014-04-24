#include "core.h"

#include <QtCore/QDir>
#include <QtCore/QPluginLoader>

#include <QtCore/QDebug>

#include "../interfaces/basicinterface.h"
#include "../interfaces/loginterface.h"
#include "../interfaces/loadableinterface.h"

#include "log.h"

Core::Core(QObject *parent) :
    QObject(parent)
{
	_objects.clear();

	connect(this, SIGNAL(log(uint,QString)),
	        this, SLOT(logMessage(uint,QString)));
}

const QObjectList &Core::plugins() const
{
	return _plugins;
}

const QJsonObject Core::pluginMetaData(QObject *plugin) const
{
	return _pluginsMetaData.value(plugin);
}

const QObjectHash &Core::objects() const
{
	return _objects;
}

void Core::clearObjects()
{
	_objects.clear();
	emit objectsChanged();
}

bool Core::insertObject(QObject *object)
{
	if ( _objects.contains(object->objectName()) )
		return false;

	_objects.insert(object->objectName(), object);
	connect(object, SIGNAL(log(uint,QString)),
	        this, SIGNAL(log(uint,QString)));

	emit objectsChanged();
	return true;
}

QObject *Core::removeObject(const QString &name)
{
	QObject *object;

	if ( _objects.contains(name) )
	{
		object = _objects.take(name);
		disconnect(object, SIGNAL(log(uint,QString)),
				   this, SLOT(log(uint,QString)));
		emit objectsChanged();

		return object;
	}
	else
		return 0;
}

void Core::loadPlugins(const QString &path)
{
	_plugins.clear();
	_pluginsMetaData.clear();
	loadPluginsInDir(path, this);
	emit pluginsChanged();
}

void Core::logMessage(const uint event, const QString &message)
{
	qDebug() << event << message;
}

/*void Core::log(const uint event, const QString &message)
{
	qDebug() << event << message;
}*/

void Core::loadPluginsInDir(const QString &path, const QObject *parent)
{
	QDir pluginsDir;

	log(Log::InfoEvent|Log::DebugEvent, tr("Loading plugins in dir: %1.").arg(path));

	pluginsDir = QDir(path);

	foreach (QString path, pluginsDir.entryList(QDir::Dirs|QDir::NoDotAndDotDot))
		loadPluginsInDir(pluginsDir.absoluteFilePath(path), parent);

	foreach (QString fileName, pluginsDir.entryList(QDir::Files))
	{
		QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));

		log(Log::InfoEvent|Log::DebugEvent,
		    tr("Trying to load: %1.").arg(pluginsDir.absoluteFilePath(fileName)));

		QObject *plugin = loader.instance();

		if ( !plugin )
		{
			log(Log::WarningEvent|Log::DebugEvent,
			    tr("Failed to load plugin %1: %2.")
			    .arg(fileName)
			    .arg(loader.errorString()));
			continue;
		}

		plugin->setParent(0);
		plugin->setObjectName(fileName);

		plugin->dumpObjectInfo();

		log(Log::InfoEvent|Log::DebugEvent,
		    tr("Trying to detect basic plugin interface"));

		BasicInterface *iBasic = qobject_cast<BasicInterface *>(plugin);
		if ( iBasic )
		{
			connect(dynamic_cast<QObject*>(iBasic), SIGNAL(log(uint,QString)),
			        this, SIGNAL(log(uint,QString)));

			iBasic->setCore(this);

			LogInterface *iLog;
			iLog = qobject_cast<LogInterface *>(plugin);
			if ( iLog )
				connect(this, SIGNAL(log(uint,QString)),
				        dynamic_cast<QObject*>(iLog), SLOT(logMessage(uint,QString)));

			LoadableInterface *iLoadable;
			iLoadable = qobject_cast<LoadableInterface *>(plugin);
			if ( iLoadable )
				iLoadable->load();

			_pluginsMetaData.insert(plugin, loader.metaData());

			log(Log::InfoEvent|Log::DebugEvent,
			    tr("Loaded: %1.").arg(iBasic->description()));

			_plugins << plugin;
		}
		else
			delete plugin;
	}
}
