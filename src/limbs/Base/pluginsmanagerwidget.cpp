#include "pluginsmanagerwidget.h"
#include "ui_pluginsmanagerwidget.h"

#include <QtWidgets/QTableView>

#include "../../core/core.h"
#include "pluginsmodel.h"

PluginsManagerWidget::PluginsManagerWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PluginsManagerWidget)
{
	ui->setupUi(this);

	_pluginsModel = new PluginsModel(this);
	ui->pluginsView->setModel(_pluginsModel);
}

PluginsManagerWidget::~PluginsManagerWidget()
{
	delete ui;
}

Core *PluginsManagerWidget::core()
{
	return _core;
}

void PluginsManagerWidget::setCore(Core *core)
{
	_core = core;
	_pluginsModel->setCore(core);
}
