#pragma once
#include "SFML/Graphics.hpp"
#include "CoordenadaTL.h"
#include "Gerenciador_Grafico.h"

class Corpo
{
private:
	sf::RectangleShape forma;
	sf::Texture* textura;
	Gerenciador_Grafico* pGerenciadorGrafico;

public:
	Corpo();
	~Corpo();

	void inicializar(const char* caminho, CoordF posicao, CoordF tamanho, Gerenciador_Grafico* GerenciadorGrafico = NULL);

	void setForma(CoordF tamanho, CoordF posicao);
	sf::RectangleShape* getForma();

	void setGerenciadorGrafico(Gerenciador_Grafico* GerenciadorGrafico);
	Gerenciador_Grafico* getGerenciadorGrafico();

	void renderizar();

	void setPosicao(CoordF posicao);
};