#include "interface.hpp"

using namespace std;

void imprimirTitulo(std::string titulo) {
  cout << "\033[1;35m" << titulo << "\033[0m" << endl << endl;
}

int lerOpcao(int opcaoMinima, int opcaoMaxima) {
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

void cadastrarMusica(Lista<Musica*> *musicas) {
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

void removerMusica(Lista<Playlist*> *playlists, Lista<Musica*> *musicas) {
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

void listarMusicas(Lista<Musica*> *musicas) {
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

bool gerenciarMusicas(Lista<Playlist*> *playlists, Lista<Musica*> *musicas) {
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

bool menuPrincipal(Lista<Playlist*> *playlists, Lista<Musica*> *musicas) {
  imprimirTitulo("MENU PRINCIPAL");
  
  cout << "1. Gerenciar Músicas" << endl;
  cout << "2. Gerenciar Playlists" << endl;
  cout << "0. Sair" << endl;

  switch (lerOpcao(0, 2)) {
    case 1:
      // Menu - Gerenciar Músicas
      while (gerenciarMusicas(playlists, musicas)) {
      }
      break;
    case 2:
       // Menu - Gerenciar Playlists
      while (1) {
      }
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