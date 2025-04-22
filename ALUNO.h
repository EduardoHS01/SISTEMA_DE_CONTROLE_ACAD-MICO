#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#ifndef ALUNO_H
#define ALUNO_H


int cod_aluno = 0;

struct ALUNO 
{
	int cod_aluno;
	char nome_aluno[50];
	char cpf[11];
	char data_nascimento[8];
	struct ALUNO *anterior;
	struct ALUNO *proximo;
};

struct ALUNO *criar_novo_aluno(struct ALUNO *topo, struct ALUNO *fim)
{
	struct ALUNO *p = NULL;
	cod_aluno++;
	p = (struct ALUNO*)malloc(sizeof(struct ALUNO));	
	p->proximo = NULL;
	p->cod_aluno = cod_aluno; 
	printf("INSIRA O NOME DO ALUNO\n");
	scanf(" %50[^\n]",&p->nome_aluno);	
	fflush(stdin);
	printf("INSIRA O CPF DO ALUNO\n");
	scanf("%s", &p->cpf);
	fflush(stdin);
	printf("INSIRA A DATA DE NASCIMENTO DO ALUNO\n");
	scanf("%s",&p->data_nascimento);
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
};

void imprimir_alunos(struct ALUNO *topo)
{	
	
	while (topo!=NULL)
	{
		char data_formatada[11];
		
		data_formatada[0]= topo->data_nascimento[0];
		data_formatada[1]= topo->data_nascimento[1];
		data_formatada[2]= '/';
		data_formatada[3]= topo->data_nascimento[2];
		data_formatada[4]= topo->data_nascimento[3];
		data_formatada[5]= '/';
		data_formatada[6]= topo->data_nascimento[4];
		data_formatada[7]= topo->data_nascimento[5];
		data_formatada[8]= topo->data_nascimento[6];
		data_formatada[9]= topo->data_nascimento[7];
		data_formatada[10]= '\0';
		
		char cpf_formatado[14];
		
	    cpf_formatado[0] = topo->cpf[0];
	    cpf_formatado[1] = topo->cpf[1];
	    cpf_formatado[2] = topo->cpf[2];
	    cpf_formatado[3] = '.';
	    cpf_formatado[4] = topo->cpf[3];
	    cpf_formatado[5] = topo->cpf[4];
	    cpf_formatado[6] = topo->cpf[5];
	    cpf_formatado[7] = '.';
	    cpf_formatado[8] = topo->cpf[6];
	    cpf_formatado[9] = topo->cpf[7];
	    cpf_formatado[10] = topo->cpf[8];
	    cpf_formatado[11] = '-';
	    cpf_formatado[12] = topo->cpf[9];
	    cpf_formatado[13] = topo->cpf[10];
	    cpf_formatado[14] = '\0'; // termina a string
		
		
		printf("ID:%d \nNOME:%s \nCPF:%s \nDATA DE NASCIMENTO:%s \nENDERECO ALUNO:%p \nENDERECO - PROXIMO: %p\n",topo->cod_aluno, topo->nome_aluno,cpf_formatado,data_formatada, topo, topo->proximo);	

		topo=topo->proximo;	
	}		
};

#endif
