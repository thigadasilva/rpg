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
	strcpy(fobia.nome, "Fobia, o Ciborgue Demoníaco");
	fobia.vida = 300;
	fobia.forca = 30;
	fobia.ataque = 20;
	strcpy(fobia.hab1, "Ataque Cibernético");
	strcpy(fobia.hab2, "Explosão de energia");	
	return fobia;
}

void imprimirIntroFobia(){
	printf("\n---------------------------------INTRODUÇÃO---------------------------------\n");
	printf("Após a derrota de Biofa, seu robô leal, Fobia jurou vingança contra você.\n");
	printf("Desesperado, ele buscou a ajuda do Rei Demônio Supremo, Márcio.\n");
	printf("Em troca de lealdade, Márcio concedeu a Fobia uma transformação completa e poderosa.");
	printf("Agora, Fobia se tornou um ciborgue demoníaco, pronto para buscar sua vingança!\n\n");
	getch();
}

int calcularDano(Chefao *fobia){
	int dano = fobia->ataque;
	int chancedeCritico = rand() % 100;
	if(chancedeCritico < 20){
		dano += fobia->forca;
		printf("Dano Crítico!\n");
	}
	return dano;
}

void imprimirChefao(Chefao *fobia){
	printf("O chefão %s busca sua vingança!\n", fobia->nome);
	printf("\n---------------------------------STATUS---------------------------------\n");
	printf("Nome: %s\n", fobia->nome);
	printf("Vida: %d\n", fobia->vida);
	printf("Força: %d\n", fobia->forca);
	printf("ataque: %d\n", fobia->ataque);
	printf("Habilidades: %s, %s\n\n", fobia->hab1, fobia->hab2);
	getch();
}
