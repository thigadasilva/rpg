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
printf(" 1 - Po��es de vida pequenas: Pre�o: 50 moedas de ouro.       |   2 - Po��es de vida grandes: Pre�o: 90 moedas de ouro.  \n", medonho->pocaoHpMin, medonho->pocaoHpMax);
printf(" 3 - Po��es de energia pequenas: Pre�o: 50 moedas de ouro.    |  4 - Po��es de energia grandes: Pre�o: 90 moedas de ouro.  \n", medonho->pocaoEnergiaMin, medonho->pocaoEnergiaMax);
printf("\nITENS:\n\n");
printf("1 - Clava de ferro - Pre�o: 100 moedas de ouro.\n");
printf("2 - Tomo de feiti�os - Pre�o: 150 moedas de ouro.\n");
printf("3 - Arco longo - Pre�o: 100 moedas de ouro.\n");
printf("4 - Adaga negra - Pre�o: 100 moedas de ouro.\n");
printf("Dinheiro atual: %d", personagem->moeda);
printf("\nEscolha: (1 - Po��es / 2 - Itens/ 3 - Sair)\n");
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
			} else if(medonho->pocaoHpMin > 0){
			medonho->pocaoHpMin -= choice;
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
			} else if(medonho->pocaoHpMax > 0){
			medonho->pocaoHpMax -= choice;
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
			} else if(medonho->pocaoEnergiaMin > 0){
			medonho->pocaoEnergiaMin -= choice;
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
			} else if(medonho->pocaoEnergiaMax > 0){
			medonho->pocaoEnergiaMax -= choice;
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
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 100){
			if(medonho->clavaa == 1){
				medonho->clavaa = medonho->clavaa - 1;
				personagem->clava = personagem->clava + 1;
			printf("\nVoc� comprou Clava de Ferro!\n");
			personagem->moeda = personagem->moeda - 100;
			break;
			} else if(medonho->clavaa == 0){
				printf("Acabou");
				break;
			}
			}
	case 2:
			if(personagem->moeda <= 0){
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 150){
			if(medonho->tomoo == 1){
				medonho->tomoo = medonho->tomoo - 1;
				personagem->tomo = personagem->tomo + 1;
			printf("\nVoc� comprou Tomo de Feiti�os!\n");
			personagem->moeda = personagem->moeda - 150;
			break;
			}else if(medonho->tomoo == 0){
				printf("Acabou");
				break;
			} 
		}
	case 3:
			if(personagem->moeda <= 0){
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 100){
			if(medonho->arcoo == 1){
				medonho->arcoo = medonho->arcoo - 1;
					personagem->arco = personagem->arco + 1;
			printf("\nVoc� comprou Arco Longo!\n");
			personagem->moeda = personagem->moeda - 100;
			break;
			}else if(medonho->arcoo == 0){
				printf("Acabou");
				break;
			} 
		}
	case 4:
			if(personagem->moeda <= 0){
			printf("\nVoc� n�o tem moedas suficientes!\n");
			break;
		} else if(personagem->moeda > 100){
			if(medonho->adagaa == 1){
				medonho->adagaa = medonho->adagaa - 1;
					personagem->adaga = personagem->adaga + 1;
			printf("\nVoc� comprou Adaga negra!\n");
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
	printf("Sua for�a aumentou em 10\n");
} else if(personagem->tomo != 0){
	personagem->iinteligencia = personagem->iinteligencia + 10;
	printf("Sua intelig�ncia aumentou em 10\n");
} else if(personagem->arco != 0){
	personagem->idestreza = personagem->idestreza + 10;
	printf("Sua destreza aumentou em 10\n");
} else if(personagem->adaga != 0){
	personagem->iagilidade = personagem->iagilidade + 10;
	printf("Sua agilidade aumentou em 10\n");
}
}
