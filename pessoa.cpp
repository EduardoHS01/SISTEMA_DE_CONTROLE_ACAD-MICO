#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <ctype.h>

#include "pessoa.h"
#include "funcoesauxiliares.h"

struct PESSOA *topoPessoa = NULL;
struct PESSOA *auxPessoa = NULL;
struct PESSOA *fimPessoa = NULL;

int ultimoCodigoPessoa = 0;

void buscarPessoa(bool tipo){
	limparBuffer();
	char nomeProcurado[50];
	printf("Digite o nome a ser consultado.\n");
	scanf("%50[^\n]", nomeProcurado);
	converteMaiusculas(nomeProcurado);
	
	struct PESSOA* pessoaEncontrado = pesquisaSequencial(nomeProcurado, tipo);
	
	if (pessoaEncontrado != NULL) {
        printf("Pessoa encontrada:\n");
        printf("Codigo: %d\n", pessoaEncontrado->cod_pessoa);
        printf("Nome: %s\n", pessoaEncontrado->nome_pessoa);
        printf("CPF: %s\n", pessoaEncontrado->cpf);
        printf("Data de Nascimento: %s\n", pessoaEncontrado->data_nascimento);
        printf("Ativo: %s\n", pessoaEncontrado->ativo ? "SIM" : "NAO");
    } else {
        printf("Pessoa com nome '%s' nao encontrada.\n", nomeProcurado);
    }
    
    limparBuffer();
    getchar();
}

struct PESSOA* pesquisaSequencial(const char* nomeBusca, bool tipo) {
    auxPessoa = topoPessoa;
    
    while (auxPessoa != NULL) {
        if (strstr(auxPessoa->nome_pessoa, nomeBusca) != NULL) {
            if (auxPessoa->professor == tipo){
            	return auxPessoa;
			}
        }
        auxPessoa = auxPessoa->proximo;
    }
    
    return NULL;
}

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
		printf("1 - Adicionar professor\n");
		printf("2 - Listar professores\n");
		printf("3 - Gerenciar professor\n");
		printf("4 - Buscar professor\n");
		printf("5 - Voltar \n");
		
		scanf("%d", &escolhaMenu);
		limparBuffer();
		
		switch(escolhaMenu)
		{
			case 1:
				CriarPessoa(true);
				break;
			case 2:
				ListarPessoas(true);
				getchar();
				break;
			case 3:
				GerenciarPessoa(true);
				break;
			case 4:
				buscarPessoa(true);
				break;
			case 5:
				return;
		}
		
	}else
	{
		system("cls");
		printf("1 - Adicionar aluno\n");
		printf("2 - Listar alunos\n");
		printf("3 - Gerenciar aluno\n");
		printf("4 - Buscar aluno\n");
		printf("5 - Voltar \n");
		
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
			case 3:
				GerenciarPessoa(false);
				break;
			case 4:
				buscarPessoa(false);
				break;
			case 5:
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
	char nome[50];
	printf("Nome completo:\n");
	scanf(" %50[^\n]", nome);
	converteMaiusculas(nome);
	strcpy(auxPessoa->nome_pessoa, nome);
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


void escrever_pessoa()
{	
    FILE *file = fopen("PESSOA.csv", "w");
    if (file == NULL) {
        perror("Error opening file");
    }
    fprintf(file, "Codigo,Nome,CPF,Data,Ativo,Professor\n");
	
    FILE *arquivo = fopen("PESSOA.csv", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    fclose(file);
	while (topoPessoa!=NULL)
	{
		FILE *arquivo = fopen("PESSOA.csv", "a");
	
	    if (arquivo == NULL) {
	        printf("Erro ao abrir o arquivo.\n");
	    }
		fprintf(arquivo,"%d,%s,%s,%s,%d,%d\n",topoPessoa->cod_pessoa,topoPessoa->nome_pessoa,topoPessoa->cpf, topoPessoa->data_nascimento,topoPessoa->ativo,topoPessoa->professor);	

		topoPessoa=topoPessoa->proximo;
		fclose(arquivo);	
	}		
};


void ler_pessoa() {
    FILE *file = fopen("PESSOA.csv", "r");
    char linha[256];
    int contador = 0;
    int erros = 0;
    if (fgets(linha, sizeof(linha), file) == NULL) {
        fclose(file);
        return;
    } 
    while (fgets(linha, sizeof(linha), file) != NULL) {
        linha[strcspn(linha, "\r\n")] = '\0';
        int codigo, ativo, professor;
        char nome[100], cpf[15], data[11];
        
        int result = sscanf(linha, "%d,%99[^,],%14[^,],%10[^,],%d,%d",
                            &codigo, nome, cpf, data, &ativo, &professor);
        
        if (result == 6) {
      	criar_pessoa_arquivo(codigo,nome,cpf,data,ativo,professor);
        }
    }
    fclose(file);
};

void criar_pessoa_arquivo(int codigo,char nome[],char cpf[],char data[],bool ativo,bool professor)
{	
	ultimoCodigoPessoa++;
	struct PESSOA *p = NULL;	
 
	p = (struct PESSOA*)malloc(sizeof(struct PESSOA));	
	p->proximo = NULL;

	p->cod_pessoa = codigo;
	strcpy(p->nome_pessoa,nome);
	strcpy(p->cpf,cpf);	
	strcpy(p->data_nascimento,data);
	p->ativo = ativo;
	p->professor = professor;	
	

	if(topoPessoa == NULL)
	{
		topoPessoa = p;
	}
	else
	{
		fimPessoa ->proximo = p;
	}
	fimPessoa = p;
	auxPessoa = topoPessoa;
};

void GerenciarPessoa(bool tipo){
	system("cls");
	
	if (topoPessoa == NULL){
		return;
	}
	
	if (tipo){
		ListarPessoas(tipo);
		printf("\nInsira o codigo do professor a ser gerenciado\n");
	} else {
		ListarPessoas(tipo);
		printf("\nInsira o codigo do aluno a ser gerenciado\n");
	}
	
	int cdPessoa = 0;
	scanf("%d", &cdPessoa);
	
	bool localizarPessoa = localizaPessoa(cdPessoa, tipo);
	
	if (!localizarPessoa){
		printf("%s nao localizado\n", tipo ? "Professor" : "Aluno");
		limparBuffer();
		getchar();
		return;
	}
	
	system("cls");
	
	int escolha = 0;
	
	if (tipo){
		printf("1-Inativar/Ativar professor\n2-Editar nome do professor\n3-Editar CPF do professor\n4-Editar data de nascimento do professor\n5-Voltar\n");
	} else {
		printf("1-Inativar/Ativar aluno\n2-Editar nome do aluno\n3-Editar CPF do aluno\n4-Editar data de nascimento do aluno\n5-Voltar\n");
	}
	
	scanf("%d", &escolha);
	limparBuffer();
	
	switch (escolha){
		case 1:
			auxPessoa = topoPessoa;
			while (auxPessoa != NULL){
				if (auxPessoa->cod_pessoa == cdPessoa){
					if (auxPessoa->ativo){
						auxPessoa->ativo = false;
						printf("%d - %s inativado com sucesso!", auxPessoa->cod_pessoa, auxPessoa->nome_pessoa);
					} else {
						auxPessoa->ativo = true;
						printf("%d - %s ativado com sucesso!", auxPessoa->cod_pessoa, auxPessoa->nome_pessoa);
					}
				}
				auxPessoa = auxPessoa->proximo;
			}
			getchar();
			break;	
		case 2:
			char novoNome[50];
			printf("Insira o novo nome\n");
			scanf("%50[^\n]", novoNome);
			limparBuffer();
			auxPessoa = topoPessoa;
			while (auxPessoa != NULL){
				if (auxPessoa->cod_pessoa == cdPessoa){
					char nomeAntigo[50];
					converteMaiusculas(novoNome);
					strcpy(nomeAntigo, auxPessoa->nome_pessoa);
					strcpy(auxPessoa->nome_pessoa, novoNome);
					limparBuffer();
					printf("Nome antigo: %s\nNovo nome: %s\nAlterado com sucesso", nomeAntigo, auxPessoa->nome_pessoa);
				}
				auxPessoa = auxPessoa->proximo;
			}
			getchar();
			break;
		case 3:
		    char novoCpf[14];
		    char cpfAntigo[14];
		    limparBuffer();
		    auxPessoa = topoPessoa;
		    while (auxPessoa != NULL){
		        if (auxPessoa->cod_pessoa == cdPessoa){
		            do {
		                fflush(stdin);
		                printf("Insira o novo CPF (formato xxx.xxx.xxx-xx)\n");
		                scanf("%s", novoCpf);
		                limparBuffer();
		                strcpy(cpfAntigo, auxPessoa->cpf);
		                if (!validar_cpf_formatado(novoCpf)) {
		                    printf("CPF invalido! Tente novamente no formato xxx.xxx.xxx-xx.\n");
		                }
		            } while (!validar_cpf_formatado(novoCpf));
		            strcpy(auxPessoa->cpf, novoCpf);
		            printf("CPF antigo: %s\nNovo CPF: %s\nAlterado com sucesso", cpfAntigo, auxPessoa->cpf);
		            break;
		        }
		        auxPessoa = auxPessoa->proximo;
		    }
		    getchar();
		    break;
		case 4:
			char dataAntiga[14];
		    char novaData[14];
		    limparBuffer();
		    auxPessoa = topoPessoa;
		    while (auxPessoa != NULL){
		        if (auxPessoa->cod_pessoa == cdPessoa){
		            do {
		                fflush(stdin);
		                printf("Insira a nova data (formato dd/mm/aaaa)\n");
		                scanf("%s", novaData);
		                limparBuffer();
		                strcpy(dataAntiga, auxPessoa->data_nascimento);
		                if (!validar_data_formatada(novaData)) {
		                    printf("Data invalida! Tente novamente no formato dd/mm/aaaa.\n");
		                }
		            } while (!validar_data_formatada(novaData));
		            strcpy(auxPessoa->data_nascimento, novaData);
		            printf("Data de nascimento antiga: %s\nNova data de nascimento: %s\nAlterada com sucesso", dataAntiga, auxPessoa->data_nascimento);
		            break;
		        }
		        auxPessoa = auxPessoa->proximo;
		    }
		    getchar();
		    break;
		case 5:
			break;
		default:
			printf("Selecione uma opcao disponivel...");
			break;
		}
}

bool localizaPessoa(int cdPessoa, bool tipo){
	bool encontrouPessoa = false;
	auxPessoa = topoPessoa;
	while (auxPessoa != NULL){
		if (auxPessoa->cod_pessoa == cdPessoa){
			if (auxPessoa->professor == tipo){
				encontrouPessoa = true;
			}
				
		}
		auxPessoa = auxPessoa->proximo;
	}
	
	if (encontrouPessoa){
		return true;
	} else {
		return false;
	}
}


















