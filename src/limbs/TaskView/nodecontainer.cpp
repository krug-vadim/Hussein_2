#include "nodecontainer.h"

#include <QtGui/QKeyEvent>
#include <QtWidgets/QVBoxLayout>

#include <QtWidgets/QLineEdit>

NodeContainer::NodeContainer(WidgetFactories *factories, QWidget *parent) :
    QWidget(parent),
    _factories(factories)
{
	setFocusPolicy(Qt::ClickFocus);
	_taskLayout = new QVBoxLayout(this);
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
			if ( !_factories || _factories->isEmpty() )
				break;
			newWidget = _factories->at(0)->create(this);
			_taskLayout->insertWidget(_taskLayout->count() - 1, newWidget);
			newWidget->setFocus(Qt::MouseFocusReason);
			break;

		default:
			return;
			break;
	}

	event->accept();
}

WidgetFactories *NodeContainer::factories() const
{
	return _factories;
}

void NodeContainer::setWidgetFactories(WidgetFactories *factories)
{
	_factories = factories;
}
