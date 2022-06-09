#include "Obst_B.h"

Obst_B::Obst_B(Gerenciador_Grafico* ger, CoordF pos, CoordF tam):
Obstaculo(Id::MOLA, ger, pos, tam)
{
	corpo.setFillColor(sf::Color::Red);
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
