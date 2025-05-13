#ifndef PROFESSOR_H
#define PROFESSOR_H

struct PROFESSOR 
{
	char cpf[14];
	int cod_professor;
	char nome_professor[50];
	struct PROFESSOR *anterior;
	struct PROFESSOR *proximo;
	char data_nascimento[10];
};

int menu_professor();
void criar_novo_professor();

#endif
