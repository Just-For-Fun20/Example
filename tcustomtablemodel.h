#ifndef TCUSTOMTABLEMODEL_H
#define TCUSTOMTABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <vector>
#include <utility>

class TCustomTableModel : public QAbstractTableModel
{
private:
    std::vector< std::pair<QString, QString> >* _data;
public:
    TCustomTableModel();
    void setData(std::vector< std::pair<QString, QString> >* data);
    void unsetData();

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

};

#endif // TCUSTOMTABLEMODEL_H
