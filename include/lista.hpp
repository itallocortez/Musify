#ifndef LISTA_H
#define LISTA_H

/**
 * @file lista.hpp
 *
 * @brief Este arquivo contém as declarações e implementações da classe Lista.
 *
 * Não é possível separá-lo em .hpp e .cpp devido ao uso de classes template.
 */

#include <stdexcept>

#include "no.hpp"

/**
 * @brief Classe que representa uma Lista Encadeada.
 * 
 * Essa classe implementa uma Lista Encadeada, utilizando dos nós implementados na classe No para armazenar uma lista de 
 * elementos. Essa estrutura de dados foi escolhida para estimular o aprendizado de ponteiros e alocação 
 * dinâmica na linguagem C++.
 */
template <typename T>
class Lista {
  private:
    No<T>* cabeca; /**< Ponteiro para o primeiro nó da lista. */
    No<T>* cauda; /**< Ponteiro para o último nó da lista. */
    int tamanho; /**< Tamanho da lista. */

  public:
    /**
     * @brief Construtor da classe Lista.
     */
    Lista()
    {
      cabeca = nullptr;
      cauda = nullptr;
      tamanho = 0;
    }

    /**
     * @brief Destrutor da classe Lista.
     *
     * Foram criadas duas funções diferentes para caso a lista
     * seja ou não de ponteiros
     * @see limparLista(); limparListaDePonteiros()
     */
    ~Lista()
    {

    }

    /**
     * @brief Verifica se a lista está vazia.
     *
     * @return true se a lista estiver vazia, false caso contrário.
     */
    bool isVazia() 
    {
      return (tamanho == 0);
    }

    /**
     * @brief Retorna o tamanho atual da lista.
     *
     * @return O tamanho atual da lista.
     */
    int getTamanho() 
    {
      return tamanho;
    }

    /**
     * @brief Insere um elemento no final da lista.
     *
     * @param valor O dado ou objeto que será inserido.
     */
    void inserirNoFinal(T valor)
    {
      // Cria um novo nó com o elemento
      No<T>* novo_no = new No<T>(valor);

      // Se a lista estiver vazia, o elemento adicionado será tanto o primeiro (head)
      // quanto o último (tail) elemento da lista.
      if (cabeca == nullptr) {
        cabeca = novo_no;
        cauda = novo_no;
      } else {
        // Se não estiver vazia, o próximo elemento do antigo último elemento
        // sera o elemento adicionado.
        cauda->setProximo(novo_no);

        // O elemento adicionado é o ultimo elemento da lista agora.
        cauda = novo_no;
      }
      // A lista tem mais um elemento.
      tamanho++;
    }

    /**
     * @brief Retorna o ponteiro do nó que está no índice informado.
     *
     * @param indice O índice do nó a ser retornado.
     * @return O nó na posição especificada.
     * @throws std::out_of_range se o índice estiver fora dos limites da lista.
     */
    No<T>* em(int indice) {
      // Se o índice for menor que zero, ou igual ou maior que o tamanho da lista
      if (indice < 0 || indice >= tamanho) {
        // Retorna um erro (out_of_range)
        throw std::out_of_range("Índice fora dos limites da lista");
      }
      // Pega a cabeça (head) da lista
      No<T>* current = cabeca;

      // Percorre a lista até chegar no nó que sera retornado.
      for (int i = 0; i < indice; i++) {
        current = current->getProximo();
      }
      return current;
    }

    /**
     * @brief Remove o nó da posição especificada.
     *
     * @param index O índice do nó a ser removido.
     * @throws std::out_of_range se o índice estiver fora dos limites da lista.
     */
    void removerEm(int indice) {
      // Se o índice for menor que zero, ou igual ou maior que o tamanho da lista
      if (indice < 0 || indice >= tamanho) {
        // Retorna um erro (out_of_range)
        throw std::out_of_range("Indice fora dos limites da lista");
      }
      
      No<T>* current = cabeca;
      No<T>* previous = nullptr;

      // Percorre a lista até chegar no nó que sera removido.
      for (int i = 0; i < indice; i++) {
          previous = current;
          current = current->getProximo();
      }

      // Se o elemento for a cabeça (head) da lista.
      if (current == cabeca) {
        //std::cout << "DEBUG: elemento removido da (head) da lista." << std::endl;

        No<T>* temp = cabeca;
        // O (head) será o próximo elemento.
        cabeca = cabeca->getProximo();
        
        // Libera a memória do nó
        delete temp;
        // Diminui o tamanho da lista
        tamanho--;

        // Se a lista ficar vazia depois disso
        if (cabeca == nullptr) {
          // A cauda não apontara para nada
          cauda = nullptr;
        }
      } else if (current == cauda) { // Se o elemento for o último da lista (tail)
        //std::cout << "DEBUG: elemento removido da (tail) da lista" << std::endl;
        No<T>* temp = cauda;

        // A cauda sera o elemento antes dela
        cauda = previous;
        // Como é o último elemento, não aponta para nada.
        cauda->setProximo(nullptr);

        // Libera a memória do nó
        delete temp;
        // Diminui o tamanho da lista
        tamanho--;
      } else { // Se o elemento estiver no meio da lista
        //std::cout << "DEBUG: elemento removido do (meio) da lista" << std::endl;
        No<T>* temp = current;

        // O nó anterior ao removido apontará para o próximo do removido.
        previous->setProximo(current->getProximo());

        // Libera a memória do nó
        delete temp;
        // Diminui o tamanho da lista
        tamanho--;
      }
    }

    /**
     * @brief Limpa a lista encadeada, removendo todos os nós.
     *
     * Essa função é feita para limpar uma lista de elementos que não são ponteiros.
     *
     * @warning Caso não seja usada até o fim da execução a memória alocada irá vazar.
     */
    void limparLista() {
      // Percorre toda a lista, removendo cada nó.
      while(!isVazia()) {
        removerEm(0); // Apaga o nó.
      }
    }

    /**
     * @brief Limpa a lista encadeada de ponteiros, removendo todos os nós e liberando a memória dos elementos.
     *
     * Essa função é feita para limpar uma lista de elementos que são ponteiros.
     *
     * @warning Caso não seja usada até o fim da execução a memória alocada irá vazar.
     */
    void limparListaDePonteiros() {
      // Percorre toda a lista, removendo cada nó e liberando a memória dos elementos.
      while(!isVazia()) {
        delete em(0)->getValor(); // Libera a memória do ponteiro do elemento.
        removerEm(0); // Apaga o nó.
      }
    }
};
#endif