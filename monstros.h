// ARQUIVO DOS MONSTROS

typedef struct{
	char nome[16];
	int vida;
	int forca;
	
}monstro;

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
	
	
}return (rand() % (max - min + 1)) + min;


Monstro criarMonstrosRandom(){
	
	Monstro monstro;
	strcpy(monstro.nome,nomes[criarMonstrosRandom(0, quantidadesNomes - 1)]);
	monstro.vida = geradorMonstros(10, 30);
	monstro.forca = geradorMonstros(3, 15);
	
	return monstro;
}
