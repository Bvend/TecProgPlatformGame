#include "Menu.h"

#define CAMINHO_FONTE "./recurssos/Menu/gooddog.otf"

namespace Menus
{
	Menu::Menu(Id ind, Gerenciadores::Gerenciador_Grafico* ger, Jogo* jogo) :
		Ente(ind, ger),
		pJogo(jogo),
		botaoPressionado(false),
		aguardarSoltarBotao(true),
		enterPressionado(false),
		fonte(new sf::Font()),
		posicao(1),
		num_botoes(0)
	{
		try
		{
			if (!fonte->loadFromFile(CAMINHO_FONTE))
			{
				throw "Falha ao carregar arquivo de Textura";
			}
		}
		catch (const char* e)
		{
			delete fonte;
			std::cout << "ERRO - " << e << std::endl;
			exit(1);
		}
	}

	Menu::~Menu()
	{
		opcoes.clear();
		coordenadas.clear();
		textos.clear();
		tamanhos.clear();
		if (fonte)
		{
			delete fonte;
		}
	}

	void Menu::inicializarBotoes()
	{
		textos.resize(num_botoes);
		for (unsigned int i = 0; i < num_botoes; i++)
		{
			textos[i].setFont(*fonte);
			textos[i].setString(opcoes[i]);
			textos[i].setCharacterSize(tamanhos[i]);
			textos[i].setFillColor(sf::Color::Black);
			textos[i].setOutlineColor(sf::Color::Cyan);
			textos[i].setPosition(coordenadas[i]);
		}
		textos[1].setOutlineThickness(4);
	}

	void Menu::executar()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (posicao < num_botoes - 1 && !aguardarSoltarBotao)
			{
				posicao++;
				textos[posicao].setOutlineThickness(4);
				textos[posicao - 1].setOutlineThickness(0);
			}
			botaoPressionado = true;
			enterPressionado = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (posicao > 1 && !aguardarSoltarBotao)
			{
				posicao--;
				textos[posicao].setOutlineThickness(4);
				textos[posicao + 1].setOutlineThickness(0);
			}
			botaoPressionado = true;
			enterPressionado = false;
		}

		if (botaoPressionado)
		{
			aguardarSoltarBotao = true;
		}
		else
		{
			aguardarSoltarBotao = false;
		}

		botaoPressionado = false;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !enterPressionado)
		{
			enterPressionado = true;
			pressionarBotao();
		}
	}

	void Menu::renderizar()
	{
		if (pGerenciadorGrafico)
		{
			pGerenciadorGrafico->renderizarCorpo(&forma);
			for (unsigned int i = 0; i < num_botoes; i++)
			{
				pGerenciadorGrafico->renderizarTexto(&textos[i]);
			}
		}
	}
}