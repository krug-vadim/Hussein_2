#ifndef NODECONTAINER_H
#define NODECONTAINER_H

#include <QtWidgets/QWidget>

#include "../../interfaces/widgetfactoryinterface.h"

class QKeyEvent;
class QVBoxLayout;

class NodeContainer : public QWidget
{
	Q_OBJECT

	public:
		explicit NodeContainer(WidgetFactories *factories = 0, QWidget *parent = 0);

		WidgetFactories* factories() const;
		void setWidgetFactories(WidgetFactories *factories);

	protected:
		void keyPressEvent(QKeyEvent *event);

	private:
		WidgetFactories *_factories;

		QVBoxLayout *_taskLayout;
};

#endif // NODECONTAINER_H
