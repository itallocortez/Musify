#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdexcept>

#include "playlist.hpp"

/**
 * @file interface.hpp
 *
 * @brief Este arquivo contém as declarações dos recursos de interface.
 *
 * Este arquivo contém os menus do sistema e as funções que permitem ao usuário interagir
 * com o sistema de músicas.
 */

/**
 * @brief Imprime o tílulo destacado dos menus.
 *
 * Esta função imprime o título do menu de forma destacada.
 *
 * @param titulo String como o título desejado.
 */
void imprimirTitulo(std::string titulo);

/**
 * @brief Lê uma opção do usuário dentro de um intervalo específico.
 *
 * Esta função solicita para que o usuario escolha uma opção dentro de um intervalo.
 * O usuário pode inserir um valor válido que esteja dentro do intervalo especificado.
 * Caso o valor inserido pelo usuário esteja fora do intervalo, será solicitado que ele insira novamente até que
 * um valor válido seja fornecido.
 *
 * @param opcaoMinima O valor mínimo do intervalo.
 * @param opcaoMaxima O valor máximo do intervalo.
 * @return Um inteiro com a opção escolhida.
 */
int lerOpcao(int opcaoMinima, int opcaoMaxima);

/**
 * @brief Menu para cadastro de músicas.
 *
 * Esta função é responsável por apresentar a interface que permite ao usuário
 * cadastrar uma nova música no sistema.
 *
 * @param musicas Ponteiro para a lista de músicas disponíveis.
 */
void cadastrarMusica(Lista<Musica*> *musicas);

/**
 * @brief Menu para remoção de músicas.
 *
 * Esta função é responsável por apresentar a interface que permite ao usuário
 * remover uma música do sistema.
 *
 * @param playlists Ponteiro para a lista de playlists existentes.
 * @param musicas Ponteiro para a lista de músicas disponíveis.
 */
void removerMusica(Lista<Playlist*> *playlists, Lista<Musica*> *musicas);

/**
 * @brief Lista todas as músicas cadastradas.
 *
 * Essa função lista para o usuário todas as músicas que foram cadastradas.
 *
 * @param musicas Ponteiro para a lista de músicas que deseja listar.
 */
void listarMusicas(Lista<Musica*> *musicas);

/**
 * @brief Menu para Gerenciamento de Músicas
 *
 * Este menu permite ao usuário acessar opções para cadastrar, remover e listar as músicas do sistema.
 * Ao selecionar uma das opções disponíveis, o usuário será direcionado para a funcionalidade correspondente.
 * O cadastro permite adicionar novas músicas à lista de músicas disponíveis no sistema.
 * A remoção permite eliminar músicas existentes, sendo uma ação irreversível.
 * A listagem exibe todas as músicas cadastradas no sistema, facilitando a visualização.
 *
 * @param playlists Ponteiro para a lista de playlists existentes.
 * @param musicas Ponteiro para a lista de músicas disponíveis.
 * @return Retorna False se o usuário fechou o menu e True se escolheu uma opção.
 */
bool gerenciarMusicas(Lista<Playlist*> *playlists, Lista<Musica*> *musicas);

/**
 * @brief Menu para cadastro de playlists.
 *
 * Esta função é responsável por apresentar a interface que permite ao usuário
 * cadastrar uma nova playlist no sistema.
 *
 * @param playlists Ponteiro para a lista de playlists disponíveis.
 */
void cadastrarPlaylist(Lista<Playlist*> *playlists);

/**
 * @brief Menu para remoção de playlists.
 *
 * Esta função é responsável por apresentar a interface que permite ao usuário
 * remover uma playlist do sistema.
 *
 * @param playlists Ponteiro para a lista de playlists existentes.
 */
void removerPlaylist(Lista<Playlist*> *playlists);

/**
 * @brief Lista todas as playlists existentes.
 *
 * Essa função lista para o usuário todas as playlists existentes.
 *
 * @param musicas Ponteiro para a lista de playlists que deseja listar.
 */
void listarPlaylists(Lista<Playlist*> *playlists);

/**
 * @brief Seleciona uma playlist para alterar.
 *
 * Essa função abre uma interface responsável por selecionar uma
 * playlist no sistema para ser gerenciada.
 *
 * @param playlists Ponteiro para a lista de playlists existentes.
 * @return Ponteiro da playlist selecionada.
 */
Playlist* selecionarPlaylist(Lista<Playlist*> *playlists);

/**
 * @brief Adiciona uma música a playlist
 *
 * Essa função abre uma interface responsável por adicionar uma
 * música na playlist.
 *
 * @param musicas Ponteiro para a lista de playlists que deseja listar.
 * @param playlists Ponteiro para a lista de playlists existentes.
 */
void adicionarMusicaNaPlaylist(Lista<Musica*> *musicas, Playlist *playlists);

/**
 * @brief Remove uma música de uma playlist.
 *
 * Essa função abre uma interface responsável por remover uma
 * música da playlist.
 *
 * @param musicas Ponteiro para a lista de playlists que deseja listar.
 */
void removerMusicaDePlaylist(Playlist *playlist);

/**
 * @brief Move uma música de uma playlist para outra.
 *
 * Essa função abre uma interface responsável por mover uma música de uma
 * playlist para outra.
 *
 * @param playlists Ponteiro para a lista de playlists existentes.
 * @param playlistSelecionada Ponteiro para a playlist que está sendo visualizada no momento.
 */
void moverMusica(Lista<Playlist*> *playlists, Playlist *playlistSelecionada);

/**
 * @brief Mostra a próxima música que será tocada.
 *
 * Essa função imprime na tela qual será a próxima música tocada pela ordem de reprodução
 * da playlist.
 *
 * @param playlistSelecionada Ponteiro para a playlist que está sendo visualizada no momento.
 */
void tocarProxima(Playlist *playlistSelecionada);

/**
 * @brief Menu para Gerenciamento de Músicas de uma Playlist
 *
 * Este menu permite ao usuário acessar opções para adicionar, remover e listar as músicas da playlist.
 * Também é possível mover músicas para outras playlists e ver qual será a próxima música tocada.
 * Ao selecionar uma das opções disponíveis, o usuário será direcionado para a funcionalidade correspondente.
 *
 * @param playlists Ponteiro para a lista de playlists existentes.
 * @param musicas Ponteiro para a lista de músicas disponíveis.
 */
void gerenciarMusicasDePlaylist(Lista<Playlist*> *playlists, Lista<Musica*> *musicas);

/**
 * @brief Menu para Gerenciamento de Playlists
 *
 * Este menu permite ao usuário acessar opções para cadastrar, remover e listar as playlists do sistema.
 * Ao selecionar uma das opções disponíveis, o usuário será direcionado para a funcionalidade correspondente.
 * O cadastro permite adicionar novas playlists à lista de playlists existentes do sistema.
 * A remoção permite eliminar playlists existentes, sendo uma ação irreversível.
 * A listagem exibe todas as playlists cadastradas no sistema, facilitando a visualização.
 *
 * @param playlists Ponteiro para a lista de playlists existentes.
 * @param musicas Ponteiro para a lista de músicas disponíveis.
 * @return Retorna False se o usuário fechou o menu e True se escolheu uma opção.
 */
bool gerenciarPlaylists(Lista<Playlist*> *playlists, Lista<Musica*> *musicas);

/**
 * @brief Menu Principal
 *
 * Este é o menu principal do sistema, que oferece ao usuário acesso a outros menus de gerenciamento.
 * O gerenciamento de músicas permite ao usuário manipular as músicas do sistema.
 * O gerenciamento de playlists permite ao usuário manipular as playlists do sistema.
 *
 * @param playlists Ponteiro para a lista de playlists existentes.
 * @param musicas Ponteiro para a lista de músicas disponíveis.
 * @return Retorna False se o usuário fechou o menu e True se escolheu uma opção.
 */
bool menuPrincipal(Lista<Playlist*> *playlists, Lista<Musica*> *musicas);

#endif