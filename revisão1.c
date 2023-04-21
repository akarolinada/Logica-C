#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

main(){
	/*QUESTAO 1
	
	int num1, num2;
	
	for(num1=1;num1<=10; num1++){
	    printf("\nA tábuada de %d\n", num1);
		for(num2=1; num2<=10; num2++){
			printf("\n%d x %d = %d\n", num1, num2, num1*num2);
		}
	}
	
	QUESTÃO 2

	char nome[50];
	float horas, salBruto, desc, salLiq,inss,ir;
	int dep, numFunc=1;
	
	while(numFunc<=20){
		printf("\n\nFuncionario %d Digite seu nome: ",numFunc);
		fflush(stdin);
		gets(nome);
		printf("\nDigite a quantidade de horas trabalhadas: ");
		scanf("%f",&horas);
		printf("\nDigite a quantidade de dependentes: ");
		scanf("%d",&dep);
		
		printf("\nNome do funcionario %d: %s",numFunc,nome);
		salBruto = (horas*10)+(dep*40);
		printf("\nO salario bruto do funcionario %d: %f",numFunc,salBruto);
		inss = 0.08;
		ir = 0.05;
		desc = (salBruto*inss)+(salBruto*ir);
		printf("\nO total de descontos sobre o salario bruto e: %f",desc);
		salLiq = salBruto - desc;
		printf("\nO salário líquido e: %f",salLiq);		
		numFunc++;
	} 
	
	QUESTÃO 3
	
	int codBoi, codBoiGordo;
	float pesoBoi, pesoBoiGordo=0;
	
	do{
		printf("Digite o codigo do boi: ");
	    scanf("%d",&codBoi);
	    if(codBoi!=0){
	       printf("Digite o peso do boi: ");
	       scanf("%f",&pesoBoi);
	       if(pesoBoi>pesoBoiGordo){
	    	  pesoBoiGordo=pesoBoi;
	    	  codBoiGordo=codBoi;
		    }
	    }
	}while(codBoi!=0);
	
	printf("O codigo do boi mais gordo e: %d e o peso dele é: %f", codBoiGordo, pesoBoiGordo);
	
	QUESTAO 4
	
	char nome[50];
	float salario, salarioReajustado;
	
	printf("Digite seu nome, funcionario: ");
	fflush(stdin);
	gets(nome);
	printf("Digite seu salario, funcionrio: ");
	scanf("%f",&salario);
	
	salarioReajustado = salario+(salario*0.12);
	
	printf("O salario do funcionario %s reajustado em 12 por cento e: %f",nome,salarioReajustado);
	
	QUESTAO 5
	
	float nota1, nota2, mediaPonderada;
	
	printf("Digite a nota 1: ");
	scanf("%f",&nota1);
	printf("Digite a nota 2: ");
	scanf("%f",&nota2);
	
	mediaPonderada=((nota1*6)+(nota2*4))/(6+4);
	
	printf("A media ponderada da %f e %f e: %f",nota1,nota2,mediaPonderada);
	
	QUESTAO 6
	
	float valorDolar;
	
	printf("Digite o valor en dolar: ");
	scanf("%f",&valorDolar);
	
	printf("O valor em reais e %f", valorDolar*1.7);
	
	QUESTAO 7
	
	float km, valorGasolina, lGasto, valorGasto;
	
	printf("Digite a distancia em km: ");
	scanf("%f",&km);
	printf("Digite o preco da gasolina por litro: ");
	scanf("%f",&valorGasolina);
	
	lGasto = km/12;
	valorGasto = lGasto*valorGasolina;
	
	printf("Foram gastos %.2f litros de gasolina no percurso, o que custou %.2f",lGasto, valorGasto);
	
	QUESTAO 8
	
	int n1,n2,x;
	
	printf("Digite o valor de n1: ");
	scanf("%d",&n1);
	printf("Digite o valor de n2: ");
	scanf("%d",&n2);
	
	printf("O valor de n1 e %d e de n2 e %d",n1,n2);
	
	x=n1;
	n1=n2;
	n2=x;
	
	printf("\nO valor de n1 e %d e de n2 e %d",n1,n2);
	
	QUESTAO 9
	
	int num;
	
	printf("Digite um valor: ");
	scanf("%d",&num);
	
	if(num%2 == 0){
		printf("%d e par",num);
	}else{
		printf("%d e impar",num);
	}
	
	QUESTAO 10
	
	float nota1,nota2,nota3,media;
	
	printf("Digite 3 notas:\n");
	scanf("%f%f%f",&nota1,&nota2,&nota3);
		
	media=(nota1+nota2+nota3)/3;
	
	if(media<4){
		printf("Sua nota foi %f e voce esta REPROVADO",media);
	} else if(media>=4 && media<7){
		printf("Sua nota foi %f e voce esta na PROVA FINAL",media);
	}else{
		printf("Sua nota foi %f e voce esta APROVADO",media);
	}
	
	QUESTAO 11
	
	int idade;
	
	printf("Digite sua idade: ");
	scanf("%d",&idade);
	
	if(idade>=5&&idade<=7){
		printf("Sua categoria e JUNIOR");
	}else if(idade>=8&&idade<=12){
		printf("Sua categoria e INFANTIL");
	}else if(idade>=13&&idade<=18){
		printf("Sua categoria e PRE");
	}else if(idade>18){
		printf("Sua categoria e AVANCADA");
	}else{
		printf("Sua categoria e indefinida ainda");
	}
	
	QUESTAO 12
	
	int num1,num2;
	char sinal;
	char soma = '+';
	char subtracao = '-';
	char multiplicacao1 = '*';
	char multiplicacao2 = 'x';
	char divisao = '/';
	
	printf("Digite o numero 1: ");
	scanf("%d",&num1);
	printf("Digite o sinal da operacao: ");
	scanf("%s",&sinal);
	printf("Digite o numero0 2: ");
	scanf("%d",&num2);
	
	if(sinal == soma){
		printf("%d + %d = %d",num1,num2,num1+num2);
	}else if(sinal == subtracao){
		printf("%d - %d = %d",num1,num2,num1-num2);
	}else if(sinal == multiplicacao1 || sinal == multiplicacao2){
		printf("%d x %d = %d",num1,num2,num1*num2);
	}else if(sinal == divisao){
		if(num2!=0){
			printf("%d / %d = %d",num1,num2,num1/num2);
		}else{
			printf("Não existe numero divisivel por 0");
		}
    }else{
    	printf("Voce nao digitou um operador valido");
	}
	
	QUESTAO 13
	
	int num1, num2, num3;
	
	printf("Digite tres numeros: ");
	scanf("%d%d%d",&num1,&num2,&num3);
	
	if((num1<num2)&&(num2<num3)){
		printf("%d%d%d",num1,num2,num3);
	}else if((num1<num3)&&(num3<num2)){
		printf("%d%d%d",num1,num3,num2);
	}else if((num2<num1)&&(num1<num3)){
		printf("%d%d%d",num2,num1,num3);
	}else if((num2<num3)&&(num3<num1)){
		printf("%d%d%d",num2,num3,num1);
	}else if((num3<num1)&&(num1<num2)){
		printf("%d%d%d",num3,num1,num2);
	}else if((num3<num2)&&(num2<num1)){
		printf("%d%d%d",num3,num2,num1);
	}else if((num1==num2)&&(num2<num3)){
		printf("%d%d%d",num1,num2,num3);
	}else if((num3<num1)&&(num1==num2)){
		printf("%d%d%d",num3,num1,num2);
	}else if((num1==num3)&&(num3<num2)){
		printf("%d%d%d",num1,num3,num2);
	}else if((num2<num1)&&(num1==num3)){
		printf("%d%d%d",num2,num1,num3);
	}else if((num2==num3)&&(num3<num1)){
		printf("%d%d%d",num2,num3,num1);
	}else if((num1<num2)&&(num2==num3)){
		printf("%d%d%d",num1,num2,num3);
	}else if((num1==num2)&&(num2==num3)){
		printf("%d%d%d",num1,num2,num3);
	}
	
	QUESTAO 14
	
	int num;
	
	printf("Digite um numero entre 20 e 39: ");
	scanf("%d",&num);
	
	if(num == 20){
		printf("vinte");
	}else if(num == 21){
		printf("vinte e um");
	}else if(num == 22){
		printf("vinte e dois");
	}else if(num == 23){
		printf("vinte e tres");	
    }else if(num == 24){
    	printf("vinte e quatro");
	}else if(num == 25){
		printf("vinte e cinco");
	}else if(num == 26){
		printf("vinte e seis");
	}else if(num == 27){
		printf("vinte e sete");
	}else if(num == 28){
		printf("vinte e oito");
	}else if(num == 29){
		printf("vinte e nove");
	}else if(num == 30){
		printf("trinta");
	}else if(num == 31){
		printf("trinta e um");
	}else if(num == 32){
		printf("trinta e dois");
	}else if(num == 33){
		printf("trinta e tres");
	}else if(num == 34){
		printf("trinta e quatro");
	}else if(num == 35){
		printf("trinta e cinco");
	}else if(num == 36){
		printf("trinta e seis");
	}else if(num == 37){
		printf("trinta e sete");
	}else if(num == 38){
		printf("trinta e oito");
	}else if(num == 39){
		printf("trinta e nove");
	}else{
		printf("voce digitou um numero fora do limite");
	}
	
	QUESTAO 15 (com erro)
	
	int idade, idadeVelha=0, idadeNova=999;
	char nome[50];
	char nomeVelha[50];
	char nomeNova[50];
	
	do{
		printf("Digite seu nome: ");
		fflush(stdin);
		gets(nome);
		printf("Digite sua idade: ");
		scanf("%d",&idade);
		
		if(idade > idadeVelha){
			idadeVelha = idade;
			strcpy(nomeVelha, nome);
		}
		
		if((idade < idadeNova) && (idade != 0)){
			idadeNova = idade;
			strcpy(nomeNova, nome);
		}
		
    } while (idade != 0);
    
    printf("O nome da pessoa mais nova e %s e o nome da pessoa mais velha e %s", nomeNova, nomeVelha);
    
	QUESTAO 16
	
	int soma, cont;	
	
	for(cont=1;cont<=50;cont++){
		if(cont%2 == 0){
			soma = soma+cont;
		}
	}
	
	printf("A soma dos numeros inteiros e pares entre 1 e 50 e %d",soma);
	
	QUESTAO 17
	
	char nome[50], acesso, sim ='s', sim2='S', genero, genero1 ='m',genero2='M',genero3='f',genero4='F', nomeHVelho[50],nomeMNova[50];
	int idade, clientes, somaIdade=0, contAcesso=0, contMulheres=0, idadeHVelho=0, idadeMNova=0;
	float mediaIdade;
		
	for(clientes=1;clientes<=4;clientes++){
		printf("Qual seu nome: ");
		fflush(stdin);
		gets(nome);
		printf("Digite a sua idade: ");
		scanf("%d",&idade);
		printf("Voce tem acesso a internet? Responda apenas com S ou N: ");
		scanf("%s",&acesso);
		
		if((acesso == sim)||(acesso == sim2)){
			contAcesso++;
			printf("%d",contAcesso);
		}
				
		printf("Qual seu genero: ");
		scanf("%s",&genero);
		
		if((genero == genero3)||(genero == genero4)){
			contMulheres++;
		}
		
		somaIdade = somaIdade+idade;
		printf("%d",somaIdade);	
			
		if((genero == genero1) && (genero == genero2) && (idade>idadeHVelho) && (acesso == sim) && (acesso == sim2)){
			idadeHVelho = idade;
			strcpy(nomeHVelho,nome);
		}
		
		if((genero == genero3) && (genero == genero4) && (idade<idadeMNova)){
			idadeMNova = idade;
			strcpy(nomeMNova,nome);
		}	
    }
	
	mediaIdade = somaIdade/4;
	printf("\nA media da idade dos clientes e %.3f", mediaIdade);
	printf("\nA quantidade de mulheres e: %d",contMulheres);
	printf("\n%d clientes tem acesso a internet",contAcesso);
	printf("\nO nome do homem mais velho e %s e ele tem %d anos", nomeHVelho, idadeHVelho);
	printf("\nO nome da mulher mais nova e %s e ela tem %d anos", nomeMNova, idadeMNova);*/
	
	
	
	
	
 
	
	
		
	
}
