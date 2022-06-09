#pragma once
#include "Entidade.h"

class Obstaculo : public Entidade
{
protected:
public:
	Obstaculo(Id ind = Id::VAZIO, CoordF pos = CoordF(0.f, 0.f), CoordF tam = CoordF(0.f, 0.f));
	~Obstaculo();

	virtual void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar) = 0;

	virtual void executar() = 0;
};

