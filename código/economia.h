typedef struct{
	int pocaoHpMin;
	int pocaoHpMax;
	int pocaoEnergiaMin;
	int pocaoEnergiaMax;
	int adaga;
	int clava;
	int tomo;
	int arco;
} Medonho;

void inicializarMedonho(Medonho *medonho) {
	medonho->pocaoHpMin = 4;
	medonho->pocaoHpMax = 4;
	medonho->pocaoEnergiaMin = 4;
	medonho->pocaoEnergiaMax = 4;
	medonho->adaga = 4;
	medonho->clava = 4;
	medonho->tomo = 4;
	medonho->arco = 4;	
}
void lojaMedonho(Medonho *medonho, Atributos *personagem){
	int escolhaLoja, escolhaLoja2, choice;
printf("===============================LOJA DO MEDONHO===============================\n");
printf(" 1 - Poções de vida pequenas: Preço: 50 moedas de ouro.       |   2 - Poções de vida grandes: Preço: 75 moedas de ouro.  \n", medonho->pocaoHpMin, medonho->pocaoHpMax);
printf(" 3 - Poções de energia pequenas: Preço: 50 moedas de ouro.    |  4 - Poções de energia grandes: Preço: 75 moedas de ouro.  \n", medonho->pocaoEnergiaMin, medonho->pocaoEnergiaMax);
printf("ITENS:\n\n");
printf("5 - Clava de Ferro - Preço: 100 moedas de ouro.\n");
printf("6 - Tomo de Feitiços - Preço: 150 moedas de ouro.\n");
printf("7 - Arco longo - Preço: 100 moedas de ouro.\n");
printf("8 - Adaga dracônica - Preço: 100 moedas de ouro.\n");
printf("Você quer comprar poções ou itens?(1 - Poções / 2 - Itens)\n");
scanf("%d", &escolhaLoja);
if(escolhaLoja == 1){
	printf("O que você quer?\n");
	scanf("%d", &escolhaLoja2);
switch(escolhaLoja2){
	case 1:
		printf("Quantas poções você quer?\n");
		scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("Você não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 50){
			personagem->potionsHpMin += choice ;
			printf("Você comprou %d poções pequenas!\n", choice);
			choice * 50;
			choice -= personagem->moeda;
			imprimirAtributos(&personagem[0]);
			break;
			}
		}
	} else if(escolhaLoja == 2){
		printf("receba!");
	} else if (escolhaLoja != 1 || 2){
		printf("Opção inválida!");
	}
}
