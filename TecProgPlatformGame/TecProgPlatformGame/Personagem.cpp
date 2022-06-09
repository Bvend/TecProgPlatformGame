#include "Personagem.h"

Personagem::Personagem(Id ind, CoordF pos, CoordF tam, int vid):
Entidade(ind, pos, tam),
num_vidas(vid),
estaNoAr(true),
deslocamentoY(0.f)
{
}

Personagem::~Personagem()
{
}

int Personagem::getNumVidas()
{
    return num_vidas;
}

void Personagem::setEstaNoAr(bool NoAr)
{
    this->estaNoAr = NoAr;
}

void Personagem::setDeslocamentoY(float desY)
{
    this->deslocamentoY = desY;
}

void Personagem::reposicionarColisao(CoordF posEntidade2, CoordF tamEntidade2, int direcao_colisao)
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
        proximaPosicao.setY(posEntidade2.getY() + tamEntidade2.getY());
        if (deslocamentoY < 0)
        {
            deslocamentoY = 0.f;
        }
    }
}
