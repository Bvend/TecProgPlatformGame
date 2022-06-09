#pragma once
#include "Obstaculo.h"

class Obst_A : public Obstaculo
{
private:
public:
    Obst_A(Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f));
    ~Obst_A();

    // Paredes tem essa função mas não usam para nada
<<<<<<< HEAD
    void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

    void executar();
=======
    void colisao(Entidade* outraEntidade);
    void setTexture();
>>>>>>> 91dcff85e6c0a5b60e1520e6cef76ba4e4b29c12
};

