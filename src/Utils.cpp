#include "Utils.hpp"

Utils::Utils()
{
}

wchar_t* Utils::getText(const locale loc, string name)
{
  wifstream txt(name, ios::binary);

  if(!txt.is_open())
  {
    cerr << "Não foi possível abrir o arquivo " << name << endl;
    exit(1);
  }

  // Aplica a localização configurada ao fluxo do arquivo
  txt.imbue(loc);

  // Move o cursor para o final do arquivo para obter o tamanho
  txt.seekg(0, ios::end);

  // Obtém o tamanho do arquivo a partir da posição atual do cursor
  streampos tamanho = txt.tellg();
      
  // Move o cursor de volta para o início do arquivo
  txt.seekg(0, ios::beg);

  wchar_t* buffer = new wchar_t[tamanho];

  // Lê o conteúdo do arquivo para o buffer
  txt.read(buffer, tamanho);
  
  txt.close();

  return buffer;
}

unordered_set<wstring> Utils::getStopWords(const locale loc)
{
  wstring word;
  unordered_set<wstring> stopwords;
  
  wifstream file("dataset/stopwords.txt");

  if(!file.is_open())
  {
    cerr << "Não foi possível abrir o arquivo!" << endl;
    exit(1);
  }

  // Aplica a localização configurada ao fluxo do arquivo
  file.imbue(loc);

  while (file >> word)
  {
    stopwords.insert(word);
  }

  file.close();

  return stopwords;
  
}

void Utils::printHeap(vector<Item> heap)
{
  for (int i = 0; i < heap.size(); i++)
  {
     wcout << "Palavra: " << heap[i].getNome() << " --- " << "Frequência: "<< heap[i].getFrequencia() << endl;
  }
}
