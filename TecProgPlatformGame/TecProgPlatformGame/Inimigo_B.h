#pragma once
#include "Inimigo.h"

class Inimigo_B : public Inimigo
{
private:
	Jogador* pJogador;
	int direcao;
	int cooldown;

public:
	Inimigo_B(int vidas = 0, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), ID ind = vazio);
	~Inimigo_B();

	void setJogador(Jogador* pJogador);

	void colisao(int direcao_colisao, ID ind);

	void executar(float dt);
};

