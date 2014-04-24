#ifndef MAINWINDOWDOCKINTERFACE_H
#define MAINWINDOWDOCKINTERFACE_H

#include <QtWidgets/QDockWidget>

class MainWindowDockInterface
{
	public:
		virtual ~MainWindowDockInterface() {}

		virtual QDockWidget *dock() = 0;
};

Q_DECLARE_INTERFACE(MainWindowDockInterface,
                    "shz.Hussein.MainWindowDockInterface/1.0")

#endif // MAINMENUDOCKINTERFACE_H
