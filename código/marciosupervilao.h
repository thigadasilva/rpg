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
    HabilidadeMarcio habilidadesM[3];
}Boss3;

int calcularDanoBoss3(Boss3 *boss3) {
    int dano = boss3->forca / 2;
    int chanceCritico = rand() % 100;
    if (chanceCritico < 8) {
        dano *= 2;
        printf("Dano Crítico!\n");
    }
    return dano;
}

HabilidadeMarcio MaodaPerdicao = {
    "Mão da Perdição",
    0, 
    20,
    30
};
HabilidadeMarcio PactodoDemonio = {
    "Pacto do Rei Demônio",
    50,
    30,
    45
};
HabilidadeMarcio Ambicaodiabolica = {
    "Ambição diabólica",
    50,
    30,
    45
};

void atacarMarcio(int classe, Atributos *personagem, Boss3 *boss3){
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
				boss3->vida -= danoCritico;
			
				printf("Márcio está com %d de hp restantes.\n", boss3->vida);
					printf("Energia atual: %d", personagem->ienergia);
				turno += 1;;
				break;
	} else{
		boss3->vida -= danoTotal;
		printf("Você atacou Márcio por %d de dano!\n", danoTotal);
			printf("Márcio está com %d de hp restantes.\n", boss3->vida);
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
                    boss3->vida -= danoTotal + 20;
                    printf("impacto Fulminante causou %d de dano!\n", danoTotal + 20);
                    printf("Márcio está com %d de hp restantes.\n\n", boss3->vida);
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
				boss3->vida -= danoCritico;
			
				printf("Márcio está com %d de hp restantes.\n", boss3->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
			turno += 1;
				break;
	} else{
				boss3->vida -= danoTotal;
				printf("Você atacou o monstro por %d de dano!\n", danoTotal);
			printf("Márcio está com %d de hp restantes.\n\n", boss3->vida);
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
                    boss3->vida -= danoTotal + 20;
                    printf("Drenador de Almas causou %d de dano!\n", danoTotal + 20);
                    printf("O monstro está com %d de hp restantes.\n\n", boss3->vida);
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
                    boss3->vida -= danoTotal + 10;
                    printf("Você retirou %d de vida do monstro!\n", danoTotal);
                    printf("Márcio está com %d de hp restantes.\n\n", boss3->vida);
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
				boss3->vida -= danoCritico;
				
		
				printf("Márcio está com %d de hp restantes.\n", boss3->vida);
					printf("Sua Energia atual: %d", personagem->ienergia);
				turno += 1;
					break;
	} else{
				boss3->vida -= danoTotal;
				printf("Você atacou Márcio por %d de dano!\n", danoTotal);
				printf("Márcio está com %d de hp restantes.\n\n", boss3->vida);
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
                    boss3->vida -= danoTotal - 30;
                    boss3->vida -= danoTotal - 30;
                    boss3->vida -= danoTotal - 30;
                    printf("Rajada de flechas acertou o inimigo 3 vezes!\n");
                    printf("Rajada causou %d de dano!\n", danoTotal - 30);
                    printf("Rajada causou %d de dano!\n", danoTotal - 30);
                    printf("Rajada causou %d de dano!\n", danoTotal - 30);
                    printf("Márcio está com %d de hp restantes.\n\n", boss3->vida);
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
                    boss3->vida -= danoTotal * 2;
                    printf("Você acertou um ponto vital e causou %d de dano!\n", danoTotal * 2);
                    printf("Márcio está com %d de hp restantes.\n\n", boss3->vida);
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
				boss3->vida -= danoCritico;
				
				
				printf("Márcio está com %d de hp restantes.\n", boss3->vida);
					printf("Sua Energia atual: %d", personagem->ienergia);
				turno += 1;
					break;
	} else{
				boss3->vida -= danoTotal;
				printf("Você atacou Márcio por %d de dano!\n", danoTotal);
				printf("Márcio está com %d de hp restantes.\n\n", boss3->vida);
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
                    boss3->vida -= danoTotal + 40;
                    printf("Chuva de Lâminas causou %d de dano!\n", danoTotal + 40);
                    printf("Márcio está com %d de hp restantes.\n\n", boss3->vida);
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
                    boss3->vida -= danoTotal;
                    personagem->ivida += danoTotal / 2;
                    printf("Você roubou %d de vida do Márcio!\n", danoTotal);
                    printf("Márcio está com %d de hp restantes.\n\n", boss3->vida);
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


void aplicarMaodaPerdicao(Boss3 *boss3, Atributos *personagem) {
    int dano = calcularDanoBoss3(boss3) + MaodaPerdicao.dano / 3;
    personagem->ivida -= dano;
    printf("%s usou Mão da Perdição em você!\n", boss3->nome);
    printf("Você tomou %d de dano!", dano);
}
void aplicarPactodoDemonio(Boss3 *boss3) {
    boss3->vida += PactodoDemonio.dano;
    boss3->forca += PactodoDemonio.dano;
    boss3->ataque += PactodoDemonio.dano;
    printf("%s ativou o Pacto com o Rei Demônio!\n", boss3->nome);
    printf("%s está mais forte agora!\n", boss3->nome);
}
void aplicarAmbicaodiabolica(Boss3 *boss3, Atributos *personagem) {
    personagem->iforca -= Ambicaodiabolica.dano;
     personagem->iinteligencia -= Ambicaodiabolica.dano;
      personagem->idestreza -= Ambicaodiabolica.dano;
       personagem->iagilidade -= Ambicaodiabolica.dano;
    printf("%s ativou Ambição Demoníaca!\n", boss3->nome);
    printf("Você foi enfraquecido!\n");
}

Boss3 criarboss3(HabilidadeMarcio habilidadesM[3]) {
    Boss3 boss3;
    strcpy(boss3.nome, "Márcio, o Rei Demônio Supremo");
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
    printf("O %s atacou você com %d de dano!\n", boss3->nome, dano);
  }
}

//funcao pra introduzir o chefao MarcioBoss
void imprimirIntroMarcio(){
	printf("\n---------------------------------!!!O DESAFIO FINAL!!!---------------------------------\n");
	printf("Márcio, o Guerrerio Lendário corrompido, agora servo do mal.\n");
	printf("O Rei Demônio Supremo, seu senhor, o transformou em uma arma de destruição.\n");
	printf("Diante de você, está o Rei Demônio Supremo, possuindo o corpo do lendário guerreiro, Márcio.");
	printf("\n A era da destruição começou. O último vilão poderoso e diabólico, o aguarda...\n\n");
	getch();
}

void imprimirDialogoMarcio(){
	printf("Então... Você conseguiu... Subir ao topo...");
	getch();
	printf("Você, uma criatura tão miserável e cheia de si, bancando ser o HERÓI,\n É o que esse mundo menos precisa.\n");
	getch();
	printf("Antes de você, vieram 4 heróis lendários, que conseguiram me expurgar para fora desse mundo.\n");
	getch();
	printf("Mas graças a um humano, com tamanha arrogancia, conhecedor de TAL PODER...\n");
	getch();
	printf("Livrou-me do selo, que me guardava, oferecendo a Alma de um lendario HERÓI, que ainda habitava esse mundo...");
	getch();
	printf("Agora, ninguém irá me deter! Nem mesmo você.\n Prepare-se para o seu último confronto.\n ");
	getch();
	printf("Essa será seu último dia no mercado de trabal-\n Digo, aqui será o seu último confronto!!!\n");
	getch();
	printf("Raios e trovões podem ser ouvidos de fundo, uma forte tempestade e\numa forte ventania surge soprando tudo\n para os ares.\n");
}

// FunÃ§Ã£o para imprimir o status do boss3
void imprimirBoss3(Boss3 *boss3) {
    printf("\n** O poderoso %s te desafiou! **\n", boss3->nome);
    printf("\n------------------------------STATUS DO BOSS---------------------------------\n");
    printf("%s\n", boss3->nome);
    printf("Vida: %d\n", boss3->vida);
    printf("Força: %d\n", boss3->forca);
}

void iniciarBatalhaContraBoss3(int classe, Atributos *personagem, Boss3 *boss3) {
    // Lógica de batalha específica para o boss3
    int turno = 0;
     while (personagem->ivida > 0 && boss3->vida > 0){
     	 printf("Vida atual: %d\nVida de Marcio, o Rei Demônio Supremo: %d\n", personagem->ivida, boss3->vida);
         	if(turno == 0){
	int escolha;
   		printf(" 1. Atacar\n 2. Inventário\n 3. Fugir\n\n");
    		scanf("%d", &escolha);
    		fflush(stdin);
	switch(escolha){
		case 1:
			atacarMarcio(classe, personagem, boss3);
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
            atacarBoss3(classe, personagem, boss3);
            turno = !turno;
        }
         if (personagem->ivida <= 0 || boss3->vida <= 0) {
            break;
        }
	  
	  
	  
	if (personagem->ivida <= 0) {
    	if (personagem->segundasChances > 0) {
		        personagem->segundasChances--;
		        personagem->ivida = 300;
		        personagem->iforca += 10;
		        personagem->iinteligencia += 10;
		        personagem->iagilidade += 10;
		        personagem->idestreza += 10;
		        
		         int heroiAleatorio = rand() % 4;
		        switch (heroiAleatorio) {
		        	case 0:
		        	printf("Você sente uma presença poderosa e benevolente.\n");
		        	printf("Diego, a lenda dos Guerreiros está presente.\n");
		        	printf("Você sente Diego te fortalecendo.\n");
		        	break;
					case 1:
					printf("Você sente uma forte presença.\n");
		        	printf("Lucas, o Mestre dos Magos está presente.\n");
		        	printf("Você sente Lucas te fortalecendo.\n");
		        	break;
					case 2:
					printf("Você pensou que estava prestes a morrer, mas\n");
		        	printf("Levi, o maior dos Arqueiros está presente.\n");
		        	printf("Você sente Levi te fortalecendo.\n");
		        	break;
					case 3:
					printf("Algo toca as suas costas.\n");
		        	printf("Thiago, o Rei dos Ladrões está presente.\n");
		        	printf("Você sente Thiago te fortalecendo.\n");
					break;
			}
		      		  printf("Vida restaurada: %d\n", personagem->ivida);
		      		  printf("Atributos melhorados!\n");
    }  if (personagem->ivida > 0) {
            continue; 
        } else {
        printf("Você morreu.\n");
    }
}  
}
if (boss3->vida <= 0){
		printf("\nVocê venceu!\n\n");
		printf("Os espíritos dos lendários heróis estão muito orgulhosos de você.\n");
		printf("Márcio morreu, porém isto não deve ser celebrado.");
		printf("Ele estava sendo controlado pelo Rei Demônio.\n");
		printf("E infelizmente, não havia outra saída.");
		printf("O mundo jaz em paz agora que novamente, o Rei demônio foi expurgado daqui.");
		return;
	} 
}
