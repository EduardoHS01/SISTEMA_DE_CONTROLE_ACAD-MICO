#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "matriculaCurso.h"
#include "pessoa.h"
#include "curso.h"
#include "funcoesauxiliares.h"

struct MATRICULA_CURSO *topoMatriculaCurso = NULL;
struct MATRICULA_CURSO *auxMatriculaCurso = NULL;
struct MATRICULA_CURSO *fimMatriculaCurso = NULL;

int ultimoCodigoMatriculaCurso = 0;

void MenuMatriculaCurso()
{
	int escolhaMenu;
	
	system("cls");
	printf("1 - Matricular aluno em curso OK\n");
	printf("2 - listar matriculas OK\n");
	printf("3 - Encontrar matricula NOK\n");
	printf("4 - Voltar \n");
	
	scanf("%d", &escolhaMenu);
	limparBuffer();
	
	switch(escolhaMenu)
	{
		case 1:
			CadastrarMatriculaCurso();
			break;
		case 2:
			ListarMatriculaCursos();
			break;
		case 4:
			return;
			break;
	}
}

void CadastrarMatriculaCurso()
{	
	auxPessoa = topoPessoa;
	int contagemAlunos = 0;
	
	while(auxPessoa != NULL)
	{
		if(auxPessoa->professor == false)
		{
			contagemAlunos++;
		}
		auxPessoa = auxPessoa->proximo;
	}
	
	if(topoCurso == NULL || contagemAlunos == 0)
	{
		printf("Nao ha dados suficientes para essa acao. Por favor cadastre mais cursos e alunos");
		getchar();
		return;
	}
	
	ultimoCodigoMatriculaCurso++;
	
	auxMatriculaCurso = (struct MATRICULA_CURSO*)malloc(sizeof(struct MATRICULA_CURSO));
	auxMatriculaCurso->cod_matricula_curso = ultimoCodigoMatriculaCurso;
	
	if(topoMatriculaCurso == NULL)
	{
		topoMatriculaCurso = auxMatriculaCurso;
	}
	else
	{
		fimMatriculaCurso->proximo = auxMatriculaCurso;
	}
	auxMatriculaCurso->proximo = NULL;
	fimMatriculaCurso = auxMatriculaCurso;
	
	printf("Escolha um aluno: \n");
	ListarPessoas(false);
	scanf("%d", &auxMatriculaCurso->cod_pessoa);
	limparBuffer();
	printf("Escolha um curso: \n");
	ListarCursos();
	scanf("%d", &auxMatriculaCurso->cod_curso);
	limparBuffer();
	
	printf("Matricula criada!");
	getchar();
}

void ListarMatriculaCursos()
{
	auxMatriculaCurso = topoMatriculaCurso;
	
	char nome_curso[30];
	char nome_aluno[50];
	
	if(topoMatriculaCurso == NULL)
	{
		printf("Nao ha nenhuma matricula cadastrada\n");
		getchar();
		return;
	}
	
	while(auxMatriculaCurso != NULL)
	{
		auxCurso = topoCurso;
		auxPessoa = topoPessoa;
		
		strcpy(nome_curso, "Curso nao encontrado");
        strcpy(nome_aluno, "Aluno nao encontrado");
        
		while(auxCurso != NULL)
		{
			if(auxCurso->cod_curso == auxMatriculaCurso->cod_curso)
			{
				strcpy(nome_curso, auxCurso->nome_curso);
			}
			auxCurso = auxCurso->proximo;
		}
		while(auxPessoa != NULL)
		{
			if(auxPessoa->cod_pessoa == auxMatriculaCurso->cod_pessoa)
			{
				strcpy(nome_aluno, auxPessoa->nome_pessoa);
			}
			auxPessoa = auxPessoa->proximo;
		}
		printf("Codigo: %d, Aluno: %s, Curso: %s\n",
		auxMatriculaCurso->cod_matricula_curso,
		nome_aluno,
		nome_curso);
		auxMatriculaCurso = auxMatriculaCurso->proximo;
	}
	getchar();
}
