#ifndef BASICINTERFACE_H
#define BASICINTERFACE_H

#include <QtCore/QtPlugin>

#include <QtCore/QString>
#include <QtCore/QStringList>

class CoreInterface;

class BasicInterface
{
	public:
		BasicInterface() : _core(0) {}
		virtual ~BasicInterface() {}

		virtual CoreInterface *core() const { return _core; }
		virtual void setCore(CoreInterface *core) { _core = core; }

		virtual QString description() const = 0;

	protected:
		virtual void log(const uint event, const QString &message) const = 0;

	private:
		CoreInterface *_core;
};

Q_DECLARE_INTERFACE(BasicInterface,
                    "shz.Hussein.BasicInterface/1.0")

#endif // BASICINTERFACE_H
