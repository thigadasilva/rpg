typedef struct{
	int pocaoHpMin;
	int pocaoHpMax;
	int pocaoEnergiaMin;
	int pocaoEnergiaMax;
} Medonho;

void inicializarMedonho(Medonho *medonho) {
	medonho->pocaoHpMin = 4;
	medonho->pocaoHpMax = 4;
	medonho->pocaoEnergiaMin = 4;
	medonho->pocaoEnergiaMax = 4;
}
void pocaoMedonho(Medonho *medonho, Atributos *personagem, int escolhaLoja2, int choice){
	switch(escolhaLoja2){
	case 1:
		printf("\nQuantas po��es voc� quer?\n");
		scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 50){
			personagem->potionsHpMin += choice ;
			printf("\nVoc� comprou %d po��es pequenas!\n", choice);
			choice * 50;
			choice -= personagem->moeda;
			break;
			}
	case 2:
			printf("\nQuantas po��es voc� quer?\n");
		scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 75){
			personagem->potionsHpMax += choice ;
			printf("\nVoc� comprou %d po��es grandes!\n", choice);
			choice * 90;
			choice -= personagem->moeda;
			break;
			}
	case 3:
			printf("\nQuantas po��es voc� quer?\n");
		scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 50){
			personagem->potionsEnergiaMin += choice ;
			printf("\nVoc� comprou %d po��es pequenas!\n", choice);
			choice * 50;
			choice -= personagem->moeda;
			break;
			}
	case 4:
			printf("\nQuantas po��es voc� quer?\n");
			scanf("%d", &choice);
			if(personagem->moeda <= 0){
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 75){
			personagem->potionsEnergiaMax += choice ;
			printf("\nVoc� comprou %d po��es grandes!\n", choice);
			choice * 90;
			choice -= personagem->moeda;
			break;
			}
	case 5:
	system("cls");
	lojaMedonho(medonho, personagem);
    break;
    default: 
    	printf("Op��o inv�lida!");
    	break;
		}
	}
	void itensMedonho(Medonho *medonho, Atributos *personagem, int escolhaLoja2, int choice){
		switch(escolhaLoja2){
	case 1:
		if(personagem->moeda <= 0){
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 100){
			personagem->clava += 1;
			printf("\nVoc� comprou Clava de Ferro!\n");
			personagem->moeda - 100;
			break;
			}
	case 2:
			if(personagem->moeda <= 0){
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 150){
			personagem->clava += 1;
			printf("\nVoc� comprou Tomo de Feiti�os!\n");
			personagem->moeda - 150;
			break;
			}
	case 3:
			if(personagem->moeda <= 0){
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 100){
			personagem->clava += 1;
			printf("\nVoc� comprou Arco Longo!\n");
			personagem->moeda - 100;
			break;
			}
	case 4:
			if(personagem->moeda <= 0){
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 100){
			personagem->clava += 1;
			printf("\nVoc� comprou Adaga negra!\n");
			personagem->moeda - 100;
			break;
			}
	case 5:
	system("cls");
	lojaMedonho(medonho, personagem);
    break;
    default:
    	printf("Op��o inv�lida!");
    	break;
		}
}

void lojaMedonho(Medonho *medonho, Atributos *personagem){
	int escolhaLoja, escolhaLoja2, choice;
printf("===============================LOJA DO MEDONHO===============================\n");
printf(" 1 - Po��es de vida pequenas: Pre�o: 50 moedas de ouro.       |   2 - Po��es de vida grandes: Pre�o: 90 moedas de ouro.  \n", medonho->pocaoHpMin, medonho->pocaoHpMax);
printf(" 3 - Po��es de energia pequenas: Pre�o: 50 moedas de ouro.    |  4 - Po��es de energia grandes: Pre�o: 90 moedas de ouro.  \n", medonho->pocaoEnergiaMin, medonho->pocaoEnergiaMax);
printf("\nITENS:\n\n");
printf("1 - Clava de ferro - Pre�o: 100 moedas de ouro.\n");
printf("2 - Tomo de feiti�os - Pre�o: 150 moedas de ouro.\n");
printf("3 - Arco longo - Pre�o: 100 moedas de ouro.\n");
printf("4 - Adaga negra - Pre�o: 100 moedas de ouro.\n");
printf("\nEscolha: (1 - Po��es / 2 - Itens/ 3 - Sair)\n");
scanf("%d", &escolhaLoja);
do {
  if(escolhaLoja == 1){
	printf("\n1 - Po��o de vida pequena / 2 - Po��o de vida grande / ");
	printf("3 - Po��o de energia pequena / 4 - Po��o de energia grande\n");
	printf("\n5 - Voltar ao menu principal\n");
	scanf("%d", &escolhaLoja2);
	pocaoMedonho(medonho, personagem, escolhaLoja2, choice);
	} else if(escolhaLoja == 2){
	printf("\n1 - Clava de ferro / 2 - Tomo de feiti�os / ");
	printf("3 - Arco longo / 4 - Adaga negra\n");
	printf("5 - Voltar ao menu principal\n");
		scanf("%d", &escolhaLoja2);
		
    itensMedonho(medonho, personagem, escolhaLoja2, choice);
	} else if(escolhaLoja == 3){
		printf("\nSaindo da loja...\n");
		return;
	} else{
		printf("Op��o inv�lida!");
	}
} while (escolhaLoja == 5);
}
