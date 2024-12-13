// Estrutura do Boss2
typedef struct {
    char nome[50];
    int vida;
    int forca;
    int ataque;
}Boss2;


void atacarBoss2(int classe, Atributos *personagem, Boss2 *boss2) {
    int custoEnergia = 10;
    int danoBase = personagem->iforca + personagem->iagilidade + personagem->idestreza + personagem->iinteligencia / 2;
    int danoAleatorio = rand() % 5 + 1;
    int danoTotal = danoBase + danoAleatorio;
    int danoCritico = 0;
    if (personagem->ienergia < custoEnergia) {
        printf("Voc� n�o tem energia suficiente para atacar!\n");
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
                printf("Voc� atacou fisicamente!\n");
                personagem->ienergia -= custoEnergia;
                if (danoCritico > 0) {
                    printf("Voc� causou %d de Dano Cr�tico!\n\n", danoCritico);
                    boss2->vida -= danoCritico;
                    printf("O fobia est� com %d de hp restantes.\n", boss->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    break;
                } else if (danoCritico < 0){
                    boss2->vida -= danoTotal;
                    printf("Voc� atacou o fobia por %d de dano!\n", danoTotal);
                    printf("O Fobia est� com %d de hp restantes.\n", boss2->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    break;
                }
            } else if (escolha2 == 2) {
                printf("Voc� usou uma habilidade!\n");
                // Implementar habilidade espec�fica
                break;
            } else if (escolha2 == 3) {
                break;
            }
            break;
        case 2: // Mago
            if (escolha2 == 1) {
                printf("Voc� lan�ou magias no Fobia!\n");
                personagem->ienergia -= custoEnergia;
                if (danoCritico > 0) {
                    printf("Voc� causou %d de Dano Cr�tico!\n\n", danoCritico);
                    boss2->vida -= danoCritico;
                    printf("O Fobia est� com %d de hp restantes.\n", boss2->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                    break;
                } else {
                    boss2->vida -= danoTotal;
                    printf("Voc� atacou o Fobia por %d de dano!\n", danoTotal);
                    printf("O Fobia est� com %d de hp restantes.\n", boss2->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                     break;
                }
            } else if (escolha2 == 2) {
                printf("Voc� usou uma habilidade!\n");
                // Implementar habilidade espec�fica
                 break;
            } else if (escolha2 == 3) {
                break;
            }
            break;
        case 3: // Arqueiro
            if (escolha2 == 1) {
                printf("Voc� atirou proj�teis no Fobia!\n");
                personagem->ienergia -= custoEnergia;
                if (danoCritico > 0) {
                    printf("Voc� causou %d de Dano Cr�tico!\n\n", danoCritico);
                    boss2->vida -= danoCritico;
                    printf("O Fobia est� com %d de hp restantes.\n", boss2->vida);
                    printf("Energia atual: %d\n", personagem->ienergia);
                     break;
                } else {
                    boss->vida -= danoTotal;
                    printf("Voc� atacou o Fobia por %d de dano!\n", danoTotal);
                    printf("O Fobia est� com %d de hp restantes.\n", boss2->vida);
                    	printf("Sua Energia atual: %d", personagem->ienergia);
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
				printf("\nVoc� apunhalou Fobia!\n");
				personagem->ienergia -= custoEnergia;
							if(danoCritico > 0){
				printf("Voc� causou %d de Dano Cr�tico!\n\n", danoCritico);
				boss2->vida -= danoCritico;
				printf("O Fobia est� com %d de hp restantes.\n", boss2->vida);
			    printf("Energia atual: %d\n", personagem->ienergia);
				printf("O Fobia est� com %d de hp restantes.\n", boss2->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
				break;
	} else{
				boss2->vida -= danoTotal;
				printf("Voc� atacou o Fobia por %d de dano!\n", danoTotal);
				printf("O Boss est� com %d de hp restantes.\n\n", boss->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
				break;
			} 
		}	else if(escolha2 == 2){
				printf("1 - M�scara das Sombras (Te deixa inv�sivel)\n2 - Festival do Ca�ador (Copia atributos inimigos)\n");
				int skill;
				scanf("%d", &skill);
				switch(skill){
					if(skill == 1){
				printf("\nChuva de laminas!\n");
				personagem->ienergia -= custoEnergia + 10;
				boss->vida -= danoTotal + 20;
				printf("Voc� atacou o Fobia por %d de dano!\n", danoTotal + 20);
				printf("O Boss est� com %d de hp restantes.\n\n", boss->vida);
				printf("Sua Energia atual: %d", personagem->ienergia);
						break;
					} else if(skill == 2){
				printf("\nRoubo de vida!\n");
				personagem->ienergia -= custoEnergia + 10;
				boss->vida -= danoTotal;
				personagem->ivida += danoTotal;
				printf("Voc� roubou %d de vida do boss Fobia!\n", danoTotal);
				printf("O Boss est� com %d de hp restantes.\n\n", boss2->vida);
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



// Função para criar o Boss
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
        printf("Dano Cr�tico!\n");
    }
    dano += rand() % (boss2->forca / 5);
    return dano;
}

void bossAtaca(Boss2 *boss2, Atributos *personagem) {
    int dano = calcularDanoBoss2(boss2);
    personagem->ivida -= dano;
    printf("O %s atacou voc� com %d de dano!\n", boss2->nome, dano);
}

//funcao pra introduzir o chefao Fobia
void imprimirIntroFobia(){
	printf("\n---------------------------------INTRODU��O---------------------------------\n");
	printf("Ap�s a derrota de Biofa, seu rob� leal, Fobia jurou vingan�a contra voc�.\n");
	printf("Desesperado, ele buscou a ajuda do Rei Dem�nio Supremo, M�rcio.\n");
	printf("Em troca de lealdade, M�rcio concedeu a Fobia uma transforma��o completa e poderosa.");
	printf("Agora, Fobia se tornou um ciborgue demon�aco, pronto para buscar sua vingan�a!\n\n");
	getch();
}
// Função para imprimir o status do Boss
void imprimirBoss(Boss *boss) {
    printf("\n** O poderoso %s te desafiou! **\n", boss->nome);
    printf("\n------------------------------STATUS DO BOSS---------------------------------\n");
    printf("%s\n", boss->nome);
    printf("Vida: %d\n", boss->vida);
    printf("For�a: %d\n", boss->forca);
}

void iniciarBatalhaContraBoss2(int classe, Atributos *personagem, Boss2 *boss2) {
    // L�gica de batalha espec�fica para o Boss
    int turno = 0;
     while (personagem->ivida > 0 && boss2->vida > 0){
     	 printf("Vida atual: %d\nVida de Fobia: %d\n", personagem->ivida, boss2->vida);
         	if(turno == 0){
	int escolha;
   		printf(" 1. Atacar\n 2. Invent�rio\n 3. Fugir\n\n");
    		scanf("%d", &escolha);
    		fflush(stdin);
	switch(escolha){
		case 1:
			atacarBoss2(classe, personagem, boss2);
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
            boss2Ataca(boss2, personagem);
            turno = !turno;
        }
         if (personagem->ivida <= 0 || boss2->vida <= 0) {
            break;
        }
	  }
	
	if(personagem->ivida < 0){
		printf("Voc� morreu.");
		return;
	} else if (boss2->vida <= 0){
		printf("\nVoc� venceu!\n\n");
		personagem->xp += rand() % 20 + 50;
		printf("XP atual: %d", personagem->xp);
		personagem->moeda += rand() % 20 + 100;
		printf("\n Moedas de ouro atuais: %d\n", personagem->moeda);
	} if(personagem->xp >= 100){
		personagem->xp -= personagem->xp;
		personagem->nivel += 1;
		printf("Voc� subiu de n�vel!\n");
		printf("N�vel atual: %d", personagem->nivel);
		atualizarAtributos(classe, personagem);
	}
   
}
