#include "Plataforma.h"

#define CAMINHO_PLATAFORMA "./recurssos/Plataforma/Plataforma.png"

namespace Entidades
{
	namespace Obstaculos
	{
		Plataforma::Plataforma(Gerenciadores::Gerenciador_Grafico* ger, CoordF pos, CoordF tam) :
			Obstaculo(Id::PAREDE, ger, pos, tam)
		{
			inicializarCorpo(CAMINHO_PLATAFORMA, posicao, tamanho);
		}

		Plataforma::~Plataforma()
		{
		}

		/* Parede � fixa, portanto em colisao se mant�m no mesmo local*/
		void Plataforma::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
		{
		}

		void Plataforma::executar()
		{
		}
	}
}


