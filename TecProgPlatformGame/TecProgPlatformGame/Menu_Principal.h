#pragma once
#include "Menu.h"

namespace Menus
{
	class Menu_Principal : public Menu
	{
	private:

	public:
		Menu_Principal(Gerenciadores::Gerenciador_Grafico* ger = NULL, Jogo* jogo = NULL);
		~Menu_Principal();

		void pressionarBotao();
	};
}