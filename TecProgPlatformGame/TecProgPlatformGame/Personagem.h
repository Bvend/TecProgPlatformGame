#pragma once
#include "Entidade_Movel.h"

class Personagem : public Entidade_Movel
{
protected:
	int num_vidas;

public:
	Personagem(int vidas = 0, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), ID ind = vazio);
	~Personagem();

	virtual void colisao(Entidade* outraEntidade) = 0;

	virtual void move(float dt) = 0;
};
