#pragma once
#include "Entidade.h"
#include "AnimacaoEstatica.h"
class EntidadeEstatica : public Entidade
{
protected:
	AnimacaoEstatica sprite;
public:
	EntidadeEstatica(CoordF posicao = CoordF(0.0f, 0.0f), CoordF tamanho = CoordF(0.0f, 0.0f), ID id = vazio);
	~EntidadeEstatica();
	void render();
	virtual void update() {}
	//virtual void inicializa() = 0;
	virtual void colisao(Entidade* outraEntidade, CoordF interseccao) {}
};

