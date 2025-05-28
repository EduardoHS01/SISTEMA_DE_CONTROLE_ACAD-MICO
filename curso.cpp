#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "curso.h"
#include "funcoesauxiliares.h"

struct CURSO *topoCurso = NULL;
struct CURSO *auxCurso = NULL;
struct CURSO *fimCurso = NULL;

int ultimoCodigoCurso = 0;

void MenuCurso()
{
	int escolhaMenu;
	
	system("cls");
	printf("1 - Criar curso OK\n");
	printf("2 - Listar cursos OK\n");
	printf("3 - Gerenciar curso NOK\n");
	printf("4 - Voltar \n");
	
	scanf("%d", &escolhaMenu);
	limparBuffer();
	
	switch(escolhaMenu)
	{
		case 1:
			CadastrarCurso();
			break;
		case 2:
			ListarCursos();
			getchar();
			break;
		case 4:
			return;
			break;
	}
	
};

void ListarCursos()
{
	auxCurso = topoCurso;
	
	if(topoCurso == NULL)
	{
		printf("Nao ha nenhum curso cadastrado");
	}
	
	while(auxCurso != NULL)
	{
		printf("Codigo: %d, Nome: %s, Quantidade de periodos: %d\n",
		auxCurso->cod_curso,
		auxCurso->nome_curso,
		auxCurso->periodos);
		auxCurso = auxCurso->proximo;
	}
};

void CadastrarCurso()
{
	ultimoCodigoCurso++;
	
	auxCurso = (struct CURSO*)malloc(sizeof(struct CURSO));
	auxCurso->cod_curso = ultimoCodigoCurso;
	
	system("cls");
	printf("Qual o nome do curso?\n");
	scanf(" %50[^\n]", auxCurso->nome_curso);
	limparBuffer();
	printf("Quantos periodos tem o curso?\n");
	scanf("%d", &auxCurso->periodos);
	limparBuffer();
	
	if(topoCurso == NULL)
	{
		topoCurso = auxCurso;
	}
	else
	{
		fimCurso->proximo = auxCurso;
	}
	auxCurso->proximo = NULL;
	fimCurso = auxCurso;
};













