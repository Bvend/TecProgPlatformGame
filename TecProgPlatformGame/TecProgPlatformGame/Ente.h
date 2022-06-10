#pragma once
#include "Gerenciador_Grafico.h"
#include "SFML/Graphics.hpp"

enum class Id
{
	VAZIO,
	JOGADOR,
	PAREDE,
	MOLA,
	ESPINHO,
	INIMIGO_A,
	INIMIGO_B,
	INIMIGO_C,
	PROJETIL
};

class Ente
{
protected:
	Id id;
	sf::RectangleShape forma;
	sf::Texture* textura;
	Gerenciadores::Gerenciador_Grafico* pGerenciadorGrafico;

public:
	Ente(Id ind = Id::VAZIO, Gerenciadores::Gerenciador_Grafico* ger = NULL);
	~Ente();

	Id getId() const;

	void setForma(CoordF tamanho, CoordF posicao = CoordF(0.f, 0.f));
	sf::RectangleShape* getForma();

	void setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico);
	Gerenciadores::Gerenciador_Grafico* getGerenciadorGrafico();

	void inicializarCorpo(const char* caminho, CoordF posicao, CoordF tamanho, Gerenciadores::Gerenciador_Grafico* ger = NULL);

	void renderizar();

	virtual void setPosicao(CoordF posicao);

	virtual void executar() = 0;
};
