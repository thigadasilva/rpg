#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

// Atributos:
typedef struct{
	char nome[16];
	int ipv;
	int iforca;
	int iconstituicao;
	int idestreza;
	int iagilidade;
	int iinteligencia;
	int ipercepcao;
	int icarisma;
	int xp;
	int nivel;
} atributos;

int main(){
setlocale(LC_ALL, "Portuguese");
	
	atributos personagem[1];
	// atribuindo atributos padr�es:

	for(int i = 0; i < 1; i++){
		personagem[1].ipv = 20;
		personagem[1].iforca = 0;
		personagem[1].iconstituicao = 0;
		personagem[1].idestreza = 0;
		personagem[1].iagilidade = 0;
		personagem[1].iinteligencia = 0;
		personagem[1].ipercepcao = 0;
		personagem[1].icarisma = 0;
		personagem[1].xp = 0;
		personagem[1].nivel = 0;
	}
	
	int classe, i;
	int letras = 0;
	
	printf("Bem vindo a sua pr�xima aventura! Vamos criar o seu personagem!\n");
	do{
	printf("Insira seu nome:\n");
	gets(personagem[1].nome);
	letras = strlen(personagem[1].nome);
		if(letras > 15){
			printf("\nN�o � poss�vel inserir um nome com mais de 15 letras.\n");	
		}
	} while(letras > 15);
	printf("\nHora de escolher a sua classe, %s!\n", personagem[1].nome);


	
	
	
	
	

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
	return 0;
}
