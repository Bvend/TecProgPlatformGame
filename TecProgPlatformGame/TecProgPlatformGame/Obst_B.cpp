#include "Obst_B.h"

Obst_B::Obst_B(Id ind, Gerenciador_Grafico* ger, CoordF pos, CoordF tam) :
Obstaculo(ind, ger, pos, tam)
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
