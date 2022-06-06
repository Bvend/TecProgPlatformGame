#pragma once
#include "ListaEntidades.h"
#include "lista.h"
#include "Entidade_Movel.h"
#include "Obstaculo.h"

class Gerenciador_Colisoes
{
private:
	//Lista<Personagem>* ListaObstaculos;
	//Lista<Obstaculo>* ListaPersonagens;
	ListaEntidades* pListaEntidades;

public:
	Gerenciador_Colisoes(ListaEntidades* LE = NULL);
	//Gerenciador_Colisoes(Lista<Personagem>* ListaObst, Lista<Obstaculo>* ListaPers);
	~Gerenciador_Colisoes();

	void setListaEntidades(ListaEntidades* LE);

	void checarColisoes();
};

