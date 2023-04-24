#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

float media(float n1 , float n2, float n3){	
	return (n1+n2+n3)/3;
}

int resto(int n1, int n2){
	return n1%n2;	
}

int menor(int n1, int n2, int n3){
	int V[] = {n1,n2,n3}, i, menor = 9999;
	
	for(i = 0; i < 3; i++){
		if(V[i] < menor){
			menor = V[i];
		}
	}
	
	return menor;
}

int idade(ano){
	return 2023 - ano;
}

int fimDoAno(mes){
	return 12 - mes;
}

main(){
	/*QUESTAO 1
	
	int M[2][2], l, c, soma = 0,cont = 0;
	float media;
	
	for(l = 0; l < 2; l++){
		for(c = 0; c < 2; c++){
			printf("Digite um numero: ");
			scanf("%d",&M[l][c]);
		}
	}
	
	for(l = 0; l < 2; l++){
		for(c = 0; c < 2; c++){
			if(M[l][c]%2 == 0){
				soma+=M[l][c];
				cont++;
			}
			printf("%d",M[l][c]);
		}
		printf("\n");
	}
	
	media = soma/cont;
	
	printf("%f", media);
	
	/* QUESTAO 2
	
	int M[2][2], l, c, maior = 0, menor= 9999, x, y;
	
	for(l = 0; l < 2; l++){
		for(c = 0; c < 2; c++){
			printf("Digite um numero: ");
			scanf("%d",&M[l][c]);
		}
	}
	
	for(l = 0; l <2; l++){
		for(c =0; c < 2; c++){
			if(M[l][c] > maior){
				maior = M[l][c];
			}
			
			if(M[l][c] < menor){
				menor = M[l][c];
				x = l;
				y = c;				
			}			
		
		}
	}
	
	printf("O menor numero e %d e ele esta na posicao M[%d][%d]",menor,x,y);
	
	QUESTAO 3
	
	float nota1, nota2, nota3;
	
	printf("Digite uma nota: ");
	scanf("%f %f %f",&nota1,&nota2,&nota3);
	
	printf("%.2f",media(nota1,nota2,nota3));
	
	QUESTAO 4
	
	int num1,num2, resto1;
	
	printf("Digite dois numero: ");
	scanf("%d %d", &num1,&num2);
	
	printf("%d",resto(num1,num2));
	
	QUESTAO 5
	
	int num1,num2,num3;
	
	printf("Digite tres numeros: ");
	scanf("%d %d %d", &num1,&num2,&num3);
	
	printf("%d",menor(num1,num2,num3));
	
	QUESTAO 6
	
	int anoNasc;
	
	printf("Digite seu ano de nascimento: ");
	scanf("%d",&anoNasc);
	
	printf("%d",idade(anoNasc));
	
	QUESTAO 7*/
	
	int mesAtual;
	
	printf("Digite o numero do mes atual: ");
	scanf("%d",&mesAtual);
	
	printf("Faltam %d meses para o ano acabar.", fimDoAno(mesAtual));
	
	
	
	
	
	
	
	
	
	
	
}
