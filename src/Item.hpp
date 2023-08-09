#include <bits/stdc++.h>

#ifndef ITEM_HPP
#define ITEM_HPP

using namespace std;

class Item
{
  private:
    wstring nome;
    int frequencia;

  public:
    Item(wstring nome, int frequencia);
    Item();

    void setNome(wstring nome);
    wstring getNome();
    void setFrequencia(int frequencia);
    int getFrequencia();
    bool operator<(const Item& other) const;
};

#endif