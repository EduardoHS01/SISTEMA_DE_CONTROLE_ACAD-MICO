//##########################################################
//# Nome do Programa: Sistema de gestão acadêmico
//# Autores: Aline Lopes Ferreira, Eduardo Henrique da Silva e Giovane Gabriel do Nascimento
//# Data: 21/04/2025
//# Descricao: Executar as funcionalidades básicas de gestão para uma instituição acadêmica, como gerenciamento de individuos, atividades e gereção de relatórios de desempenho.
//##########################################################


#include "ALUNO.h"



int main() {
	
	struct ALUNO *topo = NULL;
	struct ALUNO *aux = NULL;
	struct ALUNO *fim = NULL;
	aux = criar_novo_aluno(topo, fim);
	topo = aux;
	imprimir_alunos(topo);


    getchar(); 

	
	
}


