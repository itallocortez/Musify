#ifndef MUSICA_H
#define MUSICA_H

#include <string>

/**
 * @file musica.hpp
 *
 * @brief Este arquivo contém as declarações da classe Musica.
 */

/**
 * @brief Classe que representa uma Música no sistema.
 * 
 * A classe Musica armazena e gerencia os dados de uma música, como o seu título e nome do seu artista.
 */
class Musica {
  private:
    std::string titulo; /**< Título da música */
    std::string artista; /**< Nome do artista */

  public:
    /**
     * @brief Construtor da classe Musica.
     *
     * @param titulo O título da música.
     * @param artista O nome do artista.
     */
    Musica(std::string titulo, std::string artista);

    /**
     * @brief Destrutor da classe Musica.
     */
    ~Musica();

    /**
     * @brief Retorna o título da música.
     *
     * @return O título da música.
     */
    std::string getTitulo();

    /**
     * @brief Define o título da música.
     *
     * @param titulo O título da música.
     */
    void setTitulo(std::string titulo);

    /**
     * @brief Retorna o nome do artista.
     *
     * @return O nome do artista.
     */
    std::string getArtista();

    /**
     * @brief Define o nome do artista.
     *
     * @param artista O nome do artista.
     */
    void setArtista(std::string artista);
};

#endif