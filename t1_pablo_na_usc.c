#include<stdio.h>

int main(){
	int k, n, h, m;
	h = 0;
	m = 0;
	scanf("%d%d", &k, &n);
	if(k < 0 || k > 3 || n > 1000000000 || n < 0){
		printf("Invalid input\n");
	}
	else{
		n >>= (8 * k);

		if(n & 1){m++;printf("1");}
		else{h++;printf("0");}
		n >>= 1;

		if(n & 1){m++;printf("1");}
		else{h++;printf("0");}
		n >>= 1;

		if(n & 1){m++;printf("1");}
		else{h++;printf("0");}
		n >>= 1;

		if(n & 1){m++;printf("1");}
		else{h++;printf("0");}
		n >>= 1;

		if(n & 1){m++;printf("1");}
		else{h++;printf("0");}
		n >>= 1;

		if(n & 1){m++;printf("1");}
		else{h++;printf("0");}
		n >>= 1;

		if(n & 1){m++;printf("1");}
		else{h++;printf("0");}
		n >>= 1;

		if(n & 1){m++;printf("1");}
		else{h++;printf("0");}
		n >>= 1;
		
		printf("\n%d\n%d\n", h, m);
	}
	return 0;
}
