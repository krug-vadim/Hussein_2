#include "taskviewplugin.h"

#include "taskview.h"

#include "../../interfaces/coreinterface.h"

TaskViewPlugin::TaskViewPlugin(QObject *parent) :
    QObject(parent)
{
}

QString TaskViewPlugin::description() const
{
	return tr("Standart task view");
}

QWidget *TaskViewPlugin::newView(TreeInterface *tree, QWidget *parent)
{
	loadFactories();
	return new TaskView(tree, &_factories, parent);
}

void TaskViewPlugin::loadFactories()
{
	_factories.clear();
	foreach(QObject *plugin, core()->plugins())
	{
		WidgetFactoryInterface *iFactory;

		iFactory = qobject_cast<WidgetFactoryInterface *>(plugin);

		if ( !iFactory )
			continue;

		_factories.append(iFactory);

		emit log(0, tr("Found factory: «%1»").arg(iFactory->factoryName()));
	}
}
