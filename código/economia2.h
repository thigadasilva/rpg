typedef struct{
	int pocaoHpMin;
	int pocaoHpMax;
	int pocaoEnergiaMin;
	int pocaoEnergiaMax;
} Medonho2;

void inicializarMedonho2(Medonho2 *medonho2) {
	medonho2->pocaoHpMin = 4;
	medonho2->pocaoHpMax = 4;
	medonho2->pocaoEnergiaMin = 4;
	medonho2->pocaoEnergiaMax = 4;
}

void lojaMedonho2(Medonho2 *medonho2, Atributos *personagem){
	int a, escolhaLoja2, escolhaLoja3, b, choice, extra;
printf("===============================LOJA DO MEDONHO===============================\n");
printf(" 1 - Po��es de vida pequenas: Pre�o: 50 moedas de ouro.       |   2 - Po��es de vida grandes: Pre�o: 90 moedas de ouro.  \n", medonho2->pocaoHpMin, medonho2->pocaoHpMax);
printf(" 3 - Po��es de energia pequenas: Pre�o: 50 moedas de ouro.    |  4 - Po��es de energia grandes: Pre�o: 90 moedas de ouro.  \n", medonho2->pocaoEnergiaMin, medonho2->pocaoEnergiaMax);
printf("Upgrade: 350 moedas de ouro\n");
printf("Dinheiro atual: %d", personagem->moeda);
printf("\nEscolha: (1 - Po��es / 2 - Upgrade/ 3 - Sair)\n");
scanf("%d", &a);
do {
 	 if(a == 1){
	printf("\n1 / 2  / ");
	printf("3 / 4 \n");
	printf("\n5 - Voltar\n");
	scanf("%d", &escolhaLoja2);
	switch(escolhaLoja2){
	case 1:
		printf("\nQuantas po��es voc� quer?\n");
		scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 50){
			if(choice > 4){
				printf("N�o tenho mais que 4 po��es comigo.\n");
				break;
			} else if(medonho2->pocaoHpMin > 0){
			medonho2->pocaoHpMin -= choice;
			personagem->potionsHpMin += choice ;
			printf("\nVoc� comprou %d po��es pequenas!\n", choice);
			choice = choice * 50;
			personagem->moeda = personagem->moeda - choice;
			break;
			} else{
				printf("Minhas po��es acabaram.");
				break;
			}
		}
	case 2:
			printf("\nQuantas po��es voc� quer?\n");
		scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 50){
			if(choice > 4){
				printf("N�o tenho mais que 4 po��es comigo.\n");
				break;
			} else if(medonho2->pocaoHpMax > 0){
			medonho2->pocaoHpMax -= choice;
			personagem->potionsHpMax += choice ;
			printf("\nVoc� comprou %d po��es grande!\n", choice);
			choice = choice * 50;
		personagem->moeda = personagem->moeda - choice;
			break;
			} else{
				printf("Minhas po��es acabaram.");
				break;
			}
		}
	case 3:
			printf("\nQuantas po��es voc� quer?\n");
		scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 50){
			if(choice > 4){
				printf("N�o tenho mais que 4 po��es comigo.\n");
				break;
			} else if(medonho2->pocaoEnergiaMin > 0){
			medonho2->pocaoEnergiaMin -= choice;
			personagem->potionsEnergiaMin += choice ;
			printf("\nVoc� comprou %d po��es pequenas!\n", choice);
		choice = choice * 50;
		personagem->moeda = personagem->moeda - choice;
			break;
			} else{
				printf("Minhas po��es acabaram.");
				break;
			}
		}
	case 4:
			printf("\nQuantas po��es voc� quer?\n");
			scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 50){
			if(choice > 4){
				printf("N�o tenho mais que 4 po��es comigo.\n");
				break;
			} else if(medonho2->pocaoEnergiaMax > 0){
			medonho2->pocaoEnergiaMax -= choice;
			personagem->potionsEnergiaMax += choice ;
			printf("\nVoc� comprou %d po��es grandes!\n", choice);
			choice = choice * 50;
			personagem->moeda = personagem->moeda - choice;
			break;
			} else{
				printf("Minhas po��es acabaram.");
				break;
			}
		}
	case 5:
	system("cls");
	lojaMedonho2(medonho2, personagem);
    break;
	}
	} else if(a == 2){
	printf("1 - Upgrade\n");
	printf("2 - Voltar\n");
	scanf("%d", &escolhaLoja3);
		
   	switch(escolhaLoja3){
	case 1:
	if (personagem->moeda > 350){
		personagem->moeda -= 350;
		if(personagem->clava == 1){
			personagem->iforca += 10;
			printf("Sua clava foi melhorada! Voc� recebeu 10 de for�a!");
		} 	if(personagem->tomo == 1){
			personagem->iinteligencia += 10;
			printf("Seu tomo recebeu novas p�ginas! Voc� recebeu 10 de intelig�ncia!");
			} if(personagem->arco == 1){
			personagem->idestreza += 10;
			printf("Seu arco foi melhorada! Voc� recebeu 10 de destreza!");
				} if(personagem->adaga == 1){
			personagem->iagilidade += 10;
			printf("Sua adaga foi melhorada! Voc� recebeu 10 de agilidade!");
		}
	}
	break;
	case 2:
		lojaMedonho2(medonho2, personagem);
    break;
	default:
		printf("Op��o inv�lida!");
		break;
	}
}
	 printf("\nDeseja continuar comprando? (1 - Sim / 2 - Sair)\n");
        scanf("%d", &b);
} while (b != 2);
}
