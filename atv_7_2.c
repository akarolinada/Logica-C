#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

main(){
	typedef struct {
		int conta;
		char nome[100];
		float saldo;
	} TBanco;
	
	TBanco banco[3];
	
	float menor=9999;
	int contaMenor, op, p, cont = 0,resp;
	
	//banco[0].conta=1;
do{		
	printf("\n---------MENU-------------");
	printf("\n1-Cadastrar\n2-Listar Contas\n3-Menor Saldo\n0-Sair\nEscolha uma opcao: ");
	scanf("%d",&op);
	
	
	  if(op==1){
	  	do{
	  		printf("\ncont no INICIO=%d",cont);
	  		if(cont==0){
	  			banco[cont].conta=1;	  			
			} else {
				banco[cont].conta = banco[cont].conta + 1;
			}
			printf("nome: ");
			fflush(stdin);
			gets(banco[cont].nome);
			printf("saldo: ");
			scanf("%f",&banco[cont].saldo);
			if(banco[cont].saldo < menor){
				menor = banco[cont].saldo;
				contaMenor = banco[cont].conta;
			}
			printf("Deseja cadastrar mais um? (1-Sim \ 2 - Não): ");
			scanf("%d",&resp);
			if(resp==1){
				cont=cont+1;
			}
			printf("\ncont no FINAL=%d",cont);
		  }while ((resp==1)&&(cont<3));
		  
       }
		
		if(op==2){
			for(p=0;p<cont;p++){
				printf("\nConta= %d \ Nome= %s \ Saldo=%.2f",banco[p].conta,banco[p].nome,banco[p].saldo);
			}
		}
		if(op==3){
			printf("conta=%d tem o menor saldo = %.2f",contaMenor,menor);
	    }
    }while(op!=0);
	  
  
	
	
}
