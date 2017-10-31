#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = 0, r = 0, i = 0, j = 0, k = 0;
	char c;
	scanf("%c", &c);
	if(c == 'A'){
		scanf("%d %d", &r, &n);
		for(i = 0; i < r; i++){
			for(j = 0; j < n; j++){
				for(k = 0; k < j; k++){
					printf("X ");
				}
				printf("O");
				for(k = j + 1; k < n; k++){
					printf(" X");
				}
				printf("\n");
			}
			for(k = 0; k < n; k++){
				if(k == (n - 1))
					printf("X");
				else
					printf("X ");
			}
			printf("\n\n");
		}
	}
	else if(c == 'B'){
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			for(j = i; j < n; j++){
				for(k = 0; k < j; k++){
					printf("X ");
				}
				printf("O");
				for(k = j + 1; k < n; k++){
					printf(" X");
				}
				printf("\n");
			}
			for(k = 0; k < n; k++){
				if(k == (n - 1))
					printf("X");
				else
					printf("X ");
			}
			printf("\n\n");
		}
	}
	return 0;
}
