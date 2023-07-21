#include "interface.hpp"

/**
 * @file interface.cpp
 *
 * @brief Este arquivo implementa os recursos de interface.
 *
 * Este arquivo contém os menus do sistema e as funções que permitem ao usuário interagir
 * com o sistema de músicas.
 */

using namespace std;

void imprimirTitulo(string titulo)
{
  cout << "\033[1;35m" << titulo << "\033[0m" << endl << endl;
}

int lerOpcao(int opcaoMinima, int opcaoMaxima)
{
  std::string entrada; // Entrada do usuário
  int opcao; // Opção escolhida

  bool avisado = false; // Se o usuário foi avisado que escolheu uma opção não existente.

  // Loop que só acaba quando conseguir uma opção possível.
  while (true) {
    // Caso não tenha mostrado um aviso de erro, pede uma opção.
    if (!avisado) {
      cout << endl << "Escolha uma opção: ";
    }
    
    // Pega a entrada do usuário
    std::getline(std::cin, entrada);

    // Tenta ler a entrada como inteiro.
    try {
      opcao = std::stoi(entrada);

      // Se der certo, verifica se a opção está no invervalo possível
      if (opcao >= opcaoMinima && opcao <= opcaoMaxima) {
        // Se estiver, encerra o loop pra retornar essa opção.
        break;
      } else {
        // Se não estiver, retorna um erro que sera tratado.
        throw std::out_of_range("");
      }
    } catch (std::invalid_argument) {
      // Trata o caso do usuário escolher um caractere
      cout << "Use apenas números para escolher a opção: ";
      avisado = true;
    } catch (std::out_of_range) {
      // Trata o caso do usuário escolher uma opção que não existe
      std::cout << "Escolha um número entre " << opcaoMinima << " e " << opcaoMaxima << ": ";
      avisado = true;
    }
  }

  // No fim retorna um inteiro com a opção escolhida.
  return opcao;
}

void cadastrarMusica(Lista<Musica*> *musicas)
{
  imprimirTitulo("CADASTRAR MÚSICA");
  
  string titulo;
  string artista;
  
  cout << "Digite o título da música: ";
  getline(cin, titulo);

  cout << "Digite o nome do artista: ";
  getline(cin, artista);
  
  Musica *novaMusica = new Musica(titulo, artista);
  musicas->inserirNoFinal(novaMusica);

  cout << endl << "Música cadastrada com sucesso!" << endl;
}

void removerMusica(Lista<Playlist*> *playlists, Lista<Musica*> *musicas)
{
  if(musicas->isVazia()) {
    cout << "Nenhuma música para remover!" << endl;
  } else {
    listarMusicas(musicas);

    int indice; // O índice da música que será removida.    
    cout << "Informe o [ID] da música que será removida.";
    indice = lerOpcao(0, (musicas->getTamanho() - 1));

    Musica* musicaRemovida = musicas->em(indice)->getValor();

    // Para cada playlist cadastrada
    for(int i = 0; i < playlists->getTamanho(); i++) {
      // Para cada música dentro de cada playlist
      for(int j = 0; j < playlists->em(i)->getValor()->getTamanho(); j++){
        Musica* musicaPlaylist = playlists->em(i)->getValor()->getMusicas()->em(j)->getValor();
  
        // Se o título e o autor da música forem os mesmos, remove da playlist
        if(musicaPlaylist->getTitulo() == musicaRemovida->getTitulo() && musicaPlaylist->getArtista() == musicaRemovida->getArtista()) {
          playlists->em(i)->getValor()->removerEm(j);
        }
      }
    }
  
    // Por fim, remove da lista global de musicas
    delete musicaRemovida;
    musicas->removerEm(indice);

    cout << endl << "Música removida com sucesso!" << endl;
  }
}

void listarMusicas(Lista<Musica*> *musicas)
{
  if (musicas->isVazia()) {
    cout << "Nenhuma música para listar!" << endl;
  } else {
    cout << "Lista de músicas:\n";

    for (int i = 0; i < musicas->getTamanho(); i++) {
      cout << "[" << i << "] ";
      cout << "Título: " << musicas->em(i)->getValor()->getTitulo();
      cout << " | Artista: " << musicas->em(i)->getValor()->getArtista() << endl;
    }
    cout << endl;
  }
}

bool gerenciarMusicas(Lista<Playlist*> *playlists, Lista<Musica*> *musicas)
{
  imprimirTitulo("GERENCIAR MUSICAS");
  
  cout << "1. Cadastrar Música" << endl;
  cout << "2. Remover Música" << endl;
  cout << "3. Listar Músicas" << endl;
  cout << "0. Voltar" << endl;

  switch (lerOpcao(0, 3)) {
    case 1:
      cadastrarMusica(musicas);
      break;
    case 2:
      removerMusica(playlists, musicas);
      break;
    case 3: 
      listarMusicas(musicas);
      break;
    case 0:
      // Volta para o Menu Principal
      return false;
    default:
      cout << "Opção inválida!" << endl;
      break;
  }
  return true;
}

void cadastrarPlaylist(Lista<Playlist*> *playlists)
{
  imprimirTitulo("CADASTRAR PLAYLIST");
  
  string nome;
  
  cout << "Digite o nome da playlist: ";
  getline(cin, nome);
  
  Playlist *novaPlaylist = new Playlist(nome);
  playlists->inserirNoFinal(novaPlaylist);

  cout << endl << "Playlist cadastrada com sucesso!" << endl;
}

void removerPlaylist(Lista<Playlist*> *playlists)
{
  if(playlists->isVazia()) {
    cout << "Nenhuma playlist para remover!" << endl;
  } else {
    listarPlaylists(playlists);

    int indice; // O índice da playlist que será removida.    
    cout << "Informe o [ID] da playlist que será removida.";
    indice = lerOpcao(0, (playlists->getTamanho() - 1));

    Playlist* playlistRemovida = playlists->em(indice)->getValor();
  
    // Por fim, remove da lista global de playlists.
    delete playlistRemovida;
    playlists->removerEm(indice);

    cout << endl << "Playlist removida com sucesso!" << endl;
  }
}

void listarPlaylists(Lista<Playlist*> *playlists)
{
  if (playlists->isVazia()) {
    cout << "Nenhuma playlist para listar!" << endl;
  } else {
    cout << "Lista de playlists:\n";

    for (int i = 0; i < playlists->getTamanho(); i++) {
      cout << "[" << i << "] ";
      cout << "Nome: " << playlists->em(i)->getValor()->getNome() << endl;
    }
    cout << endl;
  }
}

bool gerenciarPlaylists(Lista<Playlist*> *playlists, Lista<Musica*> *musicas)
{
  imprimirTitulo("GERENCIAR PLAYLISTS");

  cout << "1. Cadastrar Playlist" << endl;
  cout << "2. Remover Playlist" << endl;
  cout << "3. Listar Playlists" << endl;
  cout << "0. Voltar" << endl;

  switch (lerOpcao(0, 3)) {
    case 1:
      cadastrarPlaylist(playlists);
      break;
    case 2:
      removerPlaylist(playlists);
      break;
    case 3: 
      listarPlaylists(playlists);
      break;
    case 0:
      // Volta para o Menu Principal
      return false;
    default:
      cout << "Opção inválida!" << endl;
      break;
  }
  return true;
}

Playlist* selecionarPlaylist(Lista<Playlist*> *playlists)
{
  if(playlists->isVazia()) {
    // Nenhuma playlist para selecionar!
    return nullptr;
  } else {
    listarPlaylists(playlists);

    int indice; // O índice da playlist que será alterada.    
    cout << "Informe o [ID] da playlist que será alterada.";
    indice = lerOpcao(0, (playlists->getTamanho() - 1));

    return playlists->em(indice)->getValor();
  }
}

void adicionarMusicaNaPlaylist(Lista<Musica*> *musicas, Playlist *playlists)
{
  if(musicas->isVazia()) {
    cout << "Nenhuma música para adicionar!" << endl;
  } else {
    imprimirTitulo("ADICIONAR MÚSICA");
    
    listarMusicas(musicas);
  
    int indice; // O índice da música que será adicionada.    
    cout << "Informe o [ID] da música que será adicionada.";
    indice = lerOpcao(0, (musicas->getTamanho() - 1));

    Musica *MusicaAdicionada = musicas->em(indice)->getValor();

    playlists->adicionarMusica(MusicaAdicionada);

    cout << endl << "Música Adicionada Com Sucesso na Playlist!" << endl;
  }
}

void removerMusicaDePlaylist(Playlist *playlist)
{
  if(playlist->getTamanho() == 0) {
    cout << "Nenhuma música para remover!" << endl;
  } else {
    listarMusicas(playlist->getMusicas());

    int indice; // O índice da playlist que será removida.    
    cout << "Informe o [ID] da música que será removida.";
    indice = lerOpcao(0, (playlist->getTamanho() - 1));
  
    // Por fim, remove da lista global de playlists.
    playlist->getMusicas()->removerEm(indice);

    cout << endl << "Música removida com sucesso!" << endl;
  }
}

void moverMusica(Lista<Playlist*> *playlists, Playlist *playlistSelecionada)
{
  if(playlists->getTamanho() < 2) {
    cout << "Nenhuma outra playlist para mover a música!" << endl;
  } else {
    if (playlistSelecionada->getTamanho() == 0) {
      cout << "Nenhuma música para mover nessa playlist!" << endl;
    } else {
      listarPlaylists(playlists);

      cout << "Informe o [ID] da playlist destino.";
      int idPlaylistDestino = lerOpcao(0, (playlists->getTamanho() - 1));
      Playlist *PlaylistDestino = playlists->em(idPlaylistDestino)->getValor();

      if(PlaylistDestino == playlistSelecionada) {
        cout << "Selecione uma playlist diferente da original." << endl;
      } else {
        listarMusicas(playlistSelecionada->getMusicas());
      
        cout << "Informe o [ID] da música que será movida.";
        int idMusicaMovida = lerOpcao(0, (playlistSelecionada->getMusicas()->getTamanho() - 1));
        Musica *MusicaMovida = playlistSelecionada->getMusicas()->em(idMusicaMovida)->getValor();

        // Remove a música da playlist original
        playlistSelecionada->getMusicas()->removerEm(idMusicaMovida);

        // Adiciona música na playlist destino
        PlaylistDestino->adicionarMusica(MusicaMovida);

        cout << endl << "Música movida com sucesso!" << endl;
      }
    }
  }
}

void tocarProxima(Playlist *playlistSelecionada)
{
  Musica *proximaMusica = playlistSelecionada->getProximaMusica();

  if(proximaMusica == nullptr) {
    cout << endl << "Não há mais músicas para serem tocadas." << endl;
  } else {
    cout << endl << "Próxima Música: " << proximaMusica->getTitulo() << endl;
  }
}

void gerenciarMusicasDePlaylist(Lista<Playlist*> *playlists, Lista<Musica*> *musicas)
{
  if(playlists->isVazia()) {
    cout << "Nenhuma playlist para gerenciar!" << endl;
  } else {
    bool fecharMenu = false;
  
    Playlist *playlistSelecionada = nullptr;
    
    while(!fecharMenu) {
      if(playlistSelecionada == nullptr) {
        playlistSelecionada = selecionarPlaylist(playlists);
      } else {
        imprimirTitulo("GERENCIANDO PLAYLIST");
        
        cout << "Playlist Selecionada: " << playlistSelecionada->getNome() << endl;
        cout << "1. Adicionar Música" << endl;
        cout << "2. Remover Música" << endl;
        cout << "3. Listar Músicas" << endl;
        cout << "4. Mover Música" << endl;
        cout << "5. Tocar Próxima" << endl;
        cout << "0. Voltar" << endl;
        
        switch (lerOpcao(0, 5)) {
          case 1:
            adicionarMusicaNaPlaylist(musicas, playlistSelecionada);
            break;
          case 2:
            removerMusicaDePlaylist(playlistSelecionada);
            break;
          case 3: 
            listarMusicas(playlistSelecionada->getMusicas());
            break;
          case 4: 
            moverMusica(playlists, playlistSelecionada);
            break;
          case 5: 
            tocarProxima(playlistSelecionada);
            break;
          case 0:
             // Volta para o Menu Principal
            fecharMenu = true;
            break;
          default:
            cout << "Opção inválida!" << endl;
            break;
        }
      }
    }
  }
}

bool menuPrincipal(Lista<Playlist*> *playlists, Lista<Musica*> *musicas)
{
  imprimirTitulo("MENU PRINCIPAL");
  
  cout << "1. Gerenciar Músicas" << endl;
  cout << "2. Gerenciar Playlists" << endl;
  cout << "3. Gerenciar Músicas de Playlist" << endl;
  cout << "0. Sair" << endl;

  switch (lerOpcao(0, 3)) {
    case 1:
      // Menu - Gerenciar Músicas
      while (gerenciarMusicas(playlists, musicas));
      break;
    case 2:
       // Menu - Gerenciar Playlists
      while (gerenciarPlaylists(playlists, musicas));
      break;
    case 3:
       // Menu - Gerenciar Músicas de Playlists
      gerenciarMusicasDePlaylist(playlists, musicas);
      break;
    case 0:
      // Fecha o programa
      return false;
    default:
      cout << "Opção inválida!" << endl;
      break;
  }
  return true;
}