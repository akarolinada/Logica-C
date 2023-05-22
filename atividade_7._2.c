#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

void cadastro(float *notaCadastro, char nomeCadastro[100])
{
    printf("\n---------------CADASTRO----------------");
    printf("\nNome: ");
    fflush(stdin);
    gets(nomeCadastro);
    printf("\nNota: ");
    scanf("%f", notaCadastro);
    printf("%f", *notaCadastro);
}

float media(float notaMedia, int c)
{
    int i;
    float soma = 0;
    for (i = 0; i < c; i++)
    {
        soma = soma + notaMedia;
    }
    printf("A media dos candidatos e %.2f", soma / c);
}

void humilhacao(char nomeHumilhacao[100], float *notaHumilhacao, int c2)
{
    float maior = 0, menor = 9999, notaMa, notaMe;
    char nomeMa[100], nomeMe[100];
    int i2;
    for (i2 = 0; i2 < c2; i2++)
    {
        if (*notaHumilhacao > maior)
        {
            notaMa = *notaHumilhacao;
            strcpy(nomeMa, nomeHumilhacao);
        }
        if (*notaHumilhacao < menor)
        {
            notaMe = *notaHumilhacao;
            strcpy(nomeMe, nomeHumilhacao);
        }
    }
    printf("O candidato com maior nota e %s com a nota %.2f. Já o candidato com a menor nota e %s com a nota %.2f", nomeMa, notaMa, nomeMe, notaMe);
}

main()
{
    typedef struct
    {
        char nome[100];
        float nota;
    } TCandidatos;

    TCandidatos candidato[3];

    char menuPrincipal[500] = "--------------CANDIDATOS MENU--------------\n1 - CADASTRAR\n2 - EXIBIR MEDIA GERAL\n3 - EXIBIR CANDIDATO COM MAIOR E MENOR NOTA\n0 - FINALIZAR PROGRAMA\n\nESCOLHA O NUMERO DA SUA OPCAO:",
         escolha,
         novoCandidato[500] = "Deseja cadastrar um novo candidato? (1-Sim / 0 - Menu Principal)",
         voltar[500] = "Gostaria de voltar ao Menu Principal? (1 - Sim / 0 - Fechar Programa)",
         fecharVoluntario[500] = "O programa fechou!",
         opcaoInvalida = "Voce digitou uma opcao invalida!",
         fecharForcado[500] = "Voce digitou uma opcao invalida mais de uma vez! O programa fechou!";
    int contador = 0, indice = 0;

    printf("\n%s", menuPrincipal);
    scanf("%s", &escolha);

    switch (escolha)
    {
    case '1':
        do
        {
            cadastro(&candidato[contador].nota, candidato[contador].nome);
            contador++;

        } while (contador < 3);

        printf("\n -----------Candidatos------------");
        printf("\n| Nome         | Nota             |");
        for (indice = 0; indice < contador; indice++)
        {
            printf("\n %s         |  %f              ", candidato[indice].nome, candidato[indice].nota);
        }
        printf("\n%s", voltar);
        scanf("\n%s", &escolha);
        if (escolha == '1')
        {
            printf("\n%s", menuPrincipal);
            scanf("%s", &escolha);
        }
        else
        {
            exit(0);
        }
        break;
    case '2':
        media(candidato[contador].nota, contador);
        break;
    case '3':
        humilhacao(candidato[contador].nome, &candidato[contador].nota, contador);
        break;
    case '0':
        printf("%s", fecharVoluntario);
        exit(0);
    default:
        printf("%s", opcaoInvalida);
        printf("%s", menuPrincipal);
        scanf("%s", &escolha);
        if ((escolha != '1') && (escolha != '2') && (escolha != '0'))
        {
            printf("%s",fecharForcado);
            exit(0);
        }
        break;
    }
}
