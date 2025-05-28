#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "curso.h"
#include "funcoesauxiliares.h"
#include "pessoa.h"
#include "disciplina.h"
#include "cursoDisciplina.h"
#include "matriculaCurso.h"
#include "pessoaDisciplina.h"
#include "desempenhoAlunoDisciplina.h"

int Menu()
{
	int escolhaMenu;
	
	system("cls");
	printf("Selecione a opcao que desejar! \n");
	printf("1 - Alunos \n");
	printf("2 - Professores \n");
	printf("3 - Disciplinas \n");
	printf("4 - Cursos \n");
	printf("5 - Curso-Disciplina \n");
	printf("6 - Matriculas \n");
	printf("7 - Pessoa-Disciplina\n");
	printf("8 - Cadastrar desempenho\n");
	printf("9 - Sair \n");
	
	scanf("%d", &escolhaMenu);
	limparBuffer();
	
	return escolhaMenu;
}

int main(int argc, char *argv[]) {
	int escolhaMenu;
	
	while(escolhaMenu != 9)
	{
		escolhaMenu = Menu();
		switch(escolhaMenu)
		{
			case 1:
				MenuPessoa(false);
				break;
			case 2:
				MenuPessoa(true);
				break;
			case 3:
				MenuDisciplina();
				break;
			case 4:
				MenuCurso();
				break;
			case 5:
				MenuCursoDisciplina();
				break;
			case 6:
				MenuMatriculaCurso();
				break;
			case 7:
				MenuPessoaDisciplina();
			    break;
			case 8:
				MenuDesempenhoAlunoDisciplina();
				break;
			case 9:
				printf("Encerrando o programa...\n");
			    sleep(2);
			    exit(0);
			    break;
			default:
				printf("Selecione uma opcao disponivel \n");
				fflush(stdin);
				getchar(); 
				break;
		}
		system("cls");
	}
	return 0;
}

















