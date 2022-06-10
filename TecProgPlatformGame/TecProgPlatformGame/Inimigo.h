#pragma once
#include "Jogador.h"
#include "Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo : public Personagem
        {
        protected:

        public:
            Inimigo(Id ind = Id::VAZIO, Gerenciadores::Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), int vid = 0);
            ~Inimigo();

            virtual void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar) = 0;

            virtual void executar() = 0;

            virtual void mover() = 0;
        };
    }
}



