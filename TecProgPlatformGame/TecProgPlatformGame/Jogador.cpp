#include "Jogador.h"
#include <SFML/Graphics.hpp>
using namespace sf;
//#include <iostream>

#define VELMOV 300.f
#define VELPULO 700.f

Jogador::Jogador(int vidas, CoordF pos, CoordF tam, ID ind):
Personagem(vidas, pos, tam, ind)
{
    
}

Jogador::~Jogador()
{
}

void Jogador::colisao(Entidade* Entidade2)
{
    reposicionarColisao(Entidade2->getPosicao(), Entidade2->getTamanho());

    if (!(posicao.getY() < Entidade2->getCima()
        && posicao.getY() + tamanho.getY() < Entidade2->getCima() + Entidade2->getAltura()
        && posicao.getX() < Entidade2->getDireita()
        && getDireita() > Entidade2->getEsquerda()))//(interseccao.getX() < interseccao.getY())
    {
        if (Entidade2->getID() == inimigo_A)
        {
            num_vidas--;
            cout << num_vidas << endl;
            if (num_vidas <= 0)
            {
                body.setFillColor(sf::Color::Yellow);
            }
        }
    }
}

/* Coleta input do teclado e atualiza a posição futura do jogador */
void Jogador::move(float dt)
{
    proximaPosicao = posicao;

    // Caso entidade estiver no ar, aplica aceleração da gravidade
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

void Jogador::setTexture(Texture* texture)
{
    body.setTexture(texture);
}
