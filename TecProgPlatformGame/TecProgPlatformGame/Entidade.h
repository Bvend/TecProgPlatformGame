#pragma once
#include "Ente.h"

#define COLISAO_DIREITA -1
#define COLISAO_ESQUERDA 1
#define COLISAO_BAIXO -2
#define COLISAO_CIMA 2

namespace Entidades
{
	class Entidade : public Ente
	{
	protected:
		CoordF posicao;
		CoordF proximaPosicao;
		CoordF tamanho;
		CoordF velocidade;
		bool estaNoAr;
		bool estaVivo;

	public:
		// Construtora e destrutora
		Entidade(Id ind = Id::VAZIO, Gerenciadores::Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f));
		virtual ~Entidade();

		// Posicao
		void setPosicao(CoordF pos);
		CoordF getPosicao() const;

		float getEsquerda();

		float getDireita();

		float getCima();

		float getBaixo();

		float getCentroX();

		float getCentroY();

		CoordF getCentro();

		CoordF getProximaPosicao() const;

		virtual void atualizarPos();

		// Tamanho
		void setTamanho(CoordF tam);
		CoordF getTamanho() const;

		float getLargura();

		float getAltura();

		// Vida
		void setEstaVivo(bool vivo);
		bool getEstaVivo() const;

		// Corpo e colisão
		int detectarColisao(CoordF posEntidade2, CoordF tamEntidade2);
		
		void reposicionarColisao(CoordF posEntidade2, CoordF tamEntidade2, int direcao_colisao);

		virtual void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar) = 0;

		// Executar
		virtual void executar() = 0;
	};
}

