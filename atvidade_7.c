#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

main()
{
	typedef struct
	{
		char nome[50];
		float nota;
	} TCandidatos;

	TCandidatos candidato[3];
	int c = 0, i = 0, soma = 0;
	float media, notaMaior = 0, notaMenor = 9999;
	char escolha, nomeMaior[50], nomeMenor[50],
		menuPrincipal[500] = "--------------CANDIDATOS MENU--------------\n\n\n1 - CADASTRAR\n2 - EXIBIR MEDIA GERAL\n3 - EXIBIR CANDIDATO COM MAIOR E MENOR NOTA\n0 - FINALIZAR PROGRAMA\n\nESCOLHA O NUMERO DA SUA OPCAO:",
		novoCandidato[500] = "GOSTARIA DE CADASTRAR OUTRO CANDIDATO? (1 - SIM / 2 - NAO): ",
		voltar[500] = "GOSTARIA DE VOLTAR AO MENU PRINCIPAL? (1 - SIM / 2 - FECHAR PROGRAMA): ",
		opcaoInvalida[500] = "VOCE NAO ESCOLHEU UMA OPCAO VALIDA!",
		exitForcado[500] = "VOCE DIGITOU DUAS VEZES ERRADO. O PROGRAMA ENCERROU!";

	printf("%s", menuPrincipal);

	scanf("%s", &escolha);

	switch (escolha)
	{
	case '1':
		do
		{
			if (c < 3)
			{
				printf("NOME: ");
				fflush(stdin);
				gets(candidato[c].nome);
				printf("NOTA: ");
				scanf("%f", &candidato[c].nota);
				printf("%s", &novoCandidato);
				c++;
				scanf("%s", &escolha);
				
				if (escolha == '1')
				{
					// escolha = 0;
					//c++;
				}
				else if (escolha == '2')
				{
					// escolha = 0;
					printf("%s", menuPrincipal);
					scanf("%s", &escolha);
				}
				else
				{
					// escolha = 0;
					printf("%s", opcaoInvalida);
					printf("\n%s", novoCandidato);
					scanf("%s", &escolha);
					if ((escolha != '1') || (escolha != '2'))
					{
						printf("%s", exitForcado);
						exit(0);
					}
				}
			}
			if (c == 3)
			{
				printf("NAO E POSSIVEL CADASTRAR MAIS CANDIDATOS.");
				printf("\n%s", voltar);
				scanf("%s", &escolha);
				if (escolha == '1')
				{
					printf("%s", &menuPrincipal);
					scanf("%s", &escolha);
				}
				else
				{
					exit(0);
				}
			}

		} while (c <= 3);

		break;
	case '2':
		for (i = 0; i < c; i++)
		{
			soma = soma + candidato[i].nota;
		}
		media = soma / (i + 1);
		printf("A media da nota dos candidatos e %f", media);
		printf("%s", voltar);
		scanf("%s", &escolha);
		if (escolha == '1')
		{
			printf("%s", menuPrincipal);
			scanf("%s", &escolha);
		}
		else if (escolha == '2')
		{
			exit(0);
		}
		else
		{
			printf("%s", opcaoInvalida);
			printf("%s", voltar);
			scanf("%s", &escolha);
		}
		break;
	case '3':
		for (c = 0; c < 3; c++)
		{
			if (candidato[c].nota > notaMaior)
			{
				notaMaior = candidato[c].nota;
				strcpy(nomeMaior, candidato[c].nome);
			}

			if (candidato[c].nota < notaMenor)
			{
				notaMenor = candidato[c].nota;
				strcpy(nomeMenor, candidato[c].nome);
			}
		}
		break;
	case '0':
		exit(0);
	default:
		printf("%s", opcaoInvalida);
		scanf("%s", &escolha);
		if ((escolha != 1) || (escolha != 2) || (escolha != 3) || (escolha != 0))
		{
			printf("%s", exitForcado);
			exit(0);
		}
	}
}
