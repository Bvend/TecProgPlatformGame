#pragma once
#include "Jogador.h"
#include "Personagem.h"

class Inimigo : public Personagem
{
protected:

public:
    Inimigo(Id ind = Id::VAZIO, Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), int vid = 0);
    ~Inimigo();

    virtual void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar) = 0;

    virtual void executar() = 0;
};

