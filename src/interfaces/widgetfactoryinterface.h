#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H

class QWidget;

class WidgetFactoryInterface
{
	public:
		virtual ~WidgetFactoryInterface() {}

		virtual QWidget *create(QWidget *parent = 0) = 0;
};

Q_DECLARE_INTERFACE(WidgetFactoryInterface,
                    "shz.Hussein.WidgetFactoryInterface/1.0")

#endif // WIDGETFACTORY_H
