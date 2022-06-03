#include "Jogador.h"
//#include <iostream>

#define VELMOV 300.f
#define VELPULO 360.f

Jogador::Jogador(int vidas, CoordF des, CoordF pos, CoordF tam, ID ind):
Personagem(vidas, des, pos, tam, ind)
{
    body.setFillColor(sf::Color::Cyan);
}

Jogador::~Jogador()
{
}

void Jogador::colisao(Entidade* Entidade2, CoordF interseccao, bool* estaNoChao)
{

    if (Entidade2->getID() == inimigo_A)
    {
        if (fabs(interseccao.getX()) > (interseccao.getY()))
        {

        }

        num_vidas--;
        cout << "num_vidas: " << num_vidas << endl;
        if (num_vidas <= 0)
        {
            body.setFillColor(sf::Color::Yellow);
        }
    }

    reposicionarColisao(Entidade2->getPosicao(), Entidade2->getTamanho(), interseccao, estaNoChao);
}

/* Coleta input do teclado e atualiza a posição futura do jogador */
void Jogador::move(float dt)
{
    deslocamento.setX(0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        deslocamento.atualizarX(VELMOV * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        deslocamento.atualizarX(-VELMOV * dt);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (estaNoAr == false))
    {
        deslocamento.atualizarY(-VELPULO * dt);
        estaNoAr = true;
    }

    // Caso entidade estiver no ar, aplica aceleração da gravidade
    if (estaNoAr == true)
    {
        deslocamento.atualizarY(GRAVIDADE * dt);
    }

    proximaPosicao = posicao + deslocamento;
}
