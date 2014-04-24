#ifndef SIMPLENODEWIDGET_H
#define SIMPLENODEWIDGET_H

#include <QtWidgets/QWidget>

namespace Ui
{
	class SimpleNodeWidget;
}

class SimpleNodeWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit SimpleNodeWidget(QWidget *parent = 0);
		~SimpleNodeWidget();

	private:
		Ui::SimpleNodeWidget *ui;
};

#endif // SIMPLENODEWIDGET_H
