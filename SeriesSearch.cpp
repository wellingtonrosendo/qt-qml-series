#include "SeriesSearch.h"
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <tvseries.h>
#include <QDebug>
#include <QEventLoop>

namespace {
    const QString &k_requestUrl = "https://api.tvmaze.com/";
}

SeriesSearch::SeriesSearch(QObject *parent)
    : QAbstractListModel{parent}
{
    // TvSeries *tvSerie = new TvSeries(this);
    // tvSerie->setName("Teste");
    // tvSerie->setUrl("https://doc.qt.io/style/qt-logo-documentation.svg");
    // tvSerie->setRating(5.0);
    // tvSerie->setDesc("bla bla bla");

    // m_tvSeries.append(tvSerie);
    // searchSeriesByName("walking");
    searchSeries();
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
        case DescRole:
            return tvSerie->desc();
        case GenreRole:
            return tvSerie->genre();
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
    names[DescRole] = "desc";
    names[GenreRole] = "genre";

    return names;
}


void SeriesSearch::searchSeries()
{
    QList<QString> listSeries = {"15299", "169","66", "73", "2993", "41007", "82", "46562", "44778", "526"};
    QEventLoop loop;
    qDeleteAll(m_tvSeries);
    m_tvSeries.clear();
    foreach (const QString codSerie, listSeries) {
        m_reply = m_networkManager.get(QNetworkRequest(k_requestUrl+ "shows/" + codSerie));
        setIsSearching(true);

        // connect(m_reply, &QNetworkReply::finished, this, &SeriesSearch::parseData);
        connect(m_reply, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();
        QByteArray data = m_reply->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(data);

        QJsonObject result = jsonDocument.object();
        TvSeries *tvSerie = new TvSeries(this);
        tvSerie->setName(result["name"].toString());
        tvSerie->setUrl(result["image"].toObject()["medium"].toString());
        tvSerie->setRating(result["rating"].toObject()["average"].toDouble());
        tvSerie->setDesc(result["summary"].toString());
        tvSerie->setGenre(result["genres"].toString());
        QJsonArray genres = result["genres"].toArray();
        QString concatGenres;
        for (const auto &genre: genres) {
            concatGenres += genre.toString()+"\n";
        }

        tvSerie->setGenre(concatGenres);
        setIsSearching(false);
        m_tvSeries << tvSerie;
    }
    // setIsSearching(false);
    // m_reply->deleteLater();
    // m_reply = nullptr;

}

void SeriesSearch::searchSeriesByName(const QString &name)
{
    QUrlQuery query;

    query.addQueryItem("q",name);
    m_reply = m_networkManager.get(QNetworkRequest(k_requestUrl + "search/shows/?" + query.toString()));
    setIsSearching(true);
    connect(m_reply, &QNetworkReply::finished, this, &SeriesSearch::parseDataList);

}

void SeriesSearch::parseData()
{

    if (m_reply->error() == QNetworkReply::NoError){

        QByteArray data = m_reply->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(data);

        QJsonObject result = jsonDocument.object();
        TvSeries *tvSerie = new TvSeries(this);
        tvSerie->setName(result["name"].toString());
        tvSerie->setUrl(result["image"].toObject()["medium"].toString());
        tvSerie->setRating(result["rating"].toObject()["average"].toDouble());
        tvSerie->setDesc(result["summary"].toString());
        tvSerie->setGenre(result["genres"].toString());
        QJsonArray genres = result["genres"].toArray();
        QString concatGenres;
        for (const auto &genre: genres) {
            concatGenres += genre.toString()+"\n";
        }

        tvSerie->setGenre(concatGenres);
        setIsSearching(false);
        m_tvSeriesLoad << tvSerie;

    }
    setIsSearching(false);
    m_reply->deleteLater();
    m_reply = nullptr;


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
            tvSerie->setUrl(entry["show"].toObject()["image"].toObject()["medium"].toString());
            tvSerie->setRating(entry["show"].toObject()["rating"].toObject()["average"].toDouble());
            tvSerie->setDesc(entry["show"].toObject()["summary"].toString());
            QJsonArray genres = entry["show"].toObject()["genres"].toArray();
            QString concatGenres;
            for (const auto &genre: genres) {
                concatGenres += genre.toString()+"\n";
            }

            tvSerie->setGenre(concatGenres);
            m_tvSeries << tvSerie;
        }
        endResetModel();
    }
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

void SeriesSearch::loadTvSeries()
{

}
