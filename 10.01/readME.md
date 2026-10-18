<div align="center">

# 📊 Relatório do Desempenho das Buscas

**Vetor ordenado · Vetor desordenado · Árvore ABB · Árvore AVL**

![Estruturas](https://img.shields.io/badge/estruturas-4-blue)
![Lotes](https://img.shields.io/badge/lotes-50k%20%7C%20100k%20%7C%20150k-green)
![Complexidades](https://img.shields.io/badge/complexidade-O(1)%20%7C%20O(log%20N)%20%7C%20O(N)-orange)

</div>

---

## 📑 Sumário

1. [Resultados](#-resultados)
2. [Estruturas](#-estruturas)
3. [Melhor caso × Pior caso](#-melhor-caso--pior-caso)

---

## 📈 Resultados

> 💡 **Nota:** os tempos estão em microssegundos (µs). Cada linha representa uma estrutura em um lote de dados.

### Lote de 50.000

| Estrutura         | Comparações totais | Comparações médias | Tempo médio (µs) | Complexidade teórica |
| ----------------- | -----------------: | -----------------: | ---------------: | :------------------: |
| Vetor ordenado    |            176.418 |              35,28 |         0,216 µs |     `O(Log(N))`      |
| Vetor desordenado |        125.058.797 |          25.011,76 |        70,800 µs |        `O(N)`        |
| Árvore ABB        |            200.584 |              40,12 |         0,388 µs |     `O(Log(N))`      |
| Árvore AVL        |            143.744 |              28,75 |         0,287 µs |     `O(Log(N))`      |

### Lote de 100.000

| Estrutura         | Comparações totais | Comparações médias | Tempo médio (µs) | Complexidade teórica |
| ----------------- | -----------------: | -----------------: | ---------------: | :------------------: |
| Vetor ordenado    |            189.483 |              37,90 |         0,245 µs |     `O(Log(N))`      |
| Vetor desordenado |        250.926.573 |          50.185,31 |       173,400 µs |        `O(N)`        |
| Árvore ABB        |            215.410 |              43,08 |         0,455 µs |     `O(Log(N))`      |
| Árvore AVL        |            154.820 |              30,96 |         0,347 µs |     `O(Log(N))`      |

### Lote de 150.000

| Estrutura         | Comparações totais | Comparações médias | Tempo médio (µs) | Complexidade teórica |
| ----------------- | -----------------: | -----------------: | ---------------: | :------------------: |
| Vetor ordenado    |            195.769 |              39,15 |         0,273 µs |     `O(Log(N))`      |
| Vetor desordenado |        375.229.372 |          75.045,87 |       230,400 µs |        `O(N)`        |
| Árvore ABB        |            220.710 |              44,14 |         0,500 µs |     `O(Log(N))`      |
| Árvore AVL        |            160.082 |              32,02 |         0,332 µs |     `O(Log(N))`      |

---

## 🌳 Estruturas

### 🟦 Vetor ordenado

Um dos melhores algoritmos para efetuar a busca pois os números estão organizados crescentemente, por serem armazenados em um vetor, eles ficam em um bloco contínuo na memória RAM. A busca é feita cortando o vetor sempre ao meio, se o número buscado for menor, pega do meio para a esquerda, caso contrário, pega do meio para a direita e repete até encontrar ou acabar o array.

> Tem **`complexidade O(Log(N))`** pois o array é sempre cortado ao meio.

---

### 🟥 Vetor desordenado

Força a busca sequencial pois os números estão desorganizados/sem um padrão, logo, isso faz com que seja o pior caso de busca.

> Tem **`complexidade O(N)`.** pois percorre por completo

---

### 🟩 Árvore ABB

Se organiza com os menores números à esquerda e os maiores à direita do nó que está sendo comparado. São armazenados aleatoriamente na memória RAM.

> Tem **`complexidade O(Log(N))`** pois descarta metade da árvore a cada execução até que chega à folha ou encontre o número.

---

### 🟨 Árvore AVL

Segue a mesma lógica da árvore ABB, mas o seu diferencial é o fator de auto-balanceamento, deixando-a equilibrada, assim um lado não fica maior que o outro, tornando o algoritmo mais veloz. É o algoritmo que tem menos comparações, mas pela forma como são armazenados aleatoriamente na memória RAM, as buscas levam mais tempo, que causa o aumento no tempo de resposta.

> Tem **`complexidade O(Log(N))`** pois sempre descarta metade da árvore.

---

## ⚖️ Melhor caso × Pior caso

### 🟦 Vetor ordenado

| ✅ Melhor caso | ❌ Pior caso |
| --- | --- |
| Para o melhor caso, o elemento buscado deve ser exatamente o do meio `O(1)` | No pior caso, a busca percorre o vetor completamente. Os elementos seriam os da primeira casa, última casa, meio - 1 e meio + 1 `O(Log(N))` |

### 🟥 Vetor desordenado

| ✅ Melhor caso | ❌ Pior caso |
| --- | --- |
| Para o melhor caso, o elemento procurado é o primeiro do vetor `O(1)`. | No pior caso, o elemento procurado é o último do vetor `O(N)`. |

### 🟩 Árvore ABB

| ✅ Melhor caso | ❌ Pior caso |
| --- | --- |
| Para o melhor caso, o elemento buscado é a raiz `O(1)` | Para o pior caso, o elemento é uma das folhas `O(Log(N))`. |

### 🟨 Árvore AVL

| ✅ Melhor caso | ❌ Pior caso |
| --- | --- |
| Para o melhor caso, o elemento buscado é a raiz `O(1)` | Para o pior caso, o elemento é uma das folhas `O(Log(N))`. |