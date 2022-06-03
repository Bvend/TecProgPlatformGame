#pragma once
#include "CoordenadaTL.h"
#include <time.h>

class Ente
{
protected:
	CoordF posicao;
	CoordF tamanho;

public:
	Ente(CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f));
	~Ente();

	void setPosicao(CoordF pos);
	CoordF getPosicao() const;
	void setTamanho(CoordF tam);
	CoordF getTamanho() const;
	float getLargura();
	float getAltura();
	float getEsquerda();
	float getDireita();
	float getCima();
	float getBaixo();
};
