#pragma once
#include "Menu.h"

namespace Menus
{
	class Menu_Fases : public Menu
	{
	private:

	public:
		Menu_Fases(Gerenciadores::Gerenciador_Grafico* ger = NULL, Jogo* jogo = NULL);
		~Menu_Fases();

		void pressionarBotao();
	};
}
