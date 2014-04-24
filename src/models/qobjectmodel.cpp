#include "qobjectmodel.h"

QObjectModel::QObjectModel(QObject *root, QObject *parent) :
    QAbstractItemModel(parent)
{
	_root = root;
}

QObjectModel::~QObjectModel()
{
}

QModelIndex QObjectModel::index(int row, int column, const QModelIndex &parent) const
{
	if ( !hasIndex(row, column, parent) )
		return QModelIndex();

	QObject *parentItem;

	parentItem = getItem(parent);

	if ( !parentItem )
		return QModelIndex();

	if ( row < parentItem->children().size() )
		return createIndex(row, column, parentItem->children().at(row));
	else
		return QModelIndex();
}

QModelIndex QObjectModel::parent(const QModelIndex &index) const
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

QVariant QObjectModel::data(const QModelIndex &index, int role) const
{
	QObject *object;

	if ( !index.isValid() )
		return QVariant();

	object = static_cast<QObject *>(index.internalPointer());

	switch ( role )
	{
		case Qt::DisplayRole:
			if ( !object )
				break;

			if ( index.column() == 0 )
				return object->objectName();
			else
				return QVariant();
			break;
	}

	return QVariant();
}

Qt::ItemFlags QObjectModel::flags(const QModelIndex &index) const
{
	if ( !index.isValid() )
		return 0;

	return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant QObjectModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		switch ( section )
		{
			case 0 : return tr("Task"); break;
			default: return QVariant(); break;
		}
	}

	return QVariant();
}

int QObjectModel::rowCount(const QModelIndex &parent) const
{
	QObject *parentItem;

	if ( parent.column() > 0 )
		return 0;

	parentItem = getItem(parent);

	if ( !parentItem )
		return 0;

	return parentItem->children().size();
}

int QObjectModel::columnCount(const QModelIndex &parent) const
{
	if ( getItem(parent) )
		return 1;//return getItem(parent)->columnCount();
	else
		return 0;
}

void QObjectModel::setRoot(QObject *root)
{
	beginResetModel();
	_root = root;
	endResetModel();
}

QObject *QObjectModel::getItem(const QModelIndex &index) const
{
	if ( index.isValid() )
	{
		QObject *item = static_cast<QObject *>(index.internalPointer());

		if ( item )
			return item;
	}

	return _root;
}
