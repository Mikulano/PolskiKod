#include "generator.h"

generator::generator(){
    _rod = R_NIJAKI;
    _zdanie = "";
    uzupCzas();
    uzupPrzym();
    uzupRzecz();
    uzupPrzysl();
    uzupZdZwiazek();
}

QString generator::zostacZdanie(){
    return _zdanie;
}

void generator::usunac(){
    _zdanie.clear();
}

void generator::usunacSpacje(){
    if (!_zdanie.isEmpty())
       _zdanie.remove(_zdanie.size() - 1, 1);
}

void generator ::SpZdanie(){
    switch (rand()%4) {
    case 0:
        SpPodmiotCzesc();
        SpOrzeczenieCzesc();
        break;
    case 1:
        SpOrzeczenieCzesc();
        SpPodmiotCzesc();
        break;
    case 2:
        SpPodmiotCzesc();
        SpOrzeczenieCzesc();
        usunacSpacje();
        _zdanie += ", ";
        SpZdZwiazek();
        SpPodmiotCzesc();
        SpOrzeczenieCzesc();
        break;
    case 3:
        SpPodmiotCzesc();
        SpOrzeczenieCzesc();
        usunacSpacje();
        _zdanie += ", ";
        SpZdZwiazek();
        SpOrzeczenieCzesc();
        SpPodmiotCzesc();
        break;
    default:
        break;
    }

}

void generator::SpPodmiotCzesc(){
    SpDefinicja();
    SpPodmiot();
}

void generator::SpOrzeczenieCzesc(){
    SpOkolicznosc();
    SpOrzeczenie();
}

void generator::SpDefinicja(){
    SpPrzymiotnik();
}

void generator::SpPodmiot(){
    SpRzeczownik();
}

void generator::SpOrzeczenie(){
    SpCzasownik();
}
void generator::SpOkolicznosc(){
    SpPrzyslowek();
}
void generator::SpPrzymiotnik(){
    _zdanie += (_slPrzymiotnik.begin()+rand()%_slPrzymiotnik.size()).key();
}

void generator::SpRzeczownik(){
    _zdanie += (_slRzeczownik.begin()+rand()%_slRzeczownik.size()).key();
}

void generator::SpPrzyslowek(){
    _zdanie += (_slPrzyslowek.begin()+rand()%_slPrzyslowek.size()).key();
}

void generator::SpCzasownik(){
    _zdanie += (_slCzasownik.begin()+rand()%_slCzasownik.size()).key();
}

void generator::SpZdZwiazek(){
    _zdanie += (_slZdZwiazek.begin()+rand()%_slZdZwiazek.size()).key();
}

void generator:: uzupCzas(){
   _slCzasownik.insert ("leci ", Atrybut ());
   _slCzasownik.insert("stoi ", Atrybut ());
   _slCzasownik.insert("leży ", Atrybut ());
   _slCzasownik.insert("leży ", Atrybut ());
}
void generator:: uzupRzecz(){
    _slRzeczownik.insert("pileczka ", Atrybut("dd"));
    _slRzeczownik.insert("kameń ", Atrybut ());
    _slRzeczownik.insert("muszla ", Atrybut ());
}
void generator:: uzupPrzysl(){
    _slPrzyslowek.insert("wysoko ",Atrybut ());
    _slPrzyslowek.insert("nisko ", Atrybut ());
    _slPrzyslowek.insert("dobrze ", Atrybut ());
}
void generator:: uzupPrzym(){
   _slPrzymiotnik.insert("mała ",Atrybut ());
   _slPrzymiotnik.insert("duża ", Atrybut ());
   _slPrzymiotnik.insert("wielka ", Atrybut ());
}

void generator::uzupZdZwiazek(){
    _slZdZwiazek.insert("", Atrybut ());
    _slZdZwiazek.insert("ale ", Atrybut ());
    _slZdZwiazek.insert("i ", Atrybut ());
    _slZdZwiazek.insert("bo ", Atrybut ());
    _slZdZwiazek.insert("wiec ", Atrybut ());
    _slZdZwiazek.insert("lecz ", Atrybut ());
    _slZdZwiazek.insert("dlatego ", Atrybut ());
    _slZdZwiazek.insert("jednak ", Atrybut ());
}
