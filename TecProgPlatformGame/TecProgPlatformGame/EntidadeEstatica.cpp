#include "EntidadeEstatica.h"

EntidadeEstatica::EntidadeEstatica(CoordF posicao, CoordF tamanho, ID id):
Entidade(posicao, tamanho, id),
sprite()
{
}

EntidadeEstatica::~EntidadeEstatica()
{
}

void EntidadeEstatica::render()
{
	sprite.render();
}
