#ifndef SAVABLEINTERFACE_H
#define SAVABLEINTERFACE_H

#include <QtCore/QtPlugin>

class SavableInterface
{
	public:
		virtual ~SavableInterface() {}

		virtual void save(QJsonObject &json) = 0;
};

Q_DECLARE_INTERFACE(SavableInterface,
                    "shz.Hussein.SavableInterface/1.0")

#endif // SAVABLEINTERFACE_H
