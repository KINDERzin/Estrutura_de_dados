typedef struct registro {
    int chave;
} registro;

typedef struct tabela {
    int tamanho;
    struct registro item[100];
} tabela;

int  busca_binaria(struct tabela tab, int valor) {
    int i, esq, dir;

    if(tab.tamanho == 0)
        return 0;

    else {
        esq = 0;
        dir = tab.tamanho - 1;

        do {
            i = (esq + dir) / 2;

            if(valor > tab.item[i].chave)
                esq = i + 1;
            else
                dir = i - 1;
        } while(valor != tab.item[i].chave && esq <= dir);

        if(valor == tab.item[i].chave)
            return i;
        else 
            return -1;
    }
}

int  busca_binaria(struct tabela tab, int valor, int esq, int dir) {
    if(tab.tamanho == 0)
        return 0;

    if(esq > dir)
        return -1;

    int i = (esq + dir) / 2;

    if(valor == tab.item[i].chave)
        return i;

    if(valor > tab.item[i].chave)
            return busca_binaria(tab, valor, i + 1, dir)
    else
        return busca_binaria(tab, valor, esq, i - 1)
}

int main() {
    struct tabela t;
    struct registro r;


}