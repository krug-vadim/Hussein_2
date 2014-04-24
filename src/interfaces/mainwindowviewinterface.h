#ifndef MAINWINDOWVIEWINTERFACE_H
#define MAINWINDOWVIEWINTERFACE_H

class QWidget;

class MainWindowViewInterface
{
	public:
		virtual ~MainWindowViewInterface() {}

		virtual QWidget *newView(QWidget *parent = 0) = 0;
};

Q_DECLARE_INTERFACE(MainWindowViewInterface,
                    "shz.Hussein.MainWindowViewInterface/1.0")

#endif // MAINWINDOWVIEWINTERFACE_H
