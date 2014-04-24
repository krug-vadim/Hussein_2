#include "taskviewplugin.h"

#include "taskview.h"

#include "../../interfaces/coreinterface.h"
#include "../../interfaces/widgetfactoryinterface.h"

TaskViewPlugin::TaskViewPlugin(QObject *parent) :
    QObject(parent)
{
}

QString TaskViewPlugin::description() const
{
	return tr("Standart task view");
}

QWidget *TaskViewPlugin::newView(QWidget *parent)
{
	foreach(QObject *plugin, core()->plugins())
	{
		WidgetFactoryInterface *iFactory;

		iFactory = qobject_cast<WidgetFactoryInterface *>(plugin);

		if ( !iFactory )
			continue;

		emit log(0, tr("found factroy"));
	}
	return new TaskView(parent);
}
