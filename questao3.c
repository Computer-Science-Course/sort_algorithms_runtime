#include "sort.h"
#include "utils.h"

void main(){
	int vectors_length = 500000;

    printf("Creating first vector...\n");
    int *vector1 = (int *) malloc(vectors_length * sizeof(int));
    printf("Creating second vector...\n");
    int *vector2 = (int *) malloc(vectors_length * sizeof(int));
    printf("Creating third vector...\n");
    int *vector3 = (int *) malloc(vectors_length * sizeof(int));
    printf("Creating fourth vector...\n");
    int *vector4 = (int *) malloc(vectors_length * sizeof(int));
    
    /* Variáveis pra armazenar quando os algoritmos de ordenação começam
    e terminam
    */
    long start_time, end_time;

    /*Executa 3 vezes cada algoritmo de ordenção, cada vez com um vetor
    distinto
    */
    for(int vector_time = 1; vector_time <= 3; vector_time++){
        printf("\n --- VECTOR NUMBER: %d ----------------\n", vector_time);

        //Preenche todos os vetores com a mesma sequência de números aleatórios
        printf("Filling vector with random numbers...\n");
        fillRandomVector(vector1, vectors_length, 0, 100);

        printf("Filling vector with random numbers...\n");
        copyVector(vector1, vector2, vectors_length);
        
        printf("Filling vector with random numbers...\n");
        copyVector(vector1, vector3, vectors_length);
        
        printf("Filling vector with random numbers...\n");
        copyVector(vector1, vector4, vectors_length);

        /*Em ordem:
        1 - Marca o tempo inicial;
        2 - Ordena o vetor;
        3 - Marca o tempo final;
        4 - Exibe o tempo decorrido na ordenação.
        Procedimento recorrente para os 4 algoritmos.
        */
        printf("\n-- SELECTION SORT SECTION --\n");
        printf("Sorting vector...\n");
        start_time = time(NULL);
        selectionSort(vector1, vectors_length);
        end_time = time(NULL);
        printf("Time: %ld s.\n", (end_time-start_time));
    
        printf("\n-- INSERTION SORT SECTION --\n");
        printf("Sorting vector...\n");
        start_time = time(NULL);
        insertionSort(vector2,vectors_length);
        end_time = time(NULL);
        printf("Time: %ld s.\n", (end_time-start_time));

        printf("\n-- MERGE SORT SECTION --\n");
        printf("Sorting vector...\n");
        start_time = time(NULL);
        mergesort(vector3, 0, vectors_length - 1);
        end_time = time(NULL);
        printf("Time: %ld s.\n", (end_time-start_time));

        printf("\n-- QUICK SORT SECTION --\n");
        start_time = time(NULL);
        quicksort(vector4, 0, vectors_length - 1);
        end_time = time(NULL);
        printf("Time: %ld s.\n", (end_time-start_time));
    }
    printf("\n");
}