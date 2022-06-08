#include "Ente.h"

Ente::Ente(Id ind, Gerenciador_Grafico* ger):
id(ind),
pGerenciadorGrafico(ger)
{
}

Ente::~Ente()
{
	pGerenciadorGrafico = NULL;
}

Id Ente::getId() const
{
	return id;
}

void Ente::setGerenciadorGrafico(Gerenciador_Grafico* ger)
{
	pGerenciadorGrafico = ger;
}
