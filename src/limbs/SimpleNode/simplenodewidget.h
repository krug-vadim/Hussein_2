#ifndef SIMPLENODEWIDGET_H
#define SIMPLENODEWIDGET_H

#include <QtWidgets/QWidget>

#include "../../interfaces/treeinterface.h"

namespace Ui
{
	class SimpleNodeWidget;
}

class SimpleNodeWidget : public QWidget
{
	Q_OBJECT

	public:
		explicit SimpleNodeWidget(TreeSharedPointer &node, QWidget *parent = 0);
		~SimpleNodeWidget();

		TreeSharedPointer &node();

	private:
		void updateUi();

		TreeSharedPointer _node;

		Ui::SimpleNodeWidget *ui;
};

#endif // SIMPLENODEWIDGET_H
