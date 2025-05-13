#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

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
	char nome[50];
	struct ALUNO *p = NULL;
	cod_aluno++;
	p = (struct ALUNO*)malloc(sizeof(struct ALUNO));
	p->cod_aluno = cod_aluno; 
	printf("INSIRA O NOME DO ALUNO\n");
	scanf(" %50[^\n]", &nome);
	converterString(nome);
	strcpy(p->nome_aluno, nome);	
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
	int escolhaConsulta;
	printf("1-Consultar por nome \n2-Consultar por CPF \n3-Consultar por codigo \n");
	scanf("%d", &escolhaConsulta);
	
	int contadorALunos = 0;
	
	switch(escolhaConsulta){
		case 1:
			char nomeConsulta[50];
			printf("Insira o nome a ser consultado \n");
			scanf(" %50[^\n]", &nomeConsulta);
			converterString(nomeConsulta);
			
			aux_aluno = topo_aluno;
			while(aux_aluno != NULL){
			if (strstr(aux_aluno->nome_aluno, nomeConsulta) != NULL){
				printf("\nID:%d \nNOME:%s \nCPF:%s \nDATA DE NASCIMENTO:%s \nENDERECO ALUNO:%p \nSTATUS ALUNO:%p \n", aux_aluno->cod_aluno, aux_aluno->nome_aluno, aux_aluno->cpf, aux_aluno->data_nascimento, topo_aluno);	
				contadorALunos++;
			}
		
				aux_aluno = aux_aluno->proximo;
			}
			break;
			
		case 2: {
		    char cpfConsulta[15];
		    printf("Insira o CPF a ser consultado \n");
		    scanf(" %14[^\n]", cpfConsulta);
		
		    char cpfConsultaLimpo[12];
		    removerFormatacaoCPF(cpfConsulta, cpfConsultaLimpo);
		
		    aux_aluno = topo_aluno;
		    while (aux_aluno != NULL) {
		        char cpfArmazenadoLimpo[12];
		        removerFormatacaoCPF(aux_aluno->cpf, cpfArmazenadoLimpo);
		
		        if (strcmp(cpfArmazenadoLimpo, cpfConsultaLimpo) == 0) {
		            printf("\nID:%d \nNOME:%s \nCPF:%s \nDATA DE NASCIMENTO:%s \n",
		                   aux_aluno->cod_aluno, aux_aluno->nome_aluno, aux_aluno->cpf, aux_aluno->data_nascimento);
		            contadorALunos++;
		        }
		        aux_aluno = aux_aluno->proximo;
		    }
		    break;
		}
			
		case 3:
			int codigo;
			printf("Insira o codigo a ser consultado \n");
			scanf(" %d", &codigo);
			
			aux_aluno = topo_aluno;
			while(aux_aluno != NULL){
			if (aux_aluno->cod_aluno == codigo){
				printf("\nID:%d \nNOME:%s \nCPF:%s \nDATA DE NASCIMENTO:%s \nENDERECO ALUNO:%p \nSTATUS ALUNO:%p \n", aux_aluno->cod_aluno, aux_aluno->nome_aluno, aux_aluno->cpf, aux_aluno->data_nascimento, topo_aluno);	
				contadorALunos++;
			}
		
				aux_aluno = aux_aluno->proximo;
			}
			break;
			
		default:
			printf("Por favor, escolha uma opcao entre 1 e 3... \n");
			break;
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

