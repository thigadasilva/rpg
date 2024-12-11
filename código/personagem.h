// ARQUIVOS DOS PERSONAGENS

typedef struct{
	char nome[16];
	char classe[16];
	int iforca;
	int ivida;
	int iagilidade;
	int idestreza;
	int iinteligencia;
	int xp;
	int nivel;
	int moeda;
} Atributos;

void inicializarPersonagens(Atributos *atributos) {
	atributos->iforca = 0;
	atributos->ivida = 0;
	atributos->iagilidade = 0;
	atributos->iinteligencia = 0;
	atributos->idestreza = 0;
	atributos->xp = 0;
	atributos->nivel = 0;
	atributos->moeda = 0;
}
void imprimirAtributos(Atributos *personagem){
	for(int i = 0; i < 1; i++){
	printf("\n-------------------------------ATRIBUTOS INICIAIS-------------------------------\n");
	printf("|  Classe: %s\n", personagem[0].classe);
	printf("|  Força: %d\n", personagem[0].iforca);
	printf("|  Destreza: %d\n", personagem[0].idestreza);
	printf("|  Agilidade: %d\n", personagem[0].iagilidade);
	printf("|  Vida: %d\n", personagem[0].ivida);
	printf("|  Inteligência: %d\n", personagem[0].iinteligencia);
	printf("|  Nível: %d\n", personagem[0].nivel);
	printf("--------------------------------------------------------------------------------\n");
}
}
