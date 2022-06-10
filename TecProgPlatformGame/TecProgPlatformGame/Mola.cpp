#include "Mola.h"

#define CAMINHO_MOLA "./recurssos/Mola/Mola.png"

namespace Entidades
{
	namespace Obstaculos
	{
		Mola::Mola(Gerenciadores::Gerenciador_Grafico* ger, CoordF pos) :
			Obstaculo(Id::MOLA, ger, pos, CoordF(60.f, 30.f))
		{
			inicializarCorpo(CAMINHO_MOLA, posicao, tamanho);
		}

		Mola::~Mola()
		{
		}

		void Mola::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
		{
		}

		void Mola::executar()
		{
		}
	}
}


