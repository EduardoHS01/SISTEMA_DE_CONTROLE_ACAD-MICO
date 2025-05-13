/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//##########################################################
//# Nome do Programa: Sistema de gest?o acad?mico
//# Autores: Aline Lopes Ferreira, Eduardo Henrique da Silva e Giovane Gabriel do Nascimento
//# Data: 21/04/2025
//# Descricao: Executar as funcionalidades b?sicas de gest?o para uma institui??o acad?mica, como gerenciamento de individuos, atividades e gere??o de relat?rios de desempenho.
//##########################################################

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "aluno.h"
#include "professor.h"

int menu(){
	system("cls");
	printf("Seja bem-vindo. Selecione a opcao que desejar! \n");
	printf("1-Alunos \n");
	printf("2-Professores \n");
	printf("3-Disciplinas \n");
	printf("4-Sair \n");
	
	int escolha;
	scanf("%d", &escolha);
	
	return escolha;
}

int main(int argc, char** argv) {
	int menu_principal;
	
	while (menu_principal != 4){
		printf("INSIRA UM NUMERO: \n");
		menu_principal = menu();
		switch(menu_principal)
		{
			case 1:
				menu_aluno();
				break;
			case 2:
				menu_professor();
				break;
			case 3:
				break;
			case 4:
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
