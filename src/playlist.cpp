#include "playlist.hpp"

using namespace std;

Playlist::Playlist(string nome)
{
  this->nome = nome;
  this->idProximaMusica = 0;
}

Playlist::~Playlist()
{ 
  musicas.limparLista(); 
}

void Playlist::setNome(string nome)
{
  this->nome = nome;
}

string Playlist::getNome(void)
{ 
  return nome;
}

Lista<Musica*>* Playlist::getMusicas(void)
{
  return &musicas;
}

int Playlist::getTamanho() 
{ 
  return musicas.getTamanho();
}

void Playlist::adicionarMusica(Musica* musica) 
{
  musicas.inserirNoFinal(musica);
}

void Playlist::removerEm(int indice)
{ 
  musicas.removerEm(indice);
}

Musica* Playlist::getProximaMusica() 
{
  Musica *proximaMusica = nullptr;
  
  if (idProximaMusica < musicas.getTamanho()) {
    proximaMusica = musicas.em(idProximaMusica)->getValor();
    ++idProximaMusica;
  } else {
    proximaMusica = nullptr;
  }

  return proximaMusica;
}

void Playlist::imprimir(int indice)
{
  if (musicas.isVazia()) {
    std::cout << "Essa playlist está vazia!\n";
  } else if (indice < musicas.getTamanho()) {
    //cout << indice + 1 << ". " << musicas.em(indice)->getValor();
    cout << "Título: " << musicas.em(indice)->getValor()->getTitulo()
         << " | Artista: " << musicas.em(indice)->getValor()->getArtista() << endl;
    imprimir(++indice);
  }  
}
