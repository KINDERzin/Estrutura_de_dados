#define MAX_50K 50000
#define MAX_100K 100000
#define MAX_150K 150000

#define BUSCA_MAX 5000
#define PERCENTUAL_EXISTENTE 100

#define REP_RAPIDA 1000   // vetor ordenado, ABB e AVL
#define REP_LENTA 1       // vetor desordenado e ABB ordenada

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
   struct VetorOrdenado vo_50;
   struct VetorDesordenado vd_50;
   
   // Para 100K posições
   struct ArvoreAbb abb_100;
   struct ArvoreAvl avl_100;
   struct VetorOrdenado vo_100;
   struct VetorDesordenado vd_100;

   // Para 150K posições
   struct ArvoreAbb abb_150;
   struct ArvoreAvl avl_150;
   struct VetorOrdenado vo_150;
   struct VetorDesordenado vd_150;

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
   int comparacoes_abbord50 = 0;

   int comparacoes_avl100 = 0;
   int comparacoes_abb100 = 0;
   int comparacoes_vo100 = 0;
   int comparacoes_vd100 = 0;
   int comparacoes_abbord100 = 0;

   int comparacoes_avl150 = 0;
   int comparacoes_abb150 = 0;
   int comparacoes_vo150 = 0;
   int comparacoes_vd150 = 0;
   int comparacoes_abbord150 = 0;

   int chaves50[BUSCA_MAX], chaves100[BUSCA_MAX], chaves150[BUSCA_MAX];

   for(int i = 0; i < BUSCA_MAX; i++) {
      int numero = (rand() << 15) | rand();
      int n50 = numero, n100 = numero, n150 = numero;

      if(rand() % 100 < PERCENTUAL_EXISTENTE) {
         n50 = vo_50.vetor[((rand() << 15) | rand()) % MAX_50K];
         n100 = vo_100.vetor[((rand() << 15) | rand()) % MAX_100K];
         n150 = vo_150.vetor[((rand() << 15) | rand()) % MAX_150K];
      }

      chaves50[i] = n50;
      chaves100[i] = n100;
      chaves150[i] = n150;
   }

   for(int i = 0; i < BUSCA_MAX; i++) {
      // 50K
      retornar_numeros_ordenados(&vo_50, chaves50[i], &comparacoes_vo50);
      retornar_numeros_desordenados(&vd_50, chaves50[i], &comparacoes_vd50);
      retorna_no_abb(abb_50.raiz, chaves50[i], &comparacoes_abb50);
      retorna_no_avl(avl_50.raiz, chaves50[i], &comparacoes_avl50);

      // 100K
      retornar_numeros_ordenados(&vo_100, chaves100[i], &comparacoes_vo100);
      retornar_numeros_desordenados(&vd_100, chaves100[i], &comparacoes_vd100);
      retorna_no_abb(abb_100.raiz, chaves100[i], &comparacoes_abb100);
      retorna_no_avl(avl_100.raiz, chaves100[i], &comparacoes_avl100);

      // 150K
      retornar_numeros_ordenados(&vo_150, chaves150[i], &comparacoes_vo150);
      retornar_numeros_desordenados(&vd_150, chaves150[i], &comparacoes_vd150);
      retorna_no_abb(abb_150.raiz, chaves150[i], &comparacoes_abb150);
      retorna_no_avl(avl_150.raiz, chaves150[i], &comparacoes_avl150);
   }

   // TEMPO (só as buscas)
   clock_t inicio, fim;
   int c;

   double tempo_vd50,  tempo_vo50,  tempo_abb50,  tempo_avl50;
   double tempo_vd100, tempo_vo100, tempo_abb100, tempo_avl100;
   double tempo_vd150, tempo_vo150, tempo_abb150, tempo_avl150;

   inicio = clock();
   for(int r = 0; r < REP_LENTA; r++)
      for(int i = 0; i < BUSCA_MAX; i++) {
         c = 0;
         retornar_numeros_desordenados(&vd_50, chaves50[i], &c);
      }
   fim = clock();
   tempo_vd50 = 1000000.0 * (double)(fim - inicio) / CLOCKS_PER_SEC / ((double)REP_LENTA * BUSCA_MAX);

   inicio = clock();
   for(int r = 0; r < REP_RAPIDA; r++)
      for(int i = 0; i < BUSCA_MAX; i++) {
         c = 0;
         retornar_numeros_ordenados(&vo_50, chaves50[i], &c);
      }
   fim = clock();
   tempo_vo50 = 1000000.0 * (double)(fim - inicio) / CLOCKS_PER_SEC / ((double)REP_RAPIDA * BUSCA_MAX);

   inicio = clock();
   for(int r = 0; r < REP_RAPIDA; r++)
      for(int i = 0; i < BUSCA_MAX; i++) {
         c = 0;
         retorna_no_abb(abb_50.raiz, chaves50[i], &c);
      }
   fim = clock();
   tempo_abb50 = 1000000.0 * (double)(fim - inicio) / CLOCKS_PER_SEC / ((double)REP_RAPIDA * BUSCA_MAX);

   inicio = clock();
   for(int r = 0; r < REP_RAPIDA; r++)
      for(int i = 0; i < BUSCA_MAX; i++) {
         c = 0;
         retorna_no_avl(avl_50.raiz, chaves50[i], &c);
      }
   fim = clock();
   tempo_avl50 = 1000000.0 * (double)(fim - inicio) / CLOCKS_PER_SEC / ((double)REP_RAPIDA * BUSCA_MAX);

   inicio = clock();
   for(int r = 0; r < REP_LENTA; r++)
      for(int i = 0; i < BUSCA_MAX; i++) {
         c = 0;
         retornar_numeros_desordenados(&vd_100, chaves100[i], &c);
      }
   fim = clock();
   tempo_vd100 = 1000000.0 * (double)(fim - inicio) / CLOCKS_PER_SEC / ((double)REP_LENTA * BUSCA_MAX);

   inicio = clock();
   for(int r = 0; r < REP_RAPIDA; r++)
      for(int i = 0; i < BUSCA_MAX; i++) {
         c = 0;
         retornar_numeros_ordenados(&vo_100, chaves100[i], &c);
      }
   fim = clock();
   tempo_vo100 = 1000000.0 * (double)(fim - inicio) / CLOCKS_PER_SEC / ((double)REP_RAPIDA * BUSCA_MAX);

   inicio = clock();
   for(int r = 0; r < REP_RAPIDA; r++)
      for(int i = 0; i < BUSCA_MAX; i++) {
         c = 0;
         retorna_no_abb(abb_100.raiz, chaves100[i], &c);
      }
   fim = clock();
   tempo_abb100 = 1000000.0 * (double)(fim - inicio) / CLOCKS_PER_SEC / ((double)REP_RAPIDA * BUSCA_MAX);

   inicio = clock();
   for(int r = 0; r < REP_RAPIDA; r++)
      for(int i = 0; i < BUSCA_MAX; i++) {
         c = 0;
         retorna_no_avl(avl_100.raiz, chaves100[i], &c);
      }
   fim = clock();
   tempo_avl100 = 1000000.0 * (double)(fim - inicio) / CLOCKS_PER_SEC / ((double)REP_RAPIDA * BUSCA_MAX);

   inicio = clock();
   for(int r = 0; r < REP_LENTA; r++)
      for(int i = 0; i < BUSCA_MAX; i++) {
         c = 0;
         retornar_numeros_desordenados(&vd_150, chaves150[i], &c);
      }
   fim = clock();
   tempo_vd150 = 1000000.0 * (double)(fim - inicio) / CLOCKS_PER_SEC / ((double)REP_LENTA * BUSCA_MAX);

   inicio = clock();
   for(int r = 0; r < REP_RAPIDA; r++)
      for(int i = 0; i < BUSCA_MAX; i++) {
         c = 0;
         retornar_numeros_ordenados(&vo_150, chaves150[i], &c);
      }
   fim = clock();
   tempo_vo150 = 1000000.0 * (double)(fim - inicio) / CLOCKS_PER_SEC / ((double)REP_RAPIDA * BUSCA_MAX);

   inicio = clock();
   for(int r = 0; r < REP_RAPIDA; r++)
      for(int i = 0; i < BUSCA_MAX; i++) {
         c = 0;
         retorna_no_abb(abb_150.raiz, chaves150[i], &c);
      }
   fim = clock();
   tempo_abb150 = 1000000.0 * (double)(fim - inicio) / CLOCKS_PER_SEC / ((double)REP_RAPIDA * BUSCA_MAX);

   inicio = clock();
   for(int r = 0; r < REP_RAPIDA; r++)
      for(int i = 0; i < BUSCA_MAX; i++) {
         c = 0;
         retorna_no_avl(avl_150.raiz, chaves150[i], &c);
      }
   fim = clock();
   tempo_avl150 = 1000000.0 * (double)(fim - inicio) / CLOCKS_PER_SEC / ((double)REP_RAPIDA * BUSCA_MAX);

   FILE *relatorio = fopen("relatorio_do_desempenho.txt", "w");

   if(relatorio != NULL) {
      fprintf(relatorio, "========================================\n");
      fprintf(relatorio, "     RELATORIO DE DESEMPENHO (BUSCAS)\n");
      fprintf(relatorio, "========================================\n\n");

      // LOTE 50K
      fprintf(relatorio, "--- LOTE 50K ---\n");
      fprintf(relatorio, "Vetor Ordenado (Busca Binaria): %d comparacoes (media %.2f), %.3f us por busca\n", comparacoes_vo50, (double) comparacoes_vo50 / BUSCA_MAX, tempo_vo50);
      fprintf(relatorio, "Vetor Desordenado (Sequencial): %d comparacoes (media %.2f), %.3f us por busca\n", comparacoes_vd50, (double) comparacoes_vd50 / BUSCA_MAX, tempo_vd50);
      fprintf(relatorio, "Arvore ABB: %d comparacoes (media %.2f), %.3f us por busca\n", comparacoes_abb50, (double) comparacoes_abb50 / BUSCA_MAX, tempo_abb50);
      fprintf(relatorio, "Arvore AVL: %d comparacoes (media %.2f), %.3f us por busca\n", comparacoes_avl50, (double) comparacoes_avl50 / BUSCA_MAX, tempo_avl50);

      // LOTE 100K
      fprintf(relatorio, "--- LOTE 100K ---\n");
      fprintf(relatorio, "Vetor Ordenado (Busca Binaria): %d comparacoes (media %.2f), %.3f us por busca\n", comparacoes_vo100, (double) comparacoes_vo100 / BUSCA_MAX, tempo_vo100);
      fprintf(relatorio, "Vetor Desordenado (Sequencial): %d comparacoes (media %.2f), %.3f us por busca\n", comparacoes_vd100, (double) comparacoes_vd100 / BUSCA_MAX, tempo_vd100);
      fprintf(relatorio, "Arvore ABB: %d comparacoes (media %.2f), %.3f us por busca\n", comparacoes_abb100, (double) comparacoes_abb100 / BUSCA_MAX, tempo_abb100);
      fprintf(relatorio, "Arvore AVL: %d comparacoes (media %.2f), %.3f us por busca\n", comparacoes_avl100, (double) comparacoes_avl100 / BUSCA_MAX, tempo_avl100);

      // LOTE 150K
      fprintf(relatorio, "--- LOTE 150K ---\n");
      fprintf(relatorio, "Vetor Ordenado (Busca Binaria): %d comparacoes (media %.2f), %.3f us por busca\n", comparacoes_vo150, (double) comparacoes_vo150 / BUSCA_MAX, tempo_vo150);
      fprintf(relatorio, "Vetor Desordenado (Sequencial): %d comparacoes (media %.2f), %.3f us por busca\n", comparacoes_vd150, (double) comparacoes_vd150 / BUSCA_MAX, tempo_vd150);
      fprintf(relatorio, "Arvore ABB: %d comparacoes (media %.2f), %.3f us por busca\n", comparacoes_abb150, (double) comparacoes_abb150 / BUSCA_MAX, tempo_abb150);
      fprintf(relatorio, "Arvore AVL: %d comparacoes (media %.2f), %.3f us por busca\n", comparacoes_avl150, (double) comparacoes_avl150 / BUSCA_MAX, tempo_avl150);

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