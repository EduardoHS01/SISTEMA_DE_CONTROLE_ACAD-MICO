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
void criar_curso_disciplina_arquivo(int cod_curso_disciplina, int cod_curso, int cod_disciplina, int periodo);
void ler_curso_disciplina();
void escrever_curso_disciplina();
#endif
