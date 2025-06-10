#ifndef PESSOADISCIPLINA_H
#define PESSOADISCIPLINA_H

extern struct PESSOA_DISCIPLINA *topoPessoaDisciplina;
extern struct PESSOA_DISCIPLINA *auxPessoaDisciplina;
extern struct PESSOA_DISCIPLINA *fimPessoaDisciplina;

extern int ultimoCodigoPessoaDisciplina;

struct PESSOA_DISCIPLINA
{
	int cod_pessoa_disciplina;
	int cod_pessoa;
	int cod_curso_disciplina;
	struct PESSOA_DISCIPLINA *proximo;
};

void CadastrarPessoaDisciplina();
void MenuPessoaDisciplina();
void ListarPessoaDisciplinas();
void ListarPessoaDisciplinaAlunos();
void escrever_pessoa_displina_arquivo();
void ler_pessoa_disciplina();
void criar_pessoa_displina_arquivo(int codigo, int cod_pessoa,int cod_pessoa_disciplina);
#endif
