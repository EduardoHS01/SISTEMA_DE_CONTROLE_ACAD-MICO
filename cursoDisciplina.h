#ifndef CURSODISCIPLINA_H
#define CURSODISCIPLINA_H

extern struct CURSO_DISCIPLINA *topoCursoDisciplina;
extern struct CURSO_DISCIPLINA *auxCursoDisciplina;
extern struct CURSO_DISCIPLINA *fimCursoDisciplina;

extern int ultimoCodigoCursoDisciplina;

struct CURSO_DISCIPLINA
{
	int cod_curso_disciplina;
	int cod_curso;
	int cod_disciplina;
	int periodo;
	struct CURSO_DISCIPLINA *proximo;
};

void CadastrarCursoDisciplina();
void MenuCursoDisciplina();
void ListarCursoDisciplinas();
#endif
