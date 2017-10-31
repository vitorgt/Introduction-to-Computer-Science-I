#include<stdio.h>
#include<stdlib.h>

void allocM(int ***m, int l, int c){
	int i = 0;
	*m = (int **)malloc(sizeof(int *) * l);
	for(; i < l; i++)
		*(*m + i) = (int *)malloc(sizeof(int) * c);
}

void clearM(int **m, int l, int c){
	int i = 0, j = 0;
	for(; i < l; i++)
		for(j = 0; j < c; j++)
			m[i][j] = 0;
}

void printM(int **m, int l, int c){
	int i = 0, j = 0;
	for(; i < l; i++){
		for(j = 0; j < c; j++)
			printf("%d\t", m[i][j]);
		printf("\n");
	}
}

void freeM(int ***m, int l){
	int i = 0;
	for(; i < l; i++)
		free(*(*m + i));
	free(*m);
}
