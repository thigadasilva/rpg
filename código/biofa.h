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
        printf("Você não tem energia suficiente para atacar!\n");
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
                printf("Você atacou fisicamente!\n");
                personagem->ienergia -= custoEnergia;
                if (danoCritico > 0) {
                    printf("Você causou %d de Dano Crítico!\n\n", danoCritico);
                    boss->vida -= danoCritico;
                    printf("O Biofa está com %d de hp restantes.\n", boss->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    turno += 1;
                } else {
                    boss->vida -= danoTotal;
                    printf("Você atacou o Biofa por %d de dano!\n", danoTotal);
                    printf("O Biofa está com %d de hp restantes.\n", boss->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    turno += 1;
                }
            } else if (escolha2 == 2) {
                printf("Você usou uma habilidade!\n");
                // Implementar habilidade específica
            } else if (escolha2 == 3) {
                break;
            }
            break;
        case 2: // Mago
            if (escolha2 == 1) {
                printf("Você lançou magias no Biofa!\n");
                personagem->ienergia -= custoEnergia;
                if (danoCritico > 0) {
                    printf("Você causou %d de Dano Crítico!\n\n", danoCritico);
                    boss->vida -= danoCritico;
                    printf("O Biofa está com %d de hp restantes.\n", boss->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    turno += 1;
                } else {
                    boss->vida -= danoTotal;
                    printf("Você atacou o Biofa por %d de dano!\n", danoTotal);
                    printf("O Biofa está com %d de hp restantes.\n", boss->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    turno += 1;
                }
            } else if (escolha2 == 2) {
                printf("Você usou uma habilidade!\n");
                // Implementar habilidade específica
            } else if (escolha2 == 3) {
                break;
            }
            break;
        case 3: // Arqueiro
            if (escolha2 == 1) {
                printf("Você atirou projéteis no Biofa!\n");
                personagem->ienergia -= custoEnergia;
                if (danoCritico > 0) {
                    printf("Você causou %d de Dano Crítico!\n\n", danoCritico);
                    boss->vida -= danoCritico;
                    printf("O Biofa está com %d de hp restantes.\n", boss->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    turno += 1;
                } else {
                    boss->vida -= danoTotal;
                    printf("Você atacou o Biofa por %d de dano!\n", danoTotal);
                    printf("O Biofa está com %d de hp restantes.\n", boss->vida);
                    	printf("Sua Energia atual: %d", personagem->ienergia);
				turno += 1;
					break;
			} 
			}else if(escolha2 == 2){
				printf("Você usou uma habilidade!\n");
				turno += 1;
					break;
			} else if(escolha2 == 3){
				break;
			}
		break;
			case 4:
			if (escolha2 == 1){
				printf("\nVocê apunhalou Biofa!\n");
				personagem->ienergia -= custoEnergia;
							if(danoCritico > 0){
				printf("Você causou %d de Dano Crítico!\n\n", danoCritico);
				boss->vida -= danoCritico;
				printf("O Biofa está com %d de hp restantes.\n", boss->vida);
			    printf("Energia atual: %d\n", personagem->ienergia);
				printf("O Biofa está com %d de hp restantes.\n", boss->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
				turno += 1;
					break;
	} else{
				boss->vida -= danoTotal;
				printf("Você atacou o Biofa por %d de dano!\n", danoTotal);
				printf("O Boss está com %d de hp restantes.\n\n", boss->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
				turno += 1;
					break;
			} 
			}else if(escolha2 == 2){
				printf("Você usou uma habilidade!\n");
				turno += 1;
					break;
			} else if(escolha2 == 3){
				break;
			}
		break;
	}
}



// FunÃ§Ã£o para criar o Boss
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
		printf("Você não conseguiu fugir!\n");
		return 0;
	}
}


int calcularDanoBoss(Boss *boss) {
    int dano = boss->forca;
    int chanceCritico = rand() % 100;
    if (chanceCritico < 20) {
        dano += boss->forca;
        printf("Dano Crítico!\n");
    }
    return dano;
}

void bossAtaca(Boss *boss, Atributos *personagem) {
    int dano = calcularDanoBoss(boss);
    personagem->ivida -= dano;
    turno--;
    printf("O %s atacou você com %d de dano!\n", boss->nome, dano);
}



// FunÃ§Ã£o para imprimir o status do Boss
void imprimirBoss(Boss *boss) {
    printf("\n** O poderoso %s te desafiou! **\n", boss->nome);
    printf("\n------------------------------STATUS DO BOSS---------------------------------\n");
    printf("%s\n", boss->nome);
    printf("Vida: %d\n", boss->vida);
    printf("Força: %d\n", boss->forca);
}

void iniciarBatalhaContraBoss(int classe, Atributos *personagem, Boss *boss) {
    // Lógica de batalha específica para o Boss
    int chanceFuga = calcularChanceFuga(*personagem);
    int fugiu = 0;
    int turno = 0;
    do{
         	if(turno == 0){
	int escolha;
   		printf(" 1. Atacar\n 2. Inventário\n 3. Fugir\n\n");
    		scanf("%d", &escolha);
	switch(escolha){
		case 1:
			atacarBoss(classe, personagem, boss);
			printf("Turno: %d", turno);
			turno += 1;
			break;
		case 2:
			printf(" INVENTÁRIO:\n");
			printf(" Poções de vida pequena: %d\n", personagem->potionsHpMin);
			printf(" Poções de vida grande: %d\n", personagem->potionsHpMax);
			printf(" Poções de Energia pequena: %d\n", personagem->potionsEnergiaMin);
			printf(" Poções de Energia Grande: %d\n\n", personagem->potionsEnergiaMax);
			
			inventario(personagem);
			break;
		case 3:
		fugiu =	tentarFuuga(chanceFuga, *boss);
		if (fugiu){
			boss->vida = 0;
		}
			break;
		default:
			printf("Opção inválida!");	
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
	printf("Você fugiu com sucesso!");	
	}else if (boss->vida <= 0){
		printf("\nVocê venceu!\n\n");
		personagem->xp += rand() % 20 + 50;
		printf("XP atual: %d", personagem->xp);
		personagem->moeda += rand() % 20 + 100;
		printf("\n Moedas de ouro atuais: %d\n", personagem->moeda);
	}
    }


