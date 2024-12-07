// ARQUIVOS DOS PERSONAGENS

typedef struct{
	char nome[16];
	int iforca;
	int ivida;
	int idestreza;
	int iinteligencia;
	int xp;
	int nivel;
} Atributos;

void inicializarPersonagens(Atributos *atributos, int itamanho) {
	int i = 0;
	for(i = 0; i < itamanho; i++){
		Atributos personagem[1];
		personagem[i].iforca = 0;
		personagem[i].ivida = 0;
		personagem[i].iinteligencia = 0;
		personagem[i].idestreza = 0;
		personagem[i].xp = 0;
		personagem[i].nivel = 0;
	}
}




