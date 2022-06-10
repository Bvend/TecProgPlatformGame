#include "Espinho.h"

#define CAMINHO_ESPINHO "./recurssos/Espinho/Espinho.png"

namespace Entidades
{
	namespace Obstaculos
	{
		Espinho::Espinho(Gerenciadores::Gerenciador_Grafico* ger, CoordF pos) :
			Obstaculo(Id::ESPINHO, ger, pos, CoordF(60, 20))
		{
			inicializarCorpo(CAMINHO_ESPINHO, posicao, tamanho);
		}

		Espinho::~Espinho()
		{
		}

		void Espinho::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
		{
		}

		void Espinho::executar()
		{
		}
	}
}

