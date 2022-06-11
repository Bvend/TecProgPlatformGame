#pragma once
#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Mola : public Obstaculo
        {
        private:
        public:
            Mola(Gerenciadores::Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f));
            ~Mola();

            // Paredes tem essa função mas não usam para nada
            void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

            void executar();

            void mover();
        };
    }
}



