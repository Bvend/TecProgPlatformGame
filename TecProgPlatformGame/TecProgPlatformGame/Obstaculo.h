#pragma once
#include "Entidade.h"
class Obstaculo : public Entidade
{
protected:
public:
	Obstaculo(CoordF pos, CoordF tam, ID ind = vazio);
	~Obstaculo();

	virtual void colisao(Entidade* outraEntidade, CoordF interseccao, bool* estaNoChao) = 0;
};

