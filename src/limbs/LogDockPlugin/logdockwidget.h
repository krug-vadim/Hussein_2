#ifndef LOGDOCKWIDGET_H
#define LOGDOCKWIDGET_H

#include <QtWidgets/QDockWidget>

namespace Ui
{
	class LogDockWidget;
}

class LogDockWidget : public QDockWidget
{
		Q_OBJECT

	public:
		explicit LogDockWidget(QWidget *parent = 0);
		~LogDockWidget();

		void appendLog(const QString &text);

	private:
		Ui::LogDockWidget *ui;
};

#endif // LOGDOCKWIDGET_H
