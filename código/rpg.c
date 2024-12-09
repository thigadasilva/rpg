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

	int classe, i = 0;
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
	inicializarPersonagens(&personagem[0]);
	printf("\nHora de escolher a sua classe, %s!\n", personagem[0].nome);
	printf("\nEscolha uma das classes a seguir:\n1 - Guerreiro - Altos níveis de Força e vida iniciais.\n");
	printf("2 - Mago - Altos níveis de Inteligência iniciais.\n");
	printf("3 - Arqueiro - Altos níveis de Destreza iniciais.\n");
	printf("4 - Ladrão - Altos níveis de Destreza e força iniciais.\n\n");
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
			personagem[i].idestreza = 0;
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
			personagem[i].iforca = 5;
			personagem[i].ivida = 20;
			personagem[i].iagilidade = 10;
			personagem[i].iinteligencia = 0;
			personagem[i].idestreza = 8;
			personagem[i].xp = 0;
			personagem[i].nivel = 1;
			break;	
	}

system("cls");

imprimirAtributos(&personagem[0]);



printf("\n\n  De frente para o Dedo de Deus, reflito sobre tudo que aquele traste me fez. Agora, ele sofrerá com as consequências.");
printf("\n  Márcio se encontra no topo do Dedo de Deus, protegido por seus serviçais.");
printf("\n  Sem mais demora, ele vai morrer.\n\n");
getch();
printf("* Você caminhou até a entrada da montanha, há um elemento presente. Ele aguarda ansioso por você.\n");
getch();
switch(classe){
		case 1: 
		printf("\n  Velhote misterioso: Vejo que você é bem parrudo não é mesmo? Provavelmente é um Guerreiro...\n");
			break;
		case 2:
		printf("\n  Velhote misterioso: Vejo uma grande reserva de magia em você. Você é um conhecedor das artes das trevas não é mesmo?\n");
			break;
		case 3:
		printf("\n  Velhote misterioso: Seus olhos são bem atentos não é mesmo? Imagino que você seja um atirador.\n");
			break;
		case 4:
		printf("\n  Velhote misterioso: Porque vem na ponta do pé? por acaso tem segundas intenções?\n");
			break;	
}
printf("  Velhote misterioso: Tanto faz, o importante é: Há monstros dificeis pelo caminho que enfrentará.\n  Quem você procura está no topo desta montanha.\n");
printf("  Velhote misterioso: Só mais uma coisa: Há seres poderosos aqui, para enfrentá-los, recomendo que visite Medonho, ele tem artigos que serão úteis e costuma acampar próximo destes seres.");
	return 0;
}
