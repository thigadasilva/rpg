typedef struct{
	char nome[200];
	int vida;
	int forca;
	int ataque;
	char hab1[50];
	char hab2[50];
} Chefao;

Chefao criarChefaoFobia(){
	Chefao fobia;
	strcpy(fobia.nome, "Fobia, o Ciborgue Demon�aco");
	fobia.vida = 300;
	fobia.forca = 30;
	fobia.ataque = 20;
	strcpy(fobia.hab1, "Ataque Cibern�tico");
	strcpy(fobia.hab2, "Explos�o de energia");	
	return fobia;
}

void imprimirIntroFobia(){
	printf("\n---------------------------------INTRODU��O---------------------------------\n");
	printf("Ap�s a derrota de Biofa, seu rob� leal, Fobia jurou vingan�a contra voc�.\n");
	printf("Desesperado, ele buscou a ajuda do Rei Dem�nio Supremo, M�rcio.\n");
	printf("Em troca de lealdade, M�rcio concedeu a Fobia uma transforma��o completa e poderosa.");
	printf("Agora, Fobia se tornou um ciborgue demon�aco, pronto para buscar sua vingan�a!\n\n");
	getch();
}

int calcularDano(Chefao *fobia){
	int dano = fobia->ataque;
	int chancedeCritico = rand() % 100;
	if(chancedeCritico < 20){
		dano += fobia->forca;
		printf("Dano Cr�tico!\n");
	}
	return dano;
}

void imprimirChefao(Chefao *fobia){
	printf("O chef�o %s busca sua vingan�a!\n", fobia->nome);
	printf("\n---------------------------------STATUS---------------------------------\n");
	printf("Nome: %s\n", fobia->nome);
	printf("Vida: %d\n", fobia->vida);
	printf("For�a: %d\n", fobia->forca);
	printf("ataque: %d\n", fobia->ataque);
	printf("Habilidades: %s, %s\n\n", fobia->hab1, fobia->hab2);
	getch();
}
