#include "Menu_Jogadores.h"
#include "Jogo.h"

#define CAMINHO_MENU_JOGADORES "./recurssos/Menu/Menu_Jogadores.png"

namespace Menus
{
	Menu_Jogadores::Menu_Jogadores(Gerenciadores::Gerenciador_Grafico* ger, Jogo* jogo) :
		Menu(Id::MENU_JOGADORES, ger, jogo)
	{
		opcoes = { "Selecionar Jogadores", "Um Jogador", "Dois Jogadores", "Voltar" };
		coordenadas = { {70.f,47.f}, {45.f,205.f}, {44.f,303.f}, {45.f,399.f} };
		tamanhos = { 50, 35, 35, 35 };
		num_botoes = opcoes.size();

		inicializarCorpo(CAMINHO_MENU_JOGADORES, CoordF(0.f, 0.f), CoordF(1280.f, 720.f));

		inicializarBotoes();
	}

	Menu_Jogadores::~Menu_Jogadores()
	{
	}

	void Menu_Jogadores::pressionarBotao()
	{
		switch (posicao)
		{
		case 1:
			textos[posicao].setFillColor(sf::Color::Red);
			textos[posicao + 1].setFillColor(sf::Color::Black);
			break;
		case 2:
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