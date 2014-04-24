#ifndef PLUGINSMANAGERWIDGET_H
#define PLUGINSMANAGERWIDGET_H

#include <QtWidgets/QDialog>

namespace Ui
{
	class PluginsManagerWidget;
}

class Core;
class PluginsModel;

class PluginsManagerWidget : public QDialog
{
	Q_OBJECT

	public:
		explicit PluginsManagerWidget(QWidget *parent = 0);
		~PluginsManagerWidget();

		Core *core();
		void setCore(Core *core);

	private:
		Core *_core;

		PluginsModel *_pluginsModel;

		Ui::PluginsManagerWidget *ui;
};

#endif // PLUGINSMANAGERWIDGET_H
