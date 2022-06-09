#include "Entidade.h"

/*Construtora
Inicializa a entidade na posição informada no canto superior esquerdo*/
Entidade::Entidade(Id ind, CoordF pos, CoordF tam):
Ente(ind),
posicao(pos),
proximaPosicao(pos),
tamanho(tam),
corpo()
{
}

Entidade::~Entidade()
{
}

void Entidade::setPosicao(CoordF pos)
{
    posicao = pos;
}

CoordF Entidade::getPosicao() const
{
    return posicao;
}

float Entidade::getEsquerda()
{
    return posicao.getX();
}

float Entidade::getDireita()
{
    return posicao.getX() + tamanho.getX();
}

CoordF Entidade::getProximaPosicao()
{
    return proximaPosicao;
}

/* Atualiza posicao do personagem de acordo com deslocamento */
void Entidade::atualizarPos()
{
    if (proximaPosicao.getX() < 0)
    {
        proximaPosicao.setX(0);
    }

    posicao = proximaPosicao;

    corpo.setPosicao(posicao);
}

float Entidade::getCima()
{
    return posicao.getY();
}

float Entidade::getBaixo()
{
    return posicao.getY() + tamanho.getY();
}

float Entidade::getCentroX()
{
    return posicao.getX() + tamanho.getX() / 2.f;
}

float Entidade::getCentroY()
{
    return posicao.getY() + tamanho.getY() / 2.f;
}

void Entidade::setTamanho(CoordF tam)
{
    tamanho = tam;
}

CoordF Entidade::getTamanho() const
{
    return tamanho;
}

float Entidade::getLargura()
{
    return (tamanho.getX());
}

float Entidade::getAltura()
{
    return tamanho.getY();
}

int Entidade::detectarColisao(CoordF posEntidade2, CoordF tamEntidade2)
{
    // Colisão pela direita
    if (posicao.getX() < posEntidade2.getX()
        && getDireita() < posEntidade2.getX() + tamEntidade2.getX()
        && posicao.getY() < posEntidade2.getY() + tamEntidade2.getY()
        && posicao.getY() + tamanho.getY() > posEntidade2.getY()
        )
    {
        return COLISAO_DIREITA;
    }
    // Colisão pela esquerda
    else if (posicao.getX() > posEntidade2.getX()
        && getDireita() > posEntidade2.getX() + tamEntidade2.getX()
        && posicao.getY() < posEntidade2.getY() + tamEntidade2.getY()
        && posicao.getY() + tamanho.getY() > posEntidade2.getY()
        )
    {
        return COLISAO_ESQUERDA;
    }
    // Colisão por baixo
    else if (posicao.getY() < posEntidade2.getY()
        && posicao.getY() + tamanho.getY() < posEntidade2.getY() + tamEntidade2.getY()
        && posicao.getX() < posEntidade2.getX() + tamEntidade2.getX()
        && getDireita() > posEntidade2.getX()
        )
    {
        return COLISAO_BAIXO;
    }
    // Colisão por cima
    else if (posicao.getY() > posEntidade2.getY()
        && posicao.getY() + tamanho.getY() > posEntidade2.getY() + tamEntidade2.getY()
        && posicao.getX() < posEntidade2.getX() + tamEntidade2.getX()
        && getDireita() > posEntidade2.getX()
        )
    {
        return COLISAO_CIMA;
    }

    return 0;
}

sf::RectangleShape* Entidade::getForma()
{
    return corpo.getForma();
}

void Entidade::renderizar()
{
    corpo.renderizar();
}
