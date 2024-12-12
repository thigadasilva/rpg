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
		printf("\nQuantas poções você quer?\n");
		scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 50){
			personagem->potionsHpMin += choice ;
			printf("\nVocê comprou %d poções pequenas!\n", choice);
			choice * 50;
			choice -= personagem->moeda;
			break;
			}
	case 2:
			printf("\nQuantas poções você quer?\n");
		scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 75){
			personagem->potionsHpMax += choice ;
			printf("\nVocê comprou %d poções grandes!\n", choice);
			choice * 90;
			choice -= personagem->moeda;
			break;
			}
	case 3:
			printf("\nQuantas poções você quer?\n");
		scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 50){
			personagem->potionsEnergiaMin += choice ;
			printf("\nVocê comprou %d poções pequenas!\n", choice);
			choice * 50;
			choice -= personagem->moeda;
			break;
			}
	case 4:
			printf("\nQuantas poções você quer?\n");
			scanf("%d", &choice);
			if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 75){
			personagem->potionsEnergiaMax += choice ;
			printf("\nVocê comprou %d poções grandes!\n", choice);
			choice * 90;
			choice -= personagem->moeda;
			break;
			}
	case 5:
	system("cls");
	lojaMedonho(medonho, personagem);
    break;
    default: 
    	printf("Opção inválida!");
    	break;
		}
	}
	void itensMedonho(Medonho *medonho, Atributos *personagem, int escolhaLoja2, int choice){
		switch(escolhaLoja2){
	case 1:
		if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 100){
			personagem->clava += 1;
			printf("\nVocê comprou Clava de Ferro!\n");
			personagem->moeda - 100;
			break;
			}
	case 2:
			if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 150){
			personagem->clava += 1;
			printf("\nVocê comprou Tomo de Feitiços!\n");
			personagem->moeda - 150;
			break;
			}
	case 3:
			if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 100){
			personagem->clava += 1;
			printf("\nVocê comprou Arco Longo!\n");
			personagem->moeda - 100;
			break;
			}
	case 4:
			if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 100){
			personagem->clava += 1;
			printf("\nVocê comprou Adaga negra!\n");
			personagem->moeda - 100;
			break;
			}
	case 5:
	system("cls");
	lojaMedonho(medonho, personagem);
    break;
    default:
    	printf("Opção inválida!");
    	break;
		}
}

void lojaMedonho(Medonho *medonho, Atributos *personagem){
	int escolhaLoja, escolhaLoja2, choice;
printf("===============================LOJA DO MEDONHO===============================\n");
printf(" 1 - Poções de vida pequenas: Preço: 50 moedas de ouro.       |   2 - Poções de vida grandes: Preço: 90 moedas de ouro.  \n", medonho->pocaoHpMin, medonho->pocaoHpMax);
printf(" 3 - Poções de energia pequenas: Preço: 50 moedas de ouro.    |  4 - Poções de energia grandes: Preço: 90 moedas de ouro.  \n", medonho->pocaoEnergiaMin, medonho->pocaoEnergiaMax);
printf("\nITENS:\n\n");
printf("1 - Clava de ferro - Preço: 100 moedas de ouro.\n");
printf("2 - Tomo de feitiços - Preço: 150 moedas de ouro.\n");
printf("3 - Arco longo - Preço: 100 moedas de ouro.\n");
printf("4 - Adaga negra - Preço: 100 moedas de ouro.\n");
printf("\nEscolha: (1 - Poções / 2 - Itens/ 3 - Sair)\n");
scanf("%d", &escolhaLoja);
do {
  if(escolhaLoja == 1){
	printf("\n1 - Poção de vida pequena / 2 - Poção de vida grande / ");
	printf("3 - Poção de energia pequena / 4 - Poção de energia grande\n");
	printf("\n5 - Voltar ao menu principal\n");
	scanf("%d", &escolhaLoja2);
	pocaoMedonho(medonho, personagem, escolhaLoja2, choice);
	} else if(escolhaLoja == 2){
	printf("\n1 - Clava de ferro / 2 - Tomo de feitiços / ");
	printf("3 - Arco longo / 4 - Adaga negra\n");
	printf("5 - Voltar ao menu principal\n");
		scanf("%d", &escolhaLoja2);
		
    itensMedonho(medonho, personagem, escolhaLoja2, choice);
	} else if(escolhaLoja == 3){
		printf("\nSaindo da loja...\n");
		return;
	} else{
		printf("Opção inválida!");
	}
} while (escolhaLoja == 5);
}
