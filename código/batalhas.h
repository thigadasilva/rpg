int turno = 0;
void inventario(Atributos *personagem){
	int escolhaa;
	int escolha2;
	printf("  1. Po��o de Vida\n  2. Po��es de Energia\n  3. Voltar\n");
	scanf("%d", &escolha2);
	
	if (escolha2 == 1){
		printf(" 1. Po��o Pequena\n 2. Po��o Grande\n 3. Voltar\n");
		scanf("%d", &escolhaa);
		switch(escolhaa){
			case 1:
				if(personagem->potionsHpMin <= 0){
					printf("Voc� n�o tem po��o!\n");
						} else{
							personagem->potionsHpMin -= 1;
							personagem->ivida += 50;
							printf("Voc� utilizou po��o de vida e se curou em mais 50 de hp! Voc� est� com %d\n", personagem->ivida);
							turno += 1;
							break;
	} 	case 2: 
	    	if(personagem -> potionsHpMax <= 0){
	    		printf("Voc� n�o tem po��o!\n");
	    		turno += 1;
	    		break;
	} else{
		personagem->potionsHpMax -= 1;
		personagem->ivida += 100;
		printf("Voc� utilizou po��o de vida e se curou em mais 50 de hp! Voc� est� com %d\n", personagem->ivida);
		turno += 1;
		break;
			}
		}
	} 	else if(escolha2 == 2){
			printf(" 1. Po��o Pequena\n 2. Po��o Grande\n");
				scanf("%d", &escolhaa);
					switch(escolhaa){
						case 1:
						if(personagem->potionsEnergiaMin <= 0){
							printf("Voc� n�o tem po��o!\n");
							turno += 1;
							break;
		} else{
		personagem->potionsEnergiaMin -= 1;
		personagem->ienergia += 50;
		printf("Voc� utilizou po��o de energia pequena e se curou em mais 50 de energia! Voc� est� com %d\n", personagem->ienergia);
		turno += 1;
		break;
	} case 2: 
			if(personagem->potionsEnergiaMax <= 0){
			printf("Voc� n�o tem po��o!\n");
			turno += 1;
			break;
		} else{
		personagem->potionsEnergiaMax -= 1;
		personagem->ienergia += 100;
		printf("Voc� utilizou po��o de energia e se curou em mais 50 de hp! Voc� est� com %d\n", personagem->ienergia);
		turno += 1;
		break;
      } case 3:
      	break;
}  
		}
}

// ATAQUE

void gameOver(	) {
    printf("\nVoc� est� morto!!\n");
	exit(0); 
}
void check(Atributos *personagem){
	if(personagem->ivida <= 0){
	gameOver();
	}
}

void atacar(int classe, Atributos *personagem, Monstro *monstro){
	int danoBase = personagem->iforca + personagem->iagilidade + personagem->idestreza + personagem->iinteligencia;
	int danoAleatorio = rand() % 5 + 1;
	int danoTotal = danoBase + danoAleatorio;
	int danoCritico = 0;
	
	if(rand() % 100 + 1 <= personagem->iagilidade * 2){
		danoCritico = danoTotal * 2;
		danoTotal = danoBase + danoAleatorio;
	
	}

	int escolha2;
	printf("  1. Golpear\n  2. Usar Habilidade\n  3. Voltar\n");
	scanf("%d", &escolha2);

	switch (classe){
		case 1:
			if(escolha2 == 1){
				printf("Voc� atacou fisicamente!\n");
				if(danoCritico > 0){
				printf("Voc� causou %d de Dano Cr�tico!\n", danoCritico);
				monstro->vida -= danoCritico;
				monstro->vida -= danoTotal;
			
				printf("O monstro est� com %d de hp restantes.\n", monstro->vida);
				turno += 1;;
				break;
	} else{
		monstro->vida -= danoTotal;
		printf("Voc� atacou o monstro por %d de dano!", danoTotal);
			turno += 1;
			break;
	}
			}else if(escolha2 == 2){
				printf("Voc� usou uma habilidade!\n");
				turno += 1;
					break;
			} else if(escolha2 == 3){
				break;
			}
		break;
			case 2:
			if (escolha2 == 1){
				printf("\nVoc� lan�ou magias no inimigo!\n");
				if(danoCritico > 0){
				printf("Voc� causou %d de Dano Cr�tico!\n", danoCritico);
				monstro->vida -= danoCritico;
				monstro->vida -= danoTotal;
				printf("O monstro est� com %d de hp restantes.\n", monstro->vida);
			turno += 1;
				break;
	} else{
				monstro->vida -= danoTotal;
				printf("Voc� atacou o monstro por %d de dano!\n", danoTotal);
			printf("O monstro est� com %d de hp restantes.\n", monstro->vida);
		turno += 1;
			break;
			} 
			}else if(escolha2 == 2){
				printf("Voc� usou uma habilidade!\n");
			turno += 1;
				break;
			}else if(escolha2 == 3){
				break;
			}
		break;
			case 3:
			if (escolha2 == 1){
				printf("\nVoc� atirou proj�teis no inimigo!\n");
							if(danoCritico > 0){
				printf("Voc� causou %d de Dano Cr�tico!\n", danoCritico);
				monstro->vida -= danoCritico;
				monstro->vida -= danoTotal;
		
				printf("O monstro est� com %d de hp restantes.\n", monstro->vida);
				turno += 1;
					break;
	} else{
				monstro->vida -= danoTotal;
				printf("Voc� atacou o monstro por %d de dano!\n", danoTotal);
				printf("O monstro est� com %d de hp restantes.\n", monstro->vida);
				turno += 1;
					break;
			} 
			}else if(escolha2 == 2){
				printf("Voc� usou uma habilidade!\n");
				turno += 1;
					break;
			} else if(escolha2 == 3){
				break;
			}
		break;
			case 4:
			if (escolha2 == 1){
				printf("\nVoc� apunhalou o inimigo!\n");
							if(danoCritico > 0){
				printf("Voc� causou %d de Dano Cr�tico!\n", danoCritico);
				monstro->vida -= danoCritico;
				monstro->vida -= danoTotal;
				
				printf("O monstro est� com %d de hp restantes.\n", monstro->vida);
				turno += 1;
					break;
	} else{
				monstro->vida -= danoTotal;
				printf("Voc� atacou o monstro por %d de dano!\n", danoTotal);
				printf("O monstro est� com %d de hp restantes.\n", monstro->vida);
				turno += 1;
					break;
			} 
			}else if(escolha2 == 2){
				printf("Voc� usou uma habilidade!\n");
				turno += 1;
					break;
			} else if(escolha2 == 3){
				break;
			}
		break;
	}
}



// FUGA
int calcularChanceFuga(Atributos personagem) {
	int chanceFuga = (personagem.iagilidade + personagem.nivel);
		return chanceFuga;
};

int tentarFuga(int chanceFuga, Monstro *monstro){
	int roll = rand() % 20 + 1;
	if (roll <= chanceFuga){
		return 1;
	} else{
		printf("Voc� n�o conseguiu fugir!\n");
		return 0;
	}
}

void monstroAtaca(Monstro *monstro, Atributos *personagem){
  int danoBase = monstro->ataque + monstro->forca / 2;
    int danoAleatorio = rand() % (monstro->forca / 2) + 1;
    int danoTotal = danoBase + danoAleatorio;
	personagem->ivida -= danoTotal;
	printf("O monstro atacou voc� e causou %d de dano!\n\n", danoTotal);
	printf("Voc� agora est� com %d de hp.\n", personagem->ivida);
}

void iniciarbatalha(int classe, Atributos *personagem, Monstro *monstro){
	 int chanceFuga = calcularChanceFuga(*personagem); 
	 int fugiu = 0;
	 turno = 0;
	 
	 while(personagem->ivida > 0 && monstro->vida > 0){
	 
	 	if(turno == 0){
	int escolha;
   		printf(" 1. Atacar\n 2. Invent�rio\n 3. Fugir\n\n");
    		scanf("%d", &escolha);
	switch(escolha){
		case 1:
			atacar(classe, personagem, monstro);
			break;
		case 2:
			printf(" INVENT�RIO:\n");
			printf(" Po��es de vida pequena: %d\n", personagem->potionsHpMin);
			printf(" Po��es de vida grande: %d\n", personagem->potionsHpMax);
			printf(" Po��es de Energia pequena: %d\n", personagem->potionsEnergiaMin);
			printf(" Po��es de Energia Grande: %d\n\n", personagem->potionsEnergiaMax);
			
			inventario(personagem);
			break;
		case 3:
		fugiu =	tentarFuga(chanceFuga, monstro);
		if (fugiu){
			monstro->vida = 0;
		}
			break;
		default:
			printf("Op��o inv�lida!");	
		} 
		} else{
			printf("\nTurno do monstro!\n");
			getch();
			monstroAtaca(monstro, personagem);
			turno -= 1;
	 }
	
	
	if(personagem->ivida <= 0){
		return;
	} else if(fugiu == 1){
	printf("Voc� fugiu com sucesso!");	
	}else if (monstro->vida <= 0){
		printf("\nVoc� venceu!\n\n");
		personagem->xp += rand() % 20 + 50;
		printf("XP atual: %d", personagem->xp);
		personagem->moeda += rand() % 20 + 100;
		printf("\n Moedas de ouro atuais: %d\n", personagem->moeda);
	}
		
	} if(personagem->xp >= 100){
		personagem->xp -= personagem->xp;
		personagem->nivel += 1;
		printf("Voc� subiu de n�vel!\n");
		printf("N�vel atual: %d", personagem->nivel);
		atualizarAtributos(personagem);
	}
}
