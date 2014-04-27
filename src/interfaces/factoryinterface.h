#ifndef FACTORYINTERFACE_H
#define FACTORYINTERFACE_H

class FactoryInterface
{
	public:
		virtual ~FactoryInterface() {}

		virtual void populateAvailableTypes() = 0;
		virtual const QStringList &availableTypes() const = 0;

		virtual QObject *create(int type, QObject *parent = 0) = 0;
};

Q_DECLARE_INTERFACE(FactoryInterface,
                    "shz.Hussein.FactoryInterface/1.0")

#endif // FACTORYINTERFACE_H
