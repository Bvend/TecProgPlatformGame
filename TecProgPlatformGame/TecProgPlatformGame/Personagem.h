#pragma once
#include "Entidade.h"

#define GRAVIDADE 9.81f

class Personagem : public Entidade
{
protected:
	int num_vidas;
	CoordF deslocamento;

public:
	Personagem(int vidas = 0, CoordF vel = CoordF(0.0f, 0.0f), CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), ID ind = vazio);
	~Personagem();

	float getDeslocamentoY();
	float getDeslocamentoX();

	void atualizarPos();
	void reposicionarColisao(CoordF posEntidade2, CoordF tamEntidade2, CoordF interseccao, bool* estaNoChao);
	virtual void colisao(Entidade* outraEntidade, CoordF interseccao, bool* estaNoChao) = 0;
};
