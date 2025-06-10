#ifndef DESEMPENHOALUNODISCIPLINA_H
#define DESEMPENHOALUNODISCIPLINA_H

extern struct DESEMPENHO_ALUNO_DISCIPLINA *topoDesempenhoAlunoDisciplina;
extern struct DESEMPENHO_ALUNO_DISCIPLINA *auxDesempenhoAlunoDisciplina;
extern struct DESEMPENHO_ALUNO_DISCIPLINA *fimDesempenhoAlunoDisciplina;
extern int ultimoCodigoDesempenhoAlunoDisciplina;

struct DESEMPENHO_ALUNO_DISCIPLINA {
    int cod_desempenho;
    int cod_pessoa_disciplina;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    int faltas;
    bool aprovacao;
    struct DESEMPENHO_ALUNO_DISCIPLINA *proximo;
};

void MenuDesempenhoAlunoDisciplina();
void CadastrarDesempenhoAlunoDisciplina();
void ListarDesempenhosAlunoDisciplina();
void CalcularAprovacao(DESEMPENHO_ALUNO_DISCIPLINA* desempenho);
void criar_desempenho_arquivo(int cod_desempenho, int cod_pessoa_disciplina, float nota1, float nota2, float nota3, float nota4, int faltas, bool aprovacao);
void ler_desempenho();
void escrever_desempenho();

#endif
