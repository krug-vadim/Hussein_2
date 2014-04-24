#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H

#include <QtCore/QList>

class QWidget;

class WidgetFactoryInterface
{
	public:
		virtual ~WidgetFactoryInterface() {}

		virtual QString factoryName() const = 0;

		virtual QWidget *create(QWidget *parent = 0) = 0;
};

typedef QList<WidgetFactoryInterface *> WidgetFactories;

Q_DECLARE_INTERFACE(WidgetFactoryInterface,
                    "shz.Hussein.WidgetFactoryInterface/1.0")

#endif // WIDGETFACTORY_H
