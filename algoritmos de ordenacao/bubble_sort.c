#include <stdio.h>

void trocar(int* a, int* b) {
    int aux = *a;

    *a = *b;
    *b = aux;
}

void bubble_sort(int vetor[], int tamanho) {
    for(int i = 1; i < tamanho; i++)
        for(int j = 0; j < (tamanho - i); j++)
            if(vetor[j] > vetor[j + 1])
                trocar(&vetor[j], &vetor[j + 1]);
}

int main() {
    int teste[5];

    printf("Insira 5 numeros:\n");

    for(int i = 0; i < 5; i++) {
        printf("Numero %d: ", (i + 1));
        scanf("%d", &teste[i]);
    }

    printf("\n\nVETOR INSERIDO\n");

    for(int i = 0; i < 5; i++)
        printf("%d ", teste[i]);
    printf("\n");

    bubble_sort(teste, 5);

    printf("\nVETOR ORDENADO\n");

    for(int i = 0; i < 5; i++)
        printf("%d ", teste[i]);
    printf("\n");

    return 0;
}