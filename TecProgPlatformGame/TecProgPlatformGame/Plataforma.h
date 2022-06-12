#pragma once
#include "Obstaculo.h"

#define LARGURA_PLATAFORMA 240.f
#define ALTURA_PLATAFORMA 15.f

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma : public Obstaculo
        {
        private:
            float aceleracaoSustentacao;

        public:
            Plataforma(Gerenciadores::Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f));
            ~Plataforma();

            // Paredes tem essa função mas não usam para nada
            void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

            void executar();

            void mover();
        };
    }
}

