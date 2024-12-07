#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

typedef struct{
	
} registro;

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	char nome[50];
	
	printf("Bem vindo a sua próxima aventura! Vamos criar o seu personagem!\n");
	printf("Como gostaria de ser chamado?\n");
	scanf("%s", nome);
	
	printf("%s, classes...", nome);
	
	getch();
	return 0;
}
