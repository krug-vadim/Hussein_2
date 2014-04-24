#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QtWidgets/QDialog>
#include <QtCore/QStringListModel>

namespace Ui
{
	class SettingsWidget;
}

class Core;

class SettingsWidget : public QDialog
{
	Q_OBJECT

	public:
		explicit SettingsWidget(QWidget *parent = 0);
		~SettingsWidget();

		Core *core();
		void setCore(Core *core);

	private slots:
		void populateSettingsWidgets();

		void changeWidget(const QModelIndex &index);

	private:
		Core *_core;
		QStringList _settingsTitles;
		QStringListModel _settingsTitlesModel;

		Ui::SettingsWidget *ui;
};

#endif // SETTINGSWIDGET_H
