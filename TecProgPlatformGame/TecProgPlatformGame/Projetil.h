#pragma once
#include "Personagem.h"

class Projetil : public Personagem
{
private:
	float velMov;
	float direcao;

public:
	Projetil(Id ind = Id::VAZIO, Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), int vid = 0);
	~Projetil();

	void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

	void executar();
};

