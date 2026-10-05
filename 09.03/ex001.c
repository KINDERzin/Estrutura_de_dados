typedef enum { 
    false, true 
} boolean;

typedef struct No {
    int numero;
    int altura;
    struct No* direita;
    struct No* esquerda;
} No;

typedef struct Arvore {
    struct No* raiz;
} Arvore;

boolean eh_nulo(struct No* noAtual) {
    return noAtual == NULL;
}

void inicializar_arvore(struct Arvore *arv) {
    arv->raiz = NULL;
}

int altura_no(struct No* noAtual) {
    return (noAtual == NULL) ? 0 : noAtual->altura;
}

int maior_altura(struct No* noAtual) {
    if(eh_nulo(noAtual))
        return 0;

    int maior_esquerda = maior_altura(noAtual->esquerda);
    int maior_direita = maior_altura(noAtual->direita);

    if(maior_esquerda > maior_direita)
        return maior_esquerda + 1;

    else
        return maior_direita + 1;
}

int fator_balanceamento(struct No* noAtual) {
    if(eh_nulo(noAtual))
        return 0;
    
    int altura_esq = altura_no(noAtual->esquerda);
    int altura_dir = altura_no(noAtual->direita);

    return altura_dir - altura_esq;
}

struct No* rotacao_direita(struct No* noAtual) {
    struct No* noEsq = noAtual->esquerda;
    struct No* noDir = noAtual->direita;    
    // Nova raiz da subárvore
    struct No* novoPrincipal;

    novoPrincipal = noEsq;
    
    // A antiga raiz recebe o maior do menor
    noAtual->esquerda = noEsq->direita;
    // Nova raiz recebe o antigo nó na direita
    novoPrincipal->direita = noAtual;
    // Altera as alturas dos nós
    novoPrincipal->altura = maior_altura(novoPrincipal);
    noAtual->altura = maior_altura(noAtual);
    
    return novoPrincipal;
}

int main() {
    struct Arvore arv;
    struct No no;
    
    
    inicializar_arvore(&arv);
    
    
    return 0;
}