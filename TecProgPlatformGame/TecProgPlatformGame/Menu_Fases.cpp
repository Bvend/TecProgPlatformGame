#include "Menu_Fases.h"
#include "Jogo.h"

#define CAMINHO_MENU_FASES "./recurssos/Menu/Menu_Fases.png"

namespace Menus
{
	Menu_Fases::Menu_Fases(Gerenciadores::Gerenciador_Grafico* ger, Jogo* jogo):
		Menu(Id::MENU_FASES, ger, jogo)
	{
		opcoes = { "Selecionar Fase", "Fase Jardim Verde", "Fase Jardim Flores", "Voltar" };
		coordenadas = { {110.f,47.f}, {45.f,205.f}, {44.f,303.f}, {45.f,399.f} };
		tamanhos = { 50, 35, 35, 35 };
		num_botoes = opcoes.size();

		inicializarCorpo(CAMINHO_MENU_FASES, CoordF(0.f, 0.f), CoordF(1280.f, 720.f));

		inicializarBotoes();
	}

	Menu_Fases::~Menu_Fases()
	{
	}

	void Menu_Fases::pressionarBotao()
	{
		switch (posicao)
		{
		case 1:
			pJogo->setComecarNaFase1(true);
			textos[posicao].setFillColor(sf::Color::Red);
			textos[posicao + 1].setFillColor(sf::Color::Black);
			break;

		case 2:
			pJogo->setComecarNaFase1(false);
			textos[posicao].setFillColor(sf::Color::Red);
			textos[posicao - 1].setFillColor(sf::Color::Black);
			break;

		case 3:
			textos[posicao].setOutlineThickness(0);
			posicao = 1;
			textos[posicao].setOutlineThickness(4);
			pJogo->setEmExecucao(Execucao::MENU_PRINCIPAL);
			break;
		}
	}
}
