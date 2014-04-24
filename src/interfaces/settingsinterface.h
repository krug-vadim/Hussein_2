#ifndef SETTINGSINTERFACE_H
#define SETTINGSINTERFACE_H

#include <QtCore/QString>

class QWidget;

class SettingsInterface
{
	public:
		virtual ~SettingsInterface() {}

		virtual QString title() const = 0;
		virtual QWidget *widget() = 0;
};

Q_DECLARE_INTERFACE(SettingsInterface,
                    "shz.Hussein.SettingsInterface/1.0")

#endif // SETTINGSINTERFACE_H
