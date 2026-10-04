#ifndef ARVORE_ABB_H
#define ARVORE_ABB_H

#include <stdlib.h>

typedef enum {
   false, true
} boolean;

typedef struct No {
   int numero;
   struct No* direita;
   struct No* esquerda;
} No;

typedef struct Arvore {
   struct No* raiz;
} Arvore;

void inicializar_arvore_abb(struct Arvore *arv) {
   arv->raiz = NULL;
}

boolean eh_nula_abb(struct No* noAtual) {
   return noAtual == NULL;
}

struct No* criar_no_abb(int numero) {
   No *novoNo = (struct No*) malloc(sizeof(struct No)); 

   novoNo->numero = numero;
   novoNo->direita = NULL;
   novoNo->esquerda = NULL;

   return novoNo;
}

struct No* inserir_no_abb(struct No* noAtual, int numero) {
   if(eh_nula_abb(noAtual))
      noAtual = criar_no_abb(numero);

   else if(noAtual->numero < numero)
      noAtual->esquerda = inserir_no_abb(noAtual->esquerda, numero);
   
   else if(noAtual->numero > numero)
      noAtual->direita = inserir_no_abb(noAtual->direita, numero);

   return noAtual;
}

// Retorna o nó procurado
struct No* retorna_no_abb(struct No* noAtual, int numero, int* comparacoes) {
   if(eh_nula_abb(noAtual))
      return NULL;
   
   (*comparacoes)++;
   if(noAtual->numero == numero) 
      return noAtual;
   
   (*comparacoes)++;
   if(numero < noAtual->numero)
      return retorna_no_abb(noAtual->esquerda, numero, comparacoes);
   else
      return retorna_no_abb(noAtual->direita, numero, comparacoes);
}

#endif