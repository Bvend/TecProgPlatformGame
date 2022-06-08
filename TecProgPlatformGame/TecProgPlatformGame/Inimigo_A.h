#pragma once
#include "Inimigo.h"

class Inimigo_A : public Inimigo
{
private:
	Jogador* pJogador;
	float trajeto;
	float distPercorrida;
	int direcao;
	float cooldown;
	float velMov;

public:
	Inimigo_A(Id ind = Id::VAZIO, Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), int vid = 0);
	~Inimigo_A();

	void setJogador(Jogador* pJogador);

	void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

	void executar();
};

