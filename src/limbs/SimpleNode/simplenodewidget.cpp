#include "simplenodewidget.h"
#include "ui_simplenodewidget.h"

#include <QtGui/QKeyEvent>

SimpleNodeWidget::SimpleNodeWidget(TreeSharedPointer &node, QWidget *parent) :
    QWidget(parent),
    _node(node),
    ui(new Ui::SimpleNodeWidget)
{
	ui->setupUi(this);

	setFocusPolicy(Qt::ClickFocus);
	setFocusProxy(ui->lineEdit);

	updateUi();
}

SimpleNodeWidget::~SimpleNodeWidget()
{
	delete ui;
}

TreeSharedPointer &SimpleNodeWidget::node()
{
	return _node;
}

void SimpleNodeWidget::keyPressEvent(QKeyEvent *event)
{
	QWidget::keyPressEvent(event);

	if ( event->isAccepted() )
		return;

	switch ( event->key() )
	{
		case Qt::Key_Enter:
		case Qt::Key_Return:
			node()->parent()->appendNode(node()->parent()->create());
			break;

		default:
			return;
			break;
	}

	event->accept();
}

void SimpleNodeWidget::updateUi()
{
	ui->levelFrame->setFixedWidth(node()->level() * 20);
	ui->lineEdit->setText(node()->data(tr("description")).toString());
}
