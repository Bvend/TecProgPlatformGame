#include "Obst_C.h"

#define CAMINHO_ ""

Obst_C::Obst_C(Gerenciador_Grafico* ger, CoordF pos):
Obstaculo(Id::ESPINHO, pos, CoordF())
{
	corpo.inicializar(CAMINHO_, posicao, tamanho, ger);
}

Obst_C::~Obst_C()
{
}

void Obst_C::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
{
}

void Obst_C::executar()
{
}
