#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "cursoDisciplina.h"
#include "disciplina.h"
#include "curso.h"
#include "funcoesauxiliares.h"

struct CURSO_DISCIPLINA *topoCursoDisciplina = NULL;
struct CURSO_DISCIPLINA *auxCursoDisciplina = NULL;
struct CURSO_DISCIPLINA *fimCursoDisciplina = NULL;

int ultimoCodigoCursoDisciplina = 0;

void MenuCursoDisciplina()
{
	int escolhaMenu;
	
	system("cls");
	printf("1 - Criar conexao curso-disciplina OK\n");
	printf("2 - listar conexoes curso-disciplina OK\n");
	printf("3 - Encontrar conexao curso-disciplina NOK\n");
	printf("4 - Voltar \n");
	
	scanf("%d", &escolhaMenu);
	limparBuffer();
	
	switch(escolhaMenu)
	{
		case 1:
			CadastrarCursoDisciplina();
			break;
		case 2:
			ListarCursoDisciplinas();
			getchar();
			break;
		case 4:
			return;
			break;
	}
}

void CadastrarCursoDisciplina()
{		
	if(topoCurso == NULL || topoDisciplina == NULL)
	{
		printf("Nao ha dados suficientes para essa acao. Por favor cadastre mais cursos e disciplinas");
		getchar();
		return;
	}
	
	ultimoCodigoCursoDisciplina++;
	
	auxCursoDisciplina = (struct CURSO_DISCIPLINA*)malloc(sizeof(struct CURSO_DISCIPLINA));
	auxCursoDisciplina->cod_curso_disciplina = ultimoCodigoCursoDisciplina;
	
	if(topoCursoDisciplina == NULL)
	{
		topoCursoDisciplina = auxCursoDisciplina;
	}
	else
	{
		fimCursoDisciplina->proximo = auxCursoDisciplina;
	}
	auxCursoDisciplina->proximo = NULL;
	fimCursoDisciplina = auxCursoDisciplina;
	
	printf("Escolha uma disciplina: \n");
	ListarDisciplinas();
	scanf("%d", &auxCursoDisciplina->cod_disciplina);
	limparBuffer();
	printf("Escolha um curso: \n");
	ListarCursos();
	scanf("%d", &auxCursoDisciplina->cod_curso);
	limparBuffer();
	printf("Em qual periodo essa disciplina e lecionada?\n");
	scanf("%d", &auxCursoDisciplina->periodo);
	limparBuffer();
	
	printf("Conexao curso-disciplina criada!");
	getchar();
}

void ListarCursoDisciplinas()
{
	auxCursoDisciplina = topoCursoDisciplina;
	
	char nome_curso[30];
	char nome_disciplina[50];
	
	if(topoCursoDisciplina == NULL)
	{
		printf("Nao ha nenhuma conexao curso-disciplina cadastrada\n");
		getchar();
		return;
	}
	
	while(auxCursoDisciplina != NULL)
	{
		auxCurso = topoCurso;
		auxDisciplina = topoDisciplina;
		
		strcpy(nome_curso, "Curso nao encontrado");
        strcpy(nome_disciplina, "Disciplina nao encontrada");
        
		while(auxCurso != NULL)
		{
			if(auxCurso->cod_curso == auxCursoDisciplina->cod_curso)
			{
				strcpy(nome_curso, auxCurso->nome_curso);
			}
			auxCurso = auxCurso->proximo;
		}
		while(auxDisciplina != NULL)
		{
			if(auxDisciplina->cod_disciplina == auxCursoDisciplina->cod_disciplina)
			{
				strcpy(nome_disciplina, auxDisciplina->nome_disciplina);
			}
			auxDisciplina = auxDisciplina->proximo;
		}
		printf("Codigo: %d, Disciplina: %s, Curso: %s, Periodo: %d\n",
		auxCursoDisciplina->cod_curso_disciplina,
		nome_disciplina,
		nome_curso,
		auxCursoDisciplina->periodo);
		auxCursoDisciplina = auxCursoDisciplina->proximo;
	}
}













