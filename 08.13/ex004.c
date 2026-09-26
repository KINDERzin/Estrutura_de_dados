typedef enum {
    true,
    false
} Boolean;

typedef struct No {
    int codigo;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct Arvore {
    struct No* raiz;
} Arvore;

Boolean eh_nula(struct No* noAtual) {
    return noAtual == NULL;
}

void inicializar_arvore(struct Arvore* Arvore) {
    Arvore->raiz = NULL;
}

int maior_altura(struct No* noAtual) {
    if(eh_nula(noAtual))
        return 1;

    int maior_esquerda = maior_altura(noAtual->esquerda);
    int maior_direita = maior_altura(noAtual->direita);

    if(maior_esquerda > maior_direita)
        return maior_esquerda + 1;

    else
        return maior_direita + 1;
}

int diferenca_nos(struct No* noAtual) {
    if(noAtual == NULL)
        return 1;

    int tamanho_esq = maior_altura(noAtual->esquerda);
    int tamanho_dir = maior_altura(noAtual->direita);

    int diferenca = abs(tamanho_esq - tamanho_dir);

    if(diferenca > 1)
        return 0;

    return diferenca_nos(noAtual->esquerda) && diferenca_nos(noAtual->direita);
}

int main() {
    struct Arvore arvore;
    struct No no;

    inicializar_arvore(&arvore);

    int equilibrio_arvore = diferenca_nos(arvore.raiz);

    if(equilibrio_arvore > 1)
        printf("A árvore está desbalanceada!\n");
    else if(equilibrio_arvore >= -1 && equilibrio_arvore <= 1)
        printf("A árvore está perfeitamente balanceada!\n");
    else 
        printf("Sla parça\n");
}