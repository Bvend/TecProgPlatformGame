#pragma once
#include "Gerenciador_Grafico.h"

namespace Gerenciadores
{
	class Gerenciador_Eventos
	{
	private:
		Gerenciador_Grafico* pGerenciadorGrafico;
		sf::RenderWindow* pWindow;

	public:
		Gerenciador_Eventos(Gerenciador_Grafico* GerenciadorGrafico);
		~Gerenciador_Eventos();

		void verificarEvents();
	};
}
