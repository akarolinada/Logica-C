#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main(){

//questão 1

//int idade;
//int anoDeNascimento;
//
//printf("Digite o ano do seu nascimento: ");
//scanf("%d",&anoDeNascimento);
//idade = 2023 - anoDeNascimento;
//printf("A sua idade é: %d",idade);

//questão 2

//int num;
//int ant;
//int sus;
//
//printf("Digite um numero: ");
//scanf("%d",&num);
//ant = num-1;
//sus = num+1;
//printf("O antecessor do numero que voce digitou e %d e o sucessor e %d",ant,sus);

//questão 3

//int num2;
//int cubo;
//printf("Digite um numero: ");
//scanf("%d",&num2);
//cubo = pow(num2,3);
//printf("O cubo do seu numero e %d",cubo);

//questão 4

//float salario;
//float porcentagem;
//float reajuste;
//
//printf("Digite o salario: ");
//scanf("%f",&salario);
//printf("Digite a porcentagem do reajuste: ");
//scanf("%f",&porcentagem);
//porcentagem = porcentagem/100;
//reajuste = salario + (salario*porcentagem);
//printf("O salario reajustado e %f", reajuste);

//questão 5

//int votosBrancos;
//int votosNulos;
//int votosValidos;
//int votosTotais;
//float poB;
//float poN;
//float poV;
//
//printf("Digite a quantidade de votos brancos: ");
//scanf("%d",&votosBrancos);
//printf("Digite a quantidade de votos nulos: ");
//scanf("%d",&votosNulos);
//printf("Digite a quantidade de votos validos: ");
//scanf("%d",&votosValidos);
//votosTotais = votosBrancos + votosNulos + votosValidos;
//poB = (votosBrancos*100)/votosTotais;
//poN = (votosNulos*100)/votosTotais;
//poV = (votosValidos*100)/votosTotais;
//printf("A porcentagem de votos brancos e %2f, a de votos nulos e %2f e a de votos validos e %2f, em relação ao total de %d eleitores",poB,poN,poV,votosTotais);

//questão 6

//int prestacoesTotais;
//int prestacoesPagas;
//int prestacoesDevidas;
//float valorPrestacao;
//float saldoDevedor;
//
//printf("Digite o total de prestacoes: ");
//scanf("%d",&prestacoesTotais);
//printf("Digite o total de prestacoes pagas: ");
//scanf("%d",&prestacoesPagas);
//printf("Digite o valor de cada prestacao: ");
//scanf("%f",&valorPrestacao);
//prestacoesDevidas = prestacoesTotais - prestacoesPagas;
//saldoDevedor = prestacoesDevidas*valorPrestacao;
//printf("O saldo devedor do cosorcio e de %f e faltam %d prestacoes a ser pagas",saldoDevedor,prestacoesDevidas);

//questão 7

float precoCombustivel;
float kmInicio;
float kmFinal;
float litrosGastos;
float valorTotalRecebido;
float mediaConsumo;
float lucroLiquido;

printf("Digite o preco do combustivel: ");
scanf("%f",&precoCombustivel);
printf("Digite a marcacao de km no inicio do dia: ");
scanf("%f",&kmInicio);
printf("Digite a marcacao de km no final do dia: ");
scanf("%f",&kmFinal);
printf("Digite quantos litros foram gastos no dia: ");
scanf("%f",&litrosGastos);
printf("Digite o valor total recebido dos passageiros: ");
scanf("%f",&valorTotalRecebido);
mediaConsumo = (kmFinal - kmInicio)/litrosGastos;
lucroLiquido = valorTotalRecebido - (precoCombustivel*litrosGastos);
printf("A media de comsumo e de %f e o lucro liquido e de %f",mediaConsumo,lucroLiquido);

}




