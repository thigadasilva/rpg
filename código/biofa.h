/* Vai seguir a história matar os monstrinho ai quando formos encaminhar para o bosso colocamos isso no rpg.h =(codigo principal)=
    Após a vitória sobre o monstro, o Boss é desafiado
    printf("\n** Você derrotou o monstro! Agora, prepare-se para enfrentar um poderoso Boss! **\n");
    getch();
    system("cls");
    imprimirBoss(&boss);
    iniciarbatalha(classe, &personagem[0], (Monstro*)&boss); // Enfrenta o Boss
*/


// Estrutura do Boss
typedef struct {
    char nome[50];
    int vida;
    int forca;
    int ataque;
    int defesa;
}Boss;

// Função para criar o Boss
Boss criarBoss() {
    Boss boss;
    strcpy(boss.nome, " Biofa ");
    boss.vida = 200;  
    boss.forca = 25;  
    //boss.defesa = ; 
    return boss;
}

int calcularDano(Boss *boss){
	int dano = Boss->forca;
	int chancedeCritico = rand() % 100;
	if(chancedeCritico < 20){
		dano += Boss->forca;
		printf("Dano Cr�tico!\n");
	}
	return dano;
}

// Função para imprimir o status do Boss
void imprimirBoss(Boss *boss) {
    printf("\n** Um poderoso %s te desafiou! **\n", boss->nome);
    printf("\n------------------------------STATUS DO BOSS---------------------------------\n");
    printf("%s\n", boss->nome);
    printf("Vida: %d\n", boss->vida);
    printf("Força: %d\n", boss->forca);
}


