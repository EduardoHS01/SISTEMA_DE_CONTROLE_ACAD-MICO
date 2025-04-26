#include "PROFESSOR.h"
#ifndef DISCIPLINA_H
#define DISCIPLINA_H

struct DISCIPLINA
{
	int cod_disciplina;
	char nome[20];
	struct PROFESSOR *professor;
	
};

#endif
