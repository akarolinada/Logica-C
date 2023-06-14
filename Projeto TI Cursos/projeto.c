#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// modelo do registro
typedef struct
{
    int matricula, idade, turno[2], curso[2], sexo, status;
    char nome[50];
    float mensalidade;
} TEstudante;

FILE *pestudante;

// declaracao das variaveis do registro
TEstudante estudante1;

// criacao ou abertura do arquivo
void abrirArquivo()
{
    pestudante = fopen("estudante.txt", "r+b");
    if (pestudante == NULL)
    {
        pestudante = fopen("estudante.txt", "w+b");
    }
}

// funcao de cadastro do estudante
void Cadastrar()
{
    abrirArquivo();
    int opcao2, opcao3, i = 0, j = 0, curso, proximaMatricula, repetido, tamanho;
    do
    {
        printf("\nCadastro do Estudante");
        printf("\nMatricula: ");
        // tratamento para que a matricula seja algo gerado e incrementado automaticamente a cada registro
        fseek(pestudante, -1 * sizeof(TEstudante), SEEK_END);
        fread(&estudante1, sizeof(TEstudante), 1, pestudante);
        proximaMatricula = estudante1.matricula + 1;
        estudante1.matricula = proximaMatricula;
        printf("%d", estudante1.matricula);

        printf("\n\nNome: ");
        fflush(stdin);
        gets(estudante1.nome);

        printf("\nSexo (1 - Masculino /2 - Feminino): ");
        scanf("%d", &estudante1.sexo);
        getchar(); // remove o caractere de nova linha do buffer no scanf
        // validar se o usuario vai digitar uma opcao das sugeridas
        while ((estudante1.sexo != 1) && (estudante1.sexo != 2))
        {
            printf("\nVoce digitou uma opcao invalida.\nSexo ( 1 - Masculino / 2 - Feminino ): ");
            scanf("%d", &estudante1.sexo);
            getchar();
        }

        printf("\nIdade: ");
        scanf("%d", &estudante1.idade);
        // validar se o usuario tem a idade correta para se matricular
        while (estudante1.idade < 14)
        {
            printf("\nA idade minima para se matricular e 14 anos.");
            printf("\nIdade: ");
            scanf("%d", &estudante1.idade);
        }

        do
        {
            int zerando;

            for (zerando = 0; zerando < 2; zerando++)
            {
                estudante1.curso[zerando] = 0;
                estudante1.turno[zerando] = 0;
            }

            for (i = 0; i < 2; i++)
            {

                printf("\n\nCursos (1 - Seguranca da Informacaoo / 2 - Java / 3 - Arduino / 4 - Linux ): ");
                scanf("%d", &curso);
                // validar se o curso selecionado e um dos validos
                while ((curso != 1) && (curso != 2) && (curso != 3) && (curso != 4))
                {
                    printf("\nVoce digitou uma opcao invalida!");
                    printf("\nCursos (1 - Seguranca da Informacao / 2 - Java / 3 - Arduino / 4 - Linux ): ");
                    scanf("%d", &curso);
                }
				
				
                printf("\nTurno (1 - manha / 2 - noite): ");
                scanf("%d", &estudante1.turno[i]);
                // validar se o turno selecionado e um dos validos
                while ((estudante1.turno[i] != 1) && (estudante1.turno[i] != 2))
                {
					
					printf("\nVoce digitou uma opcao invalida!");
                    printf("\nTurno (1 - manha / 2 - noite): ");
                    scanf("%d", &estudante1.turno[i]);
                }
                if(estudante1.turno[0] == estudante1.turno[1] ){
                	while(estudante1.turno[0] == estudante1.turno[1]){
                		printf("\nNao e possivel se matricular no mesmo turno.");
                		printf("\nTurno (1 - manha / 2 - noite): ");
                    	scanf("%d", &estudante1.turno[i]);
					}
					while ((estudante1.turno[1] != 1) && (estudante1.turno[i] != 2)){
							printf("\nVoce digitou uma opcao invalida!");
                    		printf("\nTurno (1 - manha / 2 - noite): ");
                    		scanf("%d", &estudante1.turno[i]);
					}
				}
            	

                // tratamento para nao permitir que um mesmo curso seja selecionado mais de uma vez
                for (j = 0; j < i; j++)
                {
                    if (estudante1.curso[j] == curso)
                    {
                        printf("Esse curso ja foi selecionado!");
                        repetido = 1;
                        --i;
                    }
                }

                if (repetido == 0 && i < 2)
                {
                    estudante1.curso[i] = curso;
                    if(i<2){
					
                    printf("\nGostaria de cadastrar outro curso? (1 - sim / 2 - nao): ");
                    scanf("%d", &opcao3);
                    }
                    while ((opcao3 != 1) && (opcao3 != 2))
                    {
                    	if(i < 2){
						
                        printf("\nVoce digitou uma opcao invalida.\nGostaria de cadastrar outro curso? (1- sim / 2 - nao): ");
                        scanf("%d", &opcao3);
                        getchar();
                        }
                    }
                }

                repetido = 0;

                // mensagem para quando o vetor de cursos estiver cheio
                if ((opcao3 == 1) && (i == 1))
                {
                    printf("Voce ja selecionou todos os cursos disponiveis. Nao e possivel se matricular duas vezes no mesmo curso.");
                    opcao3 = 2;
                }

                // quebra do laco de repeticao para quando a pessoa nao quiser mais adicionar cursos
                if (opcao3 != 1)
                {
                    break;
                }
            }

        } while (opcao3 == 1);

        // calculo da mensalidade de acordo com as regras do escopo
        estudante1.mensalidade = 0;

        for (i = 0; i < 2; i++)
        {
            if ((estudante1.curso[i] == 1) && (estudante1.turno[i] == 1))
            {
                estudante1.mensalidade += 360;
            }
            if ((estudante1.curso[i] == 1) && (estudante1.turno[i] == 2))
            {
                estudante1.mensalidade += 420;
            }
            if ((estudante1.curso[i] == 2) && (estudante1.turno[i] == 1))
            {
                estudante1.mensalidade += 320;
            }
            if ((estudante1.curso[i] == 2) && (estudante1.turno[i] == 2))
            {
                estudante1.mensalidade += 390;
            }
            if ((estudante1.curso[i] == 3) && (estudante1.turno[i] == 1))
            {
                estudante1.mensalidade += 290;
            }
            if ((estudante1.curso[i] == 3) && (estudante1.turno[i] == 2))
            {
                estudante1.mensalidade += 310;
            }
            if ((estudante1.curso[i] == 4) && (estudante1.turno[i] == 1))
            {
                estudante1.mensalidade += 340;
            }
            if ((estudante1.curso[i] == 4) && (estudante1.turno[i] == 2))
            {
                estudante1.mensalidade += 400;
            }
        }

        if (estudante1.curso[1] != 0)
        {
            estudante1.mensalidade -= (estudante1.mensalidade * 0.3);
        }
        else if (estudante1.idade > 45)
        {
            estudante1.mensalidade -= (estudante1.mensalidade * 0.15);
        }

        estudante1.status = 1; // o status inicialmente está ativo

        // alteracao no arquivo, adicionando o registo novo
        fseek(pestudante, 0, SEEK_END);
        fwrite(&estudante1, sizeof(TEstudante), 1, pestudante);
        printf("\n\nEstudante cadastrdo com sucesso!\n\n");
        printf("Gostaria de cadastrar outro estudante? (1- sim / 2 - nao): ");
        scanf("%d", &opcao2);

        while ((opcao2 != 1) && (opcao2 != 2))
        {
            printf("\nVoce digitou uma opcao invalida.\nGostaria de cadastrar outro estudante? (1- sim / 2 - nao): ");
            scanf("%d", &opcao2);
            getchar();
        }

    } while (opcao2 == 1);
    fclose(pestudante);
}

// funcao que procura de registo em registro aquele que possui a matricula desejada, e retorna quantos registros precisaram ser conferidos
int Pesquisa(int matricula)
{

    int contP;
    contP = 0;
    rewind(pestudante);
    fread(&estudante1, sizeof(TEstudante), 1, pestudante);
    while (feof(pestudante) == 0)
    {
        if (estudante1.matricula == matricula)
        {
            return contP;
        }
        else
        {
            fread(&estudante1, sizeof(TEstudante), 1, pestudante);
            contP++;
        }
    }

    return -1;
}

// funçao que exibe apenas o registro desejado pela pessoa
void Exibir(int pos)
{

    int k;

    fseek(pestudante, pos * sizeof(TEstudante), SEEK_SET);
    fread(&estudante1, sizeof(TEstudante), 1, pestudante);
    printf("\nMatricula | Nome | Sexo | Idade | Curso | Mensalidade");
    printf("\n%2d %5s", estudante1.matricula, estudante1.nome);
    if (estudante1.sexo == 1)
    {
        printf("        | Masculino |");
    }
    else if (estudante1.sexo == 2)
    {
        printf("        | Feminino |");
    }
    printf("    | %d |", estudante1.idade);
    for (k = 0; k < 2; k++)
    {
        if (estudante1.curso[k] == 1)
        {
            printf("  Sistema de Informacao /");
        }
        if (estudante1.curso[k] == 2)
        {
            printf("  Java /");
        }
        if (estudante1.curso[k] == 3)
        {
            printf(" Arduino /");
        }
        if (estudante1.curso[k] == 4)
        {
            printf("  Linux");
        }
    }
    printf("     | %.2f |", estudante1.mensalidade);
}

// funcao para alterar um registro
void Editar()
{
    int matEd, localReg, opcao9, opcao10, opcao11;
    abrirArquivo();

    do
    {
        // o usuario digita a matricura desejada
        printf("\nEditar Aluno");
        printf("\nMatricula do estudante que voce deseja editar:");
        scanf("%d", &matEd);
        localReg = Pesquisa(matEd); // chama a funcao pesquisa para encontrar o resgistro com essa matricula no arquivo
        if (localReg == -1)
        {
            printf("\nEstudante nao encontrado");
        }
        else
        {
            Exibir(localReg); // chama a funcao para mostrar apenas os dados desse registro
            do
            {
                // objetiva alterar o dado de apenas um atributo por vez a escolha do usuario, sem precisar mudar o registro todo
                printf("\n\n[1- Nome]\n[2- Sexo]\n[3- Idade]\n[4- Cursos e Turnos]\nO que voce gostaria de editar?");
                scanf("%d", &opcao10);
                while ((opcao10 != 1) && (opcao10 != 2) && (opcao10 != 3) && (opcao10 != 4))
                {
                    printf("\nOpcao invalida");
                    printf("\n\n[1- Nome]\n[2- Sexo]\n[3- Idade]\n[4- Cursos e Turnos]\nO que voce gostaria de editar?");
                    scanf("%d", &opcao10);
                }
                if (opcao10 == 1)
                {
                    printf("\nNovo nome: ");
                    fflush(stdin);
                    gets(estudante1.nome);
                    fseek(pestudante, localReg * sizeof(TEstudante), SEEK_SET);
                    fwrite(&estudante1, sizeof(TEstudante), 1, pestudante);
                    printf("\nNome alterado com sucesso!");
                    Exibir(localReg);
                }
                if (opcao10 == 2)
                {
                    printf("\nNovo Sexo[1- Masculino /2- Feminino]: ");
                    scanf("%d", &estudante1.sexo);
                    while ((estudante1.sexo != 1) && (estudante1.sexo != 2))
                    {
                        printf("\nOpcao Invalida");
                        printf("\nNovo Sexo[1- Masculino /2- Feminino]: ");
                        scanf("%d", &estudante1.sexo);
                    }
                    fseek(pestudante, localReg * sizeof(TEstudante), SEEK_SET);
                    fwrite(&estudante1, sizeof(TEstudante), 1, pestudante);
                    printf("\nSexo alterado com sucesso!");
                    Exibir(localReg);
                }
                if (opcao10 == 3)
                {
                    printf("\nNova Idade: ");
                    scanf("%d", &estudante1.idade);

                    printf("\n%f", estudante1.mensalidade);
                    printf("\n%d", estudante1.curso[4]);

                    if (estudante1.curso[1] != 0)
                    {
                        estudante1.mensalidade -= (estudante1.mensalidade * 0.3);
                    }
                    else if (estudante1.idade > 45)
                    {
                        estudante1.mensalidade -= (estudante1.mensalidade * 0.15);
                    }

                    printf("\n%f", estudante1.mensalidade);

                    fseek(pestudante, localReg * sizeof(TEstudante), SEEK_SET);
                    fwrite(&estudante1, sizeof(TEstudante), 1, pestudante);
                    printf("\nIdade alterada com sucesso!");
                    Exibir(localReg);
                }
                if (opcao10 == 4)
                {
                    int zerando2, m, novoCurso, w, rep = 0, opcao12;

                    do
                    {

                        for (zerando2 = 0; zerando2 < 2; zerando2++)
                        {
                            estudante1.curso[zerando2] = 0;
                            estudante1.turno[zerando2] = 0;
                        }

                        for (m = 0; m < 2; m++)
                        {
                            printf("\n\n Novos Cursos (1 - Seguranca da Informacaoo / 2 - Java / 3 - Arduino / 4 - Linux ): ");
                            scanf("%d", &novoCurso);
                            // validar se o curso selecionado e um dos validos
                            while ((novoCurso != 1) && (novoCurso != 2) && (novoCurso != 3) && (novoCurso != 4))
                            {
                                printf("\nVoce digitou uma opcao invalida!");
                                printf("\nCursos (1 - Seguranca da Informacao / 2 - Java / 3 - Arduino / 4 - Linux ): ");
                                scanf("%d", &novoCurso);
                            }

                            printf("\nTurno (1 - manha / 2 - noite): ");
                            scanf("%d", &estudante1.turno[m]);
                            // validar se o turno selecionado e um dos validos
                            while ((estudante1.turno[m] != 1) && (estudante1.turno[m] != 2))
                            {
                                printf("\nVoce digitou uma opcao invalida!");
                                printf("\nTurno (1 - manha / 2 - noite): ");
                                scanf("%d", &estudante1.turno[m]);
                            }
                        if(estudante1.turno[0] == estudante1.turno[1] ){
                		
							while(estudante1.turno[0] == estudante1.turno[1]){
                			printf("\nNao e possivel se matricular no mesmo turno.");
                			printf("\nTurno (1 - manha / 2 - noite): ");
                    		scanf("%d", &estudante1.turno[m]);
						}
						while ((estudante1.turno[m] != 1) && (estudante1.turno[m] != 2)){
							printf("\nVoce digitou uma opcao invalida!");
                    		printf("\nTurno (1 - manha / 2 - noite): ");
                    		scanf("%d", &estudante1.turno[m]);
					}
				}
	
                            // tratamento para nao permitir que um mesmo curso seja selecionado mais de uma vez
                            for (w = 0; w < m; w++)
                            {
                                if (estudante1.curso[w] == novoCurso)
                                {
                                    printf("Esse curso ja foi selecionado!");
                                    rep = 1;
                                    --m;
                                }
                            }

                            if (rep == 0 && m < 2)
                            {
                                estudante1.curso[m] = novoCurso;
                                if(m<2){
								
                                printf("\nGostaria de cadastrar outro curso? (1 - sim / 2 - nao): ");
                                scanf("%d", &opcao12);
                                }
                                while ((opcao12 != 1) && (opcao12 != 2))
                                {
                                    printf("\nVoce digitou uma opcao invalida.\nGostaria de cadastrar outro curso? (1- sim / 2 - nao): ");
                                    scanf("%d", &opcao12);
                                    getchar();
                                }
                                
                            }

                            rep = 0;

                            // mensagem para quando o vetor de cursos estiver cheio
                            if ((opcao12 == 1) && (m == 1))
                            {
                                printf("Voce ja selecionou todos os cursos disponiveis. Nao e possivel se matricular duas vezes no mesmo curso.");
                                opcao12 = 2;
                            }

                            // quebra do laco de repeticao para quando a pessoa nao quiser mais adicionar cursos
                            if (opcao12 != 1)
                            {
                                break;
                            }
                        }

                    } while (opcao12 == 1);

                    // calculo da mensalidade de acordo com os valores do escopo
                    estudante1.mensalidade = 0;

                    for (m = 0; m < 4; m++)
                    {
                        if ((estudante1.curso[m] == 1) && (estudante1.turno[m] == 1))
                        {
                            estudante1.mensalidade += 360;
                        }
                        if ((estudante1.curso[m] == 1) && (estudante1.turno[m] == 2))
                        {
                            estudante1.mensalidade += 420;
                        }
                        if ((estudante1.curso[m] == 2) && (estudante1.turno[m] == 1))
                        {
                            estudante1.mensalidade += 320;
                        }
                        if ((estudante1.curso[m] == 2) && (estudante1.turno[m] == 2))
                        {
                            estudante1.mensalidade += 390;
                        }
                        if ((estudante1.curso[m] == 3) && (estudante1.turno[m] == 1))
                        {
                            estudante1.mensalidade += 290;
                        }
                        if ((estudante1.curso[m] == 3) && (estudante1.turno[m] == 2))
                        {
                            estudante1.mensalidade += 310;
                        }
                        if ((estudante1.curso[m] == 4) && (estudante1.turno[m] == 1))
                        {
                            estudante1.mensalidade += 340;
                        }
                        if ((estudante1.curso[m] == 4) && (estudante1.turno[m] == 2))
                        {
                            estudante1.mensalidade += 400;
                        }
                    }

                    if (estudante1.curso[1] != 0)
                    {
                        estudante1.mensalidade -= (estudante1.mensalidade * 0.3);
                    }
                    else if (estudante1.idade > 45)
                    {
                        estudante1.mensalidade -= (estudante1.mensalidade * 0.15);
                    }

                    

                    fseek(pestudante, localReg * sizeof(TEstudante), SEEK_SET);
                    fwrite(&estudante1, sizeof(TEstudante), 1, pestudante);
                    printf("\nCursos e turnos alterados com sucesso!");
                    Exibir(localReg);
                }
                printf("\nGostaria de alterar outra informacao?[1- sim/2- nao]?");
                scanf("%d", &opcao11);
                while ((opcao11 != 1) && (opcao11 != 2))
                {
                    printf("\nOpcao Invalida");
                    printf("\nGostaria de alterar outra informacao?[1- sim/2- nao]?");
                    scanf("%d", &opcao11);
                }
            } while (opcao11 == 1);
        }
        printf("\n\nGostaria de Editar outro estudante[1- sim/2- nao]?");
        scanf("%d", &opcao9);
        while ((opcao9 != 1) && (opcao9 != 2))
        {
            printf("\nOpcao Invalida");
            printf("\n\nGostaria de Editar outro estudante[1- sim/2- nao]?");
            scanf("%d", &opcao9);
        }
    } while (opcao9 == 1);
    fclose(pestudante);
}
void Excluir()
{
    abrirArquivo();
    int matdel, conf, resp, op, opcao13;

    do
    {
        printf("\n\nDeseja Excluir um estudante?\n\n\n");
        printf("Digite a Matricula: ");
        scanf("%d", &matdel);
        op = Pesquisa(matdel);
        if (op == -1)
        {
            printf("\nEstudante nao encontrado !!");
        }
        else
        {
            Exibir(op);
            printf("\n\nDeseja excluir o estudante (1-Sim /2 -Nao)?");
            scanf("%d", &conf);
            while ((conf != 1) && (conf != 2))
            {
                printf("Voce digitou uma opcao errada.");
                printf("\n\nDeseja excluir o estudante (1-Sim /2 -Nao)?");
                scanf("%d", &conf);
            }
        }
        if (conf == 1)
        {
            estudante1.status = 0; // o status que ao cadastrar era 1, se torna 0. Isso vai servir na listagem, para apenas exibir os que tem 1 nesse atributo. Isso é a deleção lógica, onde excluimos apenas visualmente, mas manteremos os dados para possivel necessidade de uso futuro
            fseek(pestudante, op * sizeof(TEstudante), SEEK_SET);
            fwrite(&estudante1, sizeof(TEstudante), 1, pestudante);
            printf("Estudante excluido com sucesso.");
        }
        else
        {
            printf("Exclusao cancelada.");
        }

        printf("Gostaria de excluir outro estudante? [1- sim / 2- nao]");
        scanf("%d", &opcao13);
        while ((opcao13 != 1) && (opcao13 != 2))
        {
            printf("Voce digitou uma opcao invalida");
            printf("Gostaria de excluir outro estudante? [1- sim / 2- nao]");
            scanf("%d", &opcao13);
        }
    } while (opcao13 == 1);
    fclose(pestudante);
}

// lista os estudantes de acordo com o curso selecionado, mostrando apenas aqules que estão matriculados naquele curso
void ListarPorCurso()
{
    abrirArquivo();
    int opcao6, cs, opcao7;
    do
    {
        printf("\nListagem por Curso");
        printf("\nQual curso voce gostaria de pesquisar? [1 - Sistema de Informacao / 2 - Java / 3 - Arduino / 4 - Linux]");
        scanf("%d", &opcao6);

        while ((opcao6 != 1) && (opcao6 != 2) && (opcao6 != 3) && (opcao6 != 4))
        {
            printf("\nVoce digitou uma opcao invalida");
            printf("\nQual curso voce gostaria de pesquisar[1 - Sistema de Informacao / 2 - Java / 3 - Arduino / 4 - Linux]: ");
            scanf("%d", &opcao6);
        }



        printf("Matricula |       Nome       |     Sexo     |   Idade   |        Cursos           |   Mensalidade  ");


        if (opcao6 == 1)
        {
            rewind(pestudante);
            while (fread(&estudante1, sizeof(TEstudante), 1, pestudante) != 0)
            {
                for (cs = 0; cs < 4; cs++)
                {
                    if (estudante1.curso[cs] == 1)
                    {
                        if (estudante1.status != 0)
                        {
                            printf("\n| %2d |   |  %5s  |", estudante1.matricula, estudante1.nome);

                            if (estudante1.sexo == 1)
                            {
                                printf("        | Masculino |");
                            }
                            if (estudante1.sexo == 2)
                            {
                                printf("        | Feminino |");

                            }
                            printf("    | %d |", estudante1.idade);
                            printf("  Sistema de Informacao /");
                            printf("     | %.2f |", estudante1.mensalidade);
                        }
                    }
                }
            }
        }

        if (opcao6 == 2)
        {
            rewind(pestudante);
            while (fread(&estudante1, sizeof(TEstudante), 1, pestudante) != 0)
            {
                for (cs = 0; cs < 4; cs++)
                {
                    if (estudante1.curso[cs] == 2)
                    {
                        if (estudante1.status != 0)
                        {
                            printf("\n| %2d |   |  %5s  |", estudante1.matricula, estudante1.nome);

                            if (estudante1.sexo == 1)
                            {
                                printf("        | Masculino |");
                            }
                            if (estudante1.sexo == 2)
                            {
                                printf("        | Feminino |");
                            }
                            printf("    | %d |", estudante1.idade);
                            printf("  Java /");
                            printf("     | %.2f |", estudante1.mensalidade);
                        }
                    }
                }
            }
        }
        if (opcao6 == 3)
        {
            rewind(pestudante);
            while (fread(&estudante1, sizeof(TEstudante), 1, pestudante) != 0)
            {
                for (cs = 0; cs < 4; cs++)
                {
                    if (estudante1.curso[cs] == 3)
                    {
                        if (estudante1.status != 0)
                        {
                            printf("\n| %2d |   |  %5s  |", estudante1.matricula, estudante1.nome);

                            if (estudante1.sexo == 1)
                            {
                                printf("        | Masculino |");
                            }
                            if (estudante1.sexo == 2)
                            {
                                printf("        | Feminino |");
                            }
                            printf("    | %d |", estudante1.idade);
                            printf(" Arduino /");
                            printf("     | %.2f |", estudante1.mensalidade);
                        }
                    }
                }
            }
        }

        if (opcao6 == 4)
        {
            rewind(pestudante);
            while (fread(&estudante1, sizeof(TEstudante), 1, pestudante) != 0)
            {
                for (cs = 0; cs < 4; cs++)
                {
                    if (estudante1.curso[cs] == 4)
                    {
                        if (estudante1.status != 0)
                        {
                            printf("\n| %2d |   |  %5s  |", estudante1.matricula, estudante1.nome);

                            if (estudante1.sexo == 1)
                            {
                                printf("        | Masculino |");
                            }
                            if (estudante1.sexo == 2)
                            {
                                printf("        | Feminino |");
                            }
                            printf("    | %d |", estudante1.idade);
                            printf("  Linux");
                            printf("     | %.2f |", estudante1.mensalidade);

                        }
                    }
                }
            }
        }

        printf("\n\nGostaria de pesquisar outro curso?[1- sim / 2- nao]: ");
        scanf("%d", &opcao7);
        while ((opcao7 != 1) && (opcao7 != 2))
        {
            printf("\nVoce digitou uma opcao invalida ");
            printf("\n\nGostaria de pesquisar outro curso?[1- sim / 2- nao]: ");
            scanf("%d", &opcao7);
        }

    } while (opcao7 == 1);
    fclose(pestudante);
}

// lista os estudantes de acordo com o sexo selecionado, mostrando apenas aqules que estão matriculados naquele sexo
void ListarPorSexo()
{
    abrirArquivo();

    int opcao4, sx, opcao5;
    do
    {
        printf("Listagem por Sexo\n");
        printf("Qual sexo voce gostaria de pesquisar[1- Masculino / 2- Feminino]: ");
        scanf("%d", &opcao4);

        while ((opcao4 != 1) && (opcao4 != 2))
        {
            printf("Voce digitou uma opcao invalida");
            printf("Qual sexo voce gostaria de pesquisar[1- Masculino / 2- Feminino]: ");
            scanf("%d", &opcao4);
        }

        printf("Matricula |       Nome       |     Sexo     |   Idade   |        Cursos           |   Mensalidade  ");
        if (opcao4 == 1)
        {
            rewind(pestudante);
            while (fread(&estudante1, sizeof(TEstudante), 1, pestudante) != 0)
            {
                if (estudante1.sexo == 1)
                {
                    if (estudante1.status != 0)
                    {
                        printf("\n| %2d |   |  %5s  |", estudante1.matricula, estudante1.nome);
                        if (estudante1.sexo == 1)
                        {
                            printf("        | Masculino |");
                        }
                        printf("    | %d |", estudante1.idade);

                        for (sx = 0; sx < 3; sx++)
                        {
                            if (estudante1.curso[sx] == 1)
                            {
                                printf("  Sistema de Informacao /");
                            }
                            if (estudante1.curso[sx] == 2)
                            {
                                printf("  Java /");
                            }
                            if (estudante1.curso[sx] == 3)
                            {
                                printf(" Arduino /");
                            }
                            if (estudante1.curso[sx] == 4)
                            {
                                printf("  Linux");
                            }
                        }
                        printf("     | %.2f |", estudante1.mensalidade);
                    }
                }
            }
        }
        if (opcao4 == 2)
        {
            rewind(pestudante);
            while (fread(&estudante1, sizeof(TEstudante), 1, pestudante) != 0)
            {
                if (estudante1.sexo == 2)
                {
                    if (estudante1.status != 0)
                    {
                        printf("\n| %2d |   |  %5s  |", estudante1.matricula, estudante1.nome);
                        if (estudante1.sexo == 2)
                        {
                            printf("        | Feminino |");
                        }
                        printf("    | %d |", estudante1.idade);
                        for (sx = 0; sx < 4; sx++)
                        {
                            if (estudante1.curso[sx] == 1)
                            {
                                printf("  Sistema de Informacao /");
                            }
                            if (estudante1.curso[sx] == 2)
                            {
                                printf("  Java /");
                            }
                            if (estudante1.curso[sx] == 3)
                            {
                                printf(" Arduino /");
                            }
                            if (estudante1.curso[sx] == 4)
                            {
                                printf("  Linux");
                            }
                        }
                        printf("     | %.2f |", estudante1.mensalidade);
                    }
                }
            }
        }

        printf("\n\nGostaria de pesquisar outro sexo?[1- sim / 2- nao]: ");
        scanf("%d", &opcao5);
        while ((opcao5 != 1) && (opcao5 != 2))
        {
            printf("\nVoce digitou uma opcao invalida ");
            printf("\n\nGostaria de pesquisar outro sexo?[1- sim / 2- nao]: ");
            scanf("%d", &opcao5);
        }

    } while (opcao5 == 1);
    fclose(pestudante);
}

// mostra a listagem geral de todos os registros do arquivo
void ListaGeral()
{
    abrirArquivo();
    int a;

    printf("Listagem Geral\n\n");
    printf("Matricula |       Nome       |     Sexo     |   Idade   |        Cursos           |   Mensalidade  ");
    rewind(pestudante);
    while (fread(&estudante1, sizeof(TEstudante), 1, pestudante) != 0)
    {
        if (estudante1.status != 0)
        {
            printf("\n| %2d |   |  %5s  |", estudante1.matricula, estudante1.nome);
            if (estudante1.sexo == 1)
            {
                printf("        | Masculino |");
            }
            else if (estudante1.sexo == 2)
            {
                printf("        | Feminino |");
            }
            printf("    | %d |", estudante1.idade);
            for (a = 0; a < 4; a++)
            {
                if (estudante1.curso[a] == 1)
                {
                    printf("  Sistema de Informacao /");
                }
                if (estudante1.curso[a] == 2)
                {
                    printf("  Java /");
                }
                if (estudante1.curso[a] == 3)
                {
                    printf(" Arduino /");
                }
                if (estudante1.curso[a] == 4)
                {
                    printf("  Linux");
                }
            }
            printf("     | %.2f |", estudante1.mensalidade);
        }
    }
    fclose(pestudante);
    printf("\ntecle enter para voltar ao menu...");
    getche();
}

// função principal, onde tudo é executado
main()
{
    int opcao;

    do
    {
        // menu principal
        fseek(pestudante, sizeof(estudante1), SEEK_SET);
        printf("\n\nTI Cursos\n\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Editar Aluno\n");
        printf("3 - Remover Aluno\n");
        printf("4 - Listagem Geral\n");
        printf("5 - Listagem por curso\n");
        printf("6 - Listagem por sexo\n");
        printf("0 - Sair\n\n");

        // define a opção de escolha do menu principal do usuario
        printf("Selecione uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            Cadastrar();
            break;
        case 2:
            Editar();
            break;
        case 3:
            Excluir();
            break;
        case 4:
            ListaGeral();
            break;
        case 5:
            ListarPorCurso();
            break;
        case 6:
            ListarPorSexo();
            break;
        case 0:
            printf("O sistema fechou!");
            exit(0); // fecha o programa
        default:
            printf("\n\nOpcao Invalida!\n");
        }
    } while (opcao != 0);
    
}

