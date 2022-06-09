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
	Inimigo_A(Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f));
	~Inimigo_A();

	void setJogador(Jogador* pJogador);

	void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

<<<<<<< HEAD
	void executar();
=======
	void colisao(Entidade* Entidade2);

	void setTexture(Texture* texture);
>>>>>>> 91dcff85e6c0a5b60e1520e6cef76ba4e4b29c12
};

