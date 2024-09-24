#include <stdio.h>
#include <stdlib.h>

int *premiados(int n, int *inscr, float *t1, int p1, float *t2, int p2, int *tam) {
    float *medias = (float *)malloc(n * sizeof(float));  
    float maior_media = 1;  
    int i, count = 0;

    // Calcular a média ponderada de cada participante
    for (i = 0; i < n; i++) {
        medias[i] = (t1[i] * p1 + t2[i] * p2) / (p1 + p2);
        if (medias[i] > maior_media) {
            maior_media = medias[i];  // Atualiza a maior média
        }
    }

    // Contar quantos participantes têm a maior média EM CASO DE EMPATE
    for (i = 0; i < n; i++) {
        if (medias[i] == maior_media) {
            count++;
        }
    }

    // Criar um novo vetor para armazenar as inscrições dos premiados RELACIONANDO ID COM NOTA
    int *premiados = (int *)malloc(count * sizeof(int));
    *tam = count;  

    // Preencher o vetor com as inscrições dos participantes que obtiveram a maior média
    int j = 0;
    for (i = 0; i < n; i++) {
        if (medias[i] == maior_media) {
            premiados[j] = inscr[i];
            j++;
        }
    }

    // Liberar o vetor de médias
    free(medias);

    // Retornar o vetor de premiados
    return premiados;
}

int main() {
    int n, p1, p2, tam, *resultado;
    
    printf("Digite o numero de participantes: ");
    scanf("%d", &n);
    
    int *inscricoes = (int *)malloc(n * sizeof(int));
    float *notas_t1 = (float *)malloc(n * sizeof(float));
    float *notas_t2 = (float *)malloc(n * sizeof(float));
    
    // Entrada das inscrições e notas
    for (int i = 0; i < n; i++) {
        printf("\nDigite a inscricao do participante %d: ", i + 1);
        scanf("%d", &inscricoes[i]);
        
        printf("\nDigite a nota do participante %d no teste 1: ", i + 1);
        scanf("%f", &notas_t1[i]);
        
        printf("\nDigite a nota do participante %d no teste 2: ", i + 1);
        scanf("%f", &notas_t2[i]);
    }
    
    // Entrada dos pesos das notas
    printf("\nDigite o peso do teste 1: ");
    scanf("%d", &p1);
    
    printf("\nDigite o peso do teste 2: ");
    scanf("%d", &p2);
    
    // Chamar a função para calcular os premiados
    resultado = premiados(n, inscricoes, notas_t1, p1, notas_t2, p2, &tam);
    
    // Exibir o resultado
    printf("\nParticipantes premiados (inscricoes):\n");
    for (int i = 0; i < tam; i++) {
        printf("%d\n", resultado[i]);
    }
    
    // Liberar memória alocada
    free(inscricoes);
    free(notas_t1);
    free(notas_t2);
    free(resultado);
    
    return 0;
}
