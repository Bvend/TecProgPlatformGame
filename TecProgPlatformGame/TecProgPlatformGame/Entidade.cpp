#include "Entidade.h"

/*Construtora
Inicializa a entidade na posição informada no canto superior esquerdo*/
Entidade::Entidade(CoordF pos, CoordF tam, ID ind):
Ente(pos, tam),
id(ind),
body(sf::Vector2f(tamanho.getX(), tamanho.getY())),
proximaPosicao(pos)
{
	body.setPosition(posicao.getX(), posicao.getY());
}

Entidade::~Entidade()
{
}

ID Entidade::getID() const
{
	return id;
}

sf::RectangleShape* Entidade::getBody()
{
	return &body;
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

    body.setPosition(sf::Vector2f(posicao.getX(), posicao.getY()));
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
