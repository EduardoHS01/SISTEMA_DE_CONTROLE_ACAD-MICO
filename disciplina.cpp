#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "funcoesauxiliares.h"
#include "disciplina.h"

struct DISCIPLINA *topoDisciplina = NULL;
struct DISCIPLINA *auxDisciplina = NULL;
struct DISCIPLINA *fimDisciplina = NULL;

int ultimoCodigoDisciplina = 0;

void MenuDisciplina()
{
	int escolhaMenu;
	
	system("cls");
	printf("1 - Criar disciplina\n");
	printf("2 - Listar disciplinas\n");
	printf("3 - Gerenciar disciplina\n");
	printf("4 - Voltar \n");
	
	scanf("%d", &escolhaMenu);
	limparBuffer();
	
	switch(escolhaMenu)
	{
		case 1:
			CadastrarDisciplina();
			break;
		case 2:
			ListarDisciplinas();
			getchar();
			break;
		case 3:
			GerenciarDisciplina();
			break;
		case 4:
			return;
			break;
	}
	
};

void ListarDisciplinas()
{
	auxDisciplina = topoDisciplina;
	
	if(topoDisciplina == NULL)
	{
		printf("Nao ha nenhuma disciplina cadastrada");
	}
	
	while(auxDisciplina != NULL)
	{
		printf("Codigo: %d, Nome: %s, Ativo: %s\n",
		auxDisciplina->cod_disciplina,
		auxDisciplina->nome_disciplina,
		auxDisciplina->ativo ? "Sim" : "Nao");
		auxDisciplina = auxDisciplina->proximo;
	}
};

void CadastrarDisciplina()
{
	ultimoCodigoDisciplina++;
	
	auxDisciplina = (struct DISCIPLINA*)malloc(sizeof(struct DISCIPLINA));
	auxDisciplina->cod_disciplina = ultimoCodigoDisciplina;
	auxDisciplina->ativo = true;
	
	system("cls");
	char nomeDisciplina[50];
	printf("Qual o nome da disciplina?\n");
	scanf(" %50[^\n]", nomeDisciplina);
	converteMaiusculas(nomeDisciplina);
	strcpy(auxDisciplina->nome_disciplina, nomeDisciplina);
	limparBuffer();
	
	if(topoDisciplina == NULL)
	{
		topoDisciplina = auxDisciplina;
	}
	else
	{
		fimDisciplina->proximo = auxDisciplina;
	}
	auxDisciplina->proximo = NULL;
	fimDisciplina = auxDisciplina;
};

void GerenciarDisciplina(){
	system("cls");
	limparBuffer();
	int cdDisciplina = 0;
	
	ListarDisciplinas();
	
	if (topoDisciplina == NULL){
		getchar();
		return;
	}
	
	printf("\nInsira o codigo da disciplina a ser gerenciada\n");
	scanf("%d", &cdDisciplina);
	
	int encontrouDisciplina = localizaDisciplina(cdDisciplina);
	
	if (!encontrouDisciplina){
		printf("Disciplina nao localizada...");
		getchar();
		return;
	}
	
	system("cls");
	
	int escolha = 0;
	printf("1-Inativar/Ativar disciplina\n2-Editar nome da disciplina\n3-Voltar\n");
	scanf("%d", &escolha);
	limparBuffer();
	
	if (escolha == 1){
		auxDisciplina = topoDisciplina;
		while (auxDisciplina != NULL){
			if (auxDisciplina->cod_disciplina == cdDisciplina){
				if (auxDisciplina->ativo){
					auxDisciplina->ativo = false;
					printf("%s inativada com sucesso", auxDisciplina->nome_disciplina);
				} else {
					auxDisciplina->ativo = true;
					printf("%s ativada com sucesso", auxDisciplina->nome_disciplina);
				}
			}
			auxDisciplina = auxDisciplina->proximo;
		}
		getchar();
	} else if (escolha == 2) {
		limparBuffer();
		auxDisciplina = topoDisciplina;
		char novoNome[50];
		char nomeAntigo[50];
		while (auxDisciplina != NULL){
			if (auxDisciplina->cod_disciplina == cdDisciplina){
				printf("Insira o novo nome:\n");
				scanf("%s", novoNome);
				converteMaiusculas(novoNome);
				strcpy(nomeAntigo, auxDisciplina->nome_disciplina);
				strcpy(auxDisciplina->nome_disciplina, novoNome);
				
				printf("Nome antigo: %s\nNovo nome: %s\nAlterado com sucesso", nomeAntigo, auxDisciplina->nome_disciplina);
			}
			auxDisciplina = auxDisciplina->proximo;
		}
		limparBuffer();
		getchar();
	} else {
		return;
	}
}

bool localizaDisciplina(int cdDisciplina){
	bool encontrouDisciplina = false;
	auxDisciplina = topoDisciplina;
	while (auxDisciplina != NULL){
		if (auxDisciplina->cod_disciplina == cdDisciplina){
			encontrouDisciplina = true;
		}
		auxDisciplina = auxDisciplina->proximo;
	}
	
	if (encontrouDisciplina){
		return true;
	} else {
		return false;
	}
}

void escrever_disciplina()
{	
    FILE *file = fopen("DISCIPLINA.csv", "w");
    if (file == NULL) {
        perror("Error opening file");
    }
    fprintf(file, "Codigo,Nome,Ativo\n");
	
    FILE *arquivo = fopen("DISCIPLINA.csv", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    fclose(file);
	while (topoDisciplina!=NULL)
	{
		FILE *arquivo = fopen("DISCIPLINA.csv", "a");
	
	    if (arquivo == NULL) {
	        printf("Erro ao abrir o arquivo.\n");
	    }
		fprintf(arquivo,"%d,%s,%d\n",topoDisciplina->cod_disciplina,topoDisciplina->nome_disciplina,topoDisciplina->ativo);	

		topoDisciplina=topoDisciplina->proximo;
		fclose(arquivo);	
	}		
};


void ler_disciplina() {
    FILE *file = fopen("DISCIPLINA.csv", "r");
    char linha[256];
    int contador = 0;
    int erros = 0;
    if (fgets(linha, sizeof(linha), file) == NULL) {
        fclose(file);
        return;
    } 
    while (fgets(linha, sizeof(linha), file) != NULL) {
        linha[strcspn(linha, "\r\n")] = '\0';
        int codigo, ativo;
        char nome[50];
        
        int result = sscanf(linha, "%d,%50[^,],%d",
                            &codigo, nome, &ativo);
        
        if (result == 3) {
      	criar_displina_arquivo(codigo,nome,ativo);
        }
    }
    fclose(file);
};
void criar_displina_arquivo(int codigo, char nome[],bool ativo)
{	
	ultimoCodigoDisciplina++;
	
	auxDisciplina = (struct DISCIPLINA*)malloc(sizeof(struct DISCIPLINA));
	auxDisciplina->cod_disciplina = codigo;
	auxDisciplina->ativo = ativo;
	
	strcpy(auxDisciplina->nome_disciplina, nome);
	
	if(topoDisciplina == NULL)
	{
		topoDisciplina = auxDisciplina;
	}
	else
	{
		fimDisciplina->proximo = auxDisciplina;
	}
	auxDisciplina->proximo = NULL;
	fimDisciplina = auxDisciplina;
};












