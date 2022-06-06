#pragma once
#include "Entidade.h"

#define GRAVIDADE 9.81f

class Entidade_Movel : public Entidade
{
protected:
	bool estaNoAr;
	float deslocamentoY;

public:
	Entidade_Movel(CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), ID ind = vazio);
	~Entidade_Movel();

	void setEstaNoAr(bool estaNoAr);
	void setDeslocamentoY(float deslocamenoY);

	void reposicionarColisao(CoordF posEntidade2, CoordF tamEntidade2, int direcao_colisao);
	virtual void colisao(int direcao_colisao, ID ind) = 0;

	virtual void executar(float dt) = 0;
};
