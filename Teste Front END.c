#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "personagem.h"
#include "monstro.h"
#include "batalhas.h"

void inicializarNcurses() {
    initscr();              // Inicia o ncurses
    cbreak();               // Desabilita buffering de linha
    noecho();               // Desabilita echo das teclas
    curs_set(0);            // Desativa o cursor
    timeout(100);           // Define tempo limite de espera para a tela
}

void finalizarNcurses() {
    endwin();               // Finaliza o ncurses
}

void desenharMenu() {
    clear();
    mvprintw(5, 5, "Bem-vindo a sua aventura! Vamos criar seu personagem!");
    mvprintw(7, 5, "Pressione qualquer tecla para começar...");
    refresh();
    getch();
}

void desenharEscolhaClasse(Atributos *personagem) {
    clear();
    mvprintw(5, 5, "Escolha sua classe:");
    mvprintw(7, 5, "1 - Guerreiro");
    mvprintw(8, 5, "2 - Mago");
    mvprintw(9, 5, "3 - Arqueiro");
    mvprintw(10, 5, "4 - Ladino");
    refresh();
}

void obterNome(Atributos *personagem) {
    char nome[16];
    mvprintw(5, 5, "Digite seu nome (max 15 caracteres): ");
    echo();
    getstr(nome);
    noecho();
    strcpy(personagem->nome, nome);
}

void imprimirAtributos(Atributos *personagem) {
    clear();
    mvprintw(5, 5, "Atributos de %s:", personagem->nome);
    mvprintw(6, 5, "Classe: %s", personagem->classe);
    mvprintw(7, 5, "Força: %d", personagem->iforca);
    mvprintw(8, 5, "Vida: %d", personagem->ivida);
    mvprintw(9, 5, "Destreza: %d", personagem->idestreza);
    mvprintw(10, 5, "Agilidade: %d", personagem->iagilidade);
    mvprintw(11, 5, "Inteligencia: %d", personagem->iinteligencia);
    mvprintw(12, 5, "Nivel: %d", personagem->nivel);
    refresh();
    getch();
}

void batalha(Atributos *personagem, Monstro *monstro) {
    int escolha;
    int turno = 0; // 0 = Jogador, 1 = monstro

    while (personagem->ivida > 0 && monstro->vida > 0) {
        clear();
        mvprintw(5, 5, "Batalha contra %s!", monstro->nome);
        mvprintw(7, 5, "Vida do Monstro: %d", monstro->vida);
        mvprintw(8, 5, "Sua Vida: %d", personagem->ivida);
        
        if (turno == 0) {
            mvprintw(10, 5, "Escolha uma ação:");
            mvprintw(11, 5, "1 - Atacar");
            mvprintw(12, 5, "2 - Fugir");

            refresh();
            escolha = getch() - '0';

            switch (escolha) {
                case 1:
                    atacar(1, *personagem, monstro);  // Atacar com classe Guerreiro
                    break;
                case 2:
                    tentarFuga(calcularChanceFuga(*personagem));
                    break;
                default:
                    mvprintw(14, 5, "Escolha inválida!");
                    break;
            }
        } else {
            mvprintw(14, 5, "O monstro ataca!");
            getch();
            monstroAtaca(monstro, personagem);
        }
        turno = !turno;  // Altera o turno
        refresh();
    }
    if (personagem->ivida <= 0) {
        mvprintw(16, 5, "Você morreu! Pressione qualquer tecla.");
    } else {
        mvprintw(16, 5, "Você venceu! Pressione qualquer tecla.");
    }
    refresh();
    getch();
}

int main() {
    srand(time(NULL));

    Atributos personagem;
    Monstro monstro = criarMonstrosRandom();

    inicializarNcurses();

    desenharMenu();
    
    obterNome(&personagem);
    inicializarPersonagens(&personagem);

    desenharEscolhaClasse(&personagem);
    int classe;
    mvprintw(13, 5, "Escolha uma classe (1-4): ");
    scanw("%d", &classe);

    switch (classe) {
        case 1:
            strcpy(personagem.classe, "Guerreiro");
            personagem.iforca = 10;
            personagem.ivida = 25;
            break;
        case 2:
            strcpy(personagem.classe, "Mago");
            personagem.iforca = 5;
            personagem.ivida = 20;
            break;
        case 3:
            strcpy(personagem.classe, "Arqueiro");
            personagem.iforca = 8;
            personagem.ivida = 20;
            break;
        case 4:
            strcpy(personagem.classe, "Ladino");
            personagem.iforca = 7;
            personagem.ivida = 20;
            break;
        default:
            strcpy(personagem.classe, "Guerreiro");
            personagem.iforca = 10;
            personagem.ivida = 25;
    }

    imprimirAtributos(&personagem);

    batalha(&personagem, &monstro);

    finalizarNcurses();
    return 0;
}

