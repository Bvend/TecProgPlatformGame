#include "Obst_A.h"

Obst_A::Obst_A(Gerenciador_Grafico* ger, CoordF pos, CoordF tam):
Obstaculo(Id::PAREDE, ger, pos, tam)
{
}

Obst_A::~Obst_A()
{
}

/* Parede � fixa, portanto em colisao se mant�m no mesmo local*/
void Obst_A::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
{
}

void Obst_A::executar()
{
}
