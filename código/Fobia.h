// Estrutura do Boss2
typedef struct {
    char nome[50];
    int vida;
    int forca;
    int ataque;
}boss2;


void atacarBoss2(int classe, Atributos *personagem, Boss2 *boss2) {
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
                    boss2->vida -= danoCritico;
                    printf("O fobia está com %d de hp restantes.\n", boss->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    break;
                } else if (danoCritico < 0){
                    boss2->vida -= danoTotal;
                    printf("Você atacou o fobia por %d de dano!\n", danoTotal);
                    printf("O Fobia está com %d de hp restantes.\n", boss2->vida);
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
                printf("Você lançou magias no Fobia!\n");
                personagem->ienergia -= custoEnergia;
                if (danoCritico > 0) {
                    printf("Você causou %d de Dano Crítico!\n\n", danoCritico);
                    boss2->vida -= danoCritico;
                    printf("O Fobia está com %d de hp restantes.\n", boss2->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    break;
                } else {
                    boss2->vida -= danoTotal;
                    printf("Você atacou o Fobia por %d de dano!\n", danoTotal);
                    printf("O Fobia está com %d de hp restantes.\n", boss2->vida);
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
                printf("Você atirou projéteis no Fobia!\n");
                personagem->ienergia -= custoEnergia;
                if (danoCritico > 0) {
                    printf("Você causou %d de Dano Crítico!\n\n", danoCritico);
                    boss2->vida -= danoCritico;
                    printf("O Fobia está com %d de hp restantes.\n", boss2->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                     break;
                } else {
                    boss->vida -= danoTotal;
                    printf("Você atacou o Fobia por %d de dano!\n", danoTotal);
                    printf("O Fobia está com %d de hp restantes.\n", boss2->vida);
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
				printf("\nVocê apunhalou Fobia!\n");
				personagem->ienergia -= custoEnergia;
							if(danoCritico > 0){
				printf("Você causou %d de Dano Crítico!\n\n", danoCritico);
				boss2->vida -= danoCritico;
				printf("O Fobia está com %d de hp restantes.\n", boss2->vida);
			    printf("Energia atual: %d\n", personagem->ienergia);
				printf("O Fobia está com %d de hp restantes.\n", boss2->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
				break;
	} else{
				boss2->vida -= danoTotal;
				printf("Você atacou o Fobia por %d de dano!\n", danoTotal);
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
				printf("Você atacou o Fobia por %d de dano!\n", danoTotal + 20);
				printf("O Boss está com %d de hp restantes.\n\n", boss->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
						break;
					} else if(skill == 2){
				printf("\nRoubo de vida!\n");
				personagem->ienergia -= custoEnergia + 10;
				boss->vida -= danoTotal;
				personagem->ivida += danoTotal;
				printf("Você roubou %d de vida do boss Fobia!\n", danoTotal);
				printf("O Boss está com %d de hp restantes.\n\n", boss2->vida);
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
Boss criarBoss2() {
    Boss2 boss2;
    strcpy(boss2.nome, "Fobia");
    boss2.vida = 420;  
    boss2.forca = 37;  
    return boss2;
}





int calcularDanoBoss(Boss2 *boss2) {
    int dano = boss2->forca / 1.5;
    int chanceCritico = rand() % 100;
    if (chanceCritico < 20) {
        dano *= 2;
        printf("Dano Crítico!\n");
    }
    dano += rand() % (boss2->forca / 5);
    return dano;
}

void bossAtaca(Boss2 *boss2, Atributos *personagem) {
    int dano = calcularDanoBoss2(boss2);
    personagem->ivida -= dano;
    printf("O %s atacou você com %d de dano!\n", boss2->nome, dano);
}

//funcao pra introduzir o chefao Fobia
void imprimirIntroFobia(){
	printf("\n---------------------------------INTRODUÇÃO---------------------------------\n");
	printf("Após a derrota de Biofa, seu robô leal, Fobia jurou vingança contra você.\n");
	printf("Desesperado, ele buscou a ajuda do Rei Demônio Supremo, Márcio.\n");
	printf("Em troca de lealdade, Márcio concedeu a Fobia uma transformação completa e poderosa.");
	printf("Agora, Fobia se tornou um ciborgue demoníaco, pronto para buscar sua vingança!\n\n");
	getch();
}
// FunÃ§Ã£o para imprimir o status do Boss
void imprimirBoss(Boss *boss) {
    printf("\n** O poderoso %s te desafiou! **\n", boss->nome);
    printf("\n------------------------------STATUS DO BOSS---------------------------------\n");
    printf("%s\n", boss->nome);
    printf("Vida: %d\n", boss->vida);
    printf("Força: %d\n", boss->forca);
}

void iniciarBatalhaContraBoss2(int classe, Atributos *personagem, Boss2 *boss2) {
    // Lógica de batalha específica para o Boss
    int turno = 0;
     while (personagem->ivida > 0 && boss2->vida > 0){
     	 printf("Vida atual: %d\nVida de Fobia: %d\n", personagem->ivida, boss2->vida);
         	if(turno == 0){
	int escolha;
   		printf(" 1. Atacar\n 2. Inventário\n 3. Fugir\n\n");
    		scanf("%d", &escolha);
    		fflush(stdin);
	switch(escolha){
		case 1:
			atacarBoss2(classe, personagem, boss2);
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
            boss2Ataca(boss2, personagem);
            turno = !turno;
        }
         if (personagem->ivida <= 0 || boss2->vida <= 0) {
            break;
        }
	  }
	
	if(personagem->ivida < 0){
		printf("Você morreu.");
		return;
	} else if (boss2->vida <= 0){
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
