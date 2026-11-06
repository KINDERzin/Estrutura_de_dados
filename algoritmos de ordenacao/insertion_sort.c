#include <stdio.h>
// Vai casa a casa e ordena de frente pra trás
// 3, 2, 1,  -> 2, 3, 1 -> 2, 1, 3, -> 1, 2, 3
void ordenar(int vetor[], int posicao) {
    int auxiliar = vetor[posicao];

    while(posicao > 0 && auxiliar < vetor[posicao - 1]) {
        vetor[posicao] = vetor[posicao - 1]; // A posição N recebe a posição (N - 1)
        posicao--;
    }

    vetor[posicao] = auxiliar;
}

void insertion_sort(int vetor[], int tamanho) {
    for(int i = 0; i < (tamanho - 1); i++)
        ordenar(vetor, i);
}

int main() {

    int vetor_teste[5];

    printf("Insira 5 numeros:\n");
    for(int i = 0; i < 5; i++) {
        printf("Numero %d: ", (i + 1));
        scanf("%d", &vetor_teste[i]);
    }

    printf("\nVETOR INSERIDO\n");
    for(int i = 0; i < 5; i++)
        printf("%d ", vetor_teste[i]);
    printf("\n");

    insertion_sort(vetor_teste, 5);

    printf("\nVETOR ORDENADO\n");
    for(int i = 0; i < 5; i++)
        printf("%d ", vetor_teste[i]);
    printf("\n");

    return 0;
}