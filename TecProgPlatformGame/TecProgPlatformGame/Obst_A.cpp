#include "Obst_A.h"

Obst_A::Obst_A(CoordF pos, CoordF tam, ID ind) :
Obstaculo(pos, tam, ind)
{
}

Obst_A::~Obst_A()
{
}

/* Parede é fixa, portanto em colisao se mantém no mesmo local*/
void Obst_A::colisao(int direcao_colisao, ID ind)
{
}

void Obst_A::executar(float dt)
{
}
