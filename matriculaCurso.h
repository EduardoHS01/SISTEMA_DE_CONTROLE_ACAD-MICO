#ifndef MATRICULACURSO_H
#define MATRICULACURSO_H

extern struct MATRICULA_CURSO *topoMatriculaCurso;
extern struct MATRICULA_CURSO *auxMatriculaCurso;
extern struct MATRICULA_CURSO *fimMatriculaCurso;

extern int ultimoCodigoMatriculaCurso;

struct MATRICULA_CURSO
{
	int cod_matricula_curso;
	int cod_pessoa;
	int cod_curso;
	struct MATRICULA_CURSO *proximo;
};

void CadastrarMatriculaCurso();
void MenuMatriculaCurso();
void ListarMatriculaCursos();
#endif
