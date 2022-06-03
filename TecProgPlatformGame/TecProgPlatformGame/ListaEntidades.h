#pragma once
#include "Lista.h"
#include "Entidade.h"

class ListaEntidades
{
private:
	Lista<Entidade>* LE;

public:
	ListaEntidades();
	~ListaEntidades();

	int getLength();
	void adicionarEntidade(Entidade* E);
	Entidade* operator[](int i);
	Elemento<Entidade>* getElemento(int posicao);
	void limpar();
};

