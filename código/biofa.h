
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
// Função para imprimir o status do Boss
void imprimirBoss(Boss *boss) {
    printf("\n** Um poderoso %s te desafiou! **\n", boss->nome);
    printf("\n------------------------------STATUS DO BOSS---------------------------------\n");
    printf("%s\n", boss->nome);
    printf("Vida: %d\n", boss->vida);
    printf("Força: %d\n", boss->forca);
    //printf("Defesa: %d\n\n", boss->defesa);
}


