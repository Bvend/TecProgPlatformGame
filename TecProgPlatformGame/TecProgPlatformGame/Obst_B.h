#pragma once
#include "Obstaculo.h"

class Obst_B : public Obstaculo
{
private:
public:
    Obst_B(Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f));
    ~Obst_B();

    // Paredes tem essa fun��o mas n�o usam para nada
    void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

    void executar();
};

