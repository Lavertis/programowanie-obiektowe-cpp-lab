#include <iostream>
#pragma once

using namespace std;

class Prezent {
private:
    string id_;
    int dolny_wiek_;
    int gorny_wiek_;
public:
    const string &getId() const;

    void setId(const string &id);

    int getDolnyWiek() const;

    void setDolnyWiek(int dolnyWiek);

    int getGornyWiek() const;

    void setGornyWiek(int gornyWiek);

    Prezent(string id, int dolnyWiek, int gornyWiek);
};

