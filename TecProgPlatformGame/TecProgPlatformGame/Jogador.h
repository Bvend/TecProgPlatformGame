#pragma once
#include "Personagem.h"

class Jogador : public Personagem
{
private:
    // Nada ainda
public:
    Jogador(int vidas = 0, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), ID ind = vazio);
    ~Jogador();

    void colisao(Entidade* Entidade2);
    void move(float dt);

    void setTexture(Texture* texture);
};

