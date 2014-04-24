#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>

#include "../../core/core.h"

namespace Ui
{
	class MainWindow;
}

class PluginsManagerWidget;
class SettingsWidget;

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private slots:
		void populateToolbars();
		void populateMenus();
		void populateDocks();
		void populateViews();

	private:
		void connectActions();

		Core _core;

		PluginsManagerWidget *_pluginsManager;
		SettingsWidget *_settingsWidget;
		Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
