#include "Fase1.h"

#define CAMINHO_FASE1 "./recurssos/Fase1/Fase1.jpg"

namespace Fases
{
	Fase1::Fase1(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico, Gerenciadores::Gerenciador_Colisoes* pGerenciadorColisoes):
		Fase(GerenciadorGrafico, pGerenciadorColisoes)
	{
		//inicializarCorpo(CAMINHO_FASE1, CoordF(0.f, 0.f), CoordF(1280.f, 720.f));
	}

	Fase1::~Fase1()
	{
	}
}