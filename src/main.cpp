#include <bits/stdc++.h>
#include "Utils.hpp"
#include "Item.hpp"

using namespace std;

int main()
{
  auto start = chrono::high_resolution_clock::now();
  
  setlocale(LC_ALL, "pt_BR.UTF-8");
  // Cria um objeto de localização com conversão UTF-8 para wide characters
  locale loc(locale(), new codecvt_utf8<wchar_t>);

  const int k = 20;
  Utils u;
  vector<Item> minHeap;
  unordered_map <wstring, int> frequenceMap;
  unordered_set<wstring> stopwords = u.getStopWords(loc);
  wchar_t* txt = u.getText(loc), *ch = txt;
  wstring word;
  
  while(*ch)
  {
    switch(*ch)
    {
      case L' ': case L'!': case L'?': case L'.': case L'\n': case L',': case L'(': case L')': case L';': case L'/': case L':': case L'—': case L'"': case L'\'':
        if(!word.empty())
        {
          transform(word.begin(), word.end(), word.begin(), ::tolower);
          if(stopwords.find(word) == stopwords.end())
          {
            frequenceMap[word]++;
          }
          word.clear();
        }
        break;

      default:
        if(*ch == '-' && word.size() == 0)
        {
          break;
        }
        word += *ch;
        break;
    }
    ch++;
  }

  for (const auto& aux: frequenceMap)
  {
    if(minHeap.size() < k)
    {
      minHeap.push_back(Item(aux.first, aux.second));
      if(minHeap.size() == k)
      {
        make_heap(minHeap.begin(), minHeap.end());
      }
    }
    else
    {
      if(aux.second > minHeap[0].getFrequencia())
      {
        pop_heap(minHeap.begin(), minHeap.end());
        minHeap.pop_back();
        minHeap.push_back(Item(aux.first, aux.second));
        push_heap(minHeap.begin(), minHeap.end());
      }
    }
  }

  sort(minHeap.begin(), minHeap.end());
  u.printHeap(minHeap);

  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
  wcout << endl << duration.count() << " ms" << endl;

  delete[] txt;

  return 0;
}
