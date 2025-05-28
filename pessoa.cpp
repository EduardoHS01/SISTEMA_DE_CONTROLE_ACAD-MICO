#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "pessoa.h"
#include "funcoesauxiliares.h"

struct PESSOA *topoPessoa = NULL;
struct PESSOA *auxPessoa = NULL;
struct PESSOA *fimPessoa = NULL;

int ultimoCodigoPessoa = 0;

bool validar_cpf_formatado(const char *cpf) {
	if (strlen(cpf) != 14)//strlen só vê até o espaço antes o \0, por isso 14
		return false;
	
	for (int i = 0; i < 14; i++) {
		if (i == 3 || i == 7) {
			if (cpf[i] != '.') return false;
		} else if (i == 11) {
			if (cpf[i] != '-') return false;
		} else {
			if (!isdigit(cpf[i])) return false;
		}
	}
	return true;
}

bool validar_data_formatada(const char *data) {
    if (strlen(data) != 10)
        return false;

    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            if (data[i] != '/') return false;
        } else {
            if (!isdigit(data[i])) return false;
        }
    }
    return true;
}

void MenuPessoa(bool tipo)  //1 = professor, 0 = aluno
{
	int escolhaMenu;
	
	if(tipo) //se for professor
	{
		system("cls");
		printf("1 - Adicionar professor OK\n");
		printf("2 - Listar professores OK\n");
		printf("3 - Gerenciar professor NOK\n");
		printf("4 - Voltar \n");
		
		scanf("%d", &escolhaMenu);
		limparBuffer();
		
		switch(escolhaMenu)
		{
			case 1:
				CriarPessoa(true);
				break;
			case 2:
				ListarPessoas(true);
				break;
			case 4:
				return;
		}
		
	}else
	{
		system("cls");
		printf("1 - Adicionar aluno OK\n");
		printf("2 - Listar alunos OK\n");
		printf("3 - Gerenciar aluno NOK\n");
		printf("4 - Voltar \n");
		
		scanf("%d", &escolhaMenu);
		limparBuffer();
		
		switch(escolhaMenu)
		{
			case 1:
				CriarPessoa(false);
				break;
			case 2:
				ListarPessoas(false);
				getchar();
				break;
			case 4:
				return;
		}
	}
}

void CriarPessoa(bool tipo)
{
	char cpf[15];
	char data[11];
	
	ultimoCodigoPessoa++;
	if(topoPessoa == NULL){
		topoPessoa = (struct PESSOA*) malloc(sizeof(struct PESSOA));
		auxPessoa = topoPessoa;
		auxPessoa -> anterior = NULL;
	}
	else{
		auxPessoa = (struct PESSOA*) malloc(sizeof(struct PESSOA));
		auxPessoa -> anterior = fimPessoa;
		fimPessoa -> proximo = auxPessoa;
	}
	auxPessoa -> proximo = NULL;
	fimPessoa = auxPessoa;
	
	auxPessoa->cod_pessoa = ultimoCodigoPessoa;
	auxPessoa->professor = tipo;
	auxPessoa->ativo = true;
	
	system("cls");
	printf("Nome completo:\n");
	scanf(" %50[^\n]", auxPessoa->nome_pessoa);
	limparBuffer();
	do {
		fflush(stdin);
		printf("CPF: (formato xxx.xxx.xxx-xx):\n");
		scanf("%s", cpf);
		limparBuffer();
		if (!validar_cpf_formatado(cpf)) {
			printf("CPF invalido! Tente novamente no formato xxx.xxx.xxx-xx.\n");
		}
	} while (!validar_cpf_formatado(cpf));
	strcpy(auxPessoa->cpf, cpf);
	
	do {
        fflush(stdin);
        printf("Data de nascimento: (formato dd/mm/aaaa):\n");
        scanf("%s", data);
        limparBuffer();
        if (!validar_data_formatada(data)) {
            printf("Data invalida! Tente novamente no formato dd/mm/aaaa.\n");
        }
    } while (!validar_data_formatada(data));
    strcpy(auxPessoa->data_nascimento, data);
	limparBuffer();	
}

void ListarPessoas(bool tipo)
{	
	auxPessoa = topoPessoa;
	
	//confere se temos pessoas do tipo esperado
	int contador = 0;
	while(auxPessoa != NULL)
	{
		if(auxPessoa->professor == tipo)
		{
			contador++;
		}
		auxPessoa = auxPessoa->proximo;
	}
	if(contador == 0)
	{
		printf("Nao ha %s cadastrados", tipo ? "professores" : "alunos");
		getchar();
		return;
	}
	
	auxPessoa = topoPessoa;
	
	while(auxPessoa != NULL)
	{
		if(tipo && auxPessoa->professor)
		{
			printf("Codigo: %d, Nome: %s, CPF: %s, Data de Nascimento: %s, Ativo: %s\n",
			auxPessoa->cod_pessoa,
			auxPessoa->nome_pessoa,
			auxPessoa->cpf,
			auxPessoa->data_nascimento,
			auxPessoa->ativo ? "Sim" : "Nao");
		}
		if(tipo == false && auxPessoa->professor == false)
		{
			printf("Codigo: %d, Nome: %s, CPF: %s, Data de Nascimento: %s, Ativo: %s\n",
			auxPessoa->cod_pessoa,
			auxPessoa->nome_pessoa,
			auxPessoa->cpf,
			auxPessoa->data_nascimento,
			auxPessoa->ativo ? "Sim" : "Nao");
		}
		auxPessoa = auxPessoa->proximo;
	}
}

void ListarTodasPessoas()
{	
	auxPessoa = topoPessoa;
	
	while(auxPessoa != NULL)
	{
		printf("Codigo: %d, Nome: %s, CPF: %s, Data de Nascimento: %s, Tipo: %s, Ativo: %s\n",
			auxPessoa->cod_pessoa,
			auxPessoa->nome_pessoa,
			auxPessoa->cpf,
			auxPessoa->data_nascimento,
			auxPessoa->professor ? "Professor" : "Aluno",
			auxPessoa->ativo ? "Sim" : "Nao");
			
		auxPessoa = auxPessoa->proximo;
	}
}


















