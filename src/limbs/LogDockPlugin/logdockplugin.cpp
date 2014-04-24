#include "logdockplugin.h"

#include "logdockwidget.h"

LogDockPlugin::LogDockPlugin(QObject *parent) :
    QObject(parent)
{
	_dock = new LogDockWidget(0);
}

QString LogDockPlugin::description() const
{
	return tr("Log UI");
}

void LogDockPlugin::logMessage(const uint event, const QString &message)
{
	_dock->appendLog(message);
}

QDockWidget *LogDockPlugin::dock()
{
	return _dock;
}
