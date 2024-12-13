// Estrutura do Boss
typedef struct {
    char nome[50];
    int vida;
    int forca;
    int ataque;
}Boss;


void atacarBoss(int classe, Atributos *personagem, Boss *boss) {
		int berserkerDuracao = 30;
	int berserkerInicio = 0;
	int aumentoForca;
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

    	switch (classe){
		case 1:
			if(escolha2 == 1){
				printf("Você atacou fisicamente!\n");
				personagem->ienergia -= custoEnergia;
				if(danoCritico > 0){
				printf("Você causou %d de Dano Crítico!\n\n", danoCritico);
				boss->vida -= danoCritico;
			
				printf("O monstro está com %d de hp restantes.\n", boss->vida);
					printf("Energia atual: %d", personagem->ienergia);
				turno += 1;;
				break;
	} else{
		boss->vida -= danoTotal;
		printf("Você atacou o monstro por %d de dano!\n", danoTotal);
			printf("O monstro está com %d de hp restantes.\n", boss->vida);
			printf("Energia atual: %d", personagem->ienergia);
			turno += 1;
			break;
	}
			}else if(escolha2 == 2){		
				if (escolha2 == 2) {
        printf("1 - Impacto Fulminante\n2 - Berserker\n");
        int skill;
        scanf("%d", &skill);
        switch (skill) {
            case 1:
            	if (!verificarCooldown(&impactoFulminante)) {
                if (personagem->ienergia >= custoEnergia + 10) {
                    personagem->ienergia -= custoEnergia + 10;
                    boss->vida -= danoTotal + 20;
                    printf("impacto Fulminante causou %d de dano!\n", danoTotal + 20);
                    printf("O monstro está com %d de hp restantes.\n\n", boss->vida);
                   	printf("\nSua Energia atual: %d\n", personagem->ienergia);
                   		turno = !turno;
                } else {
                    printf("\nVocê não tem energia suficiente!\n");
                }
                 atualizarCooldown(&impactoFulminante);
			} else {
    		int tempoRestante = tempoRestanteCooldown(&impactoFulminante);
		}			
                break;
            case 2:
            	
            	
			
            	if (!verificarCooldown(&berserker)) {
             		 berserkerInicio = time(NULL);
                if (personagem->ienergia >= custoEnergia + 10) {
                    personagem->ienergia -= custoEnergia + 10;
                    aumentoForca = rand() %  10 + 3;
                    personagem->iforca = (personagem->iforca + aumentoForca);
                    printf("Você está em modo Berserker e sua força aumentou em %d!\n", personagem->iforca);
                    printf("\nSua Energia atual: %d\n", personagem->ienergia);
                    	turno = !turno;
                } else {
                    printf("Você não tem energia suficiente!\n");
                } 
                 atualizarCooldown(&berserker);
                 } else {
    		int tempoRestante = 
			tempoRestanteCooldown(&berserker);
		}	
	} if (berserkerInicio != 0 && time(NULL) - berserkerInicio <= berserkerDuracao) {
    // Habilidade ainda está ativa
} else if (berserkerInicio != 0) {
    personagem->iforca -= aumentoForca;
    berserkerInicio = 0;
    printf("A fúria do Berseker acabou.");
}
                break;
			}
			} else if(escolha2 == 3){
				break;
			}
		break;
			case 2:
			if (escolha2 == 1){
				printf("\nVocê lançou magias no inimigo!\n");
				personagem->ienergia -= custoEnergia;
				if(danoCritico > 0){
				printf("Você causou %d de Dano Crítico!\n\n", danoCritico);
				boss->vida -= danoCritico;
			
				printf("O monstro está com %d de hp restantes.\n", boss->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
			turno += 1;
				break;
	} else{
				boss->vida -= danoTotal;
				printf("Você atacou o monstro por %d de dano!\n", danoTotal);
			printf("O monstro está com %d de hp restantes.\n\n", boss->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
		turno += 1;
			break;
			} 
			}else if(escolha2 == 2){
			  printf("1 - Drenador de Almas\n 2 - Furia de Pegasus\n");
        int skill;
        scanf("%d", &skill);
        switch (skill) {
            case 1:
            	if (!verificarCooldown(&drenadorDeAlmas)) {
                if (personagem->ienergia >= custoEnergia + 10) {
                    personagem->ienergia -= custoEnergia + 10;
                    boss->vida -= danoTotal + 20;
                    printf("Drenador de Almas causou %d de dano!\n", danoTotal + 20);
                    printf("O monstro está com %d de hp restantes.\n\n", boss->vida);
                   	printf("\nSua Energia atual: %d\n", personagem->ienergia);
                   	turno = !turno;
                } else {
                    printf("\nVocê não tem energia suficiente!\n");
                }
                 atualizarCooldown(&drenadorDeAlmas);
			} else {
    		int tempoRestante = tempoRestanteCooldown(&drenadorDeAlmas);
		}			
                break;
            case 2:
            	if (!verificarCooldown(&furiaDePegasus)) {
                if (personagem->ienergia >= custoEnergia + 10) {
                    personagem->ienergia -= custoEnergia + 10;
                    boss->vida -= danoTotal + 10;
                    printf("Você retirou %d de vida do monstro!\n", danoTotal);
                    printf("O monstro está com %d de hp restantes.\n\n", boss->vida);
                    printf("\nSua Energia atual: %d\n", personagem->ienergia);
                    turno = !turno;
                } else {
                    printf("Você não tem energia suficiente!\n");
                } 
                 atualizarCooldown(&furiaDePegasus);
                 } else {
    		int tempoRestante = tempoRestanteCooldown(&furiaDePegasus);
		}
				break;
			}
			}else if(escolha2 == 3){
				break;
			}
		break;
			case 3:
			if (escolha2 == 1){
				printf("\nVocê atirou projéteis no inimigo!\n");
				personagem->ienergia -= custoEnergia;
							if(danoCritico > 0){
				printf("Você causou %d de Dano Crítico!\n\n", danoCritico);
				boss->vida -= danoCritico;
				
		
				printf("O monstro está com %d de hp restantes.\n", boss->vida);
					printf("Sua Energia atual: %d", personagem->ienergia);
				turno += 1;
					break;
	} else{
				boss->vida -= danoTotal;
				printf("Você atacou o monstro por %d de dano!\n", danoTotal);
				printf("O monstro está com %d de hp restantes.\n\n", boss->vida);
					printf("Sua Energia atual: %d", personagem->ienergia);
				turno += 1;
					break;
			} 
			}else if(escolha2 == 2){
						  printf("1 - Rajada de Flechas\n2 - Tiro Certeiro\n");
        int skill;
        scanf("%d", &skill);
        switch (skill) {
            case 1:
            	if (!verificarCooldown(&rajadaDeFlechas)) {
                if (personagem->ienergia >= custoEnergia + 10) {
                    personagem->ienergia -= custoEnergia + 10;
                    boss->vida -= danoTotal - 30;
                    boss->vida -= danoTotal - 30;
                    boss->vida -= danoTotal - 30;
                    printf("Rajada de flechas acertou o inimigo 3 vezes!\n");
                    printf("Rajada causou %d de dano!\n", danoTotal - 30);
                    printf("Rajada causou %d de dano!\n", danoTotal - 30);
                    printf("Rajada causou %d de dano!\n", danoTotal - 30);
                    printf("O monstro está com %d de hp restantes.\n\n", boss->vida);
                   	printf("\nSua Energia atual: %d\n", personagem->ienergia);
                   	turno = !turno;
                } else {
                    printf("\nVocê não tem energia suficiente!\n");
                }
                 atualizarCooldown(&rajadaDeFlechas);
			} else {
    		int tempoRestante = tempoRestanteCooldown(&rajadaDeFlechas);
		}			
                break;
            case 2:
            	if (!verificarCooldown(&tiroCerteiro)) {
                if (personagem->ienergia >= custoEnergia + 10) {
                    personagem->ienergia -= custoEnergia + 10;
                    boss->vida -= danoTotal * 2;
                    printf("Você acertou um ponto vital e causou %d de dano!\n", danoTotal * 2);
                    printf("O monstro está com %d de hp restantes.\n\n", boss->vida);
                    printf("\nSua Energia atual: %d\n", personagem->ienergia);
                    turno = !turno;
                } else {
                    printf("Você não tem energia suficiente!\n");
                } 
                 atualizarCooldown(&tiroCerteiro);
                 } else {
    		int tempoRestante = tempoRestanteCooldown(&tiroCerteiro);
		}
				turno += 1;
					break;
			} 
			}else if(escolha2 == 3){
				break;
			}
		break;
			case 4:
			if (escolha2 == 1){
				printf("\nVocê apunhalou o inimigo!\n");
				personagem->ienergia -= custoEnergia;
							if(danoCritico > 0){
				printf("Você causou %d de Dano Crítico!\n\n", danoCritico);
				boss->vida -= danoCritico;
				
				
				printf("O monstro está com %d de hp restantes.\n", boss->vida);
					printf("Sua Energia atual: %d", personagem->ienergia);
				turno += 1;
					break;
	} else{
				boss->vida -= danoTotal;
				printf("Você atacou o monstro por %d de dano!\n", danoTotal);
				printf("O monstro está com %d de hp restantes.\n\n", boss->vida);
					printf("Sua Energia atual: %d", personagem->ienergia);
				turno += 1;
					break;
			} 
			}else if(escolha2 == 2){
	  if (escolha2 == 2) {
        printf("1 - Chuva de Lâminas\n2 - Roubo de Vida\n");
        int skill;
        scanf("%d", &skill);
        switch (skill) {
            case 1:
            	if (!verificarCooldown(&chuvaDeLaminas)) {
                if (personagem->ienergia >= custoEnergia + 10) {
                    personagem->ienergia -= custoEnergia + 10;
                    boss->vida -= danoTotal + 20;
                    printf("Chuva de Lâminas causou %d de dano!\n", danoTotal + 20);
                    printf("O monstro está com %d de hp restantes.\n\n", boss->vida);
                   	printf("\nSua Energia atual: %d\n", personagem->ienergia);
                   	turno = !turno;
                } else {
                    printf("\nVocê não tem energia suficiente!\n");
                }
                 atualizarCooldown(&chuvaDeLaminas);
			} else {
    		int tempoRestante = 
			tempoRestanteCooldown(&chuvaDeLaminas);
		}			
                break;
            case 2:
            	if (!verificarCooldown(&rouboDeVida)) {
                if (personagem->ienergia >= custoEnergia + 10) {
                    personagem->ienergia -= custoEnergia + 10;
                    boss->vida -= danoTotal;
                    personagem->ivida += danoTotal / 2;
                    printf("Você roubou %d de vida do monstro!\n", danoTotal);
                    printf("O monstro está com %d de hp restantes.\n\n", boss->vida);
                    printf("\nSua Energia atual: %d\n", personagem->ienergia);
                    printf("Seu Hp atual: %d\n", personagem->ivida);
                    	turno = !turno;
                } else {
                    printf("Você não tem energia suficiente!\n");
                } 
                 atualizarCooldown(&rouboDeVida);
                 } else {
    		int tempoRestante = 
			tempoRestanteCooldown(&rouboDeVida);
		}			
                break;
            default:
                printf("Opção inválida!\n");
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

//funcao pra introduzir o chefao Biofa
void imprimirIntroBiofa(){
	printf("\n---------------------------------INTRODUÇÃO---------------------------------\n");
	printf("Na escuridão da montanha Dedo de Deus, um monstro mecânico desperta.\n");
	printf("Biofa, a criação mais Ambiciosa de Fobia, foi concebida para um proposito sinistro:\n");
	printf("impedir que o Heroi alcance o topo da montanha.\n");
	printf("Onde o Rei Demônio Supremo, possessivo do corpo de Márcio,\n");
	printf("Mestre do Heroi, aguarda seu destino.\n");
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
