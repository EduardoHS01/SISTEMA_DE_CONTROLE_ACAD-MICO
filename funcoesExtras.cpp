#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "aluno.h"
#include "professor.h"

char formatar_cpf_aluno(char cpf[11], struct ALUNO *fim){
		
	fim->cpf[0] = cpf[0];
	fim->cpf[1] = cpf[1];
	fim->cpf[2] = cpf[2];
	fim->cpf[3] = '.';
	fim->cpf[4] = cpf[3];
	fim->cpf[5] = cpf[4];
	fim->cpf[6] = cpf[5];
	fim->cpf[7] = '.';
	fim->cpf[9] = cpf[7];
	fim->cpf[8] = cpf[6];
	fim->cpf[10] = cpf[8];
	fim->cpf[12] = cpf[9];
	fim->cpf[11] = '-';
	fim->cpf[13] = cpf[10];
	fim->cpf[14] = '\0'; // termina a string
}

char formatar_data_aluno(char data[8], struct ALUNO *fim){
	
	fim->data_nascimento[0] = data[0];
	fim->data_nascimento[1] = data[1];
	fim->data_nascimento[2] = '/';
	fim->data_nascimento[3] = data[2];
	fim->data_nascimento[4] = data[3];
	fim->data_nascimento[5] = '/';
	fim->data_nascimento[6] = data[4];
	fim->data_nascimento[7] = data[5];
	fim->data_nascimento[8] = data[6];
	fim->data_nascimento[9] = data[7];
	fim->data_nascimento[10] = '\0';
}

char formatar_data_professor(char data[8], struct PROFESSOR *fim){
	
	fim->data_nascimento[0] = data[0];
	fim->data_nascimento[1] = data[1];
	fim->data_nascimento[2] = '/';
	fim->data_nascimento[3] = data[2];
	fim->data_nascimento[4] = data[3];
	fim->data_nascimento[5] = '/';
	fim->data_nascimento[6] = data[4];
	fim->data_nascimento[7] = data[5];
	fim->data_nascimento[8] = data[6];
	fim->data_nascimento[9] = data[7];
	fim->data_nascimento[10] = '\0';
}

char formatar_cpf_professor(char cpf[11], struct PROFESSOR *fim){
		
	fim->cpf[0] = cpf[0];
	fim->cpf[1] = cpf[1];
	fim->cpf[2] = cpf[2];
	fim->cpf[3] = '.';
	fim->cpf[4] = cpf[3];
	fim->cpf[5] = cpf[4];
	fim->cpf[6] = cpf[5];
	fim->cpf[7] = '.';
	fim->cpf[9] = cpf[7];
	fim->cpf[8] = cpf[6];
	fim->cpf[10] = cpf[8];
	fim->cpf[12] = cpf[9];
	fim->cpf[11] = '-';
	fim->cpf[13] = cpf[10];
	fim->cpf[14] = '\0'; // termina a string
}
