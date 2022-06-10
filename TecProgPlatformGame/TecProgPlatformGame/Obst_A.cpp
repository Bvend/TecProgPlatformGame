#include "Obst_A.h"

#define CAMINHO_PLATAFORMA "./recurssos/Plataforma/Plataforma.png"

Obst_A::Obst_A(Gerenciador_Grafico* ger, CoordF pos, CoordF tam):
Obstaculo(Id::PAREDE, ger, pos, tam)
{
	inicializarCorpo(CAMINHO_PLATAFORMA, posicao, tamanho);
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
