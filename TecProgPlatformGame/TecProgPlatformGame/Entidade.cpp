#include "Entidade.h"

/*Construtora
Inicializa a entidade na posição informada no canto superior esquerdo*/
Entidade::Entidade(Id ind, Gerenciador_Grafico* ger, CoordF pos, CoordF tam):
Ente(ind, ger),
posicao(pos),
proximaPosicao(pos),
tamanho(tam),
corpo(sf::Vector2f(tamanho.getX(), tamanho.getY()))
{
	corpo.setPosition(posicao.getX(), posicao.getY());
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

    corpo.setPosition(sf::Vector2f(posicao.getX(), posicao.getY()));
}

float Entidade::getCima()
{
    return posicao.getY();
}

float Entidade::getBaixo()
{
    return posicao.getY() + tamanho.getY();
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

sf::RectangleShape* Entidade::getCorpo()
{
	return &corpo;
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

void Entidade::renderizar()
{
    if (pGerenciadorGrafico)
    {
        pGerenciadorGrafico->renderizar(&corpo);
    }
}
