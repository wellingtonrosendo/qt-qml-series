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
