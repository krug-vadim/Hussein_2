#include "taskview.h"
#include "ui_taskview.h"

TaskView::TaskView(TreeInterface *tree, WidgetFactories *factories, QWidget *parent) :
    QWidget(parent),
    _factories(factories),
    ui(new Ui::TaskView)
{
	ui->setupUi(this);

	ui->nodeArea->setWidgetFactories(_factories);
	ui->nodeArea->setTaskScrollArea(ui->nodeAreaScrollBox);

	ui->nodeArea->setTree(tree);
}

TaskView::~TaskView()
{
	delete ui;
}

WidgetFactories *TaskView::factories() const
{
	return _factories;
}
