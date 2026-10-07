#include <stdlib.h>

typedef enum {
   false, true
} boolean;

typedef struct NoAbb {
   int valor;
   struct NoAbb* direita;
   struct NoAbb* esquerda;
} NoAbb;

typedef struct ArvoreAbb {
   struct NoAbb* raiz;
} ArvoreAbb;

void inicializar_arvore_abb(struct ArvoreAbb *arv) {
   arv->raiz = NULL;
}

boolean eh_nula_abb(struct NoAbb* noAtual) {
   return noAtual == NULL;
}

struct NoAbb* criar_no_abb(int valor) {
   struct NoAbb *novoNo = (struct NoAbb*) malloc(sizeof(struct NoAbb)); 

   novoNo->valor = valor;
   novoNo->direita = NULL;
   novoNo->esquerda = NULL;

   return novoNo;
}

struct NoAbb* inserir_no_abb(struct NoAbb* noAtual, int valor) {
   if(eh_nula_abb(noAtual))
      noAtual = criar_no_abb(valor);

   else if(noAtual->valor < valor)
      noAtual->esquerda = inserir_no_abb(noAtual->esquerda, valor);
   
   else if(noAtual->valor > valor)
      noAtual->direita = inserir_no_abb(noAtual->direita, valor);

   return noAtual;
}

// Retorna o nó procurado
struct NoAbb* retorna_no_abb(struct NoAbb* noAtual, int valor, int* comparacoes) {
   if(eh_nula_abb(noAtual))
      return NULL;
   
   (*comparacoes)++;
   if(noAtual->valor == valor) 
      return noAtual;
   
   (*comparacoes)++;
   if(valor < noAtual->valor)
      return retorna_no_abb(noAtual->esquerda, valor, comparacoes);
   else
      return retorna_no_abb(noAtual->direita, valor, comparacoes);
}