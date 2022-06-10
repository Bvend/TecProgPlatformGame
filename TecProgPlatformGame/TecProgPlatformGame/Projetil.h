#pragma once
#include "Personagem.h"

namespace Entidades
{
	class Projetil : public Entidade
	{
	private:
		float deslocamentoY;
		float velMov;
		int direcao;

	public:
		Projetil(Gerenciadores::Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), int dir = 1);
		~Projetil();

		void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

		void executar();

		void mover();

		void atualizarPos();
	};
}

