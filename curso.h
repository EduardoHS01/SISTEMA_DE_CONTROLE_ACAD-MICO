#ifndef CURSO_H
#define CURSO_H

extern struct CURSO *topoCurso;
extern struct CURSO *auxCurso;
extern struct CURSO *fimCurso;

extern int ultimoCodigoCurso;

struct CURSO
{
	int cod_curso;
	char nome_curso[30];
	int periodos;
	struct CURSO *proximo;
};

void CadastrarCurso();
void MenuCurso();
void ListarCursos();
void escrever_curso();
void ler_curso();
void criar_curso_arquivo(int codigo, char nome[], int periodos);
#endif











