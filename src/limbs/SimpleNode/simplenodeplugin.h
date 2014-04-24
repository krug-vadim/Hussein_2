#ifndef SIMPLENODEPLUGIN_H
#define SIMPLENODEPLUGIN_H

#include <QtCore/QObject>

#include "../../interfaces/basicinterface.h"
#include "../../interfaces/widgetfactoryinterface.h"

class SimpleNodePlugin : public QObject,
                         public BasicInterface,
                         public WidgetFactoryInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.Hussein.SimpleNodePlugin")
	Q_INTERFACES(BasicInterface)
	Q_INTERFACES(WidgetFactoryInterface)

	public:
		explicit SimpleNodePlugin(QObject *parent = 0);

		// BasicInterface
		virtual QString description() const;

		// WidgetFactoryInterface
		virtual QString factoryName() const;
		virtual QWidget *create(QWidget *parent = 0);

	signals:
		void log(const uint event, const QString &message) const;
};

#endif // SIMPLENODEPLUGIN_H
