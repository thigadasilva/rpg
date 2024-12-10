// ATAQUE
void atacar(int classe){
	int escolha2;
	printf("  1. Golpear\n  2. Usar Habilidade\n");
	scanf("%d", &escolha2);
	
	switch (classe){
		case 1:
			if (escolha2 == 1){
				printf("Você atacou fisicamente!\n");
			} else if(escolha2 == 2){
				printf("Você usou uma habilidade!\n");
			}
		break;
			case 2:
			if (escolha2 == 1){
				printf("Você lançou magias no inimigo!\n");
			} else if(escolha2 == 2){
				printf("Você usou uma habilidade!\n");
			}
		break;
			case 3:
			if (escolha2 == 1){
				printf("Você atirou projéteis no inimigo!\n");
			} else if(escolha2 == 2){
				printf("Você usou uma habilidade!\n");
			}
		break;
			case 4:
			if (escolha2 == 1){
				printf("Você apunhalou o inimigo!\n");
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

void iniciarbatalha(int classe, Atributos personagem){
	 int chanceFuga = calcularChanceFuga(personagem);
	int escolha;
   		printf(" 1. Atacar\n 2. Inventário\n 3. Fugir\n\n");
    		scanf("%d", &escolha);
	switch(escolha){
		case 1:
			atacar(classe);
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
}
