typedef struct registro {
    int chave;
} registro;

typedef struct tabela {
    int tamanho;
    struct registro item[100];
} tabela;

int elementoRepetido(struct tabela tab, int valor) {
    int contador = 0;

    for(int i = 0; i < tab.tamanho; i++) {
        printf("%d\n", i);
        if(tab.item[i].chave == valor){
            printf("Repetiu %d\n", i);
            contador++;
        }
    }

    return contador;
}

// int tamanhoTabela(struct tabela tab) {
//     int i = 0;
//     struct registro registro = tab.item[0];
    
//     while(registro != NULL) {
//         i++;
//         registro = tab.item[i];
//     }
    
//     return i;
// }

int main() {
    struct registro r;
    struct tabela t;
    
    // t.tamanho = tamanhoTabela(t)
    t.tamanho = 0; 
    
    // Gambiarra
    for(int i = 0; i <= 100; i++) {
        t.item[i].chave = i;
        t.tamanho++;
    }    
    
    printf("Tamanho da lista %d\n", t.tamanho);
        
    for(int i = 0; i < t.tamanho; i++)
        printf("%d\n", t.item[i].chave);

    printf("O numero 5 se repetiu %d vezes na tabela", elementoRepetido(t, 5));
    
}