#ifndef TASKVIEW_H
#define TASKVIEW_H

#include <QtWidgets/QWidget>

#include "../../interfaces/treeinterface.h"
#include "../../interfaces/widgetfactoryinterface.h"

namespace Ui
{
	class TaskView;
}

class TaskView : public QWidget
{
	Q_OBJECT

	public:
		explicit TaskView(TreeSharedPointer &root, WidgetFactories *factories = 0, QWidget *parent = 0);
		~TaskView();

		WidgetFactories* factories() const;

	private:
		WidgetFactories *_factories;

		Ui::TaskView *ui;
};

#endif // TASKVIEW_H
