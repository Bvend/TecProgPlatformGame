#pragma once
#include "ListaEntidades.h"

class Gerenciador_Colisoes
{
private:
	//ListaEntidades* EntidadesMoveis;
	//ListaEntidades* EntidadesFixas;
	ListaEntidades* Entidades;

public:
	Gerenciador_Colisoes(ListaEntidades* LE); //ListaEntidades* ListaMoveis = NULL, ListaEntidades* ListaFixas = NULL);
	~Gerenciador_Colisoes();

	void checarColisoes();
};

