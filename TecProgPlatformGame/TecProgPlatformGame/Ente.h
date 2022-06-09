#pragma once
#include "Gerenciador_Grafico.h"
#include <time.h>

enum class Id {
	VAZIO,
	JOGADOR,
	PAREDE,
	MOLA,
	ESPINHO,
	INIMIGO_A,
	INIMIGO_B,
	INIMIGO_C,
	PROJETIL
};

class Ente
{
protected:
	Id id;

public:
	Ente(Id ind = Id::VAZIO);
	~Ente();

	Id getId() const;

	virtual void executar() = 0;
};
