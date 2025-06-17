#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "curso.h"
#include "funcoesauxiliares.h"

struct CURSO *topoCurso = NULL;
struct CURSO *auxCurso = NULL;
struct CURSO *fimCurso = NULL;

int ultimoCodigoCurso = 0;

void MenuCurso()
{
	int escolhaMenu;
	
	system("cls");
	printf("1 - Criar curso\n");
	printf("2 - Listar cursos\n");
	printf("3 - Gerenciar curso\n");
	printf("4 - Voltar \n");
	
	scanf("%d", &escolhaMenu);
	limparBuffer();
	
	switch(escolhaMenu)
	{
		case 1:
			CadastrarCurso();
			break;
		case 2:
			ListarCursos();
			getchar();
			break;
		case 3:
			GerenciarCurso();
			break;
		case 4:
			return;
			break;
	}
	
};

void ListarCursos()
{
	auxCurso = topoCurso;
	
	if(topoCurso == NULL)
	{
		printf("Nao ha nenhum curso cadastrado");
	}
	
	while(auxCurso != NULL)
	{
		printf("Codigo: %d, Nome: %s, Quantidade de periodos: %d\n",
		auxCurso->cod_curso,
		auxCurso->nome_curso,
		auxCurso->periodos);
		auxCurso = auxCurso->proximo;
	}
};

void CadastrarCurso()
{
	limparBuffer();
	ultimoCodigoCurso++;
	
	auxCurso = (struct CURSO*)malloc(sizeof(struct CURSO));
	auxCurso->cod_curso = ultimoCodigoCurso;
	
	system("cls");
	char nomeCurso[50];
	printf("Qual o nome do curso?\n");
	scanf(" %50[^\n]", nomeCurso);
	converteMaiusculas(nomeCurso);
	strcpy(auxCurso->nome_curso, nomeCurso);
	limparBuffer();
	printf("Quantos periodos tem o curso?\n");
	scanf("%d", &auxCurso->periodos);
	limparBuffer();
	
	if(topoCurso == NULL)
	{
		topoCurso = auxCurso;
	}
	else
	{
		fimCurso->proximo = auxCurso;
	}
	auxCurso->proximo = NULL;
	fimCurso = auxCurso;
};

void GerenciarCurso(){
	system("cls");
	limparBuffer();
	
	if (topoCurso == NULL){
		return;
	}
	
	int cdCurso = 0;
	
	ListarCursos();
	printf("\nInsira o codigo do curso a ser gerenciado\n");
	scanf("%d", &cdCurso);
	
	bool localizaCurso = localizarCurso(cdCurso);
	
	if (!localizaCurso){
		printf("Curso nao localizado");
		return;
	}
	
	system("cls");
	limparBuffer();
	
	int escolha = 0;
	printf("1-Editar nome do curso\n2-Editar numero de periodos\n3-Voltar\n");
	scanf("%d", &escolha);
	
	switch (escolha){
		case 1:
			char novoNome[50];
			auxCurso = topoCurso;
			printf("Insira o novo nome\n");
			scanf("%s", novoNome);
			while (auxCurso != NULL){
				if (auxCurso->cod_curso == cdCurso){
					char nomeAntigo[50];
					converteMaiusculas(novoNome);
					strcpy(nomeAntigo, auxCurso->nome_curso);
					strcpy(auxCurso->nome_curso, novoNome);
					limparBuffer();
					printf("Nome antigo: %s\nNovo nome: %s", nomeAntigo, auxCurso->nome_curso);
					getchar();
				}
				
				auxCurso = auxCurso->proximo;
			}
			break;
			
		case 2:
			int novoPeriodo = 0;
			int periodoAntigo = 0;
			auxCurso = topoCurso;
			while (auxCurso != NULL){
				if (auxCurso->cod_curso == cdCurso){
					printf("Insira a nova quantidade de periodos\n");
					scanf("%d", &novoPeriodo);
					periodoAntigo = auxCurso->periodos;
					auxCurso->periodos = novoPeriodo;
					limparBuffer();
					printf("Nome antigo: %s\nNovo nome: %s", periodoAntigo, auxCurso->periodos);
					getchar();
				}
				
				auxCurso = auxCurso->proximo;
			}
			break;
	}

}

bool localizarCurso(int cdCurso){
	bool encontrouCurso = false;
	auxCurso = topoCurso;
	while (auxCurso != NULL){
		if (auxCurso->cod_curso == cdCurso){
			encontrouCurso = true;	
		}
		auxCurso = auxCurso->proximo;
	}
	
	if (encontrouCurso){
		return true;
	} else {
		return false;
	}
}

void escrever_curso()
{
    FILE *file = fopen("CURSO.csv", "w");
    if (file == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }
    fprintf(file, "Codigo,Nome,Periodos\n");
    
    struct CURSO *atual = topoCurso;
    while (atual != NULL)
    {
        fprintf(file, "%d,%s,%d\n",
                atual->cod_curso,
                atual->nome_curso,
                atual->periodos);

        atual = atual->proximo;
    }
    fclose(file);
}

void ler_curso() {
    FILE *file = fopen("CURSO.csv", "r");
    if (file == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }
    
    char linha[256];
    // Ignora cabe?alho
    if (fgets(linha, sizeof(linha), file) == NULL) {
        fclose(file);
        return;
    } 
    
    while (fgets(linha, sizeof(linha), file) != NULL) {
        linha[strcspn(linha, "\r\n")] = '\0';
        int codigo, periodos;
        char nome[30];
        
        int result = sscanf(linha, "%d,%30[^,],%d",
                            &codigo, nome, &periodos);
        
        if (result == 3) {
            criar_curso_arquivo(codigo, nome, periodos);
        }
        else {
            printf("Erro ao ler linha: %s\n", linha);
        }
    }
    fclose(file);
}

void criar_curso_arquivo(int codigo, char nome[], int periodos)
{	
    auxCurso = (struct CURSO*)malloc(sizeof(struct CURSO));
    
    auxCurso->cod_curso = codigo;
    auxCurso->periodos = periodos;
    strncpy(auxCurso->nome_curso, nome, sizeof(auxCurso->nome_curso) - 1);
    auxCurso->nome_curso[sizeof(auxCurso->nome_curso) - 1] = '\0'; // Garante termina??o
    
    auxCurso->proximo = NULL;
    
    if(topoCurso == NULL) {
        topoCurso = auxCurso;
        fimCurso = auxCurso;
    }
    else {
        fimCurso->proximo = auxCurso;
        fimCurso = auxCurso;
    }
};













