#include <bits/stdc++.h>
#include "Item.hpp"

#ifndef UTILS_HPP
#define UTILS_HPP

using namespace std;

class Utils
{
  public:
    Utils();

    wchar_t* getText(const locale loc);
    void printHeap(vector<Item> heap);
};

#endif