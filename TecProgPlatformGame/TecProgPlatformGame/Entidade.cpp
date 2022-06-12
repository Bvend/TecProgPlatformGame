#include "Entidade.h"

namespace Entidades
{
    /* Construtora
    Inicializa a entidade na posição informada no canto superior esquerdo */
    Entidade::Entidade(Id ind, Gerenciadores::Gerenciador_Grafico* ger, CoordF pos, CoordF tam) :
        Ente(ind, ger),
        posicao(pos),
        proximaPosicao(pos),
        tamanho(tam),
        velocidade(0.f, 0.f),
        estaVivo(true),
        estaNoAr(true)
    {
    }

    Entidade::~Entidade()
    {
    }

    void Entidade::setPosicao(CoordF pos)
    {
        posicao = pos;
        forma.setPosition(sf::Vector2f(posicao.getX(), posicao.getY()));
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

    CoordF Entidade::getProximaPosicao() const
    {
        return proximaPosicao;
    }

    /* Atualiza posicao do personagem de acordo com deslocamento */
    void Entidade::atualizarPos()
    {
        if (proximaPosicao.getX() < 0.f)
        {
            proximaPosicao.setX(0.f);
        }
        else if (proximaPosicao.getX() + tamanho.getX() > pGerenciadorGrafico->getLarguraJanela())
        {
            proximaPosicao.setX(pGerenciadorGrafico->getLarguraJanela() - tamanho.getX());
        }
        if (proximaPosicao.getY() < 0.f)
        {
            proximaPosicao.setY(0.f);
            velocidade.setY(0.f);
        }

        posicao = proximaPosicao;

        setPosicao(posicao);
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

    CoordF Entidade::getCentro()
    {
        return CoordF(getCentroX(), getCentroY());
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

    void Entidade::setEstaVivo(bool vivo)
    {
        estaVivo = vivo;
    }

    bool Entidade::getEstaVivo() const
    {
        return estaVivo;
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

    void Entidade::reposicionarColisao(CoordF posEntidade2, CoordF tamEntidade2, int direcao_colisao)
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
            velocidade.setY(0.f);
            estaNoAr = false;
        }
        // Colisão por cima
        else if (direcao_colisao == COLISAO_CIMA)
        {
            proximaPosicao.setY(posEntidade2.getY() + tamEntidade2.getY());
            if (velocidade.getY() < 0.f)
            {
                velocidade.setY(0.f);
            }
        }
    }
}


