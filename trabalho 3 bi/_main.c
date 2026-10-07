#define MAX_50K 50000
#define MAX_100K 100000
#define MAX_150K 150000

#define BUSCA_MAX 5000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "arvore_abb.h"
#include "arvore_avl.h"
#include "vetor_ordenado.h"
#include "vetor_desordenado.h"

int main() {
   srand(time(NULL));
   // DECLARAÇÃO DAS ESTRUTURAS
   
   // Para 50K posições
   struct ArvoreAbb abb_50;
   struct ArvoreAvl avl_50;
   struct VetorVo vo_50;
   struct VetorVd vd_50;
   
   // Para 100K posições
   struct ArvoreAbb abb_100;
   struct ArvoreAvl avl_100;
   struct VetorVo vo_100;
   struct VetorVd vd_100;

   // Para 150K posições
   struct ArvoreAbb abb_150;
   struct ArvoreAvl avl_150;
   struct VetorVo vo_150;
   struct VetorVd vd_150;

   // INICIALIZAÇÃO DAS ESTRUTURAS
   inicializa_vetor_vd(&vd_50);
   inicializa_vetor_vd(&vd_100);
   inicializa_vetor_vd(&vd_150);

   inicializa_vetor_vo(&vo_50);
   inicializa_vetor_vo(&vo_100);
   inicializa_vetor_vo(&vo_150);

   inicializar_arvore_abb(&abb_50);
   inicializar_arvore_abb(&abb_100);
   inicializar_arvore_abb(&abb_150);
   
   inicializar_arvore_avl(&avl_50);
   inicializar_arvore_avl(&avl_100);
   inicializar_arvore_avl(&avl_150);

   // INICIALIZAÇÃO DOS ARRAYS
   // 50K Posições
   vo_50.tamanho = MAX_50K;
   vo_50.vetor = (int*) malloc(MAX_50K * sizeof(int));
   
   vd_50.tamanho = MAX_50K;
   vd_50.vetor = (int*) malloc(MAX_50K * sizeof(int));
   
   // 100K Posições
   vo_100.tamanho = MAX_100K;
   vo_100.vetor = (int*) malloc(MAX_100K * sizeof(int));

   vd_100.tamanho = MAX_100K;
   vd_100.vetor = (int*) malloc(MAX_100K * sizeof(int));
   
   // 150K Posições
   vo_150.tamanho = MAX_150K;
   vo_150.vetor = (int*) malloc(MAX_150K * sizeof(int));

   vd_150.tamanho = MAX_150K;
   vd_150.vetor = (int*) malloc(MAX_150K * sizeof(int));

   // POPULANDO ARRAYS
   for(int i = 0; i < MAX_50K; i++) {
      int valor = (rand() << 15) | rand();
      vo_50.vetor[i] = valor;
      vd_50.vetor[i] = valor;
      abb_50.raiz = inserir_no_abb(abb_50.raiz, valor);
      avl_50.raiz = inserir_no_avl(avl_50.raiz, valor);
   }

   for(int i = 0; i < MAX_100K; i++) {
      int valor = (rand() << 15) | rand();

      vo_100.vetor[i] = valor;
      vd_100.vetor[i] = valor;
      abb_100.raiz = inserir_no_abb(abb_100.raiz, valor);
      avl_100.raiz = inserir_no_avl(avl_100.raiz, valor);
   }

   for(int i = 0; i < MAX_150K; i++) {
      int valor = (rand() << 15) | rand();

      vo_150.vetor[i] = valor;
      vd_150.vetor[i] = valor;
      abb_150.raiz = inserir_no_abb(abb_150.raiz, valor);
      avl_150.raiz = inserir_no_avl(avl_150.raiz, valor);
   }

   // Ordena os vetores vetor
   ordenar_vetor_vo(&vo_50);   
   ordenar_vetor_vo(&vo_100);
   ordenar_vetor_vo(&vo_150);

   // VARIÁVEIS DE COMPARAÇÃO
   int comparacoes_avl50 = 0;
   int comparacoes_abb50 = 0;
   int comparacoes_vo50 = 0;
   int comparacoes_vd50 = 0;

   int comparacoes_avl100 = 0;
   int comparacoes_abb100 = 0;
   int comparacoes_vo100 = 0;
   int comparacoes_vd100 = 0;

   int comparacoes_avl150 = 0;
   int comparacoes_abb150 = 0;
   int comparacoes_vo150 = 0;
   int comparacoes_vd150 = 0;

   for(int i = 0; i < BUSCA_MAX; i++) {
      int numero = (rand() << 15) | rand();

      // 50K
      retornar_numeros_ordenados(&vo_50, numero, &comparacoes_vo50);
      retornar_numeros_desordenados(&vd_50, numero, &comparacoes_vd50);
      retorna_no_abb(abb_50.raiz, numero, &comparacoes_abb50);
      retorna_no_avl(avl_50.raiz, numero, &comparacoes_avl50);
      
      // 100K
      retornar_numeros_ordenados(&vo_100, numero, &comparacoes_vo100);
      retornar_numeros_desordenados(&vd_100, numero, &comparacoes_vd100);
      retorna_no_abb(abb_100.raiz, numero, &comparacoes_abb100);
      retorna_no_avl(avl_100.raiz, numero, &comparacoes_avl100);

      // 150K
      retornar_numeros_ordenados(&vo_150, numero, &comparacoes_vo150);
      retornar_numeros_desordenados(&vd_150, numero, &comparacoes_vd150);
      retorna_no_abb(abb_150.raiz, numero, &comparacoes_abb150);
      retorna_no_avl(avl_150.raiz, numero, &comparacoes_avl150);
   }

   FILE *relatorio = fopen("relatorio_do_desempenho.txt", "w");

   if(relatorio != NULL) {
      fprintf(relatorio, "========================================\n");
      fprintf(relatorio, "     RELATORIO DE DESEMPENHO (BUSCAS)\n");
      fprintf(relatorio, "========================================\n\n");

      // LOTE 50K
      fprintf(relatorio, "--- LOTE 50K ---\n");
      fprintf(relatorio, "Vetor Ordenado (Busca Binaria): %d comparacoes\n", comparacoes_vo50);
      fprintf(relatorio, "Vetor Desordenado (Sequencial): %d comparacoes\n", comparacoes_vd50);
      fprintf(relatorio, "Arvore ABB: %d comparacoes\n", comparacoes_abb50);
      fprintf(relatorio, "Arvore AVL: %d comparacoes\n\n", comparacoes_avl50);

      // LOTE 100K
      fprintf(relatorio, "--- LOTE 100K ---\n");
      fprintf(relatorio, "Vetor Ordenado (Busca Binaria): %d comparacoes\n", comparacoes_vo100);
      fprintf(relatorio, "Vetor Desordenado (Sequencial): %d comparacoes\n", comparacoes_vd100);
      fprintf(relatorio, "Arvore ABB: %d comparacoes\n", comparacoes_abb100);
      fprintf(relatorio, "Arvore AVL: %d comparacoes\n\n", comparacoes_avl100);

      // LOTE 150K
      fprintf(relatorio, "--- LOTE 150K ---\n");
      fprintf(relatorio, "Vetor Ordenado (Busca Binaria): %d comparacoes\n", comparacoes_vo150);
      fprintf(relatorio, "Vetor Desordenado (Sequencial): %d comparacoes\n", comparacoes_vd150);
      fprintf(relatorio, "Arvore ABB: %d comparacoes\n", comparacoes_abb150);
      fprintf(relatorio, "Arvore AVL: %d comparacoes\n\n", comparacoes_avl150);

      // Fecha o arquivo para salvar os dados corretamente
      fclose(relatorio);
      printf("Relatorio gerado e salvo com sucesso em 'relatorio_do_desempenho.txt'!\n");
   } else
      printf("Erro ao criar o arquivo de relatorio.\n");

   free(vo_50.vetor);
   free(vd_50.vetor);
   free(vo_100.vetor);
   free(vd_100.vetor);
   free(vo_150.vetor);
   free(vd_150.vetor);

   return 0;
}