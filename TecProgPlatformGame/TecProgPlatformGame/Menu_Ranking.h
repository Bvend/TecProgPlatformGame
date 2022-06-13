#pragma once
#include "Menu.h"

namespace Menus
{
	class Menu_Ranking : public Menu
	{
	private:

	public:
		Menu_Ranking(Gerenciadores::Gerenciador_Grafico* ger = NULL, Jogo* jogo = NULL);
		~Menu_Ranking();

		void executar();

		void pressionarBotao();
	};
}
