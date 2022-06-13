#pragma once
#include "Ente.h"

class Jogo;

namespace Menus
{
	class Menu : public Ente
	{
	protected:
		Jogo* pJogo;

		unsigned int num_botoes;
		unsigned int posicao;

		bool botaoPressionado;
		bool aguardarSoltarBotao;

		bool enterPressionado;

		sf::Font* fonte;

		std::vector<const char*> opcoes;
		std::vector<sf::Vector2f> coordenadas;
		std::vector<sf::Text> textos;
		std::vector<std::size_t> tamanhos;

	public:
		Menu(Id ind = Id::VAZIO, Gerenciadores::Gerenciador_Grafico* ger = NULL, Jogo* jogo = NULL);
		virtual ~Menu();

		virtual void executar();

		void coletarInputSetas();

		void coletarInputEnter();

		void inicializarBotoes();

		void renderizar();

		virtual void pressionarBotao() = 0;
	};
}

