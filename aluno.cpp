#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#include "aluno.h"
#include "funcoes.h"

int cod_aluno = 0;
struct ALUNO *topo_aluno = NULL;
struct ALUNO *fim_aluno = NULL;
struct ALUNO *aux_aluno = NULL;

void criar_novo_aluno()
{
	system("cls");
	char cpf[11];
	char data[8];
	struct ALUNO *p = NULL;
	cod_aluno++;
	p = (struct ALUNO*)malloc(sizeof(struct ALUNO));
	p->cod_aluno = cod_aluno; 
	printf("INSIRA O NOME DO ALUNO\n");
	scanf(" %50[^\n]",&p->nome_aluno);	
	fflush(stdin);
	printf("INSIRA O CPF DO ALUNO\n");
	scanf("%s", &cpf);
	fflush(stdin);
	printf("INSIRA A DATA DE NASCIMENTO DO ALUNO\n");
	scanf("%s", &data);
	p->ativo = true;
	fflush(stdin);
	getch();

	if(topo_aluno == NULL)
	{
		p->proximo = NULL;
		p->anterior = NULL;
		fim_aluno = p;
		topo_aluno = p;
	}
	else
	{
		fim_aluno->proximo = p;
		p->anterior = fim_aluno;
		fim_aluno = p;
		p->proximo = NULL;
		aux_aluno = topo_aluno;
	}
	
	fim_aluno = p;
	
	formatar_cpf_aluno(cpf, fim_aluno);
	fflush(stdin);
	formatar_data_aluno(data, fim_aluno);	

	aux_aluno = topo_aluno;
	getchar();
};

void consultar_alunos(){
	system("cls");
	printf("Informe o nome do aluno a ser consultado \n");
	char nomeConsulta[50];
	scanf(" %50[^\n]", &nomeConsulta);
	int contadorALunos = 0;
	
	aux_aluno = topo_aluno;
	while(aux_aluno != NULL){
		if (strcmp(aux_aluno->nome_aluno, nomeConsulta) == 0){
			printf("ID:%d \nNOME:%s \nCPF:%s \nDATA DE NASCIMENTO:%s \nENDERECO ALUNO:%p \nSTATUS ALUNO:%p \n", aux_aluno->cod_aluno, aux_aluno->nome_aluno, aux_aluno->cpf, aux_aluno->data_nascimento, topo_aluno);	
			contadorALunos++;
		}
		
		aux_aluno = aux_aluno->proximo;
	}
	
	if (contadorALunos == 0){
			printf("Nao foi localizado nenhum aluno...");
		}
	
	fflush(stdin);
	getchar();
}

void imprimir_alunos()
{	
	system("cls");
	if (topo_aluno == NULL){
		printf("Nao existe nenhum aluno cadastrado! \n");
	}
	
	aux_aluno = topo_aluno;
	while (aux_aluno != NULL)
	{		
		char status[7];
		if (aux_aluno->ativo){
			strcpy(status, "Ativo");
		} else {
			strcpy(status, "Inativo");
		}
		
		printf("ID:%d \nNOME:%s \nCPF:%s \nDATA DE NASCIMENTO:%s \nSTATUS ALUNO:%s \nENDERECO - ANTERIOR:%x \nENDERECO ALUNO:%x \nENDERECO - PROXIMO: %x\n \n", aux_aluno->cod_aluno, aux_aluno->nome_aluno, aux_aluno->cpf, aux_aluno->data_nascimento, status, aux_aluno->anterior, aux_aluno, aux_aluno->proximo);	

		aux_aluno=aux_aluno->proximo;
	}
	
	fflush(stdin);
	getchar();	
};

int menu_aluno(){
	system("cls");
	printf("Qual operacao deseja realizar? \n");
	printf("1-Cadastrar novo aluno \n");
	printf("2-Inativar cadastro de aluno \n");
	printf("3-Consultar cadastro de aluno \n");
	printf("4-Imprimir todos os alunos cadastrados \n");
	printf("5-Voltar \n");
	
	int opcao;
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1:
			criar_novo_aluno();
			break;	
		case 2:
			break;	
		case 3:	
			consultar_alunos();
			break;
		case 4:
			imprimir_alunos();
			break;
		case 5:
			break;
		default:
			printf("Selecione uma opcao disponivel \n");
			fflush(stdin);
			getchar();
			menu_aluno();
			break;
	}

}

