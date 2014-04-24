#include "simplenodeplugin.h"

#include "simplenodewidget.h"

SimpleNodePlugin::SimpleNodePlugin(QObject *parent) :
    QObject(parent)
{
}

QString SimpleNodePlugin::description() const
{
	return tr("Simple node factory");
}

QString SimpleNodePlugin::factoryName() const
{
	return tr("Simple Node");
}

QWidget *SimpleNodePlugin::create(QWidget *parent)
{
	return new SimpleNodeWidget(parent);
}
