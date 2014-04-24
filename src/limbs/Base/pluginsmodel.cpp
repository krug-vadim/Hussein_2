#include "pluginsmodel.h"

#include "../../core/core.h"
#include "../../interfaces/basicinterface.h"

PluginsModel::PluginsModel(QObject *parent) :
    QAbstractTableModel(parent)
{
	_core = 0;
}

PluginsModel::~PluginsModel()
{
}

QVariant PluginsModel::data(const QModelIndex &index, int role) const
{
	if ( !index.isValid() )
		return QVariant();

	if ( !core() )
		return QVariant();

	QObject *plugin = core()->plugins().at(index.row());
	BasicInterface *basic = qobject_cast<BasicInterface *>(plugin);

	switch ( role )
	{
		case Qt::DisplayRole:
			switch ( index.column() )
			{
				case ColumnFileName:
					if ( plugin )
						return plugin->objectName();
					break;

				case ColumnDescription:
					if ( basic )
						return basic->description();
					break;
			}
			break;
	}

	return QVariant();
}

QVariant PluginsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if ( role != Qt::DisplayRole )
		return QVariant();

	if ( orientation == Qt::Horizontal )
	{
		switch ( section )
		{
			case ColumnFileName:
				return tr("Plugin");
				break;

			case ColumnDescription:
				return tr("Description");
				break;
		}

		return QVariant();
	}
	else
		return section + 1;
}

int PluginsModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);

	if ( !core() )
		return -1;

	return core()->plugins().size();
}

int PluginsModel::columnCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);

	return ColumnCount;
}

Core *PluginsModel::core() const
{
	return _core;
}

void PluginsModel::setCore(Core *core)
{
	emit layoutAboutToBeChanged();
	_core = core;
	emit layoutChanged();
}
