#include "settingswidget.h"
#include "ui_settingswidget.h"

#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QListView>

#include "../../core/core.h"

#include "../../interfaces/settingsinterface.h"

SettingsWidget::SettingsWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWidget)
{
	_core = 0;
	_settingsTitles.clear();

	ui->setupUi(this);

	_settingsTitlesModel.setStringList(_settingsTitles);

	ui->settingsTitleView->setModel(&_settingsTitlesModel);

	connect(ui->settingsTitleView, SIGNAL(activated(QModelIndex)),
	        this, SLOT(changeWidget(QModelIndex)));

	connect(ui->buttonBox, SIGNAL(accepted()),
	        this, SLOT(accept()));
	connect(ui->buttonBox, SIGNAL(rejected()),
	        this, SLOT(reject()));
}

SettingsWidget::~SettingsWidget()
{
	delete ui;
}

Core *SettingsWidget::core()
{
	return _core;
}

void SettingsWidget::setCore(Core *core)
{
	_core = core;

	populateSettingsWidgets();

	if ( core )
		connect(core, &Core::pluginsChanged,
		        this, &SettingsWidget::populateSettingsWidgets);
}

void SettingsWidget::populateSettingsWidgets()
{
	if ( !core() )
		return;

	_settingsTitles.clear();

	while ( ui->settingsWidgets->count() > 1 )
		ui->settingsWidgets->removeWidget( ui->settingsWidgets->widget(1) );

	ui->settingsWidgets->setCurrentIndex(0);

	foreach(QObject *object, core()->plugins())
	{
		SettingsInterface *iSettings;

		iSettings = qobject_cast<SettingsInterface *>(object);

		if ( !iSettings )
			continue;

		if ( iSettings->widget() )
		{
			ui->settingsWidgets->addWidget(iSettings->widget());
			_settingsTitles.append(iSettings->title());
		}
	}

	_settingsTitlesModel.setStringList(_settingsTitles);
}

void SettingsWidget::changeWidget(const QModelIndex &index)
{
	if ( !index.isValid() )
	{
		ui->settingsWidgets->setCurrentIndex(0);
		return;
	}

	ui->settingsWidgets->setCurrentIndex(index.row() + 1);
	//index.row()
}
