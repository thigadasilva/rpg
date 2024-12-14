// ARQUIVO DOS MONSTROS

typedef struct{
	char nome[100];
	int vida;
	int forca;
	int ataque;
	
}Monstro;

char *nomes[] = {

"Abnegai", // Jean colega de sala
"Trefilarco", // Victor Rafael colega da sala
"Danai", // Darlan colega da sala

"Biscainha", // christian baldas colega da sala
"Alferes", // Leoni Israel colega da sala
"Maculara", // Caique amaral ex aluno

"Lavarco", //Kaua colega da sala
"Freara", // eduardo ex aluno
"Ignotos", // Gustavo ex aluno

"Aquilatai", // Quecila colega da sala
"Minore", // Marrcio ex aluno
"Merego", // Mirelle colega da sala 
};

char *criaturas[] ={

"o Goblin",
"o Troll",
"o Dragão",
"o Orc",
"o Elfo Negro",
"o Anão",
"o Lich",
"o Vampiro",
"o Lobisomem",
"o Demônio",
"o Gigante",
"o Minotauro",
"o Cíclope",
};

const int quantidadeNomes = 12;
const int quantidadeCriaturas = 12;

int geradorMonstros(int min, int max){
	
	
return (rand() % (max - min + 1)) + min;
}

Monstro criarMonstrosRandom(){
	
	Monstro monstro;
 	 int indice = geradorMonstros(0, quantidadeNomes - 1);
 	 int indiceCriatura = geradorMonstros(0, quantidadeCriaturas - 1);
 	  sprintf(monstro.nome, "%s, %s", nomes[indice], criaturas[indiceCriatura]);
	monstro.vida = geradorMonstros(50, 70);
	monstro.forca = geradorMonstros(3, 15);
	monstro.ataque = geradorMonstros(1, 7);
	
	return monstro;
}
void imprimirMonstro(Monstro *monstro){
	printf("\n------------------------------------------------------------------------\n");
	printf("Um %s te encontrou!\n", monstro->nome);
    printf("\n---------------------------------STATUS---------------------------------\n");
    printf("%s\n", monstro->nome);
    printf("Vida: %d\n", monstro->vida);
    printf("Força: %d\n\n", monstro->forca);
    getch();
}
