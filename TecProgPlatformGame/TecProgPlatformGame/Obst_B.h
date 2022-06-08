#pragma once
#include "Obstaculo.h"

class Obst_B : public Obstaculo
{
private:
public:
    Obst_B(Id ind = Id::VAZIO, Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f));
    ~Obst_B();

    // Paredes tem essa função mas não usam para nada
    void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

    void executar();
};

