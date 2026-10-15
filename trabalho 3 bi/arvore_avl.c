#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "arvore_avl.h"

void inicializar_arvore_avl(struct ArvoreAvl *arv) {
	arv->raiz = NULL;
}

boolean eh_nulo_avl(struct NoAvl* noAtual) {
   return noAtual == NULL;
}

int altura_no_avl(struct NoAvl *noAtual) {
	return (noAtual == NULL) ? 0 : noAtual->altura;
}

int maior_altura_avl(struct NoAvl *noAtual) {
	if (eh_nulo_avl(noAtual))
		return 0;

	int altura_esq = altura_no_avl(noAtual->esquerda);
	int altura_dir = altura_no_avl(noAtual->direita);

	return (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
}

int fator_balanceamento_avl(struct NoAvl *noAtual) {
	if (eh_nulo_avl(noAtual))
		return 0;

	int altura_esq = altura_no_avl(noAtual->esquerda);
	int altura_dir = altura_no_avl(noAtual->direita);

	return altura_dir - altura_esq;
}

struct NoAvl *rotacao_direita_avl(struct NoAvl *noAtual) {
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
	noAtual->altura = maior_altura_avl(noAtual);
	novoPrincipal->altura = maior_altura_avl(novoPrincipal);

	return novoPrincipal;
}

struct NoAvl *rotacao_esquerda_avl(struct NoAvl *noAtual) {
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
	noAtual->altura = maior_altura_avl(noAtual);
	novoPrincipal->altura = maior_altura_avl(novoPrincipal);

	return novoPrincipal;
}

struct NoAvl* rotacao_dupla_direita_avl(struct NoAvl *noAtual) {
	if (noAtual == NULL || noAtual->esquerda == NULL)
		return noAtual;

	noAtual->esquerda = rotacao_esquerda_avl(noAtual->esquerda);

	return rotacao_direita_avl(noAtual);
}

struct NoAvl* rotacao_dupla_esquerda_avl(struct NoAvl *noAtual) {
	if (noAtual == NULL || noAtual->direita == NULL)
		return noAtual;

	noAtual->direita = rotacao_direita_avl(noAtual->direita);

	return rotacao_esquerda_avl(noAtual);
}

struct NoAvl* balancear_avl(struct NoAvl *noAtual) {
	if (noAtual == NULL)
		return noAtual;

	int fator = fator_balanceamento_avl(noAtual);

	if (fator > 1)
	{
		if (fator_balanceamento_avl(noAtual->direita) >= 0)
			return rotacao_esquerda_avl(noAtual);
		else
			return rotacao_dupla_esquerda_avl(noAtual);
	}
	else if (fator < -1)
	{
		if (fator_balanceamento_avl(noAtual->esquerda) <= 0)
			return rotacao_direita_avl(noAtual);
		else
			return rotacao_dupla_direita_avl(noAtual);
	}
	else
		return noAtual;
}

struct NoAvl* criar_no_avl(int numero) {
	NoAvl *novoNo = (struct NoAvl *)malloc(sizeof(struct NoAvl));

	novoNo->numero = numero;
	novoNo->altura = 0;

	novoNo->direita = NULL;
	novoNo->esquerda = NULL;

	return novoNo;
}

struct NoAvl* inserir_no_avl(struct NoAvl *noAtual, int numero) {
	if (eh_nulo_avl(noAtual))
		noAtual = criar_no_avl(numero);

	else if (numero < noAtual->numero )
		noAtual->esquerda = inserir_no_avl(noAtual->esquerda, numero);

	else if (numero > noAtual->numero)
		noAtual->direita = inserir_no_avl(noAtual->direita, numero);

	noAtual->altura = maior_altura_avl(noAtual);

	return balancear_avl(noAtual);
}

struct NoAvl* retorna_no_avl(struct NoAvl *noAtual, int numero, int *comparacoes) {
	if (eh_nulo_avl(noAtual))
		return NULL;

	(*comparacoes)++;
	if (numero == noAtual->numero)
		return noAtual;

	(*comparacoes)++;
	if (numero < noAtual->numero)
		return retorna_no_avl(noAtual->esquerda, numero, comparacoes);
	else
		return retorna_no_avl(noAtual->direita, numero, comparacoes);
}