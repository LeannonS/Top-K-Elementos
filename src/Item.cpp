#include "Item.hpp"

Item::Item(wstring nome, int frequencia)
{
  setNome(nome);
  setFrequencia(frequencia);
}
Item::Item()
{
}

void Item::setNome(wstring nome)
{
  this->nome = nome;
}
wstring Item::getNome()
{
  return this->nome;
}

void Item::setFrequencia(int frequencia)
{
  this->frequencia = frequencia;
}
int Item::getFrequencia()
{
  return this->frequencia;
}

bool Item::operator<(const Item& other) const
{
  return frequencia > other.frequencia;
}