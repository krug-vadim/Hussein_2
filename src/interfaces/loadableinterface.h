#ifndef LOADABLEINTERFACE_H
#define LOADABLEINTERFACE_H

#include <QtCore/QtPlugin>

class LoadableInterface
{
	public:
		virtual ~LoadableInterface() {}

		virtual void load() = 0;
};

Q_DECLARE_INTERFACE(LoadableInterface,
                    "shz.Hussein.LoadableInterface/1.0")

#endif // LOADABLEINTERFACE_H
