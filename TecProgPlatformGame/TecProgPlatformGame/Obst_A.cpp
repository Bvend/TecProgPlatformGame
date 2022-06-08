#include "Obst_A.h"

Obst_A::Obst_A(Id ind, Gerenciador_Grafico* ger, CoordF pos, CoordF tam):
Obstaculo(ind, ger, pos, tam)
{
}

Obst_A::~Obst_A()
{
}

/* Parede é fixa, portanto em colisao se mantém no mesmo local*/
void Obst_A::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
{
}

void Obst_A::executar()
{
}
