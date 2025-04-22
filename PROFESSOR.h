#ifndef ALUNO_H
#define ALUNO_H

int cod_aluno = 0;

struct PROFESSOR 
{
	int cod_professor;
	char nome_professor[50];
	char cpf[11];
	char data_nascimento[8];
	struct PROFESSOR *anterior;
	struct PROFESSOR *proximo;
};

#endif
