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
void ler_dados_aluno(char *nome, char *cpf, char *data) {
	printf("INSIRA O NOME DO ALUNO\n");
	scanf(" %50[^\n]", nome);
	converterString(nome);

	do {
		fflush(stdin);
		printf("INSIRA O CPF DO ALUNO (formato xxx.xxx.xxx-xx):\n");
		scanf("%s", cpf);
		if (!validar_cpf_formatado(cpf)) {
			printf("CPF invalido! Tente novamente no formato xxx.xxx.xxx-xx.\n");
		}
	} while (!validar_cpf_formatado(cpf));
	
	do {
        fflush(stdin);
        printf("INSIRA A DATA DE NASCIMENTO DO ALUNO (formato dd/mm/aaaa):\n");
        scanf("%s", data);
        if (!validar_data_formatada(data)) {
            printf("Data invalida! Tente novamente no formato dd/mm/aaaa.\n");
        }
    } while (!validar_data_formatada(data));
}


void criar_novo_aluno() {
	system("cls");
	char cpf[15];
	char data[11];
	char nome[50];
	struct ALUNO *p = NULL;

	ler_dados_aluno(nome, cpf, data);

	cod_aluno++;
	p = (struct ALUNO*)malloc(sizeof(struct ALUNO));
	p->cod_aluno = cod_aluno;
	strcpy(p->nome_aluno, nome);
	strcpy(p->cpf, cpf);
	strcpy(p->data_nascimento, data);
	p->ativo = true;
		
	if(topo_aluno == NULL) {
		p->proximo = NULL;
		p->anterior = NULL;
		topo_aluno = p;
		fim_aluno = p;
	} else {
		fim_aluno->proximo = p;
		p->anterior = fim_aluno;
		p->proximo = NULL;
		fim_aluno = p;
	}
	aux_aluno = topo_aluno;
	getchar();
}

int pegar_codigo()
{
	int esc = 0;
	printf("POR FAVOR INSIRA O ID DO ALUNO QUE DESEJA MANIPULAR:\n");
	scanf("%d",&esc);
	return esc;
}
void inativar_aluno()
{
	cod_aluno = pegar_codigo();
    struct ALUNO *aux = topo_aluno;
    
    while(aux != NULL && aux->cod_aluno != cod_aluno)
    {
        aux = aux->proximo;
    }
    

    if(aux == NULL)
    {
        printf("Aluno com código %d não encontrado.\n", cod_aluno);
    }
    
    if(!aux->ativo)
    {
        printf("Aluno com código %d já está inativo.\n", cod_aluno);
    }
    
    aux->ativo = false;
    printf("Aluno com código %d marcado como inativo.\n", cod_aluno);
	getch();
}


void excluir_aluno()
{
	cod_aluno = pegar_codigo();
    struct ALUNO *aux = topo_aluno;
    
    while(aux != NULL && aux->cod_aluno != cod_aluno)
    {
        aux = aux->proximo;
    }

    if(aux == NULL)
    {
        printf("Aluno com código %d não encontrado.\n", cod_aluno);
    }
    if(aux->anterior == NULL)
    {
        topo_aluno = aux->proximo;
        if(topo_aluno != NULL)
        {
            topo_aluno->anterior = NULL;
        }
    }
    else
    {
        aux->anterior->proximo = aux->proximo;
    }
    if(aux->proximo != NULL)
    {
        aux->proximo->anterior = aux->anterior;
    }
    free(aux);  
	getch();  
    }

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
	printf("3-Excluir cadastro de aluno \n");
	printf("4-Consultar cadastro de aluno \n");
	printf("5-Imprimir todos os alunos cadastrados \n");
	printf("6-Voltar \n");
	
	int opcao;
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1:
			criar_novo_aluno();
			break;	
		case 2:
			inativar_aluno();
			break;
		case 3:
			excluir_aluno();
			break;	
		case 4:	
			consultar_alunos();
			break;
		case 5:
			imprimir_alunos();
			break;
		case 6:
			break;
		default:
			printf("Selecione uma opcao disponivel \n");
			fflush(stdin);
			getchar();
			menu_aluno();
			break;
	}

}
