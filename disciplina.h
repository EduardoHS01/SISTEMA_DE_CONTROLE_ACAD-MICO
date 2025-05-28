#ifndef DISCIPLINA_H
#define DISCIPLINA_H

extern struct DISCIPLINA *topoDisciplina;
extern struct DISCIPLINA *auxDisciplina;
extern struct DISCIPLINA *fimDisciplina;

extern int ultimoCodigoDisciplina;

struct DISCIPLINA
{
	int cod_disciplina;
	char nome_disciplina[50];
	bool ativo;
	struct DISCIPLINA *proximo;
};

void CadastrarDisciplina();
void MenuDisciplina();
void ListarDisciplinas();
#endif











