#include "Jogador.h"
//#include <iostream>

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

void Jogador::colisao(Entidade* Entidade2)
{
    if (!(posicao.getY() < Entidade2->getCima()
        && posicao.getY() + tamanho.getY() < Entidade2->getCima() + Entidade2->getAltura()
        && posicao.getX() < Entidade2->getDireita()
        && getDireita() > Entidade2->getEsquerda()))
    {
        if (Entidade2->getID() == inimigo_A)
        {
            num_vidas--;
            if (num_vidas <= 0)
            {
                body.setFillColor(sf::Color::Yellow);
            }
        }
    }

    reposicionarColisao(Entidade2->getPosicao(), Entidade2->getTamanho());
}

/* Coleta input do teclado e atualiza a posi��o futura do jogador */
void Jogador::move(float dt)
{
    proximaPosicao = posicao;

    // Caso entidade estiver no ar, aplica acelera��o da gravidade
    if (estaNoAr)
    {
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
