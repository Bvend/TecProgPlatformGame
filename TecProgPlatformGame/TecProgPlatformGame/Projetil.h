#pragma once
#include "Personagem.h"

class Projetil : public Personagem
{
private:
	float velMov;
	float direcao;

public:
	Projetil(Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), int dir = 1);
	~Projetil();

	void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

	void executar();

	void mover();
};

