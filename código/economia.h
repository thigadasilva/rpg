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
printf(" 1 - Po��es de vida pequenas: Pre�o: 50 moedas de ouro.       |   2 - Po��es de vida grandes: Pre�o: 75 moedas de ouro.  \n", medonho->pocaoHpMin, medonho->pocaoHpMax);
printf(" 3 - Po��es de energia pequenas: Pre�o: 50 moedas de ouro.    |  4 - Po��es de energia grandes: Pre�o: 75 moedas de ouro.  \n", medonho->pocaoEnergiaMin, medonho->pocaoEnergiaMax);
printf("ITENS:\n\n");
printf("5 - Clava de Ferro - Pre�o: 100 moedas de ouro.\n");
printf("6 - Tomo de Feiti�os - Pre�o: 150 moedas de ouro.\n");
printf("7 - Arco longo - Pre�o: 100 moedas de ouro.\n");
printf("8 - Adaga drac�nica - Pre�o: 100 moedas de ouro.\n");
printf("Voc� quer comprar po��es ou itens?(1 - Po��es / 2 - Itens)\n");
scanf("%d", &escolhaLoja);
if(escolhaLoja == 1){
	printf("O que voc� quer?\n");
	scanf("%d", &escolhaLoja2);
switch(escolhaLoja2){
	case 1:
		printf("Quantas po��es voc� quer?\n");
		scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("Voc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 50){
			personagem->potionsHpMin += choice ;
			printf("Voc� comprou %d po��es pequenas!\n", choice);
			choice * 50;
			choice -= personagem->moeda;
			imprimirAtributos(&personagem[0]);
			break;
			}
		}
	} else if(escolhaLoja == 2){
		printf("receba!");
	} else if (escolhaLoja != 1 || 2){
		printf("Op��o inv�lida!");
	}
}
