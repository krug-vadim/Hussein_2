#ifndef TASKSPLUGIN_H
#define TASKSPLUGIN_H

#include <QtCore/QObject>

#include "../../interfaces/basicinterface.h"
#include "../../interfaces/treeinterface.h"

#include <QtCore/QByteArray>
#include <QtCore/QVariant>

class TasksPlugin : public QObject,
                    public BasicInterface,
                    public TreeInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.Hussein.TasksPlugin")
	Q_INTERFACES(BasicInterface)
	Q_INTERFACES(TreeInterface)

	public:
		explicit TasksPlugin(QObject *parent = 0);
		~TasksPlugin();

		// BasicInterface
		virtual QString description() const;

		// TreeInterface
		virtual TreeSharedPointer create(QObject *parent = 0);

		virtual const QStringList &roles() const;

		virtual QVariant data(const QString &role) const;
		virtual bool setData(const QString &role, const QVariant &value);

	protected:

	signals:
		void log(const uint event, const QString &message) const;
		void dataChanged(QVariant &value, const QString &role);
		void parentChanged(TreeWeakPointer oldParent, TreeWeakPointer newParent);

	private:
		QStringList _roles;

		bool _expanded;
		bool _done;

		QString _description;
};

#endif // TASKSPLUGIN_H
