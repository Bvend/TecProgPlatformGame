#pragma once
#include<SFML/Graphics.hpp>
#include"Ente.h"
#include<math.h>

#define COLISAO_DIREITA -1
#define COLISAO_ESQUERDA 1
#define COLISAO_BAIXO -2
#define COLISAO_CIMA 2

enum ID {
	vazio = 0,
	jogador,
	obst_A,
	obst_B,
	obst_C,
	inimigo_A,
	inimigo_B,
	inimigo_C
};

class Entidade : public Ente
{
protected:
	ID id;
	sf::RectangleShape body;
	CoordF proximaPosicao;
	sf::Texture* characterTexture;

public:
	Entidade(CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), ID ind = vazio);
	~Entidade();

	ID getID() const;
	sf::RectangleShape* getBody();
	CoordF getProximaPosicao();

	void atualizarPos();

	int detectarColisao(CoordF posEntidade2, CoordF tamEntidade2);

	virtual void colisao(int direcao_colisao, ID ind) = 0;

	virtual void executar(float dt) = 0;
};

