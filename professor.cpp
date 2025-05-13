#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#include "professor.h"
#include "funcoes.h"

int cod_professor = 0;
struct PROFESSOR *topo_professor = NULL;
struct PROFESSOR *fim_professor = NULL;
struct PROFESSOR *aux_professor = NULL;

void criar_novo_professor()
{
	system("cls");
	char cpf[11];
	char data[8];
	struct PROFESSOR *p = NULL;
	cod_professor++;
	p = (struct PROFESSOR*)malloc(sizeof(struct PROFESSOR));	
	p->proximo = NULL;
	p->cod_professor = cod_professor; 
	printf("INSIRA O NOME DO PROFESSOR\n");
	scanf(" %50[^\n]",&p->nome_professor);	
	fflush(stdin);
	printf("INSIRA O CPF DO PROFESSOR\n");
	scanf("%s", &cpf);
	fflush(stdin);
	printf("INSIRA A DATA DE NASCIMENTO DO PROFESSOR\n");
	scanf("%s", &data);
	fflush(stdin);
	getch();

	if(topo_professor == NULL)
	{
		topo_professor = p;
	}
	else
	{
		fim_professor ->proximo = p;
	}
	
	fim_professor = p;
	
	formatar_cpf_professor(cpf, fim_professor);
	fflush(stdin);
	formatar_data_professor(data, fim_professor);
	
	printf("ID:%d \nNOME:%s \nCPF:%s \nDATA DE NASCIMENTO:%s \nENDERECO ALUNO:%x \nENDERECO - PROXIMO: %x\n", fim_professor->cod_professor, fim_professor->nome_professor, fim_professor->cpf, fim_professor->data_nascimento, fim_professor, fim_professor->proximo);	

	getchar();
};

int menu_professor(){
	system("cls");
	printf("Qual operacao deseja realizar? \n");
	printf("1-Cadastrar novo professor \n");
	printf("2-Inativar cadastro de professor \n");
	printf("3-Consultar cadastro de professor \n");
	printf("4-Imprimir todos os professores cadastrados \n");
	printf("5-Voltar \n");
	
	int opcao;
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1:
			criar_novo_professor();
			break;	
		case 2:
			break;	
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			printf("Selecione uma opcao disponivel \n");
			fflush(stdin);
			getchar();
			menu_professor();
			break;
	}

}

