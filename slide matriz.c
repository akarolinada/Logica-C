#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

main(){
	
	/*
	QUESTAO 1
	
	int M1[3][5], M2[3][5], M3[3][5], l, c;
	
	for(l = 0; l < 3; l++){
		for(c = 0; c < 5; c++){
			printf("Digite um numero para matriz 1:");
			scanf("%d",&M1[l][c]);
			printf("Digite um numero para matriz 2:");
			scanf("%d",&M2[l][c]);
			
			M3[l][c]=M1[l][c]+M2[l][c];
		}
	}
	
	for(l = 0;l<3;l++){
		for(c = 0;c<5;c++){
			printf("%d",M3[l][c]);			
		}
		printf("\n");
	}
	
	QUESTAO 2
	
	int M[3][3],l,c;
	
	for( l = 0; l < 3; l++){
		for(c = 0; c < 3; c++){
			printf("Digite um numero:");
			scanf("%d",&M[l][c]);
			
			M[l][c]=M[l][c]*5;
		}
	}
	
	for(l = 0; l < 3; l++){
		for(c = 0; c < 3; c++){
			printf("%d",M[l][c]);
		}
		printf("\n");
	}
	
	QUESTAO 3*/
	
	int M[5][5],l,c;
	
	for(l = 0; l < 5; l++){
		for(c = 0; c < 5; c++){
			printf("Digite um numero:");
			scanf("%d",&M[l][c]);
		}
	}
	
	for(l = 0;l < 5; l++){
		for(c = 0; c < 5; c++){
			if(l == c){
				printf("Os valores da diagonal primaria sao %d\n",M[l][c]);
			}			
		}
	}
	
	for(l = 0;l < 5; l++){
		for(c = 0; c < 5; c++){
			if(l + c == 4){
				printf("Os valores da diagonal secundaria sao %d\n",M[l][c]);
			}			
		}
	}
	
	int soma =0;
	
	for(l = 0; l < 5; l++){
		for(c = 0; c < 5; c++){
			if(l == 4){
				soma+=M[l][c];
			}
		}
	}
	
	printf("%d",soma);
	
	for(l = 0; l < 5; l++){
		for(c = 0; c < 5; c++){
			if(c == 2){
				soma+=M[l][c];
			}
		}
	}
	
	printf("%d",soma);
	
	
	

	
}
