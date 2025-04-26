#ifndef TURMA_H
#define TURMA_H

struct TURMA	
{
	int id_turma;
	struct DISCIPLINA *disciplinas[2];
	struct ALUNO *alunos[2];
};


#endif
