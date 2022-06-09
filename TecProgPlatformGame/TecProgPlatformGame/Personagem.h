#pragma once
#include "Entidade.h"

#define GRAVIDADE 9.81f

class Jogo;

class Personagem : public Entidade
{
protected:
	int num_vidas;
	bool estaNoAr;
	float deslocamentoY;

public:
	Personagem(Id ind = Id::VAZIO, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), int vid = 0);
	~Personagem();

	int getNumVidas();

	void setEstaNoAr(bool NoAr);

	void setDeslocamentoY(float deslY);

	void reposicionarColisao(CoordF posEntidade2, CoordF tamEntidade2, int direcao_colisao);

	virtual void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar) = 0;

	virtual void executar() = 0;

	virtual void mover() = 0;
};
