#include <stdio.h>
#include <stdlib.h>

void printArray(
	int vector[],
	int vector_length
){
	/*Imprime sequancialmente os valores do vetor vector separado por um espaço
	em uma única linha com uma quebra de linha no final.
	*/

	for(int i = 0; i < vector_length; i++){
		printf("%d ", vector[i]);
	}
	printf("\n");
}

int randInt(
	int a,
	int b
){
	/*Retorna um número aleatório contido no intervalo [a, b].
	*/

	int number;
    int floor, roof;

	if(a > b){
		floor = b;
		roof = a;
	}else if(b > a){
		floor = a;
		roof = b;
	}else{
		return 0;
	}

    // srand(time(NULL));

    return ((rand() % (roof-floor+1)) + floor);
}

void fillRandomVector(
	int vector[],
	int vector_length,
	int start,
	int end
){
	/*Preenche um vetor de tamanho n com n números pseudo-aleatórios
	de start até end.
	*/

	for(int i = 0; i < vector_length; i++){
		vector[i] = randInt(start, end);
	}
}

void copyVector(
	int root[],
	int destiny[],
	int vectors_length
){
	/*Copia de maneira sequencial os valores do vetor root para o
	vetor destiny.
	*/

	for(int i = 0; i < vectors_length; i++){
		destiny[i] = root[i];
	}
}