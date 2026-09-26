typedef struct {
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

int diferenca_nos(struct No* noAtual, int diferenca) {
    if(noAtual->esquerda != NULL && noAtual->direita != NULL)
        pass;

    else if(noAtual->esquerda != NULL)
        diferenca -= 1;

    else 
        diferenca = -1;

    if(diferenca >= -1  && diferenca <= 1) {
        diferenca_nos(noAtual->esquerda, diferenca);
        diferenca_nos(noAtual->direita, diferenca);
    }
}

int main() {

}