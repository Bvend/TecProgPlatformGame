#include "Personagem.h"

Personagem::Personagem(int vidas, CoordF pos, CoordF tam, ID ind):
Entidade_Movel(pos, tam, ind),
num_vidas(vidas)
{
}

Personagem::~Personagem()
{
}

int Personagem::getNumVidas()
{
    return num_vidas;
}
