#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#ifndef ALUNO_H
#define ALUNO_H

int cod_aluno = 0;
struct ALUNO *topo = NULL;
struct ALUNO *fim = NULL;
struct ALUNO *aux = NULL;

struct ALUNO 
{
	int cod_aluno;
	char nome_aluno[50];
	char cpf[15];
	char data_nascimento[11];
	//struct ALUNO *anterior;
	struct ALUNO *proximo;
};

char formatar_cpf(char cpf[11]){
		
	fim->cpf[0] = cpf[0];
	fim->cpf[1] = cpf[1];
	fim->cpf[2] = cpf[2];
	fim->cpf[3] = '.';
	fim->cpf[4] = cpf[3];
	fim->cpf[5] = cpf[4];
	fim->cpf[6] = cpf[5];
	fim->cpf[7] = '.';
	fim->cpf[8] = cpf[6];
	fim->cpf[9] = cpf[7];
	fim->cpf[10] = cpf[8];
	fim->cpf[11] = '-';
	fim->cpf[12] = cpf[9];
	fim->cpf[13] = cpf[10];
	fim->cpf[14] = '\0'; // termina a string
}

char formatar_data(char data[8]){
	
	fim->data_nascimento[0] = data[0];
	fim->data_nascimento[1] = data[1];
	fim->data_nascimento[2] = '/';
	fim->data_nascimento[3] = data[2];
	fim->data_nascimento[4] = data[3];
	fim->data_nascimento[5] = '/';
	fim->data_nascimento[6] = data[4];
	fim->data_nascimento[7] = data[5];
	fim->data_nascimento[8] = data[6];
	fim->data_nascimento[9] = data[7];
	fim->data_nascimento[10] = '\0';
}

void criar_novo_aluno()
{
	system("cls");
	char cpf[11];
	char data[8];
	struct ALUNO *p = NULL;
	cod_aluno++;
	p = (struct ALUNO*)malloc(sizeof(struct ALUNO));	
	p->proximo = NULL;
	p->cod_aluno = cod_aluno; 
	printf("INSIRA O NOME DO ALUNO\n");
	scanf(" %50[^\n]",&p->nome_aluno);	
	fflush(stdin);
	printf("INSIRA O CPF DO ALUNO\n");
	scanf("%s", &cpf);
	fflush(stdin);
	printf("INSIRA A DATA DE NASCIMENTO DO ALUNO\n");
	scanf("%s", &data);
	fflush(stdin);
	getch();

	if(topo == NULL)
	{
		topo = p;
	}
	else
	{
		fim ->proximo = p;
	}
	
	fim = p;
	
	formatar_cpf(cpf);
	fflush(stdin);
	formatar_data(data);
	
	//printf("ID: %d - %s cadastrado com sucesso! \nEndereco: [%x] \n", fim->cod_aluno, fim->nome_aluno, fim);
	//printf("ID:%d \nNOME:%s \nCPF:%s \nENDERECO ALUNO:%x \nENDERECO - PROXIMO: %x\n", fim->cod_aluno, fim->nome_aluno, fim->cpf, fim, fim->proximo);	

	getchar();
};

/*void consultar_alunos(){
	system("cls");
	printf("Informe o nome do aluno a ser consultado \n");
	char nomeConsulta[50];
	scanf(" %50[^\n]", nomeConsulta);
	
	aux = topoProfessorProfessorProfessor;
	while(aux != NULL){
		if (aux->nome_aluno == nomeConsulta){
				printf("ID:%d \nNOME:%s \nCPF:%s \nDATA DE NASCIMENTO:%s \nENDERECO ALUNO:%p \n",aux->cod_aluno, aux->nome_aluno, formatar_cpf(aux->cpf), formatar_data(aux->data_nascimento), topoProfessorProfessorProfessor);	

		}
	}
} */

void imprimir_alunos()
{	
	system("cls");
	if (topo == NULL){
		printf("Nao existe nenhum aluno cadastrado! \n");
	}
	
	aux = topo;
	while (aux != NULL)
	{		
		printf("ID:%d \nNOME:%s \nCPF:%s \nDATA DE NASCIMENTO:%s \nENDERECO ALUNO:%x \nENDERECO - PROXIMO: %x\n \n", aux->cod_aluno, aux->nome_aluno, aux->cpf, aux->data_nascimento, aux, aux->proximo);	

		aux=aux->proximo;
	}
	
	fflush(stdin);
	getchar();	
};

int menuAluno(){
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
			menuAluno();
			break;
	}

}

#endif
