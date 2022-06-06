#pragma once
#include "Entidade.h"
class Obstaculo : public Entidade
{
protected:
public:
	Obstaculo(CoordF pos, CoordF tam, ID ind = vazio);
	~Obstaculo();

	virtual void colisao(int direcao_colisao, ID ind) = 0;

	virtual void executar(float dt) = 0;
};

