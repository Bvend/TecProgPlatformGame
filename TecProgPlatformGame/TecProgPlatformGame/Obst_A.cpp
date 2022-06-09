#include "Obst_A.h"

#define CAMINHO_PLATAFORMA "./recurssos/Plataforma/Plataforma.png"

Obst_A::Obst_A(Gerenciador_Grafico* ger, CoordF pos, CoordF tam):
Obstaculo(Id::PAREDE, pos, tam)
{
	corpo.inicializar(CAMINHO_PLATAFORMA, posicao, tamanho, ger);
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
