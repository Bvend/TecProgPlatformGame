#pragma once
#include "Obstaculo.h"

class Obst_A : public Obstaculo
{
private:
public:
    Obst_A(Id ind = Id::VAZIO, Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f));
    ~Obst_A();

    // Paredes tem essa fun��o mas n�o usam para nada
    void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

    void executar();
};

