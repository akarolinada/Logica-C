#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

escolhaInicial(opc){
	char nome[100];
	int sexo, idade, turno, curso[], novoCurso;
	if(opc == 1){
		printf("NOME:");
		fflush(stdin);
		gets(nome);
		printf("IDADE: ");
		scanf("%d",&idade);
		printf("TURNO (SELECIONE O NUMERO: 1 - MANHA, 2 - NOITE): ");
		scanf("%d",&turno);
		printf("CURSO (SELECIONE O NUMERO: 1 - SEGURANCA DE INFORMACAO, 2 - JAVA, 3 - ARDUINO, 4 - LINUX): ");
		scanf("%d",&curso[]);
		printf("DESEJA CADASTRAR NOVO CURSO? (SELECIONE O NUMERO: 1 - SIM, 2 - NAO)");
		scanf("%d",&novoCurso);
		if (novoCurso == 1){
			printf("CURSO (SELECIONE O NUMERO: 1 - SEGURANCA DE INFORMACAO, 2 - JAVA, 3 - ARDUINO, 4 - LINUX): ");
	     	scanf("%d",&curso[]);
		}
	}
}

main(){
	int opcao;
	
	printf(" ------------------------------------------------------------------------------------------- ");
	printf("|                                     TI CURSOS                                             |");
	printf(" --------------------------------------------------------------------------------------------");
	printf("| ESCOLHA A OPCAO DESEJADA:                                                                 |");
	printf("|                                                                                           |");
	printf("| 1 - CADASTRAR ALUNO                                                                       |");
	printf("| 2 - EDITAR ALUNO                                                                          |");
	printf("| 3 - REMOVER ALUNO                                                                         |");
	printf("| 4 - LISTAGEM GERAL                                                                        |");
	printf("| 5 - LISTAGEM POR CURSO                                                                    |");
	printf("| 6 - LISTAGEM POR SEXO                                                                     |");
	printf("| 0 - SAIR                                                                                  |");
	printf("|                                                                                           |");
	printf(" ------------------------------------------------------------------------------------------- ");
	printf("\n");
	printf("\n");
	printf("DIGITE O NUMERO DA OPCAO E  LOGO APOS 'ENTER': ");
	scanf("%d",&opcao);
	

	
}
