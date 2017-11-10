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

QString zmienicRod(QString slowo, int rod){
    bool flag = true;
    int counter = -1;
    QString zakon="";
    QString::iterator it = slowo.begin();
    QString::iterator itZakon = slowo.begin();
    while (counter!=rod){
        if (*it == '/'){
            counter++;
            if(flag){
                flag = false;
                itZakon = it;
            }
        }
        it++;
    }

    while(*it != '/' && it != slowo.end()){
        zakon += *it;
        it++;
    }

    slowo.truncate(itZakon-slowo.begin());
    slowo+=zakon;
    return slowo;
}

void generator ::SpZdanie(){
    _rod = rand()%3;
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
    auto zapis = _slPrzymiotnik.begin()+rand()%_slPrzymiotnik.size();
   _zdanie += zmienicRod(zapis.key(),_rod)+=" ";
  //  _zdanie += (_slPrzymiotnik.begin()+rand()%_slPrzymiotnik.size()).key();
}

void generator::SpRzeczownik(){
    auto zapis = _slRzeczownik.begin()+rand()%_slRzeczownik.size();
    while(zapis.value()[0]!=_rod){
        zapis = _slRzeczownik.begin()+rand()%_slRzeczownik.size();
    }
    _zdanie += (zapis.key());
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
    _slRzeczownik.insert("pileczka ", Atrybut() = {R_ZENSKI});
    _slRzeczownik.insert("kameń ", Atrybut ()={R_MESKI});
    _slRzeczownik.insert("muszla ", Atrybut ()={R_ZENSKI});
    _slRzeczownik.insert("kwiat ", Atrybut ()={R_MESKI});
    _slRzeczownik.insert("kociątko ", Atrybut ()={R_NIJAKI});
    _slRzeczownik.insert("mydło ", Atrybut ()={R_NIJAKI});

}
void generator:: uzupPrzysl(){
    _slPrzyslowek.insert("wysoko ",Atrybut ());
    _slPrzyslowek.insert("nisko ", Atrybut ());
    _slPrzyslowek.insert("dobrze ", Atrybut ());
}
void generator:: uzupPrzym(){
   _slPrzymiotnik.insert("mał/y/a/e",Atrybut ());
   _slPrzymiotnik.insert("duż/y/a/e", Atrybut ());
   _slPrzymiotnik.insert("wielk/i/a/ie", Atrybut ());
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
