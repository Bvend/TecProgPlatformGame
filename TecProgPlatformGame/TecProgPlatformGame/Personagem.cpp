#include "Personagem.h"

Personagem::Personagem(int vidas, CoordF des, CoordF pos, CoordF tam, ID ind):
Entidade(pos, tam, ind),
num_vidas(vidas),
deslocamento(des)
{
}

Personagem::~Personagem()
{
}

float Personagem::getDeslocamentoY()
{
    return deslocamento.getY();
}

float Personagem::getDeslocamentoX()
{
    return deslocamento.getX();
}

/* Atualiza posicao do personagem de acordo com deslocamento */
void Personagem::atualizarPos()
{
    posicao += deslocamento;

    if (posicao.getX() < 0)
    {
        deslocamento.atualizarX(-posicao.getX());
        posicao.setX(0);
    }

    body.move(sf::Vector2f(deslocamento.getX(), deslocamento.getY()));
    //std::cout << "posicao y: " << posicao.getY() << std::endl;
}

/* Função reposiciona entidade de acordo com colisão com outra entidade */
void Personagem::reposicionarColisao(CoordF posEntidade2, CoordF tamEntidade2, CoordF interseccao, bool* estaNoChao)
{
    // Colisão pela direita
    if (posicao.getX() < posEntidade2.getX()
        && posicao.getX() + tamanho.getX() < posEntidade2.getX() + tamEntidade2.getX()
        && posicao.getY() < posEntidade2.getY() + tamEntidade2.getY()
        && posicao.getY() + tamanho.getY() > posEntidade2.getY()
        )
    {
        deslocamento.setX(0.f);
    }
    // Colisão pela esquerda
    else if (posicao.getX() > posEntidade2.getX()
        && posicao.getX() + tamanho.getX() > posEntidade2.getX() + tamEntidade2.getX()
        && posicao.getY() < posEntidade2.getY() + tamEntidade2.getY()
        && posicao.getY() + tamanho.getY() > posEntidade2.getY()
        )
    {
        deslocamento.setX(0.f);
    }
    // Colisão por baixo
    else if (posicao.getY() < posEntidade2.getY()
        && posicao.getY() + tamanho.getY() < posEntidade2.getY() + tamEntidade2.getY()
        && posicao.getX() < posEntidade2.getX() + tamEntidade2.getX()
        && posicao.getX() + tamanho.getX() > posEntidade2.getX()
        )
    {
        deslocamento.setY(0.f);
        *estaNoChao = true;
    }
    // Colisão por cima
    else if (posicao.getY() > posEntidade2.getY()
        && posicao.getY() + tamanho.getY() > posEntidade2.getY() + tamEntidade2.getY()
        && posicao.getX() < posEntidade2.getX() + tamEntidade2.getX()
        && posicao.getX() + tamanho.getX() > posEntidade2.getX()
        )
    {
        deslocamento.setY(0.f);
    }
}
