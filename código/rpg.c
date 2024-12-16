#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "personagem.h" 
#include "monstro.h"
#include "batalhas.h"
#include "economia.h"
#include "economia2.h"
#include "biofa.h"
#include "Fobia.h"
#include "marciosupervilao.h"



int main(){
setlocale(LC_ALL, "Portuguese");
srand(time(NULL));
Monstro monstro = criarMonstrosRandom();
	
	Atributos personagem[1];
	Medonho medonho;
	Medonho2 Medonho2;
	int classe;
	int letras = 0, i = 0;;
	do{
	printf("Bem vindo a sua próxima aventura! Vamos criar o seu personagem!\n\n");
	printf("Insira seu nome:\n");
	gets(personagem[0].nome);
	letras = strlen(personagem[0].nome);
		if(letras > 15){
			printf("\nNão é possível inserir um nome com mais de 15 letras.\n");	
		}
	} while(letras > 15);

	inicializarPersonagens(&personagem[0]);
	printf("\nHora de escolher a sua classe, %s!\n", personagem[0].nome);
	printf("\nEscolha uma das classes a seguir:\n1 - Guerreiro - Altos níveis de Força e vida iniciais.\n");
	printf("2 - Mago - Altos níveis de Inteligência iniciais.\n");
	printf("3 - Arqueiro - Altos níveis de Destreza iniciais.\n");
	printf("4 - Ladino - Altos níveis de Destreza e Agilidade iniciais.\n\n");
	scanf("%d", &classe);

	switch(classe){
		case 1: 
			printf("\n  Guerreiro!\n");
			strcpy(personagem[i].classe, "Guerreiro");
			personagem[i].iforca = 12;
			personagem[i].ivida = 28;
			personagem[i].ienergia = 60;
			personagem[i].iagilidade = 8;
			personagem[i].iinteligencia = 4;
			personagem[i].idestreza = 6;
			personagem[i].xp = 0;
			personagem[i].nivel = 1;
			break;
		case 2:
			printf("\n  Mago! \n");
			strcpy(personagem[i].classe, "Mago");
			personagem[i].iforca = 4;
			personagem[i].ivida = 20;
			personagem[i].ienergia = 70;
			personagem[i].iagilidade = 6;
			personagem[i].iinteligencia = 12;
			personagem[i].idestreza = 8;
			personagem[i].xp = 0;
			personagem[i].nivel = 1;
			break;
		case 3:
			printf("\n  Arqueiro!\n");
			strcpy(personagem[i].classe, "Arqueiro");
			personagem[i].iforca = 8;
			personagem[i].ivida = 20;
			personagem[i].ienergia = 50;
			personagem[i].iagilidade = 8;
			personagem[i].iinteligencia = 6;
			personagem[i].idestreza = 14;
			personagem[i].xp = 0;
			personagem[i].nivel = 1;
			break;
		case 4:
			printf("\n  Ladino!\n");
			strcpy(personagem[i].classe, "Ladino");
			personagem[i].iforca = 8;
			personagem[i].ivida = 20;
			personagem[i].ienergia = 50;
			personagem[i].iagilidade = 12;
			personagem[i].iinteligencia = 8;
			personagem[i].idestreza = 10;
			personagem[i].xp = 0;
			personagem[i].nivel = 1;
			break;	
		default:
			printf("Opção inválida!");
			return 0;
			break;
	}




system("cls");

imprimirAtributos(&personagem[0]);



printf("\n\n Voce está adiante da Montanha Dedo de Deus, uma fortaleza inexpugnável.\n");
printf(" Márcio, outrora um herói, agora comandante das forças sombrias, aguarda no topo.\n");
printf(" Sua missão: derrotá-lo e restaurar a paz...\n\n");
getch();
printf("* Você caminhou até a entrada da montanha, há uma silhueta de um senhor encapuzado e misterioso. Ele aguarda ansioso por você.\n");
getch();
switch(classe){
		case 1: 
		printf("\n  Senhor misterioso: Vejo que você é bem parrudo não é mesmo? Provavelmente é um Guerreiro...\n");
			break;
		case 2:
		printf("\n  Senhor misterioso: Vejo uma grande reserva de magia em você. Você é um mestre das artes mágicas, não é?\n");
			break;
		case 3:
		printf("\n  Senhor misterioso: Seus olhos são bem atentos não é mesmo? Imagino que você seja um atirador.\n");
			break;
		case 4:
		printf("\n  Senhor misterioso: Porque vem na ponta do pé? por acaso tem segundas intenções?\n");
			break;	
}
getch();
printf("\n Senhor misterioso: caro guerreiro, a Sua jornada será forjada por calorosas lutas, antes da verdadeira batalha,\n");
getch();
printf(" O destino do mundo aguarda, mas o caminho está infestado dos demais diversos perigos, mortais para civis comuns.\n");
getch();
printf(" Quem você está buscando, está sentado no Topo da montanha, esperando guerreiros formidáveis para enfrenta-lo...");
getch();
printf("\n Não quero tomar mais o seu tempo, siga adiante Heroi, e salve o mundo!\n");
getch();
printf("\n\n* Você escuta o conselho do senhor misterioso atentamente, e continua o caminho...\n\n");

getch();
system("cls");


imprimirAtributos(&personagem[0]);
imprimirMonstro(&monstro);

iniciarbatalha(classe, &personagem[0], &monstro);
check(personagem);
getch();
system("cls");

imprimirAtributos(&personagem[0]);

printf("\n\n*  Após a batalha, você olha para a frente e vê belos cristais. Você tem um pressentimento ruim.\n");
getch();
monstro = criarMonstrosRandom();
imprimirMonstro(&monstro);
iniciarbatalha(classe, &personagem[0], &monstro);
check(personagem);
getch();
system("cls");
imprimirAtributos(&personagem[0]);

printf("\n\n*  Próxima dos cristais, você observa a entrada para uma caverna. Você entra na mesma.\n");
getch();
monstro = criarMonstrosRandom();
imprimirMonstro(&monstro);
iniciarbatalha(classe, &personagem[0], &monstro);
check(personagem);
getch();
system("cls");
imprimirAtributos(&personagem[0]);

printf("\n\n*  Você consegue sentir uma presença mais a frente\n Uma figura já vista antes. ");
printf("\n\n Senhor Misterioso: Aproxime-se Heroi, tenho artefatos que irão te interessar.\n");
printf(" Medonho: Esqueci meu nome há tempos,de onde eu venho, me chamam de Medonho, por algum motivo...");
getch();
printf("\n Medonho: Tenho poções e itens que podem te fortalecer para a luta que encontrará mais em frente.\n");
printf(" Medonho: Porém sugiro que compre somente os itens que irão te beneficiar.\n Caso contrário, tenho certeza que sofrerá.\n");
printf(" Medonho: Aproxime-se e escolha com sabedoria.\n\n");
inicializarMedonho(&medonho);
lojaMedonho(&medonho, &personagem[0]);
verificarItem(&personagem[0]);
getch();

imprimirAtributos(&personagem[0]);

printf("\nVejo que está bem mais forte, deve ser capaz de enfrentar o que está pela frente.\n");
printf("Boa sorte.\n\n");

printf("* Você consegue ver uma entrada mais adiante.\n Você entra câmara adentro e é esmagado por uma presença poderosa.\n");

Boss boss = criarBoss();
imprimirIntroBiofa();
imprimirBoss(&boss);
iniciarBatalhaContraBoss(classe, &personagem[0], &boss);
check(personagem);
imprimirAtributos(&personagem[0]);

getch();
monstro = criarMonstrosRandom();
imprimirMonstro(&monstro);
iniciarbatalha(classe, &personagem[0], &monstro);
check(personagem);
getch();
system("cls");

imprimirAtributos(&personagem[0]);
getch();
monstro = criarMonstrosRandom();
imprimirMonstro(&monstro);
iniciarbatalha(classe, &personagem[0], &monstro);
check(personagem);
getch();
system("cls");

imprimirAtributos(&personagem[0]);
getch();
monstro = criarMonstrosRandom();
imprimirMonstro(&monstro);
iniciarbatalha(classe, &personagem[0], &monstro);
check(personagem);
getch();
system("cls");

imprimirAtributos(&personagem[0]);
printf("\nMedonho: Oh, está muito, muito mais forte do que antes.\n");
printf("\nMedonho: Suas armas parecem enfraquecidas.\n");
printf("\nMedonho: Deixe-me cuidar disso para você, tenho mais poções também.\n");
inicializarMedonho2(&Medonho2);
lojaMedonho2(&Medonho2, &personagem[0]);
getch();

imprimirAtributos(&personagem[0]);
printf("\nMedonho: Mais a frente, o criador de Biofa te aguarda.\n");
printf("\nMedonho: Ouvi dizer que ele é muito mais forte que Biofa, sua criação.\n");
printf("\nMedonho: Inclusive, ele está muito irritado contigo. Prepare-se.\n");

HabilidadeFobia habilidades[2] = {escudoDeEnergia, ataqueCibernetico};
Boss2 boss2 = criarBoss2(habilidades);
imprimirIntroFobia();
imprimirBoss2(&boss2);
iniciarBatalhaContraBoss2(classe, &personagem[0], &boss2);
check(personagem);
imprimirAtributos(&personagem[0]);

getch();
monstro = criarMonstrosRandom();
imprimirMonstro(&monstro);
iniciarbatalha(classe, &personagem[0], &monstro);
check(personagem);
getch();
system("cls");

imprimirAtributos(&personagem[0]);
getch();
monstro = criarMonstrosRandom();
imprimirMonstro(&monstro);
iniciarbatalha(classe, &personagem[0], &monstro);
check(personagem);
getch();
system("cls");

imprimirAtributos(&personagem[0]);
getch();
monstro = criarMonstrosRandom();
imprimirMonstro(&monstro);
iniciarbatalha(classe, &personagem[0], &monstro);
check(personagem);
getch();
system("cls");

 inicializarMedonho2(&Medonho2);
 lojaMedonho2(&Medonho2, &personagem[0]);
 getch();
 
 HabilidadeMarcio habilidadesM[3] = {MaodaPerdicao, PactodoDemonio, Ambicaodiabolica};
 Boss3 boss3 = criarboss3(habilidadesM);
 imprimirIntroMarcio();
 imprimirDialogoMarcio();
 imprimirBoss3(&boss3);
 iniciarBatalhaContraBoss3(classe, personagem, &boss3);

return 0;
}
