#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "personagem.h" // dados do personagem

// Atributos:

int main(){
setlocale(LC_ALL, "Portuguese");
	
	Atributos personagem[1];

	int classe, i;
	int letras = 0;
	
	printf("Bem vindo a sua próxima aventura! Vamos criar o seu personagem!\n");
	// Verificação se o nome tem mais de 15 letras
	do{
	printf("Insira seu nome:\n");
	gets(personagem[0].nome);
	letras = strlen(personagem[0].nome);
		if(letras > 15){
			printf("\nNão é possível inserir um nome com mais de 15 letras.\n");	
		}
	} while(letras > 15);
	// Escolha de Classe
	inicializarPersonagens(&personagem, 0);
	printf("\nHora de escolher a sua classe, %s!\n", personagem[0].nome);
	printf("\nEscolha uma das classes a seguir:\n1 - Guerreiro - Altos níveis de Força e vida iniciais.\n");
	printf("2 - Mago - Altos níveis de Inteligência iniciais.\n");
	printf("3 - Arqueiro - Altos níveis de Destreza iniciais.\n");
	printf("4 - Ladrão - Altos níveis de Destreza e força iniciais.\n\n");
	scanf("%d", &classe);
	
	switch(classe){
		case 1: 
			printf("\n  Guerreiro!\n");
			personagem[i].iforca = 10;
			personagem[i].ivida = 20;
			personagem[i].iinteligencia = 0;
			personagem[i].idestreza = 5;
			personagem[i].xp = 0;
			personagem[i].nivel = 1;
			break;
		case 2:
			printf("\n  Feiticeiro! \n");
			personagem[i].iforca = 0;
			personagem[i].ivida = 20;
			personagem[i].iinteligencia = 10;
			personagem[i].idestreza = 0;
			personagem[i].xp = 0;
			personagem[i].nivel = 1;
			break;
		case 3:
			printf("\n  Arqueiro!\n");
			personagem[i].iforca = 0;
			personagem[i].ivida = 20;
			personagem[i].iinteligencia = 0;
			personagem[i].idestreza = 10;
			personagem[i].xp = 0;
			personagem[i].nivel = 1;
			break;
		case 4:
			printf("\n  Ladino!\n");
			personagem[i].iforca = 5;
			personagem[i].ivida = 20;
			personagem[i].iinteligencia = 0;
			personagem[i].idestreza = 10;
			personagem[i].xp = 0;
			personagem[i].nivel = 0;
			break;	
	}

for(int i = 0; i < 1; i++){
	printf("\n-------------------------------ATRIBUTOS INICIAIS-------------------------------\n");
	printf("|  Força: %d\n", personagem[0].iforca);
	printf("|  Destreza: %d\n", personagem[0].idestreza);
	printf("|  Vida: %d\n", personagem[0].ivida);
	printf("|  Inteligência: %d\n", personagem[0].iinteligencia);
}

	return 0;
}
