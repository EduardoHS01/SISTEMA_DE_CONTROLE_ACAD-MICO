Sistema de Gestão Acadêmica em C++
Este projeto é um sistema de gestão acadêmica desenvolvido em C++ que permite gerenciar alunos, professores, disciplinas, cursos, matrículas e desempenho acadêmico. O sistema utiliza listas encadeadas para armazenamento de dados e opera através de um menu interativo no terminal.

Instalação
Certifique-se de ter um compilador C++ instalado (ex: g++ no Linux, MinGW no Windows)

Clone o repositório ou baixe os arquivos fonte

Compile o projeto com o seguinte comando:

bash
g++ main.cpp curso.cpp disciplina.cpp cursoDisciplina.cpp matriculaCurso.cpp pessoa.cpp pessoaDisciplina.cpp desempenhoAlunoDisciplina.cpp funcoesauxiliares.cpp -o gestao_academica
Uso
Execute o programa compilado:

bash
./gestao_academica
O sistema apresentará um menu principal com as seguintes opções:

Alunos:

Cadastrar novos alunos

Listar alunos cadastrados

Gerenciar informações de alunos

Professores:

Cadastrar novos professores

Listar professores cadastrados

Gerenciar informações de professores

Disciplinas:

Cadastrar novas disciplinas

Listar disciplinas disponíveis

Cursos:

Cadastrar novos cursos

Listar cursos disponíveis

Curso-Disciplina:

Associar disciplinas a cursos

Listar associações existentes

Matrículas:

Matricular alunos em cursos

Listar matrículas existentes

Pessoa-Disciplina:

Associar pessoas (alunos/professores) a disciplinas

Listar associações existentes

Desempenho:

Cadastrar notas e faltas de alunos

Listar desempenhos acadêmicos

Sair: Encerra o programa salvando os dados

Exemplo de Fluxo
Cadastre alguns cursos e disciplinas

Associe disciplinas aos cursos (Menu 5)

Cadastre alunos e professores

Matricule alunos em cursos (Menu 6)

Associe alunos/professores a disciplinas (Menu 7)

Registre notas e faltas (Menu 8)

Estrutura de Dados
O sistema utiliza as seguintes estruturas principais:

CURSO: Gerencia cursos acadêmicos

DISCIPLINA: Gerencia disciplinas

CURSO_DISCIPLINA: Relaciona cursos com disciplinas

MATRICULA_CURSO: Gerencia matrículas de alunos em cursos

PESSOA: Gerencia alunos e professores

PESSOA_DISCIPLINA: Relaciona pessoas com disciplinas

DESEMPENHO_ALUNO_DISCIPLINA: Armazena notas e faltas

Persistência de Dados
Os dados são salvos automaticamente ao sair do programa nos seguintes arquivos CSV:

CURSO.csv

DISCIPLINA.csv

CURSO_DISCIPLINA.csv

MATRICULA_CURSO.csv

PESSOA.csv

PESSOA_DISCIPLINA.csv

DESEMPENHO.csv

Licença
Este projeto está licenciado sob a Licença MIT.

Contribuição
Contribuições são bem-vindas! Siga estas etapas:

Faça um fork do projeto

Crie uma branch para sua feature (git checkout -b feature/nova-feature)

Commit suas mudanças (git commit -m 'Adiciona nova feature')

Push para a branch (git push origin feature/nova-feature)

Abra um Pull Request

Badges
https://img.shields.io/badge/C++-17-blue.svg
https://img.shields.io/badge/License-MIT-yellow.svg

