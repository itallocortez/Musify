#ifndef PLAYLIST_H
#define PLAYLIST_H

/**
 * @file playlist.hpp
 *
 * @brief Este arquivo contém as declarações da classe Playlist.
 */

#include <iostream>

#include "lista.hpp"
#include "musica.hpp"

/**
 * @brief Classe que representa uma Playlist de músicas no sistema.
 * 
 * A classe Playlist armazena uma lista de músicas e permite gerenciar qual música está sendo tocada.
 */
class Playlist {
  private:
    std::string nome; /**< Nome da playlist */
    Lista<Musica*> musicas; /**< Lista de músicas */
    int idProximaMusica; /**< ID da próxima música que será tocada */
  public:
    /**
     * @brief Construtor da classe Playlist.
     *
     * Constroi um objeto do tipo playlist setando apenas seu nome.
     */
    Playlist(std::string nome);

    /**
     * @brief Destrutor da classe Playlist.
     *
     * Limpa apenas os nós da lista de músicas, sem deletar as músicas cadastradas.
     */
    ~Playlist();


    /**
     * @brief Define o nome da playlist.
     *
     * @param nome O nome da playlist.
     */
    void setNome(std::string nome);

    /**
     * @brief Retorna o nome do playlist.
     *
     * @return O nome do playlist.
     */
    std::string getNome(void);

    /**
     * @brief Retorna a lista de músicas da playlist.
     *
     * @return O ponteiro para uma lista de ponteiros de Músicas.
     */
    Lista<Musica*>* getMusicas(void);

    /**
     * @brief Retorna o tamanho da playlist.
     *
     * @return O tamanho da playlist.
     */
    int getTamanho(void);

    /**
     * @brief Adiciona uma música à playlist.
     * 
     * Esta função adiciona uma música à playlist atual.
     * 
     * @param musica Ponteiro para o objeto Musica que será adicionado à playlist.
     */
    void adicionarMusica(Musica* musica);

    /**
     * @brief Remove a música da posição especificada.
     *
     * @param indice O índice da música a ser removida.
     * @throws std::out_of_range se o índice estiver fora dos limites da playlist.
     */
    void removerEm(int indice);

    /**
     * @brief Retorna a próxima música a ser tocada.
     *
     * Esta função retorna um ponteiro para o objeto Musica representando a próxima música
     * na playlist. Se não houver mais músicas a serem reproduzidas na playlist,
     * a função retornará nullptr.
     *
     * @return O ponteiro para o objeto Musica da proxíma música a ser tocada.
     */
    Musica* getProximaMusica(void);

    /**
     * @brief Imprime todas as músicas da playlist.
     * 
     * Esta função usa recursão para imprimir as músicas da playlist, começando pela posição especificada.
     * Se nenhum índice for fornecido, a função imprimirá as informações da primeira música
     * (índice 0) até a última música.
     * 
     * @param indice O índice da música na playlist a partir do qual se deseja imprimir as informações.
     */
    void imprimir(int indice = 0);
};

#endif