#ifndef TVSERIES_H
#define TVSERIES_H

#include <QObject>
#include <QString>

class TvSeries : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(double rating READ rating WRITE setRating NOTIFY ratingChanged)

public:
    explicit TvSeries(QObject *parent = nullptr);
    QString name() const;
    void setName(const QString &name);
    QString url() const;
    void setUrl(const QString &url);
    double rating() const;
    void setRating(double rating);

signals:
    void nameChanged();
    void urlChanged();
    void ratingChanged();

private:
    QString m_name;
    QString m_url;
    double m_rating;
};

#endif
