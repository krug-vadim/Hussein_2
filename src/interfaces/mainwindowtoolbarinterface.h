#ifndef MAINWINDOWTOOLBARINTERFACE_H
#define MAINWINDOWTOOLBARINTERFACE_H

#include <QtCore/QtPlugin>
#include <QtCore/QList>
#include <QtWidgets/QAction>

class MainWindowToolbarInterface
{
	public:
		virtual ~MainWindowToolbarInterface() {}

		virtual const QList<QAction *> &actions() const = 0;
};

Q_DECLARE_INTERFACE(MainWindowToolbarInterface,
                    "shz.Hussein.MainWindowToolbarInterface/1.0")


#endif // MAINWINDOWTOOLBARINTERFACE_H
