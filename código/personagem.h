// ARQUIVOS DOS PERSONAGENS

typedef struct{
	char nome[16];
	char classe[16];
	int iforca;
	int ivida;
	int ienergia;
	int iagilidade;
	int idestreza;
	int iinteligencia;
	int xp;
	int nivel;
	int moeda;
	int potionsHpMax;
	int potionsHpMin;
	int potionsEnergiaMax;
	int potionsEnergiaMin;
} Atributos;

void inicializarPersonagens(Atributos *atributos) {
	atributos->iforca = 0;
	atributos->ivida = 0;
	atributos->ienergia = 0;
	atributos->iagilidade = 0;
	atributos->iinteligencia = 0;
	atributos->idestreza = 0;
	atributos->xp = 0;
	atributos->nivel = 0;
	atributos->moeda = 0;
	atributos->potionsHpMin = 3;
	atributos->potionsHpMax = 0;
	atributos->potionsEnergiaMin = 3;
	atributos->potionsEnergiaMax = 0;
}
void imprimirAtributos(Atributos *personagem){
	for(int i = 0; i < 1; i++){
	printf("\n-------------------------------ATRIBUTOS INICIAIS-------------------------------\n");
	printf("|  Classe: %s\n", personagem[0].classe);
	printf("|  For�a: %d\n", personagem[0].iforca);
	printf("|  Destreza: %d\n", personagem[0].idestreza);
	printf("|  Agilidade: %d\n", personagem[0].iagilidade);
	printf("|  Vida: %d\n", personagem[0].ivida);
	printf("|  Energia: %d\n", personagem[0].ienergia);
	printf("|  Intelig�ncia: %d\n", personagem[0].iinteligencia);
	printf("|  N�vel: %d | (%d/100)\n", personagem[0].nivel, personagem[0].xp);
	printf("|  Dinheiro: %d\n", personagem[0].moeda);
}
}
void atualizarAtributos(Atributos *personagem) {
    personagem->iforca += rand() % 5 + 1;
    personagem->iagilidade += rand() % 3 + 1; 
    personagem->idestreza += rand() % 2 + 1; 
    personagem->iinteligencia += rand() % 2 + 1; 
    personagem->ivida += rand() % 20 + 10; 
    personagem->ienergia += rand() % 10 + 5; 
}

