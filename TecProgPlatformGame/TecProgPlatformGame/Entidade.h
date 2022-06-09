#pragma once
#include "Ente.h"

#define COLISAO_DIREITA -1
#define COLISAO_ESQUERDA 1
#define COLISAO_BAIXO -2
#define COLISAO_CIMA 2

class Entidade : public Ente
{
protected:
	CoordF posicao;
	CoordF proximaPosicao;
<<<<<<< HEAD
	CoordF tamanho;
	sf::RectangleShape corpo;
=======
	//sf::Texture* characterTexture;
>>>>>>> 91dcff85e6c0a5b60e1520e6cef76ba4e4b29c12

public:
	// Construtora e destrutora
	Entidade(Id ind = Id::VAZIO, Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f));
	~Entidade();

	// Posicao
	void setPosicao(CoordF pos);
	CoordF getPosicao() const;

	float getEsquerda();

	float getDireita();

	float getCima();

	float getBaixo();

	CoordF getProximaPosicao();

<<<<<<< HEAD
	void atualizarPos();

	// Tamanho
	void setTamanho(CoordF tam);
	CoordF getTamanho() const;

	float getLargura();

	float getAltura();

	// Corpo e colisão
	sf::RectangleShape* getCorpo();

	void renderizar();

	int detectarColisao(CoordF posEntidade2, CoordF tamEntidade2);

	virtual void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar) = 0;

	// Executar
	virtual void executar() = 0;
=======
	virtual void colisao(Entidade* outraEntidade) = 0;
	//virtual void setTexture() = 0;
>>>>>>> 91dcff85e6c0a5b60e1520e6cef76ba4e4b29c12
};

