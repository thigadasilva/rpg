// Estrutura do Boss
typedef struct {
    char nome[50];
    int dano;
    int custoEnergia;
    int cooldown;
} HabilidadeMarcio;

typedef struct {
    char nome[50];
    int vida;
    int forca;
    int ataque;
    HabilidadeMarcio habilidadesM[2];
}Boss3;

int calcularDanoBoss3(Boss3 *boss3) {
    int dano = boss3->forca / 1.5;
    int chanceCritico = rand() % 100;
    if (chanceCritico < 20) {
        dano *= 2;
        printf("Dano Cr�tico!\n");
    }
    dano += rand() % (boss3->forca / 5);
    return dano;
}

HabilidadeMarcio MaodaPerdicao = {
    "M�o da Perdi��o",
    0, 
    20,
    30
};
HabilidadeMarcio PactodoDemonio = {
    "Pacto do Rei Dem�nio",
    50,
    30,
    45
};
HabilidadeMarcio Ambicaodiabolica = {
    "Ambi��o diab�lica",
    50,
    30,
    45
};

void aplicarMaodaPerdicao(Boss3 *boss3, Atributos *personagem) {
    int dano = calcularDanoBoss3(boss3) + MaodaPerdicao.dano / 2;
    personagem->ivida -= dano;
    printf("%s usou M�o da Perdi��o em voc�!\n", boss3->nome);
    printf("Voc� tomou %d de dano!", dano);
}
void aplicarPactodoDemonio(Boss3 *boss3) {
    boss3->vida += PactodoDemonio.dano;
    boss3->forca += PactodoDemonio.dano;
    boss3->ataque += PactodoDemonio.dano;
    printf("%s ativou o Pacto com o Rei Dem�nio!\n", boss3->nome);
    printf("%s est� mais forte agora!\n", boss3->nome);
}
void aplicarAmbicaodiabolica(Boss3 *boss3, Atributos *personagem) {
    personagem->iforca -= Ambicaodiabolica.dano;
     personagem->iinteligencia -= Ambicaodiabolica.dano;
      personagem->idestreza -= Ambicaodiabolica.dano;
       personagem->iagilidade -= Ambicaodiabolica.dano;
    printf("%s ativou Ambi��o Demon�aca!\n", boss3->nome);
    printf("Voc� foi enfraquecido!\n");
}

Boss3 criarboss3(HabilidadeMarcio habilidadesM[2]) {
    Boss3 boss3;
    strcpy(boss3.nome, "M�rcio, o Rei Dem�nio Supremo");
    boss3.vida = 3000;  
    boss3.forca = 95;  
    boss3.habilidadesM[0] = habilidadesM[0];
    boss3.habilidadesM[1] = habilidadesM[1];
    boss3.habilidadesM[2] = habilidadesM[2];
    return boss3;
}


void atacarBoss3(int classe, Atributos *personagem, Boss3 *boss3) {
  if (rand() % 100 < 30) { // Chance de usar habilidade
        int habilidadeAleatoria = rand() % 3;
        if (habilidadeAleatoria == 0) {
            aplicarPactodoDemonio(boss3);
        } else if (habilidadeAleatoria == 1){
            aplicarMaodaPerdicao(boss3, personagem);
        } else {
            aplicarAmbicaodiabolica(boss3, personagem);
        }
} else {
    int dano = calcularDanoBoss3(boss3);
    personagem->ivida -= dano;
    printf("O %s atacou voc� com %d de dano!\n", boss3->nome, dano);
  }
}

//funcao pra introduzir o chefao MarcioBoss
void imprimirIntroMarcio(){
	printf("\n---------------------------------!!!O DESAFIO FINAL!!!---------------------------------\n");
	printf("M�rcio, o Guerrerio Lend�rio corrompido, agora servo do mal.\n");
	printf("O Rei Dem�nio Supremo, seu senhor, o transformou em uma arma de destrui��o.\n");
	printf("Diante de voc�, est� o Rei Dem�nio Supremo, possuindo o corpo do lend�rio guerreiro, M�rcio.");
	printf("\n A era da destrui��o come�ou. O �ltimo vil�o poderoso e diab�lico, o aguarda...\n\n");
	getch();
}

void imprimirDialogoMarcio(){
	printf("Ent�o... Voc� conseguiu... Subir ao topo...");
	getch();
	printf("Voc�, uma criatura t�o miser�vel e cheia de si, bancando ser o HER�I,\n � o que esse mundo menos precisa.\n");
	getch();
	printf("Antes de voc�, vieram 4 her�is lend�rios, que conseguiram me expurgar para fora desse mundo.\n");
	getch();
	printf("Mas gra�as a um humano, com tamanha arrogancia, conhecedor de TAL PODER...\n");
	getch();
	printf("Livrou-me do selo, que me guardava, oferecendo a Alma de um lendario HER�I, que ainda habitava esse mundo...");
	getch();
	printf("Agora, ningu�m ir� me deter! Nem mesmo voc�.\n Prepare-se para o seu �ltimo confronto.\n ");
	getch();
	printf("Essa ser� seu �ltimo dia no mercado de trabal-\n Digo, aqui ser� o seu �ltimo confronto!!!\n");
	getch();
	printf("Raios e trov�es podem ser ouvidos de fundo, uma forte tempestade e\numa forte ventania surge soprando tudo\n para os ares.\n");
}

// Função para imprimir o status do boss3
void imprimirBoss3(Boss3 *boss3) {
    printf("\n** O poderoso %s te desafiou! **\n", boss3->nome);
    printf("\n------------------------------STATUS DO BOSS---------------------------------\n");
    printf("%s\n", boss3->nome);
    printf("Vida: %d\n", boss3->vida);
    printf("For�a: %d\n", boss3->forca);
}

void iniciarBatalhaContraBoss3(int classe, Atributos *personagem, Boss3 *boss3) {
    // L�gica de batalha espec�fica para o boss3
    int turno = 0;
     while (personagem->ivida > 0 && boss3->vida > 0){
     	 printf("Vida atual: %d\nVida de Marcio, o Rei Dem�nio Supremo: %d\n", personagem->ivida, boss3->vida);
         	if(turno == 0){
	int escolha;
   		printf(" 1. Atacar\n 2. Invent�rio\n 3. Fugir\n\n");
    		scanf("%d", &escolha);
    		fflush(stdin);
	switch(escolha){
		case 1:
			atacarBoss3(classe, personagem, boss3);
				turno = !turno;
			break;
		case 2:
			printf(" INVENT�RIO:\n");
			printf(" Po��es de vida pequena: %d\n", personagem->potionsHpMin);
			printf(" Po��es de vida grande: %d\n", personagem->potionsHpMax);
			printf(" Po��es de Energia pequena: %d\n", personagem->potionsEnergiaMin);
			printf(" Po��es de Energia Grande: %d\n\n", personagem->potionsEnergiaMax);
			inventario(personagem);
			break;
		case 3:
			printf("\nVoc� n�o pode fugir do Chef�o.\n");
			turno = !turno;
			break;
		default:
			printf("\nOp��o inv�lida!");	
		} 
	} else {
            printf("\nTurno do Boss!\n");
            getch();
            atacarBoss3(classe, personagem, boss3);
            turno = !turno;
        }
         if (personagem->ivida <= 0 || boss3->vida <= 0) {
            break;
        }
	  }
	  
	  
	if (personagem->ivida <= 0) {
    	if (personagem->segundasChances > 0) {
		        personagem->segundasChances--;
		        for(int i = personagem->segundasChances; i > 0; i--){
		        personagem->ivida = 300;
		        personagem->iforca += 10;
		        personagem->iinteligencia += 10;
		        personagem->iagilidade += 10;
		        personagem->idestreza += 10;
		        if(i == 4){
		        	printf("Voc� sente uma presen�a poderosa e benevolente.\n");
		        	printf("Diego, a lenda dos Guerreiros est� presente.\n");
		        	printf("Voc� sente Diego te fortalecendo.\n");
				} else if (i== 3){
					printf("Voc� sente uma forte presen�a.\n");
		        	printf("Lucas, o Mestre dos Magos est� presente.\n");
		        	printf("Voc� sente Lucas te fortalecendo.\n");
				} else if (i == 2){
					printf("Voc� pensou que estava prestes a morrer, mas\n");
		        	printf("Levi, o maior dos Arqueiros est� presente.\n");
		        	printf("Voc� sente Levi te fortalecendo.\n");
				} else if (i == 1){
					printf("Algo toca as suas costas.\n");
		        	printf("Thiago, o Rei dos Ladr�es est� presente.\n");
		        	printf("Voc� sente Thiago te fortalecendo.\n");
				}
		        printf("Vida restaurada: %d\n", personagem->ivida);
		        printf("Atributos melhorados!\n");
		    }
    } else {
        printf("Voc� morreu.\n");
    }
} else if (boss3->vida <= 0){
		printf("\nVoc� venceu!\n\n");
		printf("Os esp�ritos dos lend�rios her�is est�o muito orgulhosos de voc�.\n");
		printf("M�rcio morreu, por�m isto n�o deve ser celebrado.");
		printf("Ele estava sendo controlado pelo Rei Dem�nio.\n");
		printf("E infelizmente, n�o havia outra sa�da.");
		printf("O mundo jaz em paz agora que novamente, o Rei dem�nio foi expurgado daqui.");
		return;
	} 
}
