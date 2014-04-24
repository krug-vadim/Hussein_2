#ifndef LOGINTERFACE_H
#define LOGINTERFACE_H

#include <QtCore/QString>

class LogInterface
{
	public:
		virtual ~LogInterface() {}

	public slots:
		virtual void logMessage(const uint event, const QString &message) = 0;
};

Q_DECLARE_INTERFACE(LogInterface,
                    "shz.Hussein.LogInterface/1.0")

#endif // LOGINTERFACE_H
