#pragma once
#include "ListaEntidades.h"
#include "Personagem.h"

namespace Gerenciadores
{
	class Gerenciador_Colisoes
	{
	private:
		//Lista<Personagem>* ListaObstaculos;
		//Lista<Obstaculo>* ListaPersonagens;
		Listas::ListaEntidades* pListaEntidades;

	public:
		Gerenciador_Colisoes(Listas::ListaEntidades* LE = NULL);
		//Gerenciador_Colisoes(Lista<Personagem>* ListaObst, Lista<Obstaculo>* ListaPers);
		~Gerenciador_Colisoes();

		void setListaEntidades(Listas::ListaEntidades* LE);

		void checarColisoes();
	};
}

