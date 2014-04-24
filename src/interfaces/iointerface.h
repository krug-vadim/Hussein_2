#ifndef IOINTERFACE_H
#define IOINTERFACE_H

#include <QtCore/QtPlugin>
#include <QtCore/QIODevice>

class IoInterface
{
	public:
		virtual ~IoInterface() {}

		virtual const QString &deviceName() const = 0;
};

Q_DECLARE_INTERFACE(IoInterface,
                    "shz.Hussein.IoInterface/1.0")

#endif // IOINTERFACE_H
