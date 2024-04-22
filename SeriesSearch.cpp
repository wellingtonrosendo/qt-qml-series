#include "SeriesSearch.h"
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <tvseries.h>
#include <QDebug>

namespace {
    const QString &k_requestUrl = "https://api.tvmaze.com/search/shows";
}

SeriesSearch::SeriesSearch(QObject *parent)
    : QAbstractListModel{parent}
{

}

int SeriesSearch::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_tvSeries.size();
}

QVariant SeriesSearch::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row() >= 0 && index.row() < m_tvSeries.size()) {
        TvSeries * tvSerie= m_tvSeries[index.row()];

        switch((SerieRole) role) {
        case NameRole:
            return tvSerie->name();
        case UrlRole:
            return tvSerie->url();
        case RatingRole:
            return tvSerie->rating();
        }
    }

    return {};
}

QHash<int, QByteArray> SeriesSearch::roleNames() const
{
    QHash<int, QByteArray> names;

    names[NameRole] = "name";
    names[UrlRole] = "url";
    names[RatingRole] = "rating";

    return names;
}


void SeriesSearch::searchSeries()
{
    QList<QString> listSeries = {"15299", "169", "66", "73", "2993", "41007", "82", "46562", "44778", "526"};
    foreach (const QString codSerie, listSeries) {
        m_reply = m_networkManager.get(QNetworkRequest(k_requestUrl+ "/" + codSerie));
        connect(m_reply, &QNetworkReply::finished, this, &SeriesSearch::parseData);
    }

}

void SeriesSearch::searchSeriesByName(const QString &name)
{
    QUrlQuery query;

    query.addQueryItem("q",name);
    m_reply = m_networkManager.get(QNetworkRequest(k_requestUrl + "?" + query.toString()));
    setIsSearching(true);
    connect(m_reply, &QNetworkReply::finished, this, &SeriesSearch::parseDataList);

}

void SeriesSearch::parseData()
{
    if (m_reply->error() == QNetworkReply::NoError){
        qDeleteAll(m_tvSeries);
        m_tvSeries.clear();

        QByteArray data = m_reply->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(data);
        QJsonObject headers = jsonDocument["headers"].toObject();


        if (headers["status"].toString() == "success") {
            QJsonObject result = jsonDocument["results"].toObject();
            TvSeries *tvSerie = new TvSeries(this);
            tvSerie->setName(result["name"].toString());
            tvSerie->setUrl(result["url"].toString());
            tvSerie->setRating(result["rating"].toObject()["average"].toDouble());
            m_tvSeries << tvSerie;

        } else {
            qWarning() << headers["error_string"];
        }
    }
}


void SeriesSearch::parseDataList()
{
    if (m_reply->error() == QNetworkReply::NoError){
        beginResetModel();
        qDeleteAll(m_tvSeries);
        m_tvSeries.clear();

        QByteArray data = m_reply->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(data);

        QJsonObject headers = jsonDocument["headers"].toObject();

        QJsonArray results = jsonDocument.array();
        for (const auto &result : results) {
            QJsonObject entry = result.toObject();
            TvSeries *tvSerie = new TvSeries(this);
            tvSerie->setName(entry["show"].toObject()["name"].toString());
            tvSerie->setUrl(entry["show"].toObject()["url"].toString());
            tvSerie->setRating(entry["show"].toObject()["rating"].toObject()["average"].toDouble());
            m_tvSeries << tvSerie;
        }
        endResetModel();
    }
    qDebug()<< "aaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    setIsSearching(false);
    m_reply->deleteLater();
    m_reply = nullptr;
}

bool SeriesSearch::isSearching() const
{
    return m_isSearching;
}

void SeriesSearch::setIsSearching(bool newIsSearching)
{
    if (m_isSearching == newIsSearching)
        return;
    m_isSearching = newIsSearching;
    emit isSearchingChanged();
}
