#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int Lutas = 0, VidaInicialD = 0, VidaInicialA = 0, VidaAtualD = 0, VidaAtualA = 0, DDA = 0, i = 0, Dano = 0, ClasseArmaduraD = 10, ClasseArmaduraA = 7, BatalhasGanhasA = 0, BatalhasGanhasD = 0;
	char L1[] = "Drizzt", L2[] = "Artemis";
	scanf("%d%d%d%d", &Lutas, &VidaInicialD, &VidaInicialA, &DDA);//entradas
	srand(DDA*DDA);//seed
	for(i = 1; i <= Lutas; i++){//contador das Lutas
		VidaAtualD = VidaInicialD;//define a vida do lutador como a inicial toda nova Luta
		VidaAtualA = VidaInicialA;
		printf("Luta %d\n", i);
		if((rand()%DDA) >= (rand()%DDA)){//Drizzt e Artemis jogam dado, if Drizzt maior ou igual joga, else Artemis joga
			while(VidaAtualD > 0 && VidaAtualA > 0){//while as duas vidas dessa Luta sao positivas
				if(((rand()%DDA)+1) > ClasseArmaduraA){//if resultado do dado extritamente maior do que a classe de armadura de Artemis = ataque de Drizzt em Artemis autorizado
					Dano = (rand()%9) + 1;//Rola um DA de 9 lados para saber o dano
					if(Dano == 9){//extra damage
						Dano = floor(Dano * 1.5);
					}
					if(Dano > 1){//Dano ok (not miss)
						VidaAtualA = VidaAtualA - Dano;
						printf("%s %d\n", L1, Dano);
					}
				}
				if(VidaAtualD > 0 && VidaAtualA > 0){
					if(((rand()%DDA)+1) > ClasseArmaduraD){//if resultado do dado extritamente maior do que a classe de armadura de Drizzt = ataque de Artemis em Drizzt autorizado
						Dano = ((rand()%7) + 1) + ((rand()%7) + 1);//Rola dois DAs de 7 lados para saber o dano
						if(Dano == 14){//extra damage
							Dano = floor(Dano * 1.5);
						}
						if(Dano > 2){//Dano ok (not miss)
							VidaAtualD = VidaAtualD - Dano;
							printf("%s %d\n", L2, Dano);
						}
					}
				}
			}
		}
		else{
			while(VidaAtualD > 0 && VidaAtualA > 0){//while as duas vidas dessa Luta sao positivas
				if(((rand()%DDA)+1) > ClasseArmaduraD){//if resultado do dado extritamente maior do que a classe de armadura de Drizzt = ataque de Artemis em Drizzt autorizado
					Dano = ((rand()%7) + 1) + ((rand()%7) + 1);//Rola dois DAs de 7 lados para saber o dano
					if(Dano == 14){//extra damage
						Dano = floor(Dano * 1.5);
					}
					if(Dano > 2){//Dano ok (not miss)
						VidaAtualD = VidaAtualD - Dano;
						printf("%s %d\n", L2, Dano);
					}
				}
				if(VidaAtualD > 0 && VidaAtualA > 0){
					if(((rand()%DDA)+1) > ClasseArmaduraA){//if resultado do dado extritamente maior do que a classe de armadura de Artemis = ataque de Drizzt em Artemis autorizado
						Dano = (rand()%9) + 1;//Rola um DA de 9 lados para saber o dano
						if(Dano == 9){//extra damage
							Dano = floor(Dano * 1.5);
						}
						if(Dano > 1){//Dano ok (not miss)
							VidaAtualA = VidaAtualA - Dano;
							printf("%s %d\n", L1, Dano);
						}
					}
				}
			}
		}
		if(VidaAtualD > VidaAtualA){//verifica se drizzt tem mais vida que artemis
			printf("Fim da luta. Vencedor: %s\n", L1);
			BatalhasGanhasD++;//adiciona uma luta ganha para drizzt
			if(BatalhasGanhasD == floor((Lutas/2) + 1)){//if drizzt ganhar a maioria das lutas, break, fim da batalha
				break;
			}
		}
		else{//verifica se artemis tem mais vida que drizzt
			printf("Fim da luta. Vencedor: %s\n", L2);
			BatalhasGanhasA++;//adiciona uma luta ganha para artemis
			if(BatalhasGanhasA == floor((Lutas/2) + 1)){//if artemis ganhar a maioria das lutas, break, fim da batalha
				break;
			}
		}
	}
	if(BatalhasGanhasD > BatalhasGanhasA){//veirfica quem tem o maior numero de batalhas ganhas
		printf("Fim da batalha. Vencedor: DRIZZT\n");
	}
	else{
		printf("Fim da batalha. Vencedor: ARTEMIS\n");
	}
	return 0;
}
