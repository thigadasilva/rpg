// ATAQUE
void atacar(int classe){
	int escolha2;
	printf("  1. Golpear\n  2. Usar Habilidade\n");
	scanf("%d", &escolha2);
	
	switch (classe){
		case 1:
			if (escolha2 == 1){
				printf("Voc� atacou fisicamente!\n");
			} else if(escolha2 == 2){
				printf("Voc� usou uma habilidade!\n");
			}
		break;
			case 2:
			if (escolha2 == 1){
				printf("Voc� lan�ou magias no inimigo!\n");
			} else if(escolha2 == 2){
				printf("Voc� usou uma habilidade!\n");
			}
		break;
			case 3:
			if (escolha2 == 1){
				printf("Voc� atirou proj�teis no inimigo!\n");
			} else if(escolha2 == 2){
				printf("Voc� usou uma habilidade!\n");
			}
		break;
			case 4:
			if (escolha2 == 1){
				printf("Voc� apunhalou o inimigo!\n");
			} else if(escolha2 == 2){
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

void iniciarbatalha(int classe, Atributos personagem){
	 int chanceFuga = calcularChanceFuga(personagem);
	int escolha;
   		printf(" 1. Atacar\n 2. Invent�rio\n 3. Fugir\n\n");
    		scanf("%d", &escolha);
	switch(escolha){
		case 1:
			atacar(classe);
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
}
