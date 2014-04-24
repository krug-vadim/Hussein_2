#include "nodecontainer.h"

#include <QtGui/QKeyEvent>
#include <QtWidgets/QVBoxLayout>

#include <QtWidgets/QLineEdit>

NodeContainer::NodeContainer(QWidget *parent) :
    QWidget(parent)
{
	setFocusPolicy(Qt::ClickFocus);
	_taskLayout = new QVBoxLayout(this);
	_taskLayout->addWidget(new QLineEdit(tr("123"),this));
	_taskLayout->addStretch(1);
}

void NodeContainer::keyPressEvent(QKeyEvent *event)
{
	QWidget *newWidget;
	QWidget::keyPressEvent(event);

	if ( event->isAccepted() )
		return;

	switch ( event->key() )
	{
		case Qt::Key_Enter:
		case Qt::Key_Return:
			newWidget = new QLineEdit(this);
			_taskLayout->insertWidget(0, newWidget);
			newWidget->setFocus(Qt::MouseFocusReason);
			break;

		case Qt::Key_0:
			_taskLayout->insertWidget(0, new QLineEdit(tr("0"), this));
			break;

		default:
			return;
			break;
	}

	event->accept();
}
