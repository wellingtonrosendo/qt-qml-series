#include "tvseries.h"

TvSeries::TvSeries(QObject *parent) : QObject(parent), m_rating(0.0)
{
}

QString TvSeries::name() const
{
    return m_name;
}

void TvSeries::setName(const QString &name)
{
    if (m_name != name) {
        m_name = name;
        emit nameChanged();
    }
}

QString TvSeries::url() const
{
    return m_url;
}

void TvSeries::setUrl(const QString &url)
{
    if (m_url != url) {
        m_url = url;
        emit urlChanged();
    }
}

double TvSeries::rating() const
{
    return m_rating;
}

void TvSeries::setRating(double rating)
{
    if (m_rating != rating) {
        m_rating = rating;
        emit ratingChanged();
    }
}


QString TvSeries::desc() const
{
    return m_desc;
}

void TvSeries::setDesc(const QString &desc)
{
    if (m_desc != desc) {
        m_desc = desc;
        emit nameChanged();
    }
}


QString TvSeries::genre() const
{
    return m_genre;
}

void TvSeries::setGenre(const QString &genre)
{
    if (m_genre != genre) {
        m_genre = genre;
        emit nameChanged();
    }
}
