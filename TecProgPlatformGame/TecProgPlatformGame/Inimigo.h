#pragma once
#include "Jogador.h"
#include "Personagem.h"

class Inimigo : public Personagem
{
protected:

public:
    Inimigo(Id ind = Id::VAZIO, Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), int vid = 0);
    ~Inimigo();

<<<<<<< HEAD
    virtual void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar) = 0;

    virtual void executar() = 0;
=======
    virtual void colisao(Entidade* outraEntidade) = 0;
    //virtual void setTexture() = 0;
>>>>>>> 91dcff85e6c0a5b60e1520e6cef76ba4e4b29c12
};

