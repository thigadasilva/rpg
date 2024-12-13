// Estrutura do Boss
typedef struct {
    char nome[50];
    int vida;
    int forca;
    int ataque;
}Biofa;


void atacarBoss(int classe, Atributos *personagem, Boss *boss) {
    int custoEnergia = 10;
    int danoBase = personagem->iforca + personagem->iagilidade + personagem->idestreza + personagem->iinteligencia;
    int danoAleatorio = rand() % 5 + 1;
    int danoTotal = danoBase + danoAleatorio;
    int danoCritico = 0;

    if (personagem->ienergia < custoEnergia) {
        printf("Voc� n�o tem energia suficiente para atacar!\n");
        return;
    }

    if (rand() % 100 + 1 <= personagem->iagilidade * 2) {
        danoCritico = danoTotal * 2;
    }

    int escolha2;
    printf(" 1. Golpear\n 2. Usar Habilidade\n 3. Voltar\n");
    scanf("%d", &escolha2);

    switch (classe) {
        case 1: // Guerreiro
            if (escolha2 == 1) {
                printf("Voc� atacou fisicamente!\n");
                personagem->ienergia -= custoEnergia;
                if (danoCritico > 0) {
                    printf("Voc� causou %d de Dano Cr�tico!\n\n", danoCritico);
                    boss->vida -= danoCritico;
                    printf("O Biofa est� com %d de hp restantes.\n", boss->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    turno += 1;
                } else {
                    boss->vida -= danoTotal;
                    printf("Voc� atacou o Biofa por %d de dano!\n", danoTotal);
                    printf("O Biofa est� com %d de hp restantes.\n", boss->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    turno += 1;
                }
            } else if (escolha2 == 2) {
                printf("Voc� usou uma habilidade!\n");
                // Implementar habilidade espec�fica
            } else if (escolha2 == 3) {
                break;
            }
            break;
        case 2: // Mago
            if (escolha2 == 1) {
                printf("Voc� lan�ou magias no Biofa!\n");
                personagem->ienergia -= custoEnergia;
                if (danoCritico > 0) {
                    printf("Voc� causou %d de Dano Cr�tico!\n\n", danoCritico);
                    boss->vida -= danoCritico;
                    printf("O Biofa est� com %d de hp restantes.\n", boss->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    turno += 1;
                } else {
                    boss->vida -= danoTotal;
                    printf("Voc� atacou o Biofa por %d de dano!\n", danoTotal);
                    printf("O Biofa est� com %d de hp restantes.\n", boss->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    turno += 1;
                }
            } else if (escolha2 == 2) {
                printf("Voc� usou uma habilidade!\n");
                // Implementar habilidade espec�fica
            } else if (escolha2 == 3) {
                break;
            }
            break;
        case 3: // Arqueiro
            if (escolha2 == 1) {
                printf("Voc� atirou proj�teis no Biofa!\n");
                personagem->ienergia -= custoEnergia;
                if (danoCritico > 0) {
                    printf("Voc� causou %d de Dano Cr�tico!\n\n", danoCritico);
                    boss->vida -= danoCritico;
                    printf("O Biofa est� com %d de hp restantes.\n", boss->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    turno += 1;
                } else {
                    boss->vida -= danoTotal;
                    printf("Voc� atacou o Biofa por %d de dano!\n", danoTotal);
                    printf("O Biofa est� com %d de hp restantes.\n", boss->vida);
                    	printf("Sua Energia atual: %d", personagem->ienergia);
				turno += 1;
					break;
			} 
			}else if(escolha2 == 2){
				printf("Voc� usou uma habilidade!\n");
				turno += 1;
					break;
			} else if(escolha2 == 3){
				break;
			}
		break;
			case 4:
			if (escolha2 == 1){
				printf("\nVoc� apunhalou Biofa!\n");
				personagem->ienergia -= custoEnergia;
							if(danoCritico > 0){
				printf("Voc� causou %d de Dano Cr�tico!\n\n", danoCritico);
				boss->vida -= danoCritico;
				printf("O Biofa est� com %d de hp restantes.\n", boss->vida);
			    printf("Energia atual: %d\n", personagem->ienergia);
				printf("O Biofa est� com %d de hp restantes.\n", boss->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
				turno += 1;
					break;
	} else{
				boss->vida -= danoTotal;
				printf("Voc� atacou o Biofa por %d de dano!\n", danoTotal);
				printf("O Boss est� com %d de hp restantes.\n\n", boss->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
				turno += 1;
					break;
			} 
			}else if(escolha2 == 2){
				printf("Voc� usou uma habilidade!\n");
				turno += 1;
					break;
			} else if(escolha2 == 3){
				break;
			}
		break;
	}
}



// Função para criar o Boss
Boss criarBoss() {
    Boss boss;
    strcpy(boss.nome, "Biofa");
    boss.vida = 200;  
    boss.forca = 25;  
    return boss;
}

int calcularChanceFuuga(Atributos personagem) {
	int chanceFuga = (personagem.iagilidade + personagem.nivel);
		return chanceFuga;
};

int tentarFuuga(int chanceFuuga, Boss *boss){
	int roll = rand() % 20 + 1;
	if (roll <= chanceFuga){
		return 1;
	} else{
		printf("Voc� n�o conseguiu fugir!\n");
		return 0;
	}
}


int calcularDanoBoss(Boss *boss) {
    int dano = boss->forca;
    int chanceCritico = rand() % 100;
    if (chanceCritico < 20) {
        dano += boss->forca;
        printf("Dano Cr�tico!\n");
    }
    return dano;
}

void bossAtaca(Boss *boss, Atributos *personagem) {
    int dano = calcularDanoBoss(boss);
    personagem->ivida -= dano;
    turno--;
    printf("O %s atacou voc� com %d de dano!\n", boss->nome, dano);
}



// Função para imprimir o status do Boss
void imprimirBoss(Boss *boss) {
    printf("\n** O poderoso %s te desafiou! **\n", boss->nome);
    printf("\n------------------------------STATUS DO BOSS---------------------------------\n");
    printf("%s\n", boss->nome);
    printf("Vida: %d\n", boss->vida);
    printf("For�a: %d\n", boss->forca);
}

void iniciarBatalhaContraBoss(int classe, Atributos *personagem, Boss *boss) {
    // L�gica de batalha espec�fica para o Boss
    int chanceFuga = calcularChanceFuga(*personagem);
    int fugiu = 0;
    int turno = 0;
    do{
         	if(turno == 0){
	int escolha;
   		printf(" 1. Atacar\n 2. Invent�rio\n 3. Fugir\n\n");
    		scanf("%d", &escolha);
	switch(escolha){
		case 1:
			atacarBoss(classe, personagem, boss);
			printf("Turno: %d", turno);
			turno += 1;
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
		fugiu =	tentarFuuga(chanceFuga, *boss);
		if (fugiu){
			boss->vida = 0;
		}
			break;
		default:
			printf("Op��o inv�lida!");	
		} 
		} else if (boss->vida > 0 || turno == 1) {
            printf("\nTurno do Boss!\n");
            getch();
            bossAtaca(boss, personagem);
			printf("Turno: %d", turno);
        }
	 } while (personagem->ivida > 0 && boss->vida > 0);
	
	
	if(personagem->ivida <= 0){
		return;
	} else if(fugiu == 1){
	printf("Voc� fugiu com sucesso!");	
	}else if (boss->vida <= 0){
		printf("\nVoc� venceu!\n\n");
		personagem->xp += rand() % 20 + 50;
		printf("XP atual: %d", personagem->xp);
		personagem->moeda += rand() % 20 + 100;
		printf("\n Moedas de ouro atuais: %d\n", personagem->moeda);
	}
    }


