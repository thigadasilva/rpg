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
printf(" 1 - Poções de vida pequenas: Preço: 50 moedas de ouro.       |   2 - Poções de vida grandes: Preço: 90 moedas de ouro.  \n", medonho2->pocaoHpMin, medonho2->pocaoHpMax);
printf(" 3 - Poções de energia pequenas: Preço: 50 moedas de ouro.    |  4 - Poções de energia grandes: Preço: 90 moedas de ouro.  \n", medonho2->pocaoEnergiaMin, medonho2->pocaoEnergiaMax);
printf("Upgrade: 350 moedas de ouro\n");
printf("Dinheiro atual: %d", personagem->moeda);
printf("\nEscolha: (1 - Poções / 2 - Upgrade/ 3 - Sair)\n");
scanf("%d", &a);
do {
 	 if(a == 1){
	printf("\n1 / 2  / ");
	printf("3 / 4 \n");
	printf("\n5 - Voltar\n");
	scanf("%d", &escolhaLoja2);
	switch(escolhaLoja2){
	case 1:
		printf("\nQuantas poções você quer?\n");
		scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 50){
			if(choice > 4){
				printf("Não tenho mais que 4 poções comigo.\n");
				break;
			} else if(medonho2->pocaoHpMin > 0){
			medonho2->pocaoHpMin -= choice;
			personagem->potionsHpMin += choice ;
			printf("\nVocê comprou %d poções pequenas!\n", choice);
			choice = choice * 50;
			personagem->moeda = personagem->moeda - choice;
			break;
			} else{
				printf("Minhas poções acabaram.");
				break;
			}
		}
	case 2:
			printf("\nQuantas poções você quer?\n");
		scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 50){
			if(choice > 4){
				printf("Não tenho mais que 4 poções comigo.\n");
				break;
			} else if(medonho2->pocaoHpMax > 0){
			medonho2->pocaoHpMax -= choice;
			personagem->potionsHpMax += choice ;
			printf("\nVocê comprou %d poções grande!\n", choice);
			choice = choice * 50;
		personagem->moeda = personagem->moeda - choice;
			break;
			} else{
				printf("Minhas poções acabaram.");
				break;
			}
		}
	case 3:
			printf("\nQuantas poções você quer?\n");
		scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 50){
			if(choice > 4){
				printf("Não tenho mais que 4 poções comigo.\n");
				break;
			} else if(medonho2->pocaoEnergiaMin > 0){
			medonho2->pocaoEnergiaMin -= choice;
			personagem->potionsEnergiaMin += choice ;
			printf("\nVocê comprou %d poções pequenas!\n", choice);
		choice = choice * 50;
		personagem->moeda = personagem->moeda - choice;
			break;
			} else{
				printf("Minhas poções acabaram.");
				break;
			}
		}
	case 4:
			printf("\nQuantas poções você quer?\n");
			scanf("%d", &choice);
		if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 50){
			if(choice > 4){
				printf("Não tenho mais que 4 poções comigo.\n");
				break;
			} else if(medonho2->pocaoEnergiaMax > 0){
			medonho2->pocaoEnergiaMax -= choice;
			personagem->potionsEnergiaMax += choice ;
			printf("\nVocê comprou %d poções grandes!\n", choice);
			choice = choice * 50;
			personagem->moeda = personagem->moeda - choice;
			break;
			} else{
				printf("Minhas poções acabaram.");
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
			printf("Sua clava foi melhorada! Você recebeu 10 de força!");
		} 	if(personagem->tomo == 1){
			personagem->iinteligencia += 10;
			printf("Seu tomo recebeu novas páginas! Você recebeu 10 de inteligência!");
			} if(personagem->arco == 1){
			personagem->idestreza += 10;
			printf("Seu arco foi melhorada! Você recebeu 10 de destreza!");
				} if(personagem->adaga == 1){
			personagem->iagilidade += 10;
			printf("Sua adaga foi melhorada! Você recebeu 10 de agilidade!");
		}
	}
	break;
	case 2:
		lojaMedonho2(medonho2, personagem);
    break;
	default:
		printf("Opção inválida!");
		break;
	}
}
	 printf("\nDeseja continuar comprando? (1 - Sim / 2 - Sair)\n");
        scanf("%d", &b);
} while (b != 2);
}
