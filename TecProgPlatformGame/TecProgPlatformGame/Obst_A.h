#pragma once
#include "Obstaculo.h"
class Obst_A : public Obstaculo
{
private:
public:
    Obst_A(CoordF pos, CoordF tam, ID ind = vazio);
    ~Obst_A();

    // Paredes tem essa função mas não usam para nada
    void colisao(Entidade* outraEntidade, CoordF interseccao, bool* estaNoChao);
};

