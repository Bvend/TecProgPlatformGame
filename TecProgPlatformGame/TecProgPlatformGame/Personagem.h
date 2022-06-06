#pragma once
#include "Entidade_Movel.h"

class Personagem : public Entidade_Movel
{
protected:
	int num_vidas;

public:
	Personagem(int vidas = 0, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), ID ind = vazio);
	~Personagem();

	int getNumVidas();

	virtual void colisao(int direcao_colisao, ID ind) = 0;

	virtual void executar(float dt) = 0;
};
