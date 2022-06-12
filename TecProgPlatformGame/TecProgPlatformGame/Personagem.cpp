#include "Personagem.h"
#include "Jogo.h"

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(Id ind, Gerenciadores::Gerenciador_Grafico* ger, CoordF pos, CoordF tam) :
            Entidade(ind, ger, pos, tam),
            intervaloRecarga(0.5f),
            tempoRecarregando(0.f)
        {
        }

        Personagem::~Personagem()
        {
        }
        
        void Personagem::setEstaNoAr(bool NoAr)
        {
            this->estaNoAr = NoAr;
        }

        void Personagem::setDeslocamentoY(float desY)
        {
            this->velocidade.setY(desY);
        }

        void Personagem::atualizarTempoRecarregando()
        {
            tempoRecarregando += Jogo::getDt();
        }

        void Personagem::reiniciarTempoRecarregando()
        {
            tempoRecarregando = 0;
        }

        bool Personagem::antingiuTodaRecarga()
        {
            if (tempoRecarregando >= intervaloRecarga)
            {
                return true;
            }

            return false;
        }

        bool Personagem::atingiuMetadeRecarga()
        {
            if (tempoRecarregando >= (intervaloRecarga / 2.f))
            {
                return true;
            }

            return false;
        }
    }
}


