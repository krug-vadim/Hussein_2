#include "logdockwidget.h"
#include "ui_logdockwidget.h"

#include <QtWidgets/QPlainTextEdit>

LogDockWidget::LogDockWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::LogDockWidget)
{
	ui->setupUi(this);
}

LogDockWidget::~LogDockWidget()
{
	delete ui;
}

void LogDockWidget::appendLog(const QString &text)
{
	ui->log->appendPlainText(text);
}
