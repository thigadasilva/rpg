// ARQUIVO DOS MONSTROS

typedef struct{
	char nome[50];
	int vida;
	int forca;
	
}Monstro;

char *nomes[] = {

"Abnegai", //é Jean colega de sala
"Trefilarco", // Victor Rafael colega da sala
"Danai", // Darlan colega da sala

"Biscainha", // christian baldas colega da sala
"Alferes", // Leoni Israel colega da sala
"Maculara", // Caique amaral ex aluno

"Lavarco", //Kaua colega da sala
"Freara", // eduardo ex aluno
"Ignotos", // Gustavo ex aluno

"Aquilatai", // Quecila colega da sala
"minore", // Márcio ex aluno
"merego", // Mirelle colega da sala 
};

const int quantidadeNomes = 12;

int geradorMonstros(int min, int max){
	
	
return (rand() % (max - min + 1)) + min;
}

Monstro criarMonstrosRandom(){
	
	Monstro monstro;
 	 int indice = geradorMonstros(0, quantidadeNomes - 1);
 	  strcpy(monstro.nome, nomes[indice]);
	monstro.vida = geradorMonstros(10, 30);
	monstro.forca = geradorMonstros(3, 15);
	
	return monstro;
}
void imprimirMonstro(Monstro *monstro){
	printf("Um %s te encontrou!\n", monstro->nome);
    printf("\n---------------------------------STATUS---------------------------------\n");
    printf("%s\n", monstro->nome);
    printf("Vida: %d\n", monstro->vida);
    printf("For�a: %d\n\n", monstro->forca);
}
