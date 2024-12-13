typedef struct{
	int pocaoHpMin;
	int pocaoHpMax;
	int pocaoEnergiaMin;
	int pocaoEnergiaMax;
	int clavaa;
	int tomoo;
	int arcoo;
	int adagaa;
} Medonho;

void inicializarMedonho(Medonho *medonho) {
	medonho->pocaoHpMin = 4;
	medonho->pocaoHpMax = 4;
	medonho->pocaoEnergiaMin = 4;
	medonho->pocaoEnergiaMax = 4;
	medonho->clavaa = 1;
	medonho->tomoo = 1;
	medonho->arcoo = 1;
	medonho->adagaa = 1;
}

void lojaMedonho(Medonho *medonho, Atributos *personagem){
	int a, escolhaLoja2, escolhaLoja3, b, choice, extra;
printf("===============================LOJA DO MEDONHO===============================\n");
printf(" 1 - Poções de vida pequenas: Preço: 50 moedas de ouro.       |   2 - Poções de vida grandes: Preço: 90 moedas de ouro.  \n", medonho->pocaoHpMin, medonho->pocaoHpMax);
printf(" 3 - Poções de energia pequenas: Preço: 50 moedas de ouro.    |  4 - Poções de energia grandes: Preço: 90 moedas de ouro.  \n", medonho->pocaoEnergiaMin, medonho->pocaoEnergiaMax);
printf("\nITENS:\n\n");
printf("1 - Clava de ferro - Preço: 100 moedas de ouro.\n");
printf("2 - Tomo de feitiços - Preço: 150 moedas de ouro.\n");
printf("3 - Arco longo - Preço: 100 moedas de ouro.\n");
printf("4 - Adaga negra - Preço: 100 moedas de ouro.\n");
printf("Dinheiro atual: %d", personagem->moeda);
printf("\nEscolha: (1 - Poções / 2 - Itens/ 3 - Sair)\n");
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
			} else if(medonho->pocaoHpMin > 0){
			medonho->pocaoHpMin -= choice;
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
			} else if(medonho->pocaoHpMax > 0){
			medonho->pocaoHpMax -= choice;
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
			} else if(medonho->pocaoEnergiaMin > 0){
			medonho->pocaoEnergiaMin -= choice;
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
			} else if(medonho->pocaoEnergiaMax > 0){
			medonho->pocaoEnergiaMax -= choice;
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
	lojaMedonho(medonho, personagem);
    break;
	}
	} else if(a == 2){
	printf("\n1  / 2  / ");
	printf("3  / 4 \n");
	printf("5 - Voltar\n");
	scanf("%d", &escolhaLoja3);
		
   	switch(escolhaLoja3){
	case 1:
		if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 100){
			if(medonho->clavaa == 1){
				medonho->clavaa = medonho->clavaa - 1;
				personagem->clava = personagem->clava + 1;
			printf("\nVocê comprou Clava de Ferro!\n");
			personagem->moeda = personagem->moeda - 100;
			break;
			} else if(medonho->clavaa == 0){
				printf("Acabou");
				break;
			}
			}
	case 2:
			if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 150){
			if(medonho->tomoo == 1){
				medonho->tomoo = medonho->tomoo - 1;
				personagem->tomo = personagem->tomo + 1;
			printf("\nVocê comprou Tomo de Feitiços!\n");
			personagem->moeda = personagem->moeda - 150;
			break;
			}else if(medonho->tomoo == 0){
				printf("Acabou");
				break;
			} 
		}
	case 3:
			if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 100){
			if(medonho->arcoo == 1){
				medonho->arcoo = medonho->arcoo - 1;
					personagem->arco = personagem->arco + 1;
			printf("\nVocê comprou Arco Longo!\n");
			personagem->moeda = personagem->moeda - 100;
			break;
			}else if(medonho->arcoo == 0){
				printf("Acabou");
				break;
			} 
		}
	case 4:
			if(personagem->moeda <= 0){
			printf("\nVocê não tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 100){
			if(medonho->adagaa == 1){
				medonho->adagaa = medonho->adagaa - 1;
					personagem->adaga = personagem->adaga + 1;
			printf("\nVocê comprou Adaga negra!\n");
			personagem->moeda = personagem->moeda - 100;
			break;
			}else if(medonho->adagaa == 0){
				printf("Acabou");
				break;
			} 
		}
	case 5:
	lojaMedonho(medonho, personagem);
    break;
	}
}
	 printf("\nDeseja continuar comprando? (1 - Sim / 3 - Sair)\n");
        scanf("%d", &b);
} while (b != 3);
}
void verificarItem(Atributos *personagem){
	if(personagem->clava != 0){
	personagem->iforca = personagem->iforca + 10;
	printf("Sua força aumentou em 10\n");
} else if(personagem->tomo != 0){
	personagem->iinteligencia = personagem->iinteligencia + 10;
	printf("Sua inteligência aumentou em 10\n");
} else if(personagem->arco != 0){
	personagem->idestreza = personagem->idestreza + 10;
	printf("Sua destreza aumentou em 10\n");
} else if(personagem->adaga != 0){
	personagem->iagilidade = personagem->iagilidade + 10;
	printf("Sua agilidade aumentou em 10\n");
}
}
