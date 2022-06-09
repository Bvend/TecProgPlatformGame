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
	Gerenciador_Grafico* pGerenciadorGrafico;

public:
	Ente(Id ind = Id::VAZIO, Gerenciador_Grafico* ger = NULL);
	~Ente();

	Id getId() const;

	void setGerenciadorGrafico(Gerenciador_Grafico* ger);

	virtual void renderizar() = 0;

	virtual void executar() = 0;
};
