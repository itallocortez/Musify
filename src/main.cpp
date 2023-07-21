#include "interface.hpp"

/**
 * @file main.cpp
 *
 * @brief Este arquivo contém a função inicial do programa.
 *
 * Este arquivo inicia o programa e cria músicas e playlists padrões para testes.
 */

int main() {
  Lista<Playlist*> playlists;
  Lista<Musica*> musicas;

  Playlist *play1 = new Playlist("Pop");
  Playlist *play2 = new Playlist("Metal");
  Musica *musi1 = new Musica("Uptown Funk", "Bruno Mars");
  Musica *musi2 = new Musica("Someone Like You", "Adele");
  Musica *musi3 = new Musica("Shape of You", "Ed Sheera");
  Musica *musi4 = new Musica("Paranoid", "Black Sabbath");
  Musica *musi5 = new Musica("Master of Puppets", "Metallica");

  playlists.inserirNoFinal(play1);
  playlists.inserirNoFinal(play2);
  musicas.inserirNoFinal(musi1);
  musicas.inserirNoFinal(musi2);
  musicas.inserirNoFinal(musi3);
  musicas.inserirNoFinal(musi4);
  musicas.inserirNoFinal(musi5);

  playlists.em(0)->getValor()->adicionarMusica(musi1);
  playlists.em(0)->getValor()->adicionarMusica(musi2);
  playlists.em(0)->getValor()->adicionarMusica(musi3);
  playlists.em(1)->getValor()->adicionarMusica(musi4);
  playlists.em(1)->getValor()->adicionarMusica(musi5);

  while (menuPrincipal(&playlists, &musicas)) {
  }

  playlists.limparListaDePonteiros();
  musicas.limparListaDePonteiros();

  return 0;
}