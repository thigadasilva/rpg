// ATAQUE
void atacar(int classe, Atributos personagem, Monstro *monstro){
	int danoBase = personagem.iforca * 2;
	int danoAleatorio = rand() % 5 + 1;
	int danoTotal = danoBase + danoAleatorio;
	
	if(rand() % 100 + 1 <= personagem.iagilidade * 2){
		danoTotal *= 2;
		printf("Dano Crítico!\n");
	}
	
	

	
	
	int escolha2;
	printf("  1. Golpear\n  2. Usar Habilidade\n");
	scanf("%d", &escolha2);
	
	switch (classe){
		case 1:
			if(escolha2 == 1){
				printf("Você atacou fisicamente!\n");
					monstro->vida -= danoTotal;
	printf("Você atacou o monstro por %d de dano!\n", danoTotal);
		printf("O monstro está com %d restantes.\n", monstro->vida);

			}else if(escolha2 == 2){
				printf("Você usou uma habilidade!\n");
			}
		break;
			case 2:
			if (escolha2 == 1){
				printf("\nVocê lançou magias no inimigo!\n");
					monstro->vida -= danoTotal;
	printf("Você atacou o monstro por %d de dano!\n", danoTotal);
		printf("O monstro está com %d restantes.\n", monstro->vida);
			} else if(escolha2 == 2){
				printf("Você usou uma habilidade!\n");
			}
		break;
			case 3:
			if (escolha2 == 1){
				printf("\nVocê atirou projéteis no inimigo!\n");
					monstro->vida -= danoTotal;
	printf("Você atacou o monstro por %d de dano!\n", danoTotal);
		printf("O monstro está com %d restantes.\n", monstro->vida);
			} else if(escolha2 == 2){
				printf("Você usou uma habilidade!\n");
			}
		break;
			case 4:
			if (escolha2 == 1){
				printf("\nVocê apunhalou o inimigo!\n");
					monstro->vida -= danoTotal;
	printf("Você atacou o monstro por %d de dano!\n", danoTotal);
		printf("O monstro está com %d restantes.\n", monstro->vida);
			} else if(escolha2 == 2){
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

void tentarFuga(int chanceFuga){
	int roll = rand() % 20 + 1;
	if (roll <= chanceFuga){
		printf("Você fugiu com sucesso!\n");
	} else{
		printf("Você não conseguiu fugir!\n");
	}
}

void monstroAtaca(Monstro *monstro, Atributos *personagem){
	int dano = monstro->ataque;
	personagem->ivida -= dano;
	printf("O monstro atacou você e causou %d de dano!\n\n", dano);
	printf("Você agora está com %d\n", personagem->ivida);
}

void iniciarbatalha(int classe, Atributos personagem, Monstro monstro){
	 int chanceFuga = calcularChanceFuga(personagem);
	 int turno = 0; // 0 = Jogador, 1 = monstro
	 
	 while(personagem.ivida > 0 && monstro.vida > 0){
	 
	 	
	 	
	 	
	 	
	 	if(turno == 0){
	int escolha;
   		printf(" 1. Atacar\n 2. Inventário\n 3. Fugir\n\n");
    		scanf("%d", &escolha);
	switch(escolha){
		case 1:
			atacar(classe, personagem, &monstro);
			break;
		case 2:
			printf("  OPÇÃO NÃO IMPLEMENTADA AINDA\n");
			break;
		case 3:
			tentarFuga(chanceFuga);
			break;
		default:
			printf("Opção inválida!");	
		} 
		} else{
			printf("\nTurno do monstro!\n");
			getch();
			monstroAtaca(&monstro, &personagem);
		}
	turno = !turno; // altera turno
	
	if(personagem.ivida <= 0){
		printf("Você morreu!\n");
	} else if (monstro.vida <= 0){
		printf("Você venceu!\n");
	}
}
}
