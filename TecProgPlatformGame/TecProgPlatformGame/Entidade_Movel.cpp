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

/* Função reposiciona entidade de acordo com colisão com outra entidade */
void Entidade_Movel::reposicionarColisao(CoordF posEntidade2, CoordF tamEntidade2, int direcao_colisao)
{
    // Colisão pela direita
    if (direcao_colisao == COLISAO_DIREITA)
    {
        proximaPosicao.setX(posEntidade2.getX() - tamanho.getX());
    }
    // Colisão pela esquerda
    else if (direcao_colisao == COLISAO_ESQUERDA)
    {
        proximaPosicao.setX(posEntidade2.getX() + tamEntidade2.getX());
    }
    // Colisão por baixo
    else if (direcao_colisao == COLISAO_BAIXO)
    {
        proximaPosicao.setY(posEntidade2.getY() - tamanho.getY());
        deslocamentoY = 0;
        estaNoAr = false;
    }
    // Colisão por cima
    else if (direcao_colisao == COLISAO_CIMA)
    {
        proximaPosicao.setY(posEntidade2.getY() + tamanho.getY());
        if (deslocamentoY < 0)
        {
            deslocamentoY = 0.f;
        }
    }
}