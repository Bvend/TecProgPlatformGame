#pragma once
#include "ListaEntidades.h"
#include "lista.h"
#include "Personagem.h"
#include "Obstaculo.h"

class Gerenciador_Colisoes
{
private:
	//Lista<Personagem>* ListaObstaculos;
	//Lista<Obstaculo>* ListaPersonagens;
	ListaEntidades* Entidades;

public:
	Gerenciador_Colisoes(ListaEntidades* LE);
	//Gerenciador_Colisoes(Lista<Personagem>* ListaObst, Lista<Obstaculo>* ListaPers);
	~Gerenciador_Colisoes();

	void checarColisoes();
};

