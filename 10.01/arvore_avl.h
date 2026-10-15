#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#include "boolean.h"

typedef struct NoAvl {
	int numero;
	int altura;
	struct NoAvl *direita;
	struct NoAvl *esquerda;
} NoAvl;

typedef struct ArvoreAvl {
	struct NoAvl *raiz;
} ArvoreAvl;

void inicializar_arvore_avl(struct ArvoreAvl *arv);
int altura_no_avl(struct NoAvl *noAtual);
int maior_altura_avl(struct NoAvl *noAtual);
int fator_balanceamento_avl(struct NoAvl *noAtual);
struct NoAvl *rotacao_direita_avl(struct NoAvl *noAtual);
struct NoAvl *rotacao_esquerda_avl(struct NoAvl *noAtual);
struct NoAvl *rotacao_dupla_direita_avl(struct NoAvl *noAtual);
struct NoAvl *rotacao_dupla_esquerda_avl(struct NoAvl *noAtual);
struct NoAvl *balancear_avl(struct NoAvl *noAtual);
struct NoAvl *criar_no_avl(int numero);
struct NoAvl *inserir_no_avl(struct NoAvl *noAtual, int numero);
struct NoAvl *retorna_no_avl(struct NoAvl *noAtual, int numero, int *comparacoes);

# endif