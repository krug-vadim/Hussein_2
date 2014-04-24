#include "settingsmodel.h"

SettingsModel::SettingsModel(QObject *root, QObject *parent) :
    QAbstractItemModel(parent)
{
	_root = root;
}

SettingsModel::~SettingsModel()
{
}

QModelIndex SettingsModel::index(int row, int column, const QModelIndex &parent) const
{
	if ( !hasIndex(row, column, parent) )
		return QModelIndex();

	QObject *parentItem;

	parentItem = getItem(parent);

	if ( !parentItem )
		return QModelIndex();

	if ( row >= parentItem->children().size() )
		return QModelIndex();

	if ( !qobject_cast<SettingsInterface *>(parentItem->children().at(row)) )
		return QModelIndex();

	return createIndex(row, column, parentItem->children().at(row));
}

QModelIndex SettingsModel::parent(const QModelIndex &index) const
{
	if (!index.isValid())
		return QModelIndex();

	QObject *subobject = getItem(index);
	QObject *parent = subobject->parent();

	if ( !parent )
		return QModelIndex();

	if ( parent == _root )
		return QModelIndex();

	/*if ( subtask == parent )
		return QModelIndex();*/

	if ( parent->parent() )
		return createIndex(parent->parent()->children().indexOf(parent), 0, parent);
	else
		return createIndex(0, 0, parent);
}

QVariant SettingsModel::data(const QModelIndex &index, int role) const
{
	QObject *object;
	SettingsInterface *iSettings;

	if ( !index.isValid() )
		return QVariant();

	object = static_cast<QObject *>(index.internalPointer());
	iSettings = qobject_cast<SettingsInterface *>(object);

	switch ( role )
	{
		case Qt::DisplayRole:
			if ( !object )
				break;

			if ( index.column() == 0 && iSettings )
				return iSettings->title();
			else
				return QVariant();
			break;
	}

	return QVariant();
}

Qt::ItemFlags SettingsModel::flags(const QModelIndex &index) const
{
	if ( !index.isValid() )
		return 0;

	return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant SettingsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		switch ( section )
		{
			case 0 : return tr("Settings"); break;
			default: return QVariant(); break;
		}
	}

	return QVariant();
}

int SettingsModel::rowCount(const QModelIndex &parent) const
{
	QObject *parentItem;

	if ( parent.column() > 0 )
		return 0;

	parentItem = getItem(parent);

	if ( !parentItem )
		return 0;

	return parentItem->children().size();
}

int SettingsModel::columnCount(const QModelIndex &parent) const
{
	if ( getItem(parent) )
		return 1;//return getItem(parent)->columnCount();
	else
		return 0;
}

void SettingsModel::setRoot(QObject *root)
{
	beginResetModel();
	_root = root;
	endResetModel();
}

SettingsInterface *SettingsModel::interface(const QModelIndex &index) const
{
	QObject *item = static_cast<QObject *>(index.internalPointer());
	return qobject_cast<SettingsInterface *>(item);
}

QObject *SettingsModel::getItem(const QModelIndex &index) const
{
	if ( index.isValid() )
	{
		QObject *item = static_cast<QObject *>(index.internalPointer());

		if ( item )
			return item;
	}

	return _root;
}
