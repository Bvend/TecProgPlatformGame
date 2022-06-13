#pragma once
#include<SFML/Graphics.hpp>
#include"CoordenadaTL.h"
#include <map>

namespace Gerenciadores
{
	class Gerenciador_Grafico
	{
	private:
		CoordF tamanhoJanela;
		sf::RenderWindow* janela;
		std::map<const char*, sf::Texture*> mapaTextura;

	public:
		Gerenciador_Grafico();
		~Gerenciador_Grafico();

		float getAlturaJanela();
		float getLarguraJanela();

		sf::RenderWindow* getJanela() const;

		void verificarEvento();

		bool janelaEstaAberta();

		void limparJanela();

		void renderizarCorpo(sf::RectangleShape* corpo);

		void renderizarTexto(sf::Text* texto);

		void display();

		void fecharJanela();

		sf::Texture* carregarTextura(const char* caminho);
	};
}
