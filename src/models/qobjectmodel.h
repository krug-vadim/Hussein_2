#ifndef QOBJECTMODEL_H
#define QOBJECTMODEL_H

#include <QtCore/QAbstractItemModel>

class QObjectModel : public QAbstractItemModel
{
	Q_OBJECT

	public:
		explicit QObjectModel(QObject *root = 0, QObject *parent = 0);
		~QObjectModel();

		QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
		QModelIndex parent(const QModelIndex &index) const;

		QVariant data(const QModelIndex &index, int role) const;
		Qt::ItemFlags flags(const QModelIndex &index) const;

		QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		int columnCount(const QModelIndex &parent = QModelIndex()) const;

		void setRoot(QObject *root);

	private:
		QObject *getItem(const QModelIndex &index) const;

		QObject *_root;
};

#endif // QOBJECTMODEL_H
