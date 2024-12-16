int turno = 0;
void inventario(Atributos *personagem){
	int escolhaa;
	int escolha2;
	printf("  1. Poção de Vida\n  2. Poções de Energia\n  3. Voltar\n");
	scanf("%d", &escolha2);
	
	if (escolha2 == 1){
		printf(" 1. Poção Pequena\n 2. Poção Grande\n 3. Voltar\n");
		scanf("%d", &escolhaa);
		switch(escolhaa){
			case 1:
				if(personagem->potionsHpMin <= 0){
					printf("Você não tem poção!\n");
						} else{
							personagem->potionsHpMin -= 1;
							personagem->ivida += 50;
							printf("Você utilizou poção de vida e se curou em mais 50 de hp! Você está com %d\n", personagem->ivida);
							turno += 1;
							break;
	} 	case 2: 
	    	if(personagem -> potionsHpMax <= 0){
	    		printf("Você não tem poção!\n");
	    		turno += 1;
	    		break;
	} else{
		personagem->potionsHpMax -= 1;
		personagem->ivida += 100;
		printf("Você utilizou poção de vida e se curou em mais 50 de hp! Você está com %d\n", personagem->ivida);
		turno += 1;
		break;
			}
		}
	} 	else if(escolha2 == 2){
			printf(" 1. Poção Pequena\n 2. Poção Grande\n");
				scanf("%d", &escolhaa);
					switch(escolhaa){
						case 1:
						if(personagem->potionsEnergiaMin <= 0){
							printf("Você não tem poção!\n");
							turno += 1;
							break;
		} else{
		personagem->potionsEnergiaMin -= 1;
		personagem->ienergia += 50;
		printf("Você utilizou poção de energia pequena e se curou em mais 50 de energia! Você está com %d\n", personagem->ienergia);
		turno += 1;
		break;
	} case 2: 
			if(personagem->potionsEnergiaMax <= 0){
			printf("Você não tem poção!\n");
			turno += 1;
			break;
		} else{
		personagem->potionsEnergiaMax -= 1;
		personagem->ienergia += 100;
		printf("Você utilizou poção de energia e se curou em mais 50 de hp! Você está com %d\n", personagem->ienergia);
		turno += 1;
		break;
      } case 3:
      	break;
}  
		}
}

typedef struct {
    int cooldown; // tempo de recarga em segundos
    int ultimoUso; // tempo em que a habilidade foi usada pela última vez
} Habilidade;
// Guerreiro
Habilidade impactoFulminante = {30, 0};
Habilidade berserker = {30, 30};
// Mago
Habilidade drenadorDeAlmas = {30, 0};
Habilidade furiaDePegasus = {30, 0};
// Arqueiro
Habilidade rajadaDeFlechas = {30, 0};
Habilidade tiroCerteiro = {120, 0};
// Ladino
Habilidade chuvaDeLaminas = {30, 0}; 
Habilidade rouboDeVida = {30, 0};

int tempoRestanteCooldown(Habilidade *habilidade) {
    int tempoAtual = time(NULL);
    return habilidade->cooldown - (tempoAtual - habilidade->ultimoUso);
}

int verificarCooldown(Habilidade *habilidade) {
    int tempoAtual = time(NULL); // obtém o tempo atual
    int tempoRestante = habilidade->cooldown - (tempoAtual - habilidade->ultimoUso);
    if (tempoRestante > 0) {
        printf("Habilidade em cooldown. Tempo restante: %d segundos\n", tempoRestante);
        return 1; // habilidade em cooldown
    }
    return 0; // habilidade disponível
}
void atualizarCooldown(Habilidade *habilidade) {
    habilidade->ultimoUso = time(NULL);
}


// ATAQUE

void gameOver(	) {
    printf("\nVocê está morto!!\n");
	exit(0); 
}
void check(Atributos *personagem){
	if(personagem->ivida <= 0){
	gameOver();
	}
}

void atacar(int classe, Atributos *personagem, Monstro *monstro){
	int berserkerDuracao = 30;
	int berserkerInicio = 0;
	int aumentoForca;
	int custoEnergia = 10;
	int danoBase = personagem->iforca + personagem->iagilidade + personagem->idestreza + personagem->iinteligencia;
	int danoAleatorio = rand() % 5 + 1;
	int danoTotal = danoBase + danoAleatorio;
	int danoCritico = 0;
	int skill;
	
	 if (personagem->ienergia < custoEnergia) {
        printf("Você não tem energia suficiente para atacar!\n");
        return;
    }
	
	if(rand() % 100 + 1 <= personagem->iagilidade * 2){
		danoCritico = danoTotal * 2;
		danoTotal = danoBase + danoAleatorio;
	}

	int escolha2;
	printf("  1. Golpear\n  2. Usar Habilidade\n  3. Voltar\n");
	scanf("%d", &escolha2);

	switch (classe){
		case 1:
			if(escolha2 == 1){
				printf("Você atacou fisicamente!\n");
				personagem->ienergia -= custoEnergia;
				if(danoCritico > 0){
				printf("Você causou %d de Dano Crítico!\n\n", danoCritico);
				monstro->vida -= danoCritico;
			
				printf("O monstro está com %d de hp restantes.\n", monstro->vida);
					printf("Energia atual: %d", personagem->ienergia);
				turno += 1;;
				break;
	} else{
		monstro->vida -= danoTotal;
		printf("Você atacou o monstro por %d de dano!\n", danoTotal);
			printf("O monstro está com %d de hp restantes.\n", monstro->vida);
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
                    monstro->vida -= danoTotal + 20;
                    printf("impacto Fulminante causou %d de dano!\n", danoTotal + 20);
                    printf("O monstro está com %d de hp restantes.\n\n", monstro->vida);
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
				monstro->vida -= danoCritico;
			
				printf("O monstro está com %d de hp restantes.\n", monstro->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
			turno += 1;
				break;
	} else{
				monstro->vida -= danoTotal;
				printf("Você atacou o monstro por %d de dano!\n", danoTotal);
			printf("O monstro está com %d de hp restantes.\n\n", monstro->vida);
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
                    monstro->vida -= danoTotal *= 2;
                    printf("Drenador de Almas causou %d de dano!\n", danoTotal *= 2);
                    printf("O monstro está com %d de hp restantes.\n\n", monstro->vida);
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
                    monstro->vida -= danoTotal *= 2;
                    printf("Você retirou %d de vida do monstro!\n", danoTotal *= 2);
                    printf("O monstro está com %d de hp restantes.\n\n", monstro->vida);
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
				monstro->vida -= danoCritico;
				
		
				printf("O monstro está com %d de hp restantes.\n", monstro->vida);
					printf("Sua Energia atual: %d", personagem->ienergia);
				turno += 1;
					break;
	} else{
				monstro->vida -= danoTotal;
				printf("Você atacou o monstro por %d de dano!\n", danoTotal);
				printf("O monstro está com %d de hp restantes.\n\n", monstro->vida);
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
                    monstro->vida -= danoTotal - 30;
                    monstro->vida -= danoTotal - 30;
                    monstro->vida -= danoTotal - 30;
                    printf("Rajada de flechas acertou o inimigo 3 vezes!\n");
                    printf("Rajada causou %d de dano!\n", danoTotal - 30);
                    printf("Rajada causou %d de dano!\n", danoTotal - 30);
                    printf("Rajada causou %d de dano!\n", danoTotal - 30);
                    printf("O monstro está com %d de hp restantes.\n\n", monstro->vida);
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
                    monstro->vida -= danoTotal * 2;
                    printf("Você acertou um ponto vital e causou %d de dano!\n", danoTotal * 2);
                    printf("O monstro está com %d de hp restantes.\n\n", monstro->vida);
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
				monstro->vida -= danoCritico;
				
				
				printf("O monstro está com %d de hp restantes.\n", monstro->vida);
					printf("Sua Energia atual: %d", personagem->ienergia);
				turno += 1;
					break;
	} else{
				monstro->vida -= danoTotal;
				printf("Você atacou o monstro por %d de dano!\n", danoTotal);
				printf("O monstro está com %d de hp restantes.\n\n", monstro->vida);
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
                    monstro->vida -= danoTotal + 20;
                    printf("Chuva de Lâminas causou %d de dano!\n", danoTotal + 20);
                    printf("O monstro está com %d de hp restantes.\n\n", monstro->vida);
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
                    monstro->vida -= danoTotal;
                    personagem->ivida += danoTotal / 2;
                    printf("Você roubou %d de vida do monstro!\n", danoTotal);
                    printf("O monstro está com %d de hp restantes.\n\n", monstro->vida);
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



// FUGA
int calcularChanceFuga(Atributos personagem) {
	int chanceFuga = (personagem.iagilidade + personagem.nivel);
		return chanceFuga;
};

int tentarFuga(int chanceFuga, Monstro *monstro){
	int roll = rand() % 20 + 1;
	if (roll <= chanceFuga){
		return 1;
	} else{
		printf("Você não conseguiu fugir!\n");
		return 0;
	}
}

void monstroAtaca(Monstro *monstro, Atributos *personagem){
  int danoBase = monstro->ataque + monstro->forca / 2;
    int danoAleatorio = rand() % (monstro->forca / 2) + 1;
    int danoTotal = danoBase + danoAleatorio;
	personagem->ivida -= danoTotal;
	printf("O monstro atacou você e causou %d de dano!\n\n", danoTotal);
	printf("Você agora está com %d de hp.\n", personagem->ivida);
}

void iniciarbatalha(int classe, Atributos *personagem, Monstro *monstro){
	 int chanceFuga = calcularChanceFuga(*personagem); 
	 int fugiu = 0;
	 turno = 0;
	 
	 while(personagem->ivida > 0 && monstro->vida > 0){
	 
	 	if(turno == 0){
	int escolha;
   		printf(" 1. Atacar\n 2. Inventário\n 3. Fugir\n\n");
    		scanf("%d", &escolha);
	switch(escolha){
		case 1:
			atacar(classe, personagem, monstro);
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
		fugiu =	tentarFuga(chanceFuga, monstro);
		if (fugiu){
			monstro->vida = 0;
		}
			break;
		default:
			printf("Opção inválida!");	
		} 
		} else{
			printf("\nTurno do monstro!\n");
			getch();
			monstroAtaca(monstro, personagem);
			turno -= 1;
	 }
	
	
	if(personagem->ivida <= 0){
		return;
	} else if(fugiu == 1){
	printf("Você fugiu com sucesso!");	
	}else if (monstro->vida <= 0){
		printf("\nVocê venceu!\n\n");
		personagem->xp += rand() % 20 + 50;
		printf("XP atual: %d", personagem->xp);
		personagem->moeda += rand() % 20 + 100;
		printf("\n Moedas de ouro atuais: %d\n", personagem->moeda);
	}
		
	} if(personagem->xp >= 100){
		personagem->xp -= personagem->xp;
		personagem->nivel += 1;
		printf("Você subiu de nível!\n");
		printf("Nível atual: %d", personagem->nivel);
		atualizarAtributos(classe, personagem);
	}
}
