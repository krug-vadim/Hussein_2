#include "tasksplugin.h"

TasksPlugin::TasksPlugin(QObject *parent)
    : QObject(parent)
{
	_roles.clear();
	_roles << tr("description")
	       << tr("done")
	       << tr("expanded");

	_expanded = false;
	_done = false;
	_description = tr("(empty)");
}

QString TasksPlugin::description() const
{
	return tr("Tree tasks");
}

TreeInterface *TasksPlugin::create(QObject *parent)
{
	return new TasksPlugin(parent);
}

const QStringList &TasksPlugin::roles() const
{
	return _roles;
}

QVariant TasksPlugin::data(const QString &role) const
{
	if ( role == tr("description") )
		return _description;
	else if ( role == tr("done") )
		return _done;
	else if ( role == tr("expanded") )
		return _expanded;

	return QVariant();
}

bool TasksPlugin::setData(const QString &role, const QVariant &value)
{
	if ( role == tr("description") )
	{
		_description = value.toString();
		return true;
	}
	else if ( role == tr("done") )
	{
		_done = value.toBool();
		return true;
	}
	else if ( role == tr("expanded") )
	{
		_expanded = value.toBool();
		return true;
	}
	else
		return false;
}
