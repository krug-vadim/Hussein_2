#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets/QAction>
#include <QtWidgets/QToolBar>

#include "pluginsmanagerwidget.h"
#include "settingswidget.h"

#include "../../interfaces/mainwindowmenuinterface.h"
#include "../../interfaces/mainwindowtoolbarinterface.h"
#include "../../interfaces/mainwindowdockinterface.h"
#include "../../interfaces/mainwindowviewinterface.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	_core.loadPlugins("limbs");

	ui->setupUi(this);

	_pluginsManager = new PluginsManagerWidget(this);
	_pluginsManager->setModal(true);
	_pluginsManager->setCore(&_core);
	_pluginsManager->close();

	_settingsWidget = new SettingsWidget(this);
	_settingsWidget->setModal(true);
	_settingsWidget->setCore(&_core);

	connectActions();

	populateMenus();
	populateToolbars();
	populateDocks();
	populateViews();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::populateToolbars()
{
	foreach(QObject *object, _core.plugins())
	{
		MainWindowToolbarInterface *iToolbar;

		iToolbar = qobject_cast<MainWindowToolbarInterface *>(object);

		if ( !iToolbar )
			continue;

		QToolBar *toolbar = this->addToolBar(object->objectName());
		toolbar->addActions(iToolbar->actions());
	}
}

void MainWindow::populateMenus()
{
	foreach(QObject *object, _core.plugins())
	{
		MainWindowMenuInterface *iMenu;

		iMenu = qobject_cast<MainWindowMenuInterface *>(object);

		if ( !iMenu )
			continue;

		if ( iMenu->menu() )
			ui->menuPlugins->insertMenu(ui->actionPluginsManage, iMenu->menu());
	}
}

void MainWindow::populateDocks()
{
	foreach(QObject *object, _core.plugins())
	{
		MainWindowDockInterface *iDock;

		iDock = qobject_cast<MainWindowDockInterface *>(object);

		if ( !iDock )
			continue;

		if ( iDock->dock() )
			this->addDockWidget(Qt::BottomDockWidgetArea, iDock->dock());
	}
}

void MainWindow::populateViews()
{
	foreach(QObject *object, _core.plugins())
	{
		MainWindowViewInterface *iView;

		iView = qobject_cast<MainWindowViewInterface *>(object);

		if ( !iView )
			continue;

		ui->viewTabs->addTab(iView->newView(this), tr("123"));
	}
}

void MainWindow::connectActions()
{
	connect(ui->actionExit, SIGNAL(triggered()),
	        this, SLOT(close()));

	connect(ui->actionPluginsManage, SIGNAL(triggered()),
	        _pluginsManager, SLOT(show()));

	connect(ui->actionSettings, &QAction::triggered,
	        _settingsWidget, &SettingsWidget::show);
}
