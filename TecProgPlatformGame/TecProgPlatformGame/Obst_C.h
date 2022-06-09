#pragma once
#include "Obstaculo.h"

class Obst_C : public Obstaculo
{
private:
public:
    Obst_C(Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f));
    ~Obst_C();

    // Paredes tem essa função mas não usam para nada
    void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

    void executar();
};

