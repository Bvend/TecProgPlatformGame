#pragma once
#include "Entidade.h"

#define GRAVIDADE 10.f

namespace Entidades
{
	namespace Obstaculos
	{
		class Obstaculo : public Entidade
		{
		protected:
		public:
			Obstaculo(Id ind = Id::VAZIO, Gerenciadores::Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.f, 0.f), CoordF tam = CoordF(0.f, 0.f));
			virtual ~Obstaculo();

			virtual void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar) = 0;

			virtual void executar() = 0;

			virtual void mover() = 0;
		};
	}
}



