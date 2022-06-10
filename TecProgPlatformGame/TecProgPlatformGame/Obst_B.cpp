#include "Obst_B.h"

#define CAMINHO_ ""

Obst_B::Obst_B(Gerenciador_Grafico* ger, CoordF pos):
Obstaculo(Id::MOLA, ger, pos, CoordF(30.f, 60.f))
{
	inicializarCorpo(CAMINHO_, posicao, tamanho);
}

Obst_B::~Obst_B()
{
}

void Obst_B::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
{
}

void Obst_B::executar()
{
}
