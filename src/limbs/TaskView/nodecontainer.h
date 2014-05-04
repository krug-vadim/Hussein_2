#ifndef NODECONTAINER_H
#define NODECONTAINER_H

#include <QtWidgets/QWidget>

#include "../../interfaces/widgetfactoryinterface.h"
#include "../../interfaces/treeinterface.h"

class QKeyEvent;
class QVBoxLayout;

class QScrollArea;

class NodeContainer : public QWidget
{
	Q_OBJECT

	public:
		explicit NodeContainer(TreeInterface *tree = 0, WidgetFactories *factories = 0, QWidget *parent = 0);

		WidgetFactories* factories() const;
		void setWidgetFactories(WidgetFactories *factories);

		TreeSharedPointer &root();
		void setRoot(TreeSharedPointer &root);

		void setTaskScrollArea(QScrollArea *taskScrollArea);
		QScrollArea *taskScrollArea() const;

	protected:
		void keyPressEvent(QKeyEvent *event);

	private slots:
		void moveScrollBarToBottom(int min, int max);

	private:
		void setupTree(TreeSharedPointer &node);

		TreeSharedPointer _root;
		WidgetFactories *_factories;

		QScrollArea *_taskScrollArea;
		QVBoxLayout *_taskLayout;
};

#endif // NODECONTAINER_H
