#ifndef CORE_H
#define CORE_H

#include "../interfaces/coreinterface.h"

class Core : public QObject,
             public CoreInterface
{
	Q_OBJECT
	Q_INTERFACES(CoreInterface)

	public:
		explicit Core(QObject *parent = 0);

		// Core interface
		virtual const QObjectList &plugins() const;
		virtual const QJsonObject pluginMetaData(QObject *plugin) const;
		virtual const QObjectHash &objects() const;

		virtual void clearObjects();
		virtual bool insertObject(QObject *object);
		virtual QObject *removeObject(const QString &name);

	signals:
		// Core interface
		void objectsChanged();
		void pluginsChanged();
		void log(const uint event, const QString &message) const;

	public slots:
		void loadPlugins(const QString &path);

	private slots:
		void logMessage(const uint event, const QString &message);

	private:
		void loadPluginsInDir(const QString &path, const QObject *parent);

		QObjectHash _objects;
		QObjectList _plugins;
		PluginMetaData _pluginsMetaData;
};

#endif // CORE_H
