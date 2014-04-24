#ifndef PLUGINSMODEL_H
#define PLUGINSMODEL_H

#include <QtCore/QAbstractTableModel>

class Core;

class PluginsModel : public QAbstractTableModel
{
	Q_OBJECT

	public:
		explicit PluginsModel(QObject *parent = 0);
		~PluginsModel();

		QVariant data(const QModelIndex &index, int role) const;

		QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		int columnCount(const QModelIndex &parent = QModelIndex()) const;

		Core *core() const;
		void setCore(Core *core);

	private:
		enum Columns
		{
			ColumnFileName = 0,
			ColumnDescription = 1
		};

		static const int ColumnCount = 2;

		Core *_core;
};

#endif // PLUGINSMODEL_H
