#ifndef TASKVIEWPLUGIN_H
#define TASKVIEWPLUGIN_H

#include <QtCore/QObject>

#include "../../interfaces/basicinterface.h"
#include "../../interfaces/mainwindowviewinterface.h"

class TaskViewPlugin : public QObject,
                       public BasicInterface,
                       public MainWindowViewInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.Hussein.TaskViewPlugin")
	Q_INTERFACES(BasicInterface)
	Q_INTERFACES(MainWindowViewInterface)

	public:
		explicit TaskViewPlugin(QObject *parent = 0);

		// BasicInterface
		virtual QString description() const;

		// MainWindowViewInterface
		virtual QWidget *newView(QWidget *parent = 0);

	signals:
		void log(const uint event, const QString &message) const;
};

#endif // TASKVIEWPLUGIN_H
