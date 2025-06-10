#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "pessoa.h"
#include "curso.h"
#include "cursoDisciplina.h"
#include "pessoaDisciplina.h"
#include "disciplina.h"
#include "funcoesauxiliares.h"

struct PESSOA_DISCIPLINA *topoPessoaDisciplina = NULL;
struct PESSOA_DISCIPLINA *auxPessoaDisciplina = NULL;
struct PESSOA_DISCIPLINA *fimPessoaDisciplina = NULL;

int ultimoCodigoPessoaDisciplina = 0;

void MenuPessoaDisciplina()
{
	int escolhaMenu;
	
	system("cls");
	printf("1 - Criar relacao pessoa-disciplina OK\n");
	printf("2 - listar relacoes pessoa-disciplina OK\n");
	printf("3 - Encontrar relacao pessoa-disciplina NOK\n");
	printf("4 - Voltar \n");
	
	scanf("%d", &escolhaMenu);
	limparBuffer();
	
	switch(escolhaMenu)
	{
		case 1:
			CadastrarPessoaDisciplina();
			break;
		case 2:
			ListarPessoaDisciplinas();
			getchar();
			break;
		case 4:
			return;
			break;
	}
}

void CadastrarPessoaDisciplina()
{		
	if(topoCursoDisciplina == NULL || topoPessoa == NULL)
	{
		printf("Nao ha dados suficientes para essa acao. Por favor cadastre mais pessoas e disciplinas");
		getchar();
		return;
	}
	
	ultimoCodigoPessoaDisciplina++;
	
	auxPessoaDisciplina = (struct PESSOA_DISCIPLINA*) malloc(sizeof(struct PESSOA_DISCIPLINA));
	auxPessoaDisciplina->cod_pessoa_disciplina = ultimoCodigoPessoaDisciplina;
	
	if(topoPessoaDisciplina == NULL)
	{
		topoPessoaDisciplina = auxPessoaDisciplina;
	}
	else
	{
		fimPessoaDisciplina->proximo = auxPessoaDisciplina;
	}
	auxPessoaDisciplina->proximo = NULL;
	fimPessoaDisciplina = auxPessoaDisciplina; 
	
	printf("Escolha uma pessoa: \n");
	ListarTodasPessoas();
	scanf("%d", &auxPessoaDisciplina->cod_pessoa);
	limparBuffer();
	printf("Escolha uma disciplina: \n");
	ListarCursoDisciplinas();
	scanf("%d", &auxPessoaDisciplina->cod_curso_disciplina);
	limparBuffer();
	
	printf("Relacao criada!");
	getchar();
}

void ListarPessoaDisciplinas()
{
    auxPessoaDisciplina = topoPessoaDisciplina;

    char nome_curso[50];
    char nome_pessoa[50];
    char nome_disciplina[50];

    if (topoPessoaDisciplina == NULL)
    {
        printf("Nao ha nenhuma relacao cadastrada\n");
        getchar();
        return;
    }

    while (auxPessoaDisciplina != NULL)
    {
        auxCursoDisciplina = topoCursoDisciplina;
        auxPessoa = topoPessoa;

        strcpy(nome_curso, "Curso nao encontrado");
        strcpy(nome_pessoa, "Pessoa nao encontrada");
        strcpy(nome_disciplina, "Disciplina nao encontrada");

        while (auxPessoa != NULL)
        {
            if (auxPessoa->cod_pessoa == auxPessoaDisciplina->cod_pessoa)
            {
                strcpy(nome_pessoa, auxPessoa->nome_pessoa);
                break;
            }
            auxPessoa = auxPessoa->proximo;
        }

        while (auxCursoDisciplina != NULL)
        {
            if (auxCursoDisciplina->cod_curso_disciplina == auxPessoaDisciplina->cod_curso_disciplina)
            {
                auxCurso = topoCurso;
                while (auxCurso != NULL)
                {
                    if (auxCurso->cod_curso == auxCursoDisciplina->cod_curso)
                    {
                        strcpy(nome_curso, auxCurso->nome_curso);
                        break;
                    }
                    auxCurso = auxCurso->proximo;
                }

                auxDisciplina = topoDisciplina;
                while (auxDisciplina != NULL)
                {
                    if (auxDisciplina->cod_disciplina == auxCursoDisciplina->cod_disciplina)
                    {
                        strcpy(nome_disciplina, auxDisciplina->nome_disciplina);
                        break;
                    }
                    auxDisciplina = auxDisciplina->proximo;
                }
                break;
            }
            auxCursoDisciplina = auxCursoDisciplina->proximo;
        }

        printf("Codigo: %d, Pessoa: %s, Disciplina: %s, Curso: %s\n",
               auxPessoaDisciplina->cod_pessoa_disciplina,
               nome_pessoa,
               nome_disciplina,
               nome_curso);

        auxPessoaDisciplina = auxPessoaDisciplina->proximo;
    }
}

void ListarPessoaDisciplinaAlunos()
{
    auxPessoaDisciplina = topoPessoaDisciplina;

    char nome_curso[50];
    char nome_pessoa[50];
    char nome_disciplina[50];

    if (topoPessoaDisciplina == NULL)
    {
        printf("Não há nenhuma relação cadastrada\n");
        getchar();
        return;
    }

    while (auxPessoaDisciplina != NULL)
    {
        auxCursoDisciplina = topoCursoDisciplina;
        auxPessoa = topoPessoa;

        strcpy(nome_curso, "Curso não encontrado");
        strcpy(nome_pessoa, "Pessoa não encontrada");
        strcpy(nome_disciplina, "Disciplina não encontrada");

        while (auxPessoa != NULL)
        {
            if (auxPessoa->cod_pessoa == auxPessoaDisciplina->cod_pessoa)
            {
                strcpy(nome_pessoa, auxPessoa->nome_pessoa);
                
                if (auxPessoa->professor) 
                {
                    break;
                }

                while (auxCursoDisciplina != NULL)
                {
                    if (auxCursoDisciplina->cod_curso_disciplina == auxPessoaDisciplina->cod_curso_disciplina)
                    {
                        auxCurso = topoCurso;
                        while (auxCurso != NULL)
                        {
                            if (auxCurso->cod_curso == auxCursoDisciplina->cod_curso)
                            {
                                strcpy(nome_curso, auxCurso->nome_curso);
                                break;
                            }
                            auxCurso = auxCurso->proximo;
                        }

                        auxDisciplina = topoDisciplina;
                        while (auxDisciplina != NULL)
                        {
                            if (auxDisciplina->cod_disciplina == auxCursoDisciplina->cod_disciplina)
                            {
                                strcpy(nome_disciplina, auxDisciplina->nome_disciplina);
                                break;
                            }
                            auxDisciplina = auxDisciplina->proximo;
                        }
                        break;
                    }
                    auxCursoDisciplina = auxCursoDisciplina->proximo;
                }

                printf("Código: %d, Pessoa: %s, Disciplina: %s, Curso: %s\n",
                       auxPessoaDisciplina->cod_pessoa_disciplina,
                       nome_pessoa,
                       nome_disciplina,
                       nome_curso);
                break; 
            }
            auxPessoa = auxPessoa->proximo;
        }
        auxPessoaDisciplina = auxPessoaDisciplina->proximo;
    }
}


void escrever_pessoa_displina_arquivo()
{	
    FILE *file = fopen("PESSOA_DISCIPLINA.csv", "w");
    if (file == NULL) {
        perror("Error opening file");
    }
    fprintf(file, "Codigo,Codigo_pessoa,Codigo_curso_disciplina\n");
	
    FILE *arquivo = fopen("PESSOA_DISCIPLINA.csv", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    fclose(file);
	while (topoPessoaDisciplina!=NULL)
	{
		FILE *arquivo = fopen("PESSOA_DISCIPLINA.csv", "a");
	
	    if (arquivo == NULL) {
	        printf("Erro ao abrir o arquivo.\n");
	    }
		fprintf(arquivo,"%d,%d,%d\n",topoPessoaDisciplina->cod_curso_disciplina,topoPessoaDisciplina->cod_pessoa,topoPessoaDisciplina->cod_pessoa_disciplina);	

		topoPessoaDisciplina=topoPessoaDisciplina->proximo;
		fclose(arquivo);	
	}		
};


void ler_pessoa_disciplina() {
    FILE *file = fopen("PESSOA_DISCIPLINA.csv", "r");
    char linha[256];
    if (fgets(linha, sizeof(linha), file) == NULL) {
        fclose(file);
        return;
    } 
    while (fgets(linha, sizeof(linha), file) != NULL) {
        linha[strcspn(linha, "\r\n")] = '\0';
        int codigo, cod_pessoa,cod_pessoa_disciplina;
        
        int result = sscanf(linha, "%d,%d,%d",
                            &codigo, &cod_pessoa, &cod_pessoa_disciplina);
        
        if (result == 3) {
      	criar_pessoa_displina_arquivo(codigo,cod_pessoa,cod_pessoa_disciplina);
        }
    }
    fclose(file);
};

void criar_pessoa_displina_arquivo(int codigo, int cod_pessoa,int cod_pessoa_disciplina)
{	
	ultimoCodigoPessoaDisciplina++;
	
	auxPessoaDisciplina = (struct PESSOA_DISCIPLINA*)malloc(sizeof(struct PESSOA_DISCIPLINA));
	auxPessoaDisciplina->cod_pessoa_disciplina = codigo;
	auxPessoaDisciplina->cod_pessoa = cod_pessoa;
	auxPessoaDisciplina->cod_pessoa_disciplina = cod_pessoa_disciplina;
	
	
	limparBuffer();
	
	if(topoPessoaDisciplina == NULL)
	{
		topoPessoaDisciplina = auxPessoaDisciplina;
	}
	else
	{
		fimPessoaDisciplina->proximo = auxPessoaDisciplina;
	}
	auxPessoaDisciplina->proximo = NULL;
	fimPessoaDisciplina = auxPessoaDisciplina;
};


















