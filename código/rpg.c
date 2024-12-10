#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "personagem.h" // dados do personagem
#include "monstro.h"
#include "batalhas.h"
#include "economia.h"



// Atributos:

int main(){
setlocale(LC_ALL, "Portuguese");
srand(time(NULL));
Monstro monstro = criarMonstrosRandom();
	
	Atributos personagem[1];

	int classe;
	int letras = 0, i = 0;;
	
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
	inicializarPersonagens(&personagem[0]);
	printf("\nHora de escolher a sua classe, %s!\n", personagem[0].nome);
	printf("\nEscolha uma das classes a seguir:\n1 - Guerreiro - Altos n�veis de For�a e vida iniciais.\n");
	printf("2 - Mago - Altos n�veis de Intelig�ncia iniciais.\n");
	printf("3 - Arqueiro - Altos n�veis de Destreza iniciais.\n");
	printf("4 - Ladino - Altos n�veis de Destreza e for�a iniciais.\n\n");
	scanf("%d", &classe);
	
	switch(classe){
		case 1: 
			printf("\n  Guerreiro!\n");
			strcpy(personagem[i].classe, "Guerreiro");
			personagem[i].iforca = 10;
			personagem[i].ivida = 25;
			personagem[i].iagilidade = 0;
			personagem[i].iinteligencia = 0;
			personagem[i].idestreza = 5;
			personagem[i].xp = 0;
			personagem[i].nivel = 1;
			break;
		case 2:
			printf("\n  Mago! \n");
			strcpy(personagem[i].classe, "Mago");
			personagem[i].iforca = 0;
			personagem[i].ivida = 20;
			personagem[i].iagilidade = 0;
			personagem[i].iinteligencia = 10;
			personagem[i].idestreza = 5;
			personagem[i].xp = 0;
			personagem[i].nivel = 1;
			break;
		case 3:
			printf("\n  Arqueiro!\n");
			strcpy(personagem[i].classe, "Arqueiro");
			personagem[i].iforca = 0;
			personagem[i].ivida = 20;
			personagem[i].iagilidade = 5;
			personagem[i].iinteligencia = 0;
			personagem[i].idestreza = 10;
			personagem[i].xp = 0;
			personagem[i].nivel = 1;
			break;
		case 4:
			printf("\n  Ladino!\n");
			strcpy(personagem[i].classe, "Ladino");
			personagem[i].iforca = 0;
			personagem[i].ivida = 20;
			personagem[i].iagilidade = 10;
			personagem[i].iinteligencia = 0;
			personagem[i].idestreza = 8;
			personagem[i].xp = 0;
			personagem[i].nivel = 1;
			break;	
		default:
			printf("Op��o inv�lida!");
			break;
	}

system("cls");

imprimirAtributos(&personagem[0]);



printf("\n\n  De frente para o Dedo de Deus, reflito sobre tudo que aquele traste me fez. Agora, ele sofrer� com as consequ�ncias.");
printf("\n  M�rcio se encontra no topo do Dedo de Deus, protegido por seus servi�ais.");
printf("\n  Sem mais demora, ele vai morrer.\n\n");
getch();
printf("* Voc� caminhou at� a entrada da montanha, h� um elemento presente. Ele aguarda ansioso por voc�.\n");
getch();
switch(classe){
		case 1: 
		printf("\n  Senhor misterioso: Vejo que voc� � bem parrudo n�o � mesmo? Provavelmente � um Guerreiro...\n");
			break;
		case 2:
		printf("\n  Senhor misterioso: Vejo uma grande reserva de magia em voc�. Voc� � um conhecedor das artes das trevas n�o � mesmo?\n");
			break;
		case 3:
		printf("\n  Senhor misterioso: Seus olhos s�o bem atentos n�o � mesmo? Imagino que voc� seja um atirador.\n");
			break;
		case 4:
		printf("\n  Senhor misterioso: Porque vem na ponta do p�? por acaso tem segundas inten��es?\n");
			break;	
}
printf("  Senhor misterioso: Tanto faz, o importante �: H� monstros dificeis pelo caminho que enfrentar�.\n  Quem voc� procura est� no topo desta montanha.\n");
printf("  Senhor misterioso: S� mais uma coisa: H� seres poderosos aqui, para enfrent�-los, recomendo que visite Medonho. \n  Ele tem artigos que ser�o �teis e costuma acampar pr�ximo destes seres.\n");
getch();
printf("\n\n* Voc� ignora o coment�rio, e continua o caminho.\n\n");

imprimirMonstro(&monstro);


iniciarbatalha(classe, personagem[0], monstro);

	return 0;
}
