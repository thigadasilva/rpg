// Estrutura do Boss
typedef struct {
    char nome[50];
    int vida;
    int forca;
    int ataque;
}Boss;


void atacarBoss(int classe, Atributos *personagem, Boss *boss) {
    int custoEnergia = 10;
    int danoBase = personagem->iforca + personagem->iagilidade + personagem->idestreza + personagem->iinteligencia / 2;
    int danoAleatorio = rand() % 5 + 1;
    int danoTotal = danoBase + danoAleatorio;
    int danoCritico = 0;
    if (personagem->ienergia < custoEnergia) {
        printf("Você não tem energia suficiente para atacar!\n");
        return;
    }

    if (rand() % 100 + 1 <= personagem->iforca + personagem->iagilidade + personagem->idestreza + personagem->iinteligencia / 2) {
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
                    break;
                } else if (danoCritico < 0){
                    boss->vida -= danoTotal;
                    printf("Você atacou o Biofa por %d de dano!\n", danoTotal);
                    printf("O Biofa está com %d de hp restantes.\n", boss->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    break;
                }
            } else if (escolha2 == 2) {
                printf("Você usou uma habilidade!\n");
                // Implementar habilidade específica
                break;
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
                    break;
                } else {
                    boss->vida -= danoTotal;
                    printf("Você atacou o Biofa por %d de dano!\n", danoTotal);
                    printf("O Biofa está com %d de hp restantes.\n", boss->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                     break;
                }
            } else if (escolha2 == 2) {
                printf("Você usou uma habilidade!\n");
                // Implementar habilidade específica
                 break;
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
                     break;
                } else {
                    boss->vida -= danoTotal;
                    printf("Você atacou o Biofa por %d de dano!\n", danoTotal);
                    printf("O Biofa está com %d de hp restantes.\n", boss->vida);
                    	printf("Sua Energia atual: %d", personagem->ienergia);
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
				break;
	} else{
				boss->vida -= danoTotal;
				printf("Você atacou o Biofa por %d de dano!\n", danoTotal);
				printf("O Boss está com %d de hp restantes.\n\n", boss->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
				break;
			} 
		}	else if(escolha2 == 2){
				printf("1 - Máscara das Sombras (Te deixa invísivel)\n2 - Festival do Caçador (Copia atributos inimigos)\n");
				int skill;
				scanf("%d", &skill);
				switch(skill){
					if(skill == 1){
				printf("\nChuva de laminas!\n");
				personagem->ienergia -= custoEnergia + 10;
				boss->vida -= danoTotal + 20;
				printf("Você atacou o Biofa por %d de dano!\n", danoTotal + 20);
				printf("O Boss está com %d de hp restantes.\n\n", boss->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
						break;
					} else if(skill == 2){
				printf("\nRoubo de vida!\n");
				personagem->ienergia -= custoEnergia + 10;
				boss->vida -= danoTotal;
				personagem->ivida += danoTotal;
				printf("Você roubou %d de vida do boss Biofa!\n", danoTotal);
				printf("O Boss está com %d de hp restantes.\n\n", boss->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
						break;
					}
				}
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





int calcularDanoBoss(Boss *boss) {
    int dano = boss->forca / 1.5;
    int chanceCritico = rand() % 100;
    if (chanceCritico < 20) {
        dano *= 2;
        printf("Dano Crítico!\n");
    }
    dano += rand() % (boss->forca / 5);
    return dano;
}

void bossAtaca(Boss *boss, Atributos *personagem) {
    int dano = calcularDanoBoss(boss);
    personagem->ivida -= dano;
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
    int turno = 0;
     while (personagem->ivida > 0 && boss->vida > 0){
     	 printf("Vida atual: %d\nVida de Biofa: %d\n", personagem->ivida, boss->vida);
         	if(turno == 0){
	int escolha;
   		printf(" 1. Atacar\n 2. Inventário\n 3. Fugir\n\n");
    		scanf("%d", &escolha);
    		fflush(stdin);
	switch(escolha){
		case 1:
			atacarBoss(classe, personagem, boss);
				turno = !turno;
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
			printf("\nVocê não pode fugir do Chefão.\n");
			turno = !turno;
			break;
		default:
			printf("\nOpção inválida!");	
		} 
	} else {
            printf("\nTurno do Boss!\n");
            getch();
            bossAtaca(boss, personagem);
            turno = !turno;
        }
         if (personagem->ivida <= 0 || boss->vida <= 0) {
            break;
        }
	  }
	
	if(personagem->ivida < 0){
		printf("Você morreu.");
		return;
	} else if (boss->vida <= 0){
		printf("\nVocê venceu!\n\n");
		personagem->xp += rand() % 20 + 50;
		printf("XP atual: %d", personagem->xp);
		personagem->moeda += rand() % 20 + 100;
		printf("\n Moedas de ouro atuais: %d\n", personagem->moeda);
	} if(personagem->xp >= 100){
		personagem->xp -= personagem->xp;
		personagem->nivel += 1;
		printf("Você subiu de nível!\n");
		printf("Nível atual: %d", personagem->nivel);
		atualizarAtributos(classe, personagem);
	}
   
}

