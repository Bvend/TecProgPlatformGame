#pragma once
#include<SFML/Graphics.hpp>
#include"Ente.h"
#include<math.h>

enum ID {
	vazio = 0,
	jogador,
	obst_A,
	obst_B,
	obst_C,
	inimigo_A,
	inimigo_B,
	inimigo_C
};

class Entidade : public Ente
{
protected:
	ID id;
	sf::RectangleShape body;
	CoordF proximaPosicao;
	bool estaNoAr;

public:
	Entidade(CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), ID ind = vazio);
	~Entidade();
	ID getID() const;
	virtual void colisao(Entidade* outraEntidade, CoordF interseccao, bool* estaNoChao) = 0;
	void setEstaNoAr(bool noAr);

	sf::RectangleShape* getBody();
	CoordF getProximaPosicao();
};

