#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

typedef enum {
	false, true
} boolean;

typedef struct NoAvl {
	int numero;
	int altura;
	struct NoAvl *direita;
	struct NoAvl *esquerda;
} NoAvl;

typedef struct ArvoreAvl {
	struct NoAvl *raiz;
} ArvoreAvl;

boolean eh_nulo(struct NoAvl *noAtual);
void inicializar_arvore(struct ArvoreAvl *arv);
int altura_no(struct NoAvl *noAtual);
int maior_altura(struct NoAvl *noAtual);
int fator_balanceamento(struct NoAvl *noAtual);
struct NoAvl *rotacao_direita(struct NoAvl *noAtual);
struct NoAvl *rotacao_esquerda(struct NoAvl *noAtual);
struct NoAvl *rotacao_dupla_direita(struct NoAvl *noAtual);
struct NoAvl *rotacao_dupla_esquerda(struct NoAvl *noAtual);
struct NoAvl *balancear(struct NoAvl *noAtual);
struct NoAvl *criar_no(int numero);
struct NoAvl *inserir_no(struct NoAvl *noAtual, int numero);

# endif