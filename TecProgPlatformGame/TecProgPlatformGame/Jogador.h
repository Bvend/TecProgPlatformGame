#pragma once
#include "Personagem.h"

#define LARGURA_JOGADOR 30.f
#define ALTURA_JOGADOR 75.f

namespace Entidades
{
    namespace Personagens
    {
        class Jogador : public Personagem
        {
        private:
            float velPulo;
            sf::Keyboard::Key teclaEsquerda;
            sf::Keyboard::Key teclaDireita;
            sf::Keyboard::Key teclaPulo;

        public:
            Jogador(Id ind = Id::VAZIO, Gerenciadores::Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f));
            ~Jogador();

            void configurarJogador();

            void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

            void executar();

            void mover();

            bool intersecta(CoordF pos);
        };
    }
}



