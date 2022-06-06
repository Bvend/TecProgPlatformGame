#include "Jogador.h"

#define VELMOV 300.f
#define VELPULO 700.f

Jogador::Jogador(int vidas, CoordF pos, CoordF tam, ID ind):
Personagem(vidas, pos, tam, ind)
{
    body.setFillColor(sf::Color::Cyan);
}

Jogador::~Jogador()
{
}


void Jogador::colisao(int direcao_colisao, ID ind)
{
    if (direcao_colisao != COLISAO_BAIXO)
    {
        if (ind == inimigo_A)
        {
            num_vidas--;
            if (num_vidas <= 0)
            {
                body.setFillColor(sf::Color::Yellow);
            }
        }
    }
}

/* Coleta input do teclado e atualiza a posição futura do jogador */
void Jogador::executar(float dt)
{
    proximaPosicao = posicao;

    // Caso entidade estiver no ar, aplica aceleração da gravidade
    if (estaNoAr)
    {
        if (deslocamentoY < VELMOV)
            deslocamentoY += GRAVIDADE * dt;
        proximaPosicao.atualizarY(deslocamentoY);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        proximaPosicao.atualizarX(VELMOV * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        proximaPosicao.atualizarX(-VELMOV * dt);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (!estaNoAr))
    {
        estaNoAr = true;
        deslocamentoY = -VELPULO * dt;
        proximaPosicao.atualizarY(deslocamentoY);
    }
}
