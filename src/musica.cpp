#include "musica.hpp"

/**
 * @file musica.cpp
 *
 * @brief Este arquivo implementa as funções da classe Musica.
 */

using namespace std;

Musica::Musica(string titulo, string artista)
{
  this->titulo = titulo;
  this->artista = artista;
}

Musica::~Musica()
{
  
};

string Musica::getTitulo()
{
  return titulo;
}

void Musica::setTitulo(string titulo)
{
  this->titulo = titulo;
}

string Musica::getArtista()
{
  return artista;
}

void Musica::setArtista(string artista)
{
  this->artista = artista;
}