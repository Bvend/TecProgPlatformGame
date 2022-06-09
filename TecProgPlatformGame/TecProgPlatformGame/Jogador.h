#pragma once
#include "Personagem.h"

class Jogador : public Personagem
{
private:
    float velMov;
    float velPulo;
    //sf::RectangleShape barraVida;

public:
    Jogador(Id ind = Id::VAZIO, Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), int vid = 0);
    ~Jogador();

<<<<<<< HEAD
    void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

    void executar();
=======
    void colisao(Entidade* Entidade2);
    void move(float dt);

    void setTexture(Texture* texture);
>>>>>>> 91dcff85e6c0a5b60e1520e6cef76ba4e4b29c12
};

