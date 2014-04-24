#ifndef MAINWINDOWMENUINTERFACE_H
#define MAINWINDOWMENUINTERFACE_H

#include <QtCore/QtPlugin>
#include <QtWidgets/QMenu>

class MainWindowMenuInterface
{
	public:
		virtual ~MainWindowMenuInterface() {}

		virtual QMenu *menu() = 0;
};

Q_DECLARE_INTERFACE(MainWindowMenuInterface,
                    "shz.Hussein.MainWindowMenuInterface/1.0")

#endif // MAINWINDOWMENUINTERFACE_H
