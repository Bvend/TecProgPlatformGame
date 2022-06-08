#include "Obst_C.h"

Obst_C::Obst_C(Id ind, Gerenciador_Grafico* ger, CoordF pos, CoordF tam) :
Obstaculo(ind, ger, pos, tam)
{
	corpo.setFillColor(sf::Color::Green);
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
