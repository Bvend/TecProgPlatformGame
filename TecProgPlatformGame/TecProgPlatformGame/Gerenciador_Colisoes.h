#pragma once
#include "ListaEntidades.h"
#include "Personagem.h"

namespace Gerenciadores
{
	class Gerenciador_Colisoes
	{
	private:
		Listas::ListaEntidades* pListaEntidades;

	public:
		Gerenciador_Colisoes(Listas::ListaEntidades* LE = NULL);

		~Gerenciador_Colisoes();

		void setListaEntidades(Listas::ListaEntidades* LE);

		void checarColisoes();
	};
}

