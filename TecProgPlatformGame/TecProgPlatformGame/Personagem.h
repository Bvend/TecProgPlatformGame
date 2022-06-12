#pragma once
#include "Entidade.h"

class Jogo;

namespace Entidades
{
	namespace Personagens
	{
		class Personagem : public Entidade
		{
		protected:
			float intervaloRecarga;
			float tempoRecarregando;

		public:
			Personagem(Id ind = Id::VAZIO, Gerenciadores::Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f));
			virtual ~Personagem();

			void setEstaNoAr(bool NoAr);

			void setDeslocamentoY(float deslY);

			void atualizarTempoRecarregando();

			void reiniciarTempoRecarregando();

			bool antingiuTodaRecarga();

			bool atingiuMetadeRecarga();

			virtual void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar) = 0;

			virtual void executar() = 0;

			virtual void mover() = 0;
		};
	}
}
