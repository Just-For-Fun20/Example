#include "tcustomtablemodel.h"
#include <QDebug>
TCustomTableModel::TCustomTableModel(){ }

void TCustomTableModel::setData(const std::vector<std::pair<QString, QString> > &data)
{
    _data = data;
}

void TCustomTableModel::unsetData()
{
    if(_data.size()) {_data.clear();}
}

int TCustomTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _data.size();
}

int TCustomTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant TCustomTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (_data.size())
    {
        if (index.column() == 0)
        {
            return _data.at(index.row()).first;
        }
        else if (index.column() == 1)
        {
            return _data.at(index.row()).second;
        }
    }
    return QVariant();
}

QVariant TCustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("File name");
        } else if (section == 1) {
            return QString("Size(in bytes)");
        }
    }
    return QVariant();
}
