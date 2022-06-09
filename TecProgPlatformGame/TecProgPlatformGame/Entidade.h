#pragma once
#include "Ente.h"
#include "Corpo.h"

#define COLISAO_DIREITA -1
#define COLISAO_ESQUERDA 1
#define COLISAO_BAIXO -2
#define COLISAO_CIMA 2

class Entidade : public Ente
{
protected:
	CoordF posicao;
	CoordF proximaPosicao;
	CoordF tamanho;
	Corpo corpo;

public:
	// Construtora e destrutora
	Entidade(Id ind = Id::VAZIO, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f));
	~Entidade();

	// Posicao
	void setPosicao(CoordF pos);
	CoordF getPosicao() const;

	float getEsquerda();

	float getDireita();

	float getCima();

	float getBaixo();

	float getCentroX();

	float getCentroY();

	CoordF getProximaPosicao();

	void atualizarPos();

	// Tamanho
	void setTamanho(CoordF tam);
	CoordF getTamanho() const;

	float getLargura();

	float getAltura();

	// Corpo e colis�o

	sf::RectangleShape* getForma();

	void renderizar();

	int detectarColisao(CoordF posEntidade2, CoordF tamEntidade2);

	virtual void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar) = 0;

	// Executar
	virtual void executar() = 0;
};

