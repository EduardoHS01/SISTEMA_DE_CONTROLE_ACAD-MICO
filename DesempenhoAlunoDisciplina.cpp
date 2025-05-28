#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pessoaDisciplina.h"
#include "desempenhoAlunoDisciplina.h"
#include "funcoesauxiliares.h"
#include "pessoa.h"
#include "curso.h"
#include "cursoDisciplina.h"
#include "disciplina.h"

struct DESEMPENHO_ALUNO_DISCIPLINA *topoDesempenhoAlunoDisciplina = NULL;
struct DESEMPENHO_ALUNO_DISCIPLINA *auxDesempenhoAlunoDisciplina = NULL;
struct DESEMPENHO_ALUNO_DISCIPLINA *fimDesempenhoAlunoDisciplina = NULL;
int ultimoCodigoDesempenhoAlunoDisciplina = 0;

void MenuDesempenhoAlunoDisciplina() {
    int escolhaMenu;
    
    system("cls");
    printf("1 - Cadastrar desempenho do aluno OK\n");
    printf("2 - Listar todos os desempenhos OK\n");
    printf("3 - Voltar\n");
    
    scanf("%d", &escolhaMenu);
    limparBuffer();
    
    switch(escolhaMenu) {
        case 1:
            CadastrarDesempenhoAlunoDisciplina();
            break;
        case 2:
            ListarDesempenhosAlunoDisciplina();
            break;
        case 3:
            return;
    }
}

void CadastrarDesempenhoAlunoDisciplina() {
	auxPessoaDisciplina = topoPessoaDisciplina;
	auxPessoa = topoPessoa;
	bool alunosCadastrados = false;
	
	while (auxPessoaDisciplina != NULL && !alunosCadastrados)
	{
		auxPessoa = topoPessoa;
		while(auxPessoa != NULL && !alunosCadastrados)
		{
			if(!auxPessoa->professor)
			{
				alunosCadastrados = true;
			}
		}
	}
	
    if(!alunosCadastrados) {
        printf("Nao ha relacoes aluno-disciplina cadastradas!\n");
        getchar();
        return;
    }
    
    ultimoCodigoDesempenhoAlunoDisciplina++;
    
    auxDesempenhoAlunoDisciplina = (DESEMPENHO_ALUNO_DISCIPLINA*) malloc(sizeof(DESEMPENHO_ALUNO_DISCIPLINA));
    auxDesempenhoAlunoDisciplina->cod_desempenho = ultimoCodigoDesempenhoAlunoDisciplina;
    
    if(topoDesempenhoAlunoDisciplina == NULL) {
        topoDesempenhoAlunoDisciplina = auxDesempenhoAlunoDisciplina;
    } else {
        fimDesempenhoAlunoDisciplina->proximo = auxDesempenhoAlunoDisciplina;
    }
    auxDesempenhoAlunoDisciplina->proximo = NULL;
    fimDesempenhoAlunoDisciplina = auxDesempenhoAlunoDisciplina;
    
    printf("Selecione a relacao aluno-disciplina:\n");
    ListarPessoaDisciplinaAlunos();
    scanf("%d", &auxDesempenhoAlunoDisciplina->cod_pessoa_disciplina);
    limparBuffer();
    
    printf("Digite a nota 1: ");
    scanf("%f", &auxDesempenhoAlunoDisciplina->nota1);
    limparBuffer();
    
    printf("Digite a nota 2: ");
    scanf("%f", &auxDesempenhoAlunoDisciplina->nota2);
    limparBuffer();
    
    printf("Digite a nota 3: ");
    scanf("%f", &auxDesempenhoAlunoDisciplina->nota3);
    limparBuffer();
    
    printf("Digite a nota 4: ");
    scanf("%f", &auxDesempenhoAlunoDisciplina->nota4);
    limparBuffer();
    
    printf("Digite o total de faltas: ");
    scanf("%d", &auxDesempenhoAlunoDisciplina->faltas);
    limparBuffer();
    
    CalcularAprovacao(auxDesempenhoAlunoDisciplina);
    
    printf("Desempenho cadastrado com sucesso!\n");
    getchar();
}

void CalcularAprovacao(DESEMPENHO_ALUNO_DISCIPLINA* desempenho) {
    float media = (desempenho->nota1 + desempenho->nota2 + desempenho->nota3 + desempenho->nota4) / 4;
    desempenho->aprovacao = (media >= 7.0 && desempenho->faltas <= 20);
}

void ListarDesempenhosAlunoDisciplina() {
    auxDesempenhoAlunoDisciplina = topoDesempenhoAlunoDisciplina;
    
    char nome_pessoa[50];
    char nome_disciplina[50];
    
    if(topoDesempenhoAlunoDisciplina == NULL) {
        printf("Nao ha desempenhos cadastrados!\n");
        getchar();
        return;
    }
    
    while(auxDesempenhoAlunoDisciplina != NULL) {
        auxPessoaDisciplina = topoPessoaDisciplina;
        while(auxPessoaDisciplina != NULL) {
            if(auxPessoaDisciplina->cod_pessoa_disciplina == auxDesempenhoAlunoDisciplina->cod_pessoa_disciplina) {
                auxPessoa = topoPessoa;
                while(auxPessoa != NULL) {
                    if(auxPessoa->cod_pessoa == auxPessoaDisciplina->cod_pessoa) {
                        strcpy(nome_pessoa, auxPessoa->nome_pessoa);
                        break;
                    }
                    auxPessoa = auxPessoa->proximo;
                }
                
                auxCursoDisciplina = topoCursoDisciplina;
                while(auxCursoDisciplina != NULL) {
                    if(auxCursoDisciplina->cod_curso_disciplina == auxPessoaDisciplina->cod_curso_disciplina) {
                        auxDisciplina = topoDisciplina;
                        while(auxDisciplina != NULL) {
                            if(auxDisciplina->cod_disciplina == auxCursoDisciplina->cod_disciplina) {
                                strcpy(nome_disciplina, auxDisciplina->nome_disciplina);
                                break;
                            }
                            auxDisciplina = auxDisciplina->proximo;
                        }
                        break;
                    }
                    auxCursoDisciplina = auxCursoDisciplina->proximo;
                }
                break;
            }
            auxPessoaDisciplina = auxPessoaDisciplina->proximo;
        }
        
        printf("Codigo: %d | Aluno: %s | Disciplina: %s\n", 
               auxDesempenhoAlunoDisciplina->cod_desempenho, nome_pessoa, nome_disciplina);
        printf("Notas: %.1f, %.1f, %.1f, %.1f | Faltas: %d | Situacao: %s\n\n",
               auxDesempenhoAlunoDisciplina->nota1, auxDesempenhoAlunoDisciplina->nota2,
               auxDesempenhoAlunoDisciplina->nota3, auxDesempenhoAlunoDisciplina->nota4,
               auxDesempenhoAlunoDisciplina->faltas,
               auxDesempenhoAlunoDisciplina->aprovacao ? "Aprovado" : "Reprovado");
        
        auxDesempenhoAlunoDisciplina = auxDesempenhoAlunoDisciplina->proximo;
    }
    getchar();
}
