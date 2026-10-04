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

void inicializar_arvore_avl(struct Arvore* arv) {
   arv->raiz = NULL;
}

boolean eh_nula_avl(struct No* no) {
   return no == NULL;
}

struct No* criar_no_avl(int numero) {
   struct No* novo_no = (struct No*) malloc(sizeof(struct No));
   novo_no->numero = numero;
   novo_no->direita = NULL;
   novo_no->esquerda = NULL;

   return novo_no;
}

struct No* inserir_no_avl(struct No* noAtual, int numero) {
   if(eh_nula_avl(noAtual))
      noAtual = criar_no_avl(numero);

   else if(numero < noAtual->numero)
      noAtual->esquerda = inserir_no_avl(noAtual->esquerda, numero);

   else if(numero > noAtual->numero)
      noAtual->direita = inserir_no_avl(noAtual->direita, numero);

   return noAtual;
}

struct No* retorna_no_avl(struct No* noAtual, int numero, int* comparacoes) {
   if(eh_nula_avl(noAtual))
      return NULL;

   (*comparacoes)++;
   if(noAtual->numero == numero) 
      return noAtual;

   (*comparacoes)++;
   if(numero < noAtual->numero)
      return retorna_no_avl(noAtual->esquerda, numero, comparacoes);

   else
      return retorna_no_avl(noAtual->direita, numero, comparacoes);
}

#endif