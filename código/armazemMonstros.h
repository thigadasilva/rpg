// ARQUIVOS DE ARMAZENAMENTO DE MONSTROS

typedef struct {
	monstro dados[max_monstros];
	int quant;
}listamonstros;

void iniciarmonstros(listamonstros *lista);

void addmonstros(listamonstros *lista, monstro monstros);

void imprimirmonstros(listamonstros *lista);

#endif

void iniciarmonstros(listamonstros *lista){
	lista > quant = 0;
}

void addmonstro(listamonstros *lista, monstro monstros){
	if (lista>quant < max_monstros){
		lista ->dados[lista->quant] = monstro;
		lista->quant++;
	}
}

void imprimirmonstro(listamonstros *lista){
	for(int i=0; i<lista->quant; i++){
		imprimirmonstro(&lista->dados[i]);
	}
}
