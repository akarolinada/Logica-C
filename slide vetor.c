#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

main(){
	/*SLIDE 11
	
	float nota[10], soma, media;
	int i;
	
	for(i = 0; i < 10; i++){
		printf("Digite a nota: ");
		scanf("%f",&nota[i]);
		soma = soma + nota[i];
	}
	
	media = soma/(i+1);
	
	printf("A media aritimetica dos alunos é %f", media);
	
	SLIDE 13 ~ 1
	
	int num[100], i;
	
	for(i = 0; i < 100; i++){
		if(i%2 == 0){
			num[i] = 0;
		} else {
			num[i] = 1;
		}
		
		printf("%d,",num[i]);
	}
	
	SLIDE 13 ~ 2
	
	int num[10], i, soma;
	
	for(i=0;i<10;i++){
		printf("Digite um numero: ");
		scanf("%d",&num[i]);
		
		soma+=num[i];	
	}
	
	printf("%d",soma);
	
	SLIDE 13 ~ 3
	
	float V1[20], V2[20], V3[20];
	int i, j;
	
	for(i=0; i<20;i++){
		printf("Digite um numero para o V1: ");
		scanf("%f",&V1[i]);
		printf("Digite um numero para o V2: ");
		scanf("%f",&V2[i]);
		V3[i] = V1[i]*V2[i];
	}
	
	for(j=0;j<20;j++){
		printf("%f,",V3[j]);
	}
	
	SLIDE 14
	
	int V[5], i, maior=0,menor=999;
	
	for(i=0;i<5;i++){
		printf("Digite um numero: ");
		scanf("%d",&V[i]);
		if(V[i]>maior){
			maior = V[i];			
		}
		if(V[i]<menor){
			menor = V[i];
		}		
	}
	
	printf("O maior e %d e o menor é %d", maior, menor);
	
	EXERCICIO DE VETORES ~ 1
	
	int V[10], i, pares=0, impares=0;
	
	for(i=0;i<10;i++){
		printf("Digite um numero para V: ");
		scanf("%d",&V[i]);
		if(V[i]%2 == 0){
			pares++;
		}else{
			impares++;
		}
	}
	
	printf("Existem %d numeros pares e %d numeros impares",pares, impares);
	
	EXERCICIO DE VETORES ~ 2
	
	int V[10], i;
	
	for(i=0;i<10;i++){
		printf("\nDigite um numero para V: ");
		scanf("%d",&V[i]);	
	}
	
	for(i=0;i<10;i++){
		if(i%2 == 0){
			printf("%d,",V[i]);
		}
	}
	
	EXERCICIO DE VETORES ~ 3*/
	
	int i;
	float salario[5], somaSal=0, filhos[5], mediaSalario, mediaFilhos, maiorSal=0, menorSal=1000000, percentual, somaFil=0;
	
	for(i=0;i<5;i++){
		printf("Qual seu salario: ");
		scanf("%f",&salario[i]);
		printf("Quantos filhos voce tem: ");
		scanf("%f",&filhos[i]);
		
		somaSal+=salario[i];
		somaFil+=filhos[i];
		
		if(salario>maiorSal){
			maiorSal=salario;
		}
		
		if(salario<menorSal){
			menorSal=salario;
		}				
	}
	
	mediaSalario = somaSal/5;
	mediaFilhos = somaFil/5;
	
	printf("A media de salario da populacao e %.2f",mediaSalario);
	printf("\nA media de filhos da populacao e %.2f",mediaFilhos);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
