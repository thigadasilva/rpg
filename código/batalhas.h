// ATAQUE
void atacar(int classe, Atributos personagem, Monstro *monstro){
	int danoBase = personagem.iforca + personagem.iagilidade + personagem.idestreza + personagem.iinteligencia;
	int danoAleatorio = rand() % 5 + 1;
	int danoTotal = danoBase + danoAleatorio;
	int danoCritico = 0;
	
	if(rand() % 100 + 1 <= personagem.iagilidade * 2){
		danoCritico = danoTotal * 2;
		danoTotal = danoBase + danoAleatorio;
	
	}

	int escolha2;
	printf("  1. Golpear\n  2. Usar Habilidade\n");
	scanf("%d", &escolha2);

	switch (classe){
		case 1:
			if(escolha2 == 1){
				printf("Voc� atacou fisicamente!\n");
				if(danoCritico > 0){
				printf("Voc� causou %d de Dano Cr�tico!\n", danoCritico);
				monstro->vida -= danoCritico;
				monstro->vida -= danoTotal;
				printf("Voc� atacou o monstro por %d de dano!\n", danoTotal);
				printf("O monstro est� com %d de hp restantes.\n", monstro->vida);
	} else{
		monstro->vida -= danoTotal;
		printf("Voc� atacou o monstro por %d de dano!", danoTotal);
	}
			}else if(escolha2 == 2){
				printf("Voc� usou uma habilidade!\n");
			}
		break;
			case 2:
			if (escolha2 == 1){
				printf("\nVoc� lan�ou magias no inimigo!\n");
				if(danoCritico > 0){
				printf("Voc� causou %d de Dano Cr�tico!\n", danoCritico);
				monstro->vida -= danoCritico;
				monstro->vida -= danoTotal;
				printf("Voc� atacou o monstro por %d de dano!\n", danoCritico);
				printf("O monstro est� com %d de hp restantes.\n", monstro->vida);
	} else{
				monstro->vida -= danoTotal;
				printf("Voc� atacou o monstro por %d de dano!\n", danoTotal);
			printf("O monstro est� com %d de hp restantes.\n", monstro->vida);
			} 
			}else if(escolha2 == 2){
				printf("Voc� usou uma habilidade!\n");
			}
		break;
			case 3:
			if (escolha2 == 1){
				printf("\nVoc� atirou proj�teis no inimigo!\n");
							if(danoCritico > 0){
				printf("Voc� causou %d de Dano Cr�tico!\n", danoCritico);
				monstro->vida -= danoCritico;
				monstro->vida -= danoTotal;
				printf("Voc� atacou o monstro por %d de dano!\n", danoCritico);
				printf("O monstro est� com %d de hp restantes.\n", monstro->vida);
	} else{
				monstro->vida -= danoTotal;
				printf("Voc� atacou o monstro por %d de dano!\n", danoTotal);
				printf("O monstro est� com %d de hp restantes.\n", monstro->vida);
			} 
			}else if(escolha2 == 2){
				printf("Voc� usou uma habilidade!\n");
			}
		break;
			case 4:
			if (escolha2 == 1){
				printf("\nVoc� apunhalou o inimigo!\n");
							if(danoCritico > 0){
				printf("Voc� causou %d de Dano Cr�tico!\n", danoCritico);
				monstro->vida -= danoCritico;
				monstro->vida -= danoTotal;
				printf("Voc� atacou o monstro por %d de dano!\n", danoCritico);
				printf("O monstro est� com %d de hp restantes.\n", monstro->vida);
	} else{
				monstro->vida -= danoTotal;
				printf("Voc� atacou o monstro por %d de dano!\n", danoTotal);
				printf("O monstro est� com %d de hp restantes.\n", monstro->vida);
			} 
			}else if(escolha2 == 2){
				printf("Voc� usou uma habilidade!\n");
			}
		break;
	}
}
// FUGA
int calcularChanceFuga(Atributos personagem) {
	int chanceFuga = (personagem.iagilidade + personagem.nivel);
		return chanceFuga;
};

void tentarFuga(int chanceFuga){
	int roll = rand() % 20 + 1;
	if (roll <= chanceFuga){
		printf("Voc� fugiu com sucesso!\n");
	} else{
		printf("Voc� n�o conseguiu fugir!\n");
	}
}

void monstroAtaca(Monstro *monstro, Atributos *personagem){
	int dano = monstro->ataque;
	personagem->ivida -= dano;
	printf("O monstro atacou voc� e causou %d de dano!\n\n", dano);
	printf("Voc� agora est� com %d de hp.\n", personagem->ivida);
}

void iniciarbatalha(int classe, Atributos personagem, Monstro monstro){
	 int chanceFuga = calcularChanceFuga(personagem);
	 int turno = 0; // 0 = Jogador, 1 = monstro
	 
	 while(personagem.ivida > 0 && monstro.vida > 0){
	 
	 	
	 	
	 	
	 	
	 	if(turno == 0){
	int escolha;
   		printf(" 1. Atacar\n 2. Invent�rio\n 3. Fugir\n\n");
    		scanf("%d", &escolha);
	switch(escolha){
		case 1:
			atacar(classe, personagem, &monstro);
			break;
		case 2:
			printf("  OP��O N�O IMPLEMENTADA AINDA\n");
			break;
		case 3:
			tentarFuga(chanceFuga);
			break;
		default:
			printf("Op��o inv�lida!");	
		} 
		} else{
			printf("\nTurno do monstro!\n");
			getch();
			monstroAtaca(&monstro, &personagem);
		}
	turno = !turno; // altera turno
	
	if(personagem.ivida <= 0){
		printf("\nVOC� MORREU!!\n");
	} else if (monstro.vida <= 0){
		printf("\nVoc� venceu!\n\n");
		personagem.xp += rand() % 20 + 50;
		printf("XP: %d", personagem.xp);
		personagem.moeda += rand() % 20 + 100;
		printf("\nVoc� recebeu %d moedas de ouro.\n", personagem.moeda);
	}
}
}
