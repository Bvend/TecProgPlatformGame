#pragma once
#include "Inimigo.h"

class Inimigo_A : public Inimigo
{
private:
	Jogador* pJogador;
	float trajeto;
	float distPercorrida;
	int direcao;

public:
	Inimigo_A(int vidas = 0, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), ID ind = vazio);
	~Inimigo_A();

	void setJogador(Jogador* pJogador);

	void move(float dt);

	void colisao(Entidade* Entidade2);

	void setTexture(Texture* texture);
};

