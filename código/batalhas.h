// ATAQUE
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
	printf("  1. Golpear\n  2. Usar Habilidade\n");
	scanf("%d", &escolha2);

	switch (classe){
		case 1:
			if(escolha2 == 1){
				printf("Você atacou fisicamente!\n");
				if(danoCritico > 0){
				printf("Você causou %d de Dano Crítico!\n", danoCritico);
				monstro->vida -= danoCritico;
				monstro->vida -= danoTotal;
			
				printf("O monstro está com %d de hp restantes.\n", monstro->vida);
	} else{
		monstro->vida -= danoTotal;
		printf("Você atacou o monstro por %d de dano!", danoTotal);
	}
			}else if(escolha2 == 2){
				printf("Você usou uma habilidade!\n");
			}
		break;
			case 2:
			if (escolha2 == 1){
				printf("\nVocê lançou magias no inimigo!\n");
				if(danoCritico > 0){
				printf("Você causou %d de Dano Crítico!\n", danoCritico);
				monstro->vida -= danoCritico;
				monstro->vida -= danoTotal;
				
				printf("O monstro está com %d de hp restantes.\n", monstro->vida);
	} else{
				monstro->vida -= danoTotal;
				printf("Você atacou o monstro por %d de dano!\n", danoTotal);
			printf("O monstro está com %d de hp restantes.\n", monstro->vida);
			} 
			}else if(escolha2 == 2){
				printf("Você usou uma habilidade!\n");
			}
		break;
			case 3:
			if (escolha2 == 1){
				printf("\nVocê atirou projéteis no inimigo!\n");
							if(danoCritico > 0){
				printf("Você causou %d de Dano Crítico!\n", danoCritico);
				monstro->vida -= danoCritico;
				monstro->vida -= danoTotal;
		
				printf("O monstro está com %d de hp restantes.\n", monstro->vida);
	} else{
				monstro->vida -= danoTotal;
				printf("Você atacou o monstro por %d de dano!\n", danoTotal);
				printf("O monstro está com %d de hp restantes.\n", monstro->vida);
			} 
			}else if(escolha2 == 2){
				printf("Você usou uma habilidade!\n");
			}
		break;
			case 4:
			if (escolha2 == 1){
				printf("\nVocê apunhalou o inimigo!\n");
							if(danoCritico > 0){
				printf("Você causou %d de Dano Crítico!\n", danoCritico);
				monstro->vida -= danoCritico;
				monstro->vida -= danoTotal;
				
				printf("O monstro está com %d de hp restantes.\n", monstro->vida);
	} else{
				monstro->vida -= danoTotal;
				printf("Você atacou o monstro por %d de dano!\n", danoTotal);
				printf("O monstro está com %d de hp restantes.\n", monstro->vida);
			} 
			}else if(escolha2 == 2){
				printf("Você usou uma habilidade!\n");
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
		printf("Você não conseguiu fugir!\n");
		return 0;
	}
}

void monstroAtaca(Monstro *monstro, Atributos *personagem){
	int dano = monstro->ataque;
	personagem->ivida -= dano;
	printf("O monstro atacou você e causou %d de dano!\n\n", dano);
	printf("Você agora está com %d de hp.\n", personagem->ivida);
}

void iniciarbatalha(int classe, Atributos *personagem, Monstro *monstro){
	 int chanceFuga = calcularChanceFuga(*personagem);
	 int turno = 0; // 0 = Jogador, 1 = monstro
	 int fugiu = 0;
	 
	 while(personagem->ivida > 0 && monstro->vida > 0){
	 
	 	if(turno == 0){
	int escolha;
   		printf(" 1. Atacar\n 2. Inventário\n 3. Fugir\n\n");
    		scanf("%d", &escolha);
	switch(escolha){
		case 1:
			atacar(classe, personagem, monstro);
			break;
		case 2:
			printf("INVENTÁRIO:\n");
			printf("Poções de vida: %d\n", personagem->potionsHp);
			printf("Poções de vida: %d", personagem->potionsEnergia);
			
			break;
		case 3:
		fugiu =	tentarFuga(chanceFuga, monstro);
		if (fugiu){
			monstro->vida = 0;
		}
			break;
		default:
			printf("Opção inválida!");	
		} 
		} else{
			printf("\nTurno do monstro!\n");
			getch();
			monstroAtaca(monstro, personagem);
		}
	turno = !turno; // altera turno
	
	if(personagem->ivida <= 0){
		printf("\nVOCÊ MORREU!!\n");
	} else if(fugiu == 1){
	printf("Você fugiu com sucesso!");	
	}else if (monstro->vida <= 0){
		printf("\nVocê venceu!\n\n");
		personagem->xp += rand() % 20 + 50;
		printf("XP: %d", personagem->xp);
		personagem->moeda += rand() % 20 + 100;
		printf("\nVocê recebeu %d moedas de ouro.\n", personagem->moeda);
		}
	}
}
