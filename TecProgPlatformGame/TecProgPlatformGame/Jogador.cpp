#include "Jogador.h"
#include "Jogo.h"

#define CAMINHO_JOGADOR1 "./recurssos/Jogador/Jogador1.png"
#define CAMINHO_JOGADOR2 "./recurssos/Jogador/Jogador2.png"

namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador(Id ind, Gerenciadores::Gerenciador_Grafico* ger, CoordF pos) :
            Personagem(ind, ger, pos, CoordF(LARGURA_JOGADOR, ALTURA_JOGADOR)),
            velPulo(500.f)
        {
            velocidade.setX(100.f);
            configurarJogador();
        }

        Jogador::~Jogador()
        {
        }

        /* Atribui textura e teclas para movimento de acordo com id do jogador */
        void Jogador::configurarJogador()
        {
            if (id == Id::JOGADOR1)
            {
                teclaEsquerda = sf::Keyboard::A;
                teclaDireita = sf::Keyboard::D;
                teclaPulo = sf::Keyboard::W;
                inicializarCorpo(CAMINHO_JOGADOR1, posicao, tamanho);
            }
            else if (id == Id::JOGADOR2)
            {
                teclaEsquerda = sf::Keyboard::Left;
                teclaDireita = sf::Keyboard::Right;
                teclaPulo = sf::Keyboard::Up;
                inicializarCorpo(CAMINHO_JOGADOR2, posicao, tamanho);
            }
        }

        void Jogador::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
        {
            Id ind = pEntidade->getId();
            if ((ind == Id::CACHORRO || ind == Id::FLORCHEFE || ind == Id::SOL || ind == Id::POLEN))
            {
                if (direcao_colisao == COLISAO_BAIXO)
                {
                    estaNoAr = true;
                    velocidade.setY(-0.5f * velPulo);
                    proximaPosicao.atualizarY(velocidade.getY() * Jogo::getDt());
                    return;
                }
                else
                {
                    estaVivo = false;
                }
            }
            else if (ind == Id::MOLA && direcao_colisao == COLISAO_BAIXO)
            {
                estaNoAr = true;
                velocidade.setY(-1.3f * velPulo);
                proximaPosicao.atualizarY(velocidade.getY() * Jogo::getDt());
                return;
            }
            else if (ind == Id::ESPINHO && direcao_colisao == COLISAO_BAIXO)
            {
                //num_vidas--;
                estaVivo = false;
                //estaNoAr = true;
                //velocidade.setY(-0.5f * velPulo);
                //proximaPosicao.atualizarY(velocidade.getY()* Jogo::getDt());
                //return;
            }

            if ((ind != Id::POLEN && ind != Id::JOGADOR1 && ind != Id::JOGADOR2) && reposicionar)
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
            proximaPosicao = posicao;
            // Caso entidade estiver no ar, aplica ação da gravidade
            if (estaNoAr)
            {
                velocidade.atualizarY(GRAVIDADE);
                proximaPosicao.atualizarY(velocidade.getY() * Jogo::getDt());
            }

            if (sf::Keyboard::isKeyPressed(teclaEsquerda))
            {
                proximaPosicao.atualizarX(-velocidade.getX() * Jogo::getDt());
            }
            if (sf::Keyboard::isKeyPressed(teclaDireita))
            {
                proximaPosicao.atualizarX(velocidade.getX() * Jogo::getDt());
            }
            if ((sf::Keyboard::isKeyPressed(teclaPulo)) && (!estaNoAr))
            {
                estaNoAr = true;
                velocidade.setY(-velPulo);
                proximaPosicao.atualizarY(velocidade.getY() * Jogo::getDt());
            }
        }

        bool Jogador::intersecta(CoordF pos)
        {
            sf::Rect<float> area(posicao.getX(), posicao.getY(), tamanho.getX(), tamanho.getY());
            if (area.contains(pos.getX(), pos.getY()))
            {
                return true;
            }
            return false;
        }
    }
}

