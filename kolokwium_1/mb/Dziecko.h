#pragma once
#include <iostream>

using namespace std;

class Dziecko {
private:
    string imie_;
    bool grzeczne_;
    int wiek_;
    string adres_;
public:
    Dziecko(string imie, bool grzeczne, int wiek, string adres);
    void show() const;

    const string &getImie() const;

    void setImie(const string &imie);

    bool isGrzeczne() const;

    void setGrzeczne(bool grzeczne);

    int getWiek() const;

    void setWiek(int wiek);

    const string &getAdres() const;

    void setAdres(const string &adres);
};

