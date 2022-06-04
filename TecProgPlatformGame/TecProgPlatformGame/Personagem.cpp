#include "Personagem.h"

Personagem::Personagem(int vidas, CoordF pos, CoordF tam, ID ind):
Entidade(pos, tam, ind),
num_vidas(vidas),
estaNoAr(true),
deslocamentoY(0.f)
{
}

Personagem::~Personagem()
{
}

void Personagem::setEstaNoAr(bool NoAr)
{
    this->estaNoAr = NoAr;
}

void Personagem::setDeslocamentoY(float desY)
{
    this->deslocamentoY = desY;
}

/* Atualiza posicao do personagem de acordo com deslocamento */
void Personagem::atualizarPos()
{
    if (proximaPosicao.getX() < 0)
    {
        proximaPosicao.setX(0);
    }

    posicao = proximaPosicao;

    body.setPosition(sf::Vector2f(posicao.getX(), posicao.getY()));
}

/* Fun��o reposiciona entidade de acordo com colis�o com outra entidade */
void Personagem::reposicionarColisao(CoordF posEntidade2, CoordF tamEntidade2)
{
    // Colis�o pela direita
    if (posicao.getX() < posEntidade2.getX()
        && getDireita() < posEntidade2.getX() + tamEntidade2.getX()
        && posicao.getY() < posEntidade2.getY() + tamEntidade2.getY()
        && posicao.getY() + tamanho.getY() > posEntidade2.getY()
        )
    {
        proximaPosicao.setX(posEntidade2.getX() - tamanho.getX());
    }
    // Colis�o pela esquerda
    else if (posicao.getX() > posEntidade2.getX()
        && getDireita() > posEntidade2.getX() + tamEntidade2.getX()
        && posicao.getY() < posEntidade2.getY() + tamEntidade2.getY()
        && posicao.getY() + tamanho.getY() > posEntidade2.getY()
        )
    {
        proximaPosicao.setX(posEntidade2.getX() + tamEntidade2.getX());
    }
    // Colis�o por baixo
    else if (posicao.getY() < posEntidade2.getY()
        && posicao.getY() + tamanho.getY() < posEntidade2.getY() + tamEntidade2.getY()
        && posicao.getX() < posEntidade2.getX() + tamEntidade2.getX()
        && getDireita() > posEntidade2.getX()
        )
    {
        proximaPosicao.setY(posEntidade2.getY() - tamanho.getY());
        estaNoAr = false;
        cout << "colisao por baixo" << endl;
    }
    // Colis�o por cima
    else if (posicao.getY() > posEntidade2.getY()
        && posicao.getY() + tamanho.getY() > posEntidade2.getY() + tamEntidade2.getY()
        && posicao.getX() < posEntidade2.getX() + tamEntidade2.getX()
        && getDireita() > posEntidade2.getX()
        )
    {
        proximaPosicao.setY(posEntidade2.getY() + tamanho.getY());
        deslocamentoY = 0.f;
    }
}
