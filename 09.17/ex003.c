typedef struct registro {
    int chave;
} registro;

typedef struct tabela {
    int tamanho;
    struct registro item[100];
} tabela;

int proximoElemento(struct tabela tab, int valor) {
    int i = 0;
    struct registro r = tab.item[i];
    while(true) {
        if(r.chave > valor)
            return r.chave;

        r = tab.item[i];
        i++;
    }
}

int main() {
    struct registro r;
    struct tabela t;

    for(int i = 0; i <= 100; i++) {
        t.item[i].chave = i;
        t.tamanho++;
    }    

    int maior = proximoElemento(t, 2);
    printf("Proximo %d", maior);
}