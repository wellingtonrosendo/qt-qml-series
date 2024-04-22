#ifndef SERIESSEARCH_H
#define SERIESSEARCH_H

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QAbstractListModel>

class TvSeries;

class SeriesSearch : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool isSearching READ isSearching NOTIFY isSearchingChanged)

public:
    enum SerieRole {
        NameRole=Qt::UserRole + 1,
        UrlRole,
        RatingRole
    };

    explicit SeriesSearch(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    bool isSearching() const;
    void setIsSearching(bool newIsSearching);

private:
    QNetworkAccessManager m_networkManager;
    QNetworkReply *m_reply = nullptr;
    QList<TvSeries*> m_tvSeries;
    bool m_isSearching;


signals:
    void isSearchingChanged();

public slots:
    void searchSeries();
    void searchSeriesByName(const QString &name);
    void parseData();
    void parseDataList();
};


#endif
