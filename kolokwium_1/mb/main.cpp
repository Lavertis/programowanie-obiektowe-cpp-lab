#include <iostream>
#include <vector>
#include <map>
#include "Dziecko.h"
#include "Prezent.h"

using namespace std;

void zadanie_1(vector<Dziecko> &vec);

void zadanie_2(const vector<Dziecko> &grzeczne);

void zadanie_3(vector<Dziecko> grzeczne, vector<Prezent> prezenty);

int main() {
    vector<Dziecko> vec;
    vec.emplace_back("Maja", true, 7, "Ametystowa 11");
    vec.emplace_back("Kaja", true, 5, "Ametystowa 11");
    vec.emplace_back("Jas", false, 7, "Ametystowa 11");
    vec.emplace_back("Karol", true, 4, "Bursztynowa 22");
    vec.emplace_back("Macius", true, 5, "Bursztynowa 22");
    vec.emplace_back("Ania", true, 8, "Chirurgiczna 33");
    vec.emplace_back("Ignas", false, 3, "Chirurgiczna 33");
    vec.emplace_back("Diana", false, 4, "Diamentowa 44");
    vec.emplace_back("Paulinka", true, 4, "Diamentowa 44");
    vec.emplace_back("Izydor", true, 6, "Elektryczna 55");
    cout << "Zadanie 1" << endl;
    zadanie_1(vec);
    cout << endl << "Zadanie 2" << endl;
    vector<Dziecko> grzeczne;
    grzeczne.insert(grzeczne.begin(), vec.begin(),
                    std::find_if(vec.begin(), vec.end(), [](const Dziecko& d) { return !d.isGrzeczne(); }));
    zadanie_2(grzeczne);
    vector<Prezent> prezenty;
    prezenty.emplace_back(Prezent("PZ021", 3, 5));
    prezenty.emplace_back(Prezent("PZ088", 4, 7));
    prezenty.emplace_back(Prezent("PZ090", 1, 3));
    prezenty.emplace_back(Prezent("PZ091", 0, 9));
    prezenty.emplace_back(Prezent("PZ023", 3, 5));
    prezenty.emplace_back(Prezent("PZ101", 6, 9));
    prezenty.emplace_back(Prezent("PZ087", 4, 7));
    cout << endl << "Zadanie 3" << endl;
    zadanie_3(grzeczne, prezenty);
}

void zadanie_1(vector<Dziecko> &vec) {
    cout << "Przed posortowaniem po grzecznosci" << endl;
    std::for_each(vec.begin(), vec.end(), [](auto d) { d.show(); });
    std::partition(vec.begin(), vec.end(), [](auto d) { return d.isGrzeczne(); });
    cout << "Po posortowaniu po grzecznosci" << endl;
    std::for_each(vec.begin(), vec.end(), [](auto d) { d.show(); });
}

void zadanie_2(const vector<Dziecko> &grzeczne) {
    map<string, int> map;
    for (const Dziecko &d: grzeczne) {
            map[d.getAdres()]++;
    }
    cout << "Liczba grzecznych dzieci pod danym adresem" << endl;
    for_each(map.begin(), map.end(), [](auto pair) { cout << pair.first << ": " << pair.second << endl; });
}

void zadanie_3(vector<Dziecko> grzeczne, vector<Prezent> prezenty) {
    sort(grzeczne.begin(), grzeczne.end(), [](auto d1, auto d2) { return d1.getWiek() < d2.getWiek(); });
    cout << "Grzeczne dzieci posortowane po wieku" << endl;
    std::for_each(grzeczne.begin(), grzeczne.end(), [](auto d) { d.show(); });
    vector<Dziecko> bez_prezentu;
    map<string, string> mapa_imie_prezent;
    for (const Dziecko &d: grzeczne) {
        int wiek = d.getWiek();
        auto it = std::find_if(prezenty.begin(), prezenty.end(),
                               [wiek](const Prezent &p) {
                                   return p.getDolnyWiek() <= wiek && wiek <= p.getGornyWiek();
                               });
        if (it != prezenty.end()) {
            mapa_imie_prezent[d.getImie()] = it->getId();
            prezenty.erase(it);
        } else {
            bez_prezentu.push_back(d);
        }
    }
    cout << "Dzieci z prezentami" << endl;
    for (const auto &pair: mapa_imie_prezent) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "Dzieci bez prezentu" << endl;
    std::for_each(bez_prezentu.begin(), bez_prezentu.end(), [](auto d) { d.show(); });
}