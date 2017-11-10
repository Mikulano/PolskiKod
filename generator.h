#ifndef GENERATOR_H
#define GENERATOR_H

#endif // GENERATOR_H

#include <QPair>
#include <QVector>
#include <QMap>
#include <QString>

enum rod{
    R_MESKI,
    R_ZENSKI,
    R_NIJAKI,
    R_MN
};

typedef QVector<int> Atrybut;
typedef QMap<QString,Atrybut> Slownik;

class generator{
    int _rod;
    QString _zdanie;
    Slownik _slRzeczownik;
    Slownik _slCzasownik;
    Slownik _slPrzymiotnik;
    Slownik _slPrzyslowek;
    Slownik _slZdZwiazek;
public:
    generator();

    void SpZdanie();
    void SpPodmiotCzesc();
    void SpOrzeczenieCzesc();
    void SpDefinicja();
    void SpPodmiot();
    void SpOrzeczenie();
    void SpOkolicznosc();
    void SpPrzymiotnik();
    void SpRzeczownik();
    void SpCzasownik();
    void SpPrzyslowek();
    void SpZdZwiazek();

    QString zostacZdanie();
    void usunac();
    void usunacSpacje();

    void uzupRzecz();
    void uzupCzas();
    void uzupPrzym();
    void uzupPrzysl();
    void uzupZdZwiazek();
};

QString zmienicRod(QString, rod);

