#pragma once
#include<SFML/Graphics.hpp>
#include"CoordenadaTL.h"
#include <map>

namespace Gerenciadores
{
	class Gerenciador_Grafico
	{
	private:
		sf::RenderWindow* janela;
		std::map<const char*, sf::Texture*> mapaTextura;

	public:
		Gerenciador_Grafico();
		~Gerenciador_Grafico();

		sf::RenderWindow* getJanela() const;
		bool janelaEstaAberta();
		void limparJanela();
		void renderizar(sf::RectangleShape* body);
		void display();
		void fecharJanela();
		void centralizarVista(CoordF pos, CoordF tam);
		sf::Texture* carregarTextura(const char* caminho);
	};
}
