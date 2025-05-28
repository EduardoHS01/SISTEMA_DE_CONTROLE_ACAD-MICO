#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "funcoesauxiliares.h"
#include "disciplina.h"

struct DISCIPLINA *topoDisciplina = NULL;
struct DISCIPLINA *auxDisciplina = NULL;
struct DISCIPLINA *fimDisciplina = NULL;

int ultimoCodigoDisciplina = 0;

void MenuDisciplina()
{
	int escolhaMenu;
	
	system("cls");
	printf("1 - Criar disciplina OK\n");
	printf("2 - Listar disciplinas OK\n");
	printf("3 - Gerenciar disciplina NOK\n");
	printf("4 - Voltar \n");
	
	scanf("%d", &escolhaMenu);
	limparBuffer();
	
	switch(escolhaMenu)
	{
		case 1:
			CadastrarDisciplina();
			break;
		case 2:
			ListarDisciplinas();
			getchar();
			break;
		case 4:
			return;
			break;
	}
	
};

void ListarDisciplinas()
{
	auxDisciplina = topoDisciplina;
	
	if(topoDisciplina == NULL)
	{
		printf("Nao ha nenhuma disciplina cadastrada");
	}
	
	while(auxDisciplina != NULL)
	{
		if(auxDisciplina->ativo == true)
		{
			printf("Codigo: %d, Nome: %s, Ativo: %s\n",
			auxDisciplina->cod_disciplina,
			auxDisciplina->nome_disciplina,
			auxDisciplina->ativo ? "Sim" : "Nao");
		}
		auxDisciplina = auxDisciplina->proximo;
	}
};

void CadastrarDisciplina()
{
	ultimoCodigoDisciplina++;
	
	auxDisciplina = (struct DISCIPLINA*)malloc(sizeof(struct DISCIPLINA));
	auxDisciplina->cod_disciplina = ultimoCodigoDisciplina;
	auxDisciplina->ativo = true;
	
	system("cls");
	printf("Qual o nome da disciplina?\n");
	scanf(" %50[^\n]", auxDisciplina->nome_disciplina);
	limparBuffer();
	
	if(topoDisciplina == NULL)
	{
		topoDisciplina = auxDisciplina;
	}
	else
	{
		fimDisciplina->proximo = auxDisciplina;
	}
	auxDisciplina->proximo = NULL;
	fimDisciplina = auxDisciplina;
};













