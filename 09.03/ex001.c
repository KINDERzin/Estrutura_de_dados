
#include <stdio.h>
#include <stdlib.h>

typedef enum {
	false, true
} boolean;

typedef struct No {
	int numero;
	int altura;
	struct No *direita;
	struct No *esquerda;
} No;

typedef struct Arvore {
	struct No *raiz;
} Arvore;

boolean eh_nulo(struct No *noAtual) {
	return noAtual == NULL;
}

void inicializar_arvore(struct Arvore *arv) {
	arv->raiz = NULL;
}

int altura_no(struct No *noAtual) {
	return (noAtual == NULL) ? 0 : noAtual->altura;
}

int maior_altura(struct No *noAtual) {
	if (eh_nulo(noAtual))
		return 0;

	int maior_esquerda = maior_altura(noAtual->esquerda);
	int maior_direita = maior_altura(noAtual->direita);

	if (maior_esquerda > maior_direita)
		return maior_esquerda + 1;

	else
		return maior_direita + 1;
}

int fator_balanceamento(struct No *noAtual) {
	if (eh_nulo(noAtual))
		return 0;

	int altura_esq = altura_no(noAtual->esquerda);
	int altura_dir = altura_no(noAtual->direita);

	return altura_dir - altura_esq;
}

struct No *rotacao_direita(struct No *noAtual) {
	if (noAtual == NULL || noAtual->esquerda == NULL)
		return noAtual;

	struct No *noEsq = noAtual->esquerda;
	// Nova raiz da subárvore
	struct No *novoPrincipal;

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

struct No *rotacao_esquerda(struct No *noAtual) {
	if (noAtual == NULL || noAtual->direita == NULL)
		return noAtual;

	struct No *noDir = noAtual->direita;
	// Nova raiz da subárvore
	struct No *novoPrincipal;

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

struct No *rotacao_dupla_direita(struct No *noAtual) {
	if (noAtual == NULL || noAtual->esquerda == NULL)
		return noAtual;

	noAtual->esquerda = rotacao_esquerda(noAtual->esquerda);

	return rotacao_direita(noAtual);
}

struct No *rotacao_dupla_esquerda(struct No *noAtual) {
	if (noAtual == NULL || noAtual->direita == NULL)
		return noAtual;

	noAtual->direita = rotacao_direita(noAtual->direita);

	return rotacao_esquerda(noAtual);
}

struct No *balancear(struct No *noAtual) {
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

struct No *criar_no(int numero) {
	No *novoNo = (struct No *)malloc(sizeof(struct No));

	novoNo->numero = numero;
	novoNo->altura = 0;

	novoNo->direita = NULL;
	novoNo->esquerda = NULL;

	return novoNo;
}

struct No *inserir_no(struct No *noAtual, int numero) {
	if (eh_nulo(noAtual))
		noAtual = criar_no(numero);

	else if (noAtual->numero < numero)
		noAtual->esquerda = inserir_no(noAtual->esquerda, numero);

	else if (noAtual->numero > numero)
		noAtual->direita = inserir_no(noAtual->direita, numero);

	noAtual->altura = maior_altura(noAtual) + 1;

	return balancear(noAtual);
}

void imprimir_arvore(struct No* raiz, int nivel) {
	if (raiz == NULL)
		return;

	imprimir_arvore(raiz->direita, nivel + 1);

	for (int i = 0; i < nivel; i++)
		printf("       "); 
	
	printf("%d(h:%d)\n", raiz->numero, raiz->altura);

	imprimir_arvore(raiz->esquerda, nivel + 1);
}

int main() {
	struct Arvore arv;
	int numero;

	inicializar_arvore(&arv);

	do {
		printf("Digite um número (0 para sair): ");
		
		if (scanf("%d", &numero) != 0) {
            while (getchar() != '\n');
        }

		if (numero == 0) {
			printf("Saindo do programa.\n");
			break;
		}

		arv.raiz = inserir_no(arv.raiz, numero);
        
		printf("\n--- ESTADO ATUAL DA ARVORE ---\n");
		imprimir_arvore(arv.raiz, 0);
		printf("------------------------------\n\n");

	} while(numero != 0);

	return 0;
}