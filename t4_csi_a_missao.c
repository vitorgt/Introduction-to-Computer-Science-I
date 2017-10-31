#include<math.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct _image{//definicao de uma struct tambem com typedef
	int t, X, Y;//tipo, largura e altura
	unsigned char *data, maxVal, max, min;//vetor da imagem, maximo valor possivel da imagem, maximo e minimos encontrados na imagem
}Im;

void read2(Im *i, FILE *arq){//funcao para leitura em binario
	int j = 0;
	i->min = i->maxVal;//minimo recebe o valor maximo
	i->max = 0;//maximo recebe o velor minimo
	i->data = (unsigned char *)malloc(sizeof(unsigned char) * i->X * i->Y);//alocacao dinamica do vetor da imagem
	for(j = 0; j < ((i->X)*(i->Y)); j++){//j varia ate o fim da imagem
		fscanf(arq, "%hhu", &i->data[j]);//escanear do arquivo arq para o vetor data
		if(i->data[j] < i->min){//se o escaneado for menor que o minimo
			i->min = i->data[j];//minimo recebe o valo do escaneado
		}
		if(i->data[j] > i->max){//se o escaneado for maior que o minimo
			i->max = i->data[j];//maximo recebe o valo do escaneado
		}
	}
}

void read5(Im *i, FILE *arq){
	int j = 0;
	i->min = i->maxVal;//minimo recebe o valor maximo
	i->max = 0;//maximo recebe o velor minimo
	i->data = (unsigned char *)malloc(sizeof(unsigned char) * i->X * i->Y);//alocacao dinamica do vetor da imagem
	fread(i->data, sizeof(unsigned char), (i->X * i->Y), arq);//le para o vetor data a quantidade X*Y unsigned chars do arquivo arq
	for(j = 0; j < ((i->X)*(i->Y)); j++){//j varia ate o fim da imagem
		if(i->data[j] < i->min){//se o escaneado for menor que o minimo
			i->min = i->data[j];//minimo recebe o valo do escaneado
		}
		if(i->data[j] > i->max){//se o escaneado for maior que o minimo
			i->max = i->data[j];//maximo recebe o valo do escaneado
		}
	}
}

void Op1(Im *i){
	int j = 0;
	double c = i->maxVal / log1p(i->max);//formulas dadas, mas ao inves de 255 como descrito no pdf o certo seria o valor maximo possivel de cada imagem
	for(j = 0; j < ((i->X)*(i->Y)); j++){
		i->data[j] = c * log1p(i->data[j]);//formula dada, onde log1p(x) = log(1 + x)
	}
}

void Op2(Im *i){
	int j = 0;
	double d = (double)i->maxVal / (i->max - i->min);//formula dada
	for(j = 0; j < ((i->X)*(i->Y)); j++){
		i->data[j] = (i->data[j] - i->min) * d;//formula dada
	}
}

void Op3(Im *i, int place, int newcolor){//passa a imagem, onde a alteracao acontecera e a nova cor, neste trabalho fixa em 100
	if(i->data[place] != 255 && i->data[place] != newcolor){//se for diferente de 255 e diferente da cor passada
		i->data[place] = newcolor;//altera a cor
		Op3(i, place + 1, newcolor);//chama de novo a funcao uma casa para a direita
		Op3(i, place - 1, newcolor);//esquerda
		Op3(i, place + i->X, newcolor);//cima
		Op3(i, place - i->X, newcolor);//baixo
	}
}

void readImage(Im *i, char *name){//passa a struct e o nome do arquivo para le-lo
	FILE *arq = fopen(name, "rb");//abre o arquivo em arq
	fscanf(arq, "P%d\n", &i->t);//escaneia o numero apos o P
	char *buffer = (char *)malloc(sizeof(char)*100);//cria um buffer de tamanho maximo 100
	fgets(buffer, 100, arq);//escaneia o comentario para o buffer
	free(buffer);//libera o buffer
	fscanf(arq, "%d %d\n%hhu\n", &i->X, &i->Y, &i->maxVal);//escaneia X, Y e maxVal
	if(i->t == 2){//se o tipo for 2
		read2(i, arq);//chama a funcao de ler arquivo em binario
	}
	else if(i->t == 5){
		read5(i, arq);//chama a funcao de ler arquivo em ascii
	}
	fclose(arq);//fecha o arquivo
}

int main(){
	Im i;//cria uma imagem i
	int op = 0;
	char name[15];
	scanf("%d\n%s", &op, name);
	readImage(&i, name);//chama a funcao para ler a imagem
	printf("P2\n# CREATOR: Image Generator SCC-221 - ICC I\n%d %d\n%d\n", i.X, i.Y, i.maxVal);//imprime o cabecalho 
	switch(op){
		case 1:
			Op1(&i);
			break;
		case 2:
			Op2(&i);
			break;
		case 3:
			Op3(&i, ((((i.Y)/2)*i.X)+((i.X)/2)), 100);
			break;
		default:
			printf("Operacao invalida\n");
	}
	for(op = 0; op < (i.X * i.Y); op++){
		printf("%d\n", i.data[op]);//imprime a imagem alterada
	}
	free(i.data);//libera o vetor da imagem
	return 0;
}
