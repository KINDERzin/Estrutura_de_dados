
#include <stdio.h>
#include <stdlib.h>

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

boolean eh_nulo(struct NoAvl *noAtual) {
	return noAtual == NULL;
}

void inicializar_arvore(struct ArvoreAvl *arv) {
	arv->raiz = NULL;
}

int altura_no(struct NoAvl *noAtual) {
	return (noAtual == NULL) ? 0 : noAtual->altura;
}

int maior_altura(struct NoAvl *noAtual) {
	if (eh_nulo(noAtual))
		return 0;

	int maior_esquerda = maior_altura(noAtual->esquerda);
	int maior_direita = maior_altura(noAtual->direita);

	if (maior_esquerda > maior_direita)
		return maior_esquerda + 1;

	else
		return maior_direita + 1;
}

int fator_balanceamento(struct NoAvl *noAtual) {
	if (eh_nulo(noAtual))
		return 0;

	int altura_esq = altura_no(noAtual->esquerda);
	int altura_dir = altura_no(noAtual->direita);

	return altura_dir - altura_esq;
}

struct NoAvl *rotacao_direita(struct NoAvl *noAtual) {
	if (noAtual == NULL || noAtual->esquerda == NULL)
		return noAtual;

	struct NoAvl *noEsq = noAtual->esquerda;
	// Nova raiz da subárvore
	struct NoAvl *novoPrincipal;

	novoPrincipal = noEsq;

	// A antiga raiz recebe o maior do menor
	noAtual->esquerda = noEsq->direita;
	// Nova raiz recebe o antigo nó na direita
	novoPrincipal->direita = noAtual;
	// Atualiza as alturas
	noAtual->altura = maior_altura(noAtual) + 1;
	novoPrincipal->altura = maior_altura(novoPrincipal) + 1;

	return novoPrincipal;
}

struct NoAvl *rotacao_esquerda(struct NoAvl *noAtual) {
	if (noAtual == NULL || noAtual->direita == NULL)
		return noAtual;

	struct NoAvl *noDir = noAtual->direita;
	// Nova raiz da subárvore
	struct NoAvl *novoPrincipal;

	novoPrincipal = noDir;

	// A antiga raiz recebe o menor do maior
	noAtual->direita = noDir->esquerda;
	// Nova raiz recebe o antigo nó na esquerda
	novoPrincipal->esquerda = noAtual;
	// Atualiza as alturas
	noAtual->altura = maior_altura(noAtual) + 1;
	novoPrincipal->altura = maior_altura(novoPrincipal) + 1;

	return novoPrincipal;
}

struct NoAvl *rotacao_dupla_direita(struct NoAvl *noAtual) {
	if (noAtual == NULL || noAtual->esquerda == NULL)
		return noAtual;

	noAtual->esquerda = rotacao_esquerda(noAtual->esquerda);

	return rotacao_direita(noAtual);
}

struct NoAvl *rotacao_dupla_esquerda(struct NoAvl *noAtual) {
	if (noAtual == NULL || noAtual->direita == NULL)
		return noAtual;

	noAtual->direita = rotacao_direita(noAtual->direita);

	return rotacao_esquerda(noAtual);
}

struct NoAvl *balancear(struct NoAvl *noAtual) {
	if (noAtual == NULL)
		return noAtual;

	int fator = fator_balanceamento(noAtual);

	if (fator > 1)
	{
		if (fator_balanceamento(noAtual->direita) >= 0)
			return rotacao_esquerda(noAtual);
		else
			return rotacao_dupla_esquerda(noAtual);
	}
	else if (fator < -1)
	{
		if (fator_balanceamento(noAtual->esquerda) <= 0)
			return rotacao_direita(noAtual);
		else
			return rotacao_dupla_direita(noAtual);
	}
	else
		return noAtual;
}

struct NoAvl *criar_no(int numero) {
	NoAvl *novoNo = (struct NoAvl *)malloc(sizeof(struct NoAvl));

	novoNo->numero = numero;
	novoNo->altura = 0;

	novoNo->direita = NULL;
	novoNo->esquerda = NULL;

	return novoNo;
}

struct NoAvl *inserir_no(struct NoAvl *noAtual, int numero) {
	if (eh_nulo(noAtual))
		noAtual = criar_no(numero);

	else if (noAtual->numero < numero)
		noAtual->esquerda = inserir_no(noAtual->esquerda, numero);

	else if (noAtual->numero > numero)
		noAtual->direita = inserir_no(noAtual->direita, numero);

	noAtual->altura = maior_altura(noAtual) + 1;

	return balancear(noAtual);
}