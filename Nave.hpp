#ifndef __NAVE_HPP__
#define __NAVE_HPP__
#include <allegro.h>
#include "Entidade.hpp"
#include "Tiro.hpp"

class Nave : public Entidade{

   private:
           //existem variaves que nao existem aqui mas que são usadas no cpp
           // iso pq  nave herdaou de entidade .. esssas variaveis estão declaradas
           // em entidade
      int direcao;
      int vivo;


   public:
          //funcoes ....
      Nave();
      ~Nave();

//vo descreve isso aqui no cpp
      inline int EstaVivo()   {return vivo;};;

      void Mover();
      void Imprimir(BITMAP* bmp);
      void Morre();
      void Colisao(Tiro *t);
      int getAltura() {return img->h;};
      int getLargura() {return img->w;};
      int IsAlive()    {return vivo;}; 
};

#endif
