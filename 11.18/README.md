# Counting Sort (Ordenação por Contagem)

Implementação em C do Counting Sort, trabalho prático de Estrutura de Dados.

O algoritmo **não compara elementos entre si**. Ele conta quantas vezes cada valor aparece em um vetor auxiliar e usa essas contagens para calcular a posição final de cada elemento.

- **Não comparativo:** passa da barreira de $O(N \log N)$ dos algoritmos baseados em comparação.
- **Estável:** valores iguais mantêm a ordem original, porque a saída é preenchida de trás para frente.
- **Não é in-place:** precisa de vetores auxiliares alocados dinamicamente.
- **Só inteiros não negativos** ($0$ até $K$), na forma padrão.

## Como funciona

Exemplo com `[7, 2, 9, 0, 4, 2, 8, 5, 1, 6]`:

1. **Achar $K$:** o maior valor do vetor ($K = 9$). Os vetores auxiliares têm tamanho $K + 1$.
2. **Contar:** para cada elemento, `vetor_contador[vetor[i]]++`.
3. **Somar posições:** `vetor_posicoes[i] = vetor_contador[i] + vetor_posicoes[i - 1]`. O resultado é a última posição (contando de 1) de cada valor.
4. **Montar a saída:** percorre o vetor de trás para frente, grava cada valor em `vetor_posicoes[valor] - 1` e decrementa `vetor_posicoes[valor]`.

| Valor | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|:---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| Contador | 1 | 1 | 2 | 0 | 1 | 1 | 1 | 1 | 1 | 1 |
| Posições | 1 | 2 | 4 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |

<p align="center">
  <img src="counting_sort.gif" alt="Animação Counting Sort" width="720">
</p>

<sub>🟨 lendo · 🟪 escrevendo · 🟢 saída preenchida · 🟩 resultado final</sub>

## Complexidade

$N$ = quantidade de elementos, $K$ = maior valor.

| | Tempo | Espaço |
|:---|:---:|:---:|
| Melhor, médio e pior caso | $O(N + K)$ | $O(N + K)$ |

O tempo não depende da ordem inicial. O custo sobe quando $K \gg N$ (vetor pequeno com um valor muito alto), porque o algoritmo precisa percorrer muitos baldes vazios.

## Testes

| Cenário | Vetor | $K$ | Objetivo |
|:---|:---|:---:|:---|
| Geral | `[7, 2, 9, 0, 4, 2, 8, 5, 1, 6]` | 9 | Valor 0, repetidos e estabilidade |
| Melhor caso | `[2, 1, 2, 0, 1, 2, 0, 1, 2, 1]` | 2 | $K$ bem menor que $N$ |
| Pior caso | `[1, 2, 1, 3, 2, 1, 2, 3, 1, 50]` | 50 | 51 baldes para 10 elementos (47 vazios) |

## Código

<details>
<summary><code>counting_sort.c</code></summary>

```c
#include <stdio.h>
#include <stdlib.h>

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
    int *vetor_contador = malloc(maior_numero * sizeof(int));
    int *vetor_posicoes = malloc(maior_numero * sizeof(int));
    int *vetor_ordenado = malloc(tamanho_vetor * sizeof(int));

    // Inicializa os valores com 0 para não dar lixo de memória/erro
    inicializa_vetor(vetor_contador, maior_numero);
    inicializa_vetor(vetor_posicoes, maior_numero);
    inicializa_vetor(vetor_ordenado, tamanho_vetor);

    // Conta as ocorrências de cada número
    for(int i = 0; i < tamanho_vetor; i++)
        vetor_contador[vetor[i]]++;
    
    // Marca as posições finais de cada número (Soma Cumulativa)
    vetor_posicoes[0] = vetor_contador[0];
    for(int i = 1; i < maior_numero; i++)
        vetor_posicoes[i] = vetor_contador[i] + vetor_posicoes[i - 1];

    printf("=== ETAPA 1: CONTAGEM DE FREQUENCIA (contar as ocorrencias de cada elemento) ===\n");
    for(int i = 0; i < maior_numero; i++) {
        if(vetor_contador[i] == 0)
            printf("O valor [%d] apareceu nenhuma vez.\n", i);
        else if(vetor_contador[i] == 1)
            printf("O valor [%d] apareceu %d vez.\n", i, vetor_contador[i]);
        else
            printf("O valor [%d] apareceu %d vezes.\n", i, vetor_contador[i]);
    }
    printf("\n");
    
    printf("=== ETAPA 2: POSICOES LIMITE (contar a ultima posicao de cada elemento) ===\n");
    for(int i = 0; i < maior_numero; i++) {
        printf("Numero %d | Posicao %d\n", i, vetor_posicoes[i]);
    }
    printf("\n");

    // Preenche o vetor final de trás para frente (garante estabilidade)
    for(int i = (tamanho_vetor - 1); i >= 0; i--) {
        int valor = vetor[i];

        // vetor_posicoes[valor] - 1 ajusta a contagem (1..N) para os índices do C (0..N-1)
        vetor_ordenado[vetor_posicoes[valor] - 1] = valor; 
        vetor_posicoes[valor]--; 
    }

    printf("=== ETAPA 3: ORDENAR O VETOR ===\n");
    for(int i = 0; i < tamanho_vetor; i++) {
        printf("%d ", vetor_ordenado[i]);
    }
    printf("\n");

    free(vetor_contador);
    free(vetor_ordenado);
    free(vetor_posicoes);
}

int main() {
    int tamanho_vetor;

    printf("Por favor, insira o tamanho do vetor: ");
    scanf("%d", &tamanho_vetor);
    printf("\n");

    int vetor[tamanho_vetor];

    // Preenchendo o vetor
    printf("=== ENTRADA DE DADOS ===\n");
    for(int i = 0; i < tamanho_vetor; i++) {
        printf("Elemento %d de %d: ", (i + 1), tamanho_vetor);
        scanf("%d", &vetor[i]);
    }
    printf("\n");

    printf("=== VETOR ORIGINAL ===\n");
    for(int i = 0; i < tamanho_vetor; i++)
        printf("%d ", vetor[i]);
    printf("\n\n");

    counting_sort(tamanho_vetor, vetor);

    return 0;
}
```

</details>