#include "Menu_Ranking.h"
#include "Jogo.h"

#define CAMINHO_MENU_RANKING "./recurssos/Menu/Menu_Ranking.png"

namespace Menus
{
	Menu_Ranking::Menu_Ranking(Gerenciadores::Gerenciador_Grafico* ger, Jogo* jogo) :
		Menu(Id::MENU_RANKING, ger, jogo)
	{
		opcoes = { "Rankings", "Voltar" };
		coordenadas = { {110.f,47.f}, {45.f,205.f} };
		tamanhos = { 50, 35 };
		num_botoes = opcoes.size();

		inicializarCorpo(CAMINHO_MENU_RANKING, CoordF(0.f, 0.f), CoordF(1280.f, 720.f));

		inicializarBotoes();
	}

	Menu_Ranking::~Menu_Ranking()
	{
	}

	void Menu_Ranking::pressionarBotao()
	{
		switch (posicao)
		{
		case 1:
			pJogo->setEmExecucao(Execucao::MENU_PRINCIPAL);
			break;
		}
	}
}