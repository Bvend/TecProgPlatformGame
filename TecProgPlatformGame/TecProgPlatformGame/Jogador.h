#pragma once
#include "Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador : public Personagem
        {
        private:
            float velMov;
            float velPulo;
            //sf::RectangleShape barraVida;

        public:
            Jogador(Id ind = Id::VAZIO, Gerenciadores::Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), int vid = 0);
            ~Jogador();

            void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

            void executar();

            void mover();
        };
    }
}



