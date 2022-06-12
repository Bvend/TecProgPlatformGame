#pragma once
#include "Personagem.h"

namespace Entidades
{
	class Polen : public Entidade
	{
	private:
		float deslocamentoY;
		float velMov;
		int direcao;

	public:
		Polen(Gerenciadores::Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), int dir = 1);
		virtual ~Polen();

		void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

		void executar();

		void mover();

		void atualizarPos();
	};
}

