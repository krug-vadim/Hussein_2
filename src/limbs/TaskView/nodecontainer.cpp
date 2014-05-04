#include "nodecontainer.h"

#include <QtGui/QKeyEvent>
#include <QtWidgets/QVBoxLayout>

#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>

#include <QDebug>

NodeContainer::NodeContainer(TreeInterface *tree, WidgetFactories *factories, QWidget *parent) :
    QWidget(parent),
    _factories(factories)
{
	setFocusPolicy(Qt::ClickFocus);
	_taskLayout = new QVBoxLayout(this);
	_taskLayout->addStretch(1);

	_taskScrollArea = 0;
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
			/*newWidget = _factories->at(0)->create(this);
			_taskLayout->insertWidget(_taskLayout->count() - 1, newWidget);
			newWidget->setFocus(Qt::MouseFocusReason);*/
			break;

		default:
			return;
			break;
	}

	event->accept();
}

void NodeContainer::moveScrollBarToBottom(int min, int max)
{
	Q_UNUSED(min);
	taskScrollArea()->verticalScrollBar()->setValue(max);
}

void NodeContainer::setupTree(TreeSharedPointer &node)
{
	if ( !_factories || _factories->isEmpty() )
		return;

	QWidget *newWidget = _factories->at(0)->create(node, this);
	_taskLayout->insertWidget(_taskLayout->count() - 1, newWidget);
	newWidget->setFocus(Qt::MouseFocusReason);

	foreach(TreeSharedPointer subNode, node->nodes())
	{
		qDebug() << subNode->data(tr("description"));
		setupTree(subNode);
	}
}

WidgetFactories *NodeContainer::factories() const
{
	return _factories;
}

void NodeContainer::setWidgetFactories(WidgetFactories *factories)
{
	_factories = factories;
}

TreeSharedPointer& NodeContainer::root()
{
	return _root;
}

void NodeContainer::setRoot(TreeSharedPointer &root)
{
	_root = root;

	setupTree(root);

	qDebug() << "out of setTree";
}

void NodeContainer::setTaskScrollArea(QScrollArea *taskScrollArea)
{
	_taskScrollArea = taskScrollArea;

	connect(taskScrollArea->verticalScrollBar(), SIGNAL(rangeChanged(int,int)),
	        this, SLOT(moveScrollBarToBottom(int,int)));
}

QScrollArea *NodeContainer::taskScrollArea() const
{
	return _taskScrollArea;
}
