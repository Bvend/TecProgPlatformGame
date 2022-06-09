#include "Obst_B.h"

#define CAMINHO_ ""

Obst_B::Obst_B(Gerenciador_Grafico* ger, CoordF pos):
Obstaculo(Id::MOLA, pos, CoordF(100.f, 100.f))
{
	corpo.inicializar(CAMINHO_, posicao, tamanho, ger);
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
