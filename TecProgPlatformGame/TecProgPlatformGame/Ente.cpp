#include "Ente.h"

/* Construtora */
Ente::Ente(Id ind):
id(ind)
{
}

/* Destrutora */
Ente::~Ente()
{
}

/* Retorna enum class Id do ente */
Id Ente::getId() const
{
	return id;
}
