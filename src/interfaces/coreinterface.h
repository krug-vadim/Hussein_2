#ifndef COREINTERFACE_H
#define COREINTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QHash>
#include <QtCore/QJsonObject>
#include <QtCore/QString>
#include <QtCore/QStringList>

typedef QHash<QString, QObject *> QObjectHash;
typedef QHash<QObject *, QJsonObject> PluginMetaData;

class CoreInterface
{
	public:
		explicit CoreInterface() {}
		virtual ~CoreInterface() {}

		virtual const QObjectList &plugins() const =0;
		virtual const QJsonObject pluginMetaData(QObject *plugin) const =0;
		virtual const QObjectHash &objects() const =0;

		virtual void clearObjects() =0;
		virtual bool insertObject(QObject *object) =0;
		virtual QObject *removeObject(const QString &name) =0;

	protected:
		virtual void objectsChanged() =0;
		virtual void pluginsChanged() =0;
		//void log(const uint event, const QString &message) const;
};

Q_DECLARE_INTERFACE(CoreInterface,
                    "shz.Hussein.CoreInterface/1.0")

#endif // COREINTERFACE_H
