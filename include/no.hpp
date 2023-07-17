#ifndef NO_H
#define NO_H

/**
 * @file no.hpp
 *
 * @brief Este arquivo contém as declarações e implementações da classe No.
 *
 * Não é possível separá-lo em .hpp e .cpp devido ao uso de classes template.
 */

/**
 * @brief Classe que representa um Nó da lista encadeada.
 * 
 * Essa classe é usada na implementação da lista encadeada, cada nó contém
 * um dado ou objeto que será armazenado e o ponteiro para o próximo nó da lista.
 */
template <typename T>
class No {
  private:
    T valor; /**< Dado ou objeto armazenado no nó. */
    No<T>* proximo; /**< Ponteiro para o próximo nó da lista. */

  public:
    /**
     * @brief Construtor da classe No.
     *
     * @param valor O dado ou objeto a ser armazenado no Nó.
     */
    No(T valor)
    {
      this->valor = valor;
      this->proximo = nullptr;
    }

    /**
     * @brief Destrutor padrão da classe nó.
     *
     * Só é preciso deletar o valor caso seja um ponteiro.
     * Seria interessante fazer isso já que armazenamos apenas ponteiros nesse projeto.
     * Porém, para aceitar qualquer elemento genérico na lista, não vamos deletar.
     *
     * @warning Caso a lista armazene ponteiros, será necessário percorre-la e deletar todos os valores.
     */
    ~No() 
    { 
      //delete valor;
    }


    /**
     * @brief Retorna o valor armazenado no nó.
     *
     * @return O dado ou objeto armazenado no nó.
     */
    T getValor(void)
    {
        return valor;
    }

    /**
     * @brief Define o dado ou objeto a ser armazenado no nó.
     *
     * @param valor O dado ou objeto a ser armazenado no nó.
     */
    void setValor(T valor)
    {
        this->valor = valor;
    }

    /**
     * @brief Retorna o ponteiro para o próximo nó.
     *
     * @return O ponteiro do próximo nó.
     */
    No<T>* getProximo(void)
    {
        return proximo;
    }

    /**
     * @brief Define o ponteiro para o próximo nó.
     *
     * @param proximo O ponteiro do próximo nó.
     */
    void setProximo(No<T>* proximo)
    {
        this->proximo = proximo;
    }
};
#endif