#pragma once
#include "Jogador.h"
#include "Inimigo.h"

class Inimigo : public Personagem
{
protected:

public:
    Inimigo(int vidas = 0, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), ID ind = vazio);
    ~Inimigo();

    virtual void colisao(Entidade* outraEntidade) = 0;
};

