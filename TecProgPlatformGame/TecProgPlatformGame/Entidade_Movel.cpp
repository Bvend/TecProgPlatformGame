#include "Entidade_Movel.h"

Entidade_Movel::Entidade_Movel(CoordF pos, CoordF tam, ID ind):
Entidade(pos, tam, ind),
estaNoAr(true),
deslocamentoY(0.f)
{
}

Entidade_Movel::~Entidade_Movel()
{
}

void Entidade_Movel::setEstaNoAr(bool NoAr)
{
    this->estaNoAr = NoAr;
}

void Entidade_Movel::setDeslocamentoY(float desY)
{
    this->deslocamentoY = desY;
}

/* Fun��o reposiciona entidade de acordo com colis�o com outra entidade */
void Entidade_Movel::reposicionarColisao(CoordF posEntidade2, CoordF tamEntidade2)
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
        deslocamentoY = 0;
        estaNoAr = false;
    }
    // Colis�o por cima
    else if (posicao.getY() > posEntidade2.getY()
        && posicao.getY() + tamanho.getY() > posEntidade2.getY() + tamEntidade2.getY()
        && posicao.getX() < posEntidade2.getX() + tamEntidade2.getX()
        && getDireita() > posEntidade2.getX()
        )
    {
        proximaPosicao.setY(posEntidade2.getY() + tamanho.getY());
        if (deslocamentoY < 0)
        {
            deslocamentoY = 0.f;
        }
    }
}