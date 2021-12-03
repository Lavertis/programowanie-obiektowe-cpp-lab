#include "Dziecko.h"

#include <utility>

Dziecko::Dziecko(string imie, bool grzeczne, int wiek, string adres) :
        imie_(std::move(imie)), grzeczne_(grzeczne), wiek_(wiek), adres_(std::move(adres)) {}

void Dziecko::show() const {
    cout << "Dziecko{"
         << "imie: " << getImie()
         << ", grzeczne: " << (isGrzeczne() ? "tak" : "nie")
         << ", wiek: " << getWiek()
         << ", adres: " << getAdres()
         << "}" << endl;
}

const string &Dziecko::getImie() const {
    return imie_;
}

void Dziecko::setImie(const string &imie) {
    imie_ = imie;
}

bool Dziecko::isGrzeczne() const {
    return grzeczne_;
}

void Dziecko::setGrzeczne(bool grzeczne) {
    grzeczne_ = grzeczne;
}

int Dziecko::getWiek() const {
    return wiek_;
}

void Dziecko::setWiek(int wiek) {
    wiek_ = wiek;
}

const string &Dziecko::getAdres() const {
    return adres_;
}

void Dziecko::setAdres(const string &adres) {
    adres_ = adres;
}
