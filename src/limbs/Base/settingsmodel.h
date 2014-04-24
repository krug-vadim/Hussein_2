#ifndef SETTINGSMODEL_H
#define SETTINGSMODEL_H

#include <QtCore/QAbstractItemModel>

#include "../interfaces/settingsinterface.h"

class SettingsModel : public QAbstractItemModel
{
	Q_OBJECT

	public:
		explicit SettingsModel(QObject *root = 0, QObject *parent = 0);
		~SettingsModel();

		QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
		QModelIndex parent(const QModelIndex &index) const;

		QVariant data(const QModelIndex &index, int role) const;
		Qt::ItemFlags flags(const QModelIndex &index) const;

		QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		int columnCount(const QModelIndex &parent = QModelIndex()) const;

		void setRoot(QObject *root);

		SettingsInterface *interface(const QModelIndex &index) const;

	private:
		QObject *getItem(const QModelIndex &index) const;

		QObject *_root;
};

#endif // SETTINGSMODEL_H
