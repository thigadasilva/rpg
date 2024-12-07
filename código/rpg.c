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
	
	printf("Bem vindo a sua pr�xima aventura! Vamos criar o seu personagem!\n");
	// Verifica��o se o nome tem mais de 15 letras
	do{
	printf("Insira seu nome:\n");
	gets(personagem[0].nome);
	letras = strlen(personagem[0].nome);
		if(letras > 15){
			printf("\nN�o � poss�vel inserir um nome com mais de 15 letras.\n");	
		}
	} while(letras > 15);
	// Escolha de Classe
	inicializarPersonagens(&personagem, 0);
	printf("\nHora de escolher a sua classe, %s!\n", personagem[0].nome);
	printf("\nEscolha uma das classes a seguir:\n1 - Guerreiro - Altos n�veis de For�a e Constitui��o iniciais.\n");
	printf("2 - Mago - Altos n�veis de Intelig�ncia e Percep��o iniciais.\n");
	printf("3 - Engenheiro - Altos n�veis de Intelig�ncia e Destreza iniciais.\n");
	printf("4 - Ladr�o - Altos n�veis de Agilidade, Destreza e Carisma iniciais.\n\n");
	scanf("%d", &classe);
	
	switch(classe){
		case 1: 
			for(i = 1; i <= 7; i++){
				printf("|\n");	
			};
			break;
		case 2:
			printf("\nFeiticeiro! \n");
			break;
		case 3:
			printf("\nEngenheiro!\n");
			break;
		case 4:
			printf("\nLadr�o!\n");
			break;	
	}

for(int i = 0; i < 1; i++){
	printf("For�a: %d\n", personagem[0].iforca);
	printf("Destreza: %d\n", personagem[0].idestreza);
	printf("Vida: %d\n", personagem[0].ivida);
	printf("Intelig�ncia: %d\n", personagem[0].iinteligencia);
}

	return 0;
}
