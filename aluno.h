#ifndef ALUNO_H
#define ALUNO_H

struct ALUNO 
{
	int cod_aluno;
	char nome_aluno[50];
	char cpf[15];
	char data_nascimento[11];
	struct ALUNO *anterior;
	struct ALUNO *proximo;
	bool ativo;
};
int menu_aluno();
void imprimir_alunos();
void consultar_alunos();
void criar_novo_aluno();

#endif
