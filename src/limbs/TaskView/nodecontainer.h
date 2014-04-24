#ifndef NODECONTAINER_H
#define NODECONTAINER_H

#include <QtWidgets/QWidget>

class QKeyEvent;
class QVBoxLayout;

class NodeContainer : public QWidget
{
	Q_OBJECT

	public:
		explicit NodeContainer(QWidget *parent = 0);

	protected:
		void keyPressEvent(QKeyEvent *event);

	private:
		QVBoxLayout *_taskLayout;
};

#endif // NODECONTAINER_H
