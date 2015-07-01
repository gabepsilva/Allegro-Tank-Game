#ifndef __TIRO_HPP__
#define __TIRO_HPP__

#include "Entidade.hpp"
//classe tiro
class Tiro : public Entidade{

   protected:
             //diz se o tiro ta vivo
             //ele morre quando sai da tela  
             
      int vivo;

   public:
      Tiro();
      Tiro(int lin, int col);
      ~Tiro();

      void Mover();
      void Atirou(int lin, int col);
      int  EstaVivo();
      void Morreu()   {vivo = 0;};
      void Imprimir(BITMAP* bmp);
};

#endif
