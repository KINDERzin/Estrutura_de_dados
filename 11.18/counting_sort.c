

void inicializa_vetor(int *vetor, int tamanho) {
    for(int i = 0; i < tamanho; i++)
        vetor[i] = 0;
}

void counting_sort(int tamanho_vetor, int vetor[]) {
    int maior_numero = 0;
    for(int i = 0; i < tamanho_vetor; i++)
        if(maior_numero < vetor[i])
            maior_numero = vetor[i];

    maior_numero++;
    
    // Vetores dinâmicos para ser mais eficiente
    int *vetor_contador = malloc (maior_numero  * sizeof(int));
    int *vetor_posicoes = malloc (maior_numero  * sizeof(int));
    int *vetor_ordenado = malloc (tamanho_vetor * sizeof(int));

    // Inicializa os valores com 0 para não dar lixo de memória/erro
    inicializa_vetor(vetor_contador, maior_numero );
    inicializa_vetor(vetor_posicoes, maior_numero );
    inicializa_vetor(vetor_ordenado, tamanho_vetor);

    // Conta as ocorrências de cada número
    for(int i = 0; i < tamanho_vetor; i++)
        vetor_contador[vetor[i]]++;
    
    // Marca as posições finais de cada número
    vetor_posicoes[0] = vetor_contador[0];
    for(int i = 1; i < maior_numero ; i++)
        vetor_posicoes[i] = vetor_contador[i] + vetor_posicoes[i - 1];

    // Preenche o vetor final
    for(int i = (tamanho_vetor - 1); i >= 0; i--) {
        int valor = vetor[i];

        // Pega a posição do valor pelo vetor das ocorrências
        // vetor_posicoes[valor] - 1 para pegar a posição correta, pois é de (0 - N)
        vetor_ordenado[vetor_posicoes[valor] - 1] = valor; 
        // Decrementa a posição para o próxima ocorrência
        vetor_posicoes[valor]--; 
    }

    printf("=== ETAPA 1: CONTAGEM DE FREQUENCIA (contar as ocorrencias de cada elemento) ===\n");
    for(int i = 0; i < maior_numero ; i++) {
        if(vetor_contador[i] == 0)
           printf("O valor [%d] apareceu nenhuma vez.\n", vetor_contador[i]);
        else if(vetor_contador[i] == 1)
            printf("O valor [%d] apareceu %d vez.\n", i, vetor_contador[i]);
        else
            printf("O valor [%d] apareceu %d vezes.\n", i, vetor_contador[i]);
    }
    printf("\n");
    
    printf("=== ETAPA 2: POSICOES LIMITE (contar a ultima posicao de cada elemento)\n");
    for(int i = 0; i < maior_numero ; i++){
        printf("Numero %d | Posicao %d\n", i, vetor_posicoes[i]);
    }
    printf("\n");

    printf("=== ETAPA 3: ORDENAR O VETOR ===\n");
    for(int i = 0; i < tamanho_vetor; i++) {
        printf("%d ", vetor_ordenado[i]);
    }
    printf("\n");

    free(vetor_contador);
    free(vetor_ordenado);
    free(vetor_posicoes);
}

int main(){
    int tamanho_vetor;

    printf("Por favor, insira o tamanho do vetor: ");
    scanf("%d", &tamanho_vetor);
    printf("\n");

    int vetor[tamanho_vetor];

    // Preenchendo o vetor
    printf("=== ENTRADA DE DADOS ===\n");
    for(int i = 0 ; i < tamanho_vetor; i++) {
        printf("Elemento %d de %d: ", (i + 1), tamanho_vetor);
        scanf("%d", &vetor[i]);
    }
    printf("\n");

    printf("=== VETOR ORIGINAL ===\n");
    for(int i = 0 ; i < tamanho_vetor; i++)
        printf("%d ", vetor[i]);
    printf("\n");

    counting_sort(tamanho_vetor, vetor);
}