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
void Entidade_Movel::reposicionarColisao(CoordF posEntidade2, CoordF tamEntidade2, int direcao_colisao)
{
    // Colis�o pela direita
    if (direcao_colisao == COLISAO_DIREITA)
    {
        proximaPosicao.setX(posEntidade2.getX() - tamanho.getX());
    }
    // Colis�o pela esquerda
    else if (direcao_colisao == COLISAO_ESQUERDA)
    {
        proximaPosicao.setX(posEntidade2.getX() + tamEntidade2.getX());
    }
    // Colis�o por baixo
    else if (direcao_colisao == COLISAO_BAIXO)
    {
        proximaPosicao.setY(posEntidade2.getY() - tamanho.getY());
        deslocamentoY = 0;
        estaNoAr = false;
    }
    // Colis�o por cima
    else if (direcao_colisao == COLISAO_CIMA)
    {
        proximaPosicao.setY(posEntidade2.getY() + tamanho.getY());
        if (deslocamentoY < 0)
        {
            deslocamentoY = 0.f;
        }
    }
}