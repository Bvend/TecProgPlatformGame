#pragma once
#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{
		class Inimigo_C : public Inimigo
		{
		private:
			float trajeto;
			float distPercorrida;
			int direcao;
			float velMov;

		public:
			Inimigo_C(Gerenciadores::Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f));
			~Inimigo_C();

			void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

			void executar();

			void mover();
		};
	}
}



