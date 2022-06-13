#pragma once
#include "Menu.h"

namespace Menus
{
	class Menu_Jogadores: public Menu
	{
	private:

	public:
		Menu_Jogadores(Gerenciadores::Gerenciador_Grafico* ger = NULL, Jogo* jogo = NULL);
		~Menu_Jogadores();

		void pressionarBotao();
	};
}
