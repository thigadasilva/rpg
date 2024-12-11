void inventario(Atributos *personagem){
	int escolhaa;
	int escolha2;
	printf("  1. Poção de Vida\n  2. Poções de Energia\n");
	scanf("%d", &escolha2);
	
	if (escolha2 == 1){
		printf(" 1. Poção Pequena\n 2. Poção Grande\n");
		scanf("%d", &escolhaa);
		switch(escolhaa){
		case 1:
		if(personagem->potionsHpMin <= 0){
			printf("Você não tem poção!");
		} else{
		personagem->potionsHpMin -= 1;
		personagem->ivida += 50;
		printf("Você utilizou poção de vida e se curou em mais 50 de hp! Você está com %d", personagem->ivida);
		break;
	}
	    if(personagem -> potionsHpMax <= 0){
	    	printf("Você não tem poção!");
	} else{
		case 2: 
		personagem->potionsHpMax -= 1;
		personagem->ivida += 100;
		printf("Você utilizou poção de vida e se curou em mais 50 de hp! Você está com %d", personagem->ivida);
	}
	}
	} else if(escolha2 == 2){
		printf(" 1. Poção Pequena\n 2. Poção Grande\n");
		scanf("%d", &escolhaa);
		switch(escolhaa)	{
			if(personagem->potionsEnergiaMin <= 0){
			printf("Você não tem poção!");
		} else{
		case 1:
		personagem->potionsEnergiaMin -= 1;
		personagem->ienergia += 50;
		printf("Você utilizou poção de energia e se curou em mais 50 de energia! Você está com %d", personagem->ienergia);
		break;
	} 
			if(personagem->potionsEnergiaMax <= 0){
			printf("Você não tem poção!");
		} else{
		case 2: 
		personagem->potionsEnergiaMax -= 1;
		personagem->ienergia += 100;
		printf("Você utilizou poção de energia e se curou em mais 50 de hp! Você está com %d", personagem->ienergia);
      }
	}	
}
}

// ATAQUE

void gameOver(	) {
    printf("\nVocê está morto!!\n");
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
  int danoBase = monstro->ataque + monstro->forca / 2;
    int danoAleatorio = rand() % (monstro->forca / 2) + 1;
    int danoTotal = danoBase + danoAleatorio;
	personagem->ivida -= danoTotal;
	printf("O monstro atacou você e causou %d de dano!\n\n", danoTotal);
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
			printf(" INVENTÁRIO:\n");
			printf(" Poções de vida pequena: %d\n", personagem->potionsHpMin);
			printf(" Poções de vida grande: %d\n", personagem->potionsHpMax);
			printf(" Poções de Energia pequena: %d\n", personagem->potionsEnergiaMin);
			printf(" Poções de Energia Grande: %d\n\n", personagem->potionsEnergiaMax);
			
			inventario(personagem);
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
	turno = !turno;
	
	if(personagem->ivida <= 0){
		printf("Você está morto!");
		return;
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
