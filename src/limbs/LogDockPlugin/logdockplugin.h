#ifndef LOGDOCKPLUGIN_H
#define LOGDOCKPLUGIN_H

#include <QtCore/QObject>

#include "../../interfaces/basicinterface.h"
#include "../../interfaces/loginterface.h"
#include "../../interfaces/mainwindowdockinterface.h"

class LogDockWidget;

class LogDockPlugin : public QObject,
                      public BasicInterface,
                      public LogInterface,
                      public MainWindowDockInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.Hussein.LogDockPlugin")
	Q_INTERFACES(BasicInterface)
	Q_INTERFACES(LogInterface)
	Q_INTERFACES(MainWindowDockInterface)

	public:
		explicit LogDockPlugin(QObject *parent = 0);

		// BasicInterface
		virtual QString description() const;

		// MainWindowMenuInterface
		virtual QDockWidget *dock();

	signals:
		void log(const uint event, const QString &message) const;

	public slots:
		// LogInterface
		virtual void logMessage(const uint event, const QString &message);

	private:
		LogDockWidget *_dock;
};

#endif // LOGDOCKPLUGIN_H
