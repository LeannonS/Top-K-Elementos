#include "Utils.hpp"

Utils::Utils()
{
}

wchar_t* Utils::getText(const locale loc)
{
  wifstream txt("input.data", ios::binary);

  if(!txt.is_open())
  {
    cerr << "Não foi possível abrir o arquivo!" << endl;
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

void Utils::printHeap(vector<Item> heap)
{
  for (int i = heap.size()-1; i >= 0; i--)
  {
     wcout << "Palavra: " << heap[i].getNome() << " --- " << "Frequência: "<< heap[i].getFrequencia() << endl;
  }
}