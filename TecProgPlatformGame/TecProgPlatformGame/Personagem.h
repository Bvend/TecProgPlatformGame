#pragma once
#include "Entidade.h"
#include "Animacao.h"

#define GRAVIDADE 9.81f

class Personagem : public Entidade
{
protected:
	int num_vidas;
	bool estaNoAr;
	float deslocamentoY;

public:
	Personagem(int vidas = 0, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), ID ind = vazio);
	~Personagem();

	void setEstaNoAr(bool estaNoAr);
	void setDeslocamentoY(float deslocamenoY);

	void atualizarPos();
	void reposicionarColisao(CoordF posEntidade2, CoordF tamEntidade2);
	virtual void colisao(Entidade* outraEntidade) = 0;
	//virtual void setTexture() = 0;
};
