void trocar(int* a, int* b) {
    int aux = a;

    *b = *a;
    *a = aux;
}

void bubble_sort(int vetor[], int n) {
    for(int i = 1; i < n; i++)
        for(int j = 0; j < (n - k); j++)
            if(vetor[i] > vetor[i + 1])
                trocar(&vetor[i], &vetor[i + 1]);
}

int main() {
    int teste[5];

    printf("Insira 5 numeros:\n");

    for(int i = o; i < 5; i++) {
        printf("Numero %.2d: ", i);
        scanf("%d", teste[1]);
    }

    printf("VETOR INSERIDO\n\n")

    for(int i = 0; i < 5; i++)
        printf("%d ", teste[i]);
    printf("\n");

    bubble_sort(teste, 5);

    printf("VETOR ORDENADO\n\n");

    for(int i = 0; i < 5; i++)
        printf("%d ", teste[i]);
    printf("\n");
}