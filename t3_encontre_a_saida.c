#include <stdio.h>

void readmatrix(int array[][7]){
	int i = 0, j = 0;
	for(i = 0; i < 7; ++i){//percorre as linahs da matriz
		for(j = 0; j < 7; ++j){//percorre as colunas da matriz
			scanf("%d", &array[i][j]);//escaneia a matriz
		}
	}
}

int main(){
	int maze[7][7], i = 0, j = 0, intera = 0, entr = 0;//declaracao
	readmatrix(maze);//chama a funcao de leitura de matriz para a matriz maze
	scanf("%d", &entr);//escaneia a entrada do labirinto
	for(intera = 0; intera < 24/*floor((7*7)/2)*/; ++intera){//interacoes para fechar becos sem saidas posicao por posicao
		for(i = 0; i < 7; ++i){//percorre as linhas da matriz
			for(j = 0; j < 7; ++j){//percorre as colunas da matriz
				if(!maze[i][j]){//se a posicao atual for 0 (caminho)
					if(i != 0 && i != 6 && j != 0 && j != 6){//tratamento do centro
						if(maze[i][j-1]+maze[i][j+1]+maze[i-1][j]+maze[i+1][j] == 3){// se esquerda, direita, cima e baixo somarem 3 (beco sem saida)
							maze[i][j] = 1;//fecha essa posicao
						}
						else if(maze[i][j-1]+maze[i][j+1]+maze[i-1][j]+maze[i+1][j] == 4){// se esquerda, direita, cima e baixo somarem 4 ("ilha")
							maze[i][j] = 1;//fecha essa posicao
						}
					}
				}
			}
		}
	}
	i = entr/7;//definindo a linha da matriz como a linha da entrada dada
	j = entr - (i*7);//definindo a coluna da matriz como a coluna da entrada dada
	while(1){
		if(!maze[i][j-1]){//se o proximo 0 (caminho) estiver a esquerda
			maze[i][j] = 1;//fecha essa posicao para evitar loops
			printf("%d ", (i*7)+j);//mostra a posicao atual
			j = j - 1;//vai para a esquerda
			if(i == 0 || i == 6 || j == 0 || j == 6)//se chegar em uma borda break
				break;
		}
		else if(!maze[i][j+1]){//se o proximo 0 (caminho) estiver a direita
			maze[i][j] = 1;//fecha essa posicao para evitar loops
			printf("%d ", (i*7)+j);//mostra a posicao atual
			j = j + 1;//vai para a direita
			if(i == 0 || i == 6 || j == 0 || j == 6)//se chegar em uma borda break
				break;
		}
		else if(!maze[i-1][j]){//se o proximo 0 (caminho) estiver abaixo
			maze[i][j] = 1;//fecha essa posicao para evitar loops
			printf("%d ", (i*7)+j);//mostra a posicao atual
			i = i - 1;//vai para baixo
			if(i == 0 || i == 6 || j == 0 || j == 6)//se chegar em uma borda break
				break;
		}
		else if(!maze[i+1][j]){//se o proximo 0 (caminho) estiver acima
			maze[i][j] = 1;//fecha essa posicao para evitar loops
			printf("%d ", (i*7)+j);//mostra a posicao atual
			i = i + 1;//vai para cima
			if(i == 0 || i == 6 || j == 0 || j == 6)//se chegar em uma borda break
				break;
		}
	}
	printf("%d\n", (i*7)+j);//mostra a ultima posicao (borda) encontrada e o \n
	return 0;
}
