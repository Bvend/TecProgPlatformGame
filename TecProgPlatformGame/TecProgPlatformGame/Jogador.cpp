#include "Jogador.h"
#include "Jogo.h"

#define CAMINHO_JOGADOR "./recurssos/Jogador/Jogador2.png"

namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador(Id ind, Gerenciadores::Gerenciador_Grafico* ger, CoordF pos, int vid) :
            Personagem(ind, ger, pos, CoordF(30.f, 75.f), vid),
            velMov(100.f),
            velPulo(500.f)
        {
            inicializarCorpo(CAMINHO_JOGADOR, posicao, tamanho);
        }

        Jogador::~Jogador()
        {
        }

        void Jogador::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
        {
            Id ind = pEntidade->getId();
            if ((ind == Id::INIMIGO_A || ind == Id::INIMIGO_B || ind == Id::INIMIGO_C || ind == Id::PROJETIL) && direcao_colisao == COLISAO_BAIXO)
            {
                estaNoAr = true;
                deslocamentoY = -0.5f * velPulo / 60.f;
                proximaPosicao.atualizarY(deslocamentoY);
                return;
            }
            else if (ind == Id::INIMIGO_A || ind == Id::INIMIGO_B || ind == Id::INIMIGO_C || ind == Id::PROJETIL && direcao_colisao != COLISAO_BAIXO)
            {
                num_vidas--;
                if (num_vidas <= 0)
                {
                    //estaVivo = false;
                }
            }
            else if (ind == Id::MOLA && direcao_colisao == COLISAO_BAIXO)
            {
                estaNoAr = true;
                deslocamentoY = 0;
                deslocamentoY = -1.3f * velPulo / 60.f;
                proximaPosicao.atualizarY(deslocamentoY);
                return;
            }
            else if (ind == Id::ESPINHO && direcao_colisao == COLISAO_BAIXO)
            {
                num_vidas--;
                estaNoAr = true;
                deslocamentoY = 0;
                deslocamentoY = -0.5f * velPulo / 60.f;
                proximaPosicao.atualizarY(deslocamentoY);
                return;
            }

            if (ind != Id::PROJETIL && reposicionar)
            {
                reposicionarColisao(pEntidade->getPosicao(), pEntidade->getTamanho(), direcao_colisao);
            }
        }

        /* Coleta input do teclado e atualiza a posição futura do jogador */
        void Jogador::executar()
        {
            mover();
        }

        /* Função para mover o Jogador, tanto em Y quanto em X */
        void Jogador::mover()
        {
            //proximaPosicao = posicao;

            // Caso entidade estiver no ar, aplica ação da gravidade
            if (estaNoAr)
            {
                if (deslocamentoY < 2 * velMov)
                {
                    deslocamentoY += GRAVIDADE * Jogo::getDt();;
                }
                proximaPosicao.atualizarY(deslocamentoY);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                proximaPosicao.atualizarX(velMov * Jogo::getDt());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                proximaPosicao.atualizarX(-velMov * Jogo::getDt());
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (!estaNoAr))
            {
                estaNoAr = true;
                deslocamentoY = -velPulo * Jogo::getDt();
                proximaPosicao.atualizarY(deslocamentoY);
            }
        }
    }
}

