#ifndef PESSOA_H
#define PESSOA_H

extern struct PESSOA *topoPessoa;
extern struct PESSOA *auxPessoa;
extern struct PESSOA *fimPessoa;

extern int ultimoCodigoPessoa;

struct PESSOA
{
	struct PESSOA *anterior;
	int cod_pessoa;
	char nome_pessoa[50];
	char cpf[15];
	char data_nascimento[11];
	bool ativo;
	bool professor; //1 = professor, 0 = aluno
	struct PESSOA *proximo;
};

void MenuPessoa(bool tipo); 
void CriarPessoa(bool tipo);
bool validar_cpf_formatado(const char *cpf);
bool validar_data_formatada(const char *data);
void ListarPessoas(bool tipo);
void ListarTodasPessoas();

#endif
