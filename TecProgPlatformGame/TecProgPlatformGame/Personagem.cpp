#include "Personagem.h"
#include "Jogo.h"

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(Id ind, Gerenciadores::Gerenciador_Grafico* ger, CoordF pos, CoordF tam, int vid) :
            Entidade(ind, ger, pos, tam),
            num_vidas(vid),
            intervaloRecarga(0.5f),
            tempoRecarregando(0.f)
        {
        }

        Personagem::~Personagem()
        {
        }

        int Personagem::getNumVidas()
        {
            return num_vidas;
        }

        void Personagem::setEstaNoAr(bool NoAr)
        {
            this->estaNoAr = NoAr;
        }

        void Personagem::setDeslocamentoY(float desY)
        {
            this->deslocamentoY = desY;
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


