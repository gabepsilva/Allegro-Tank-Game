#ifndef __JOGO_HPP__
#define __JOGO_HPP__
#include "Cenario.hpp"
#include "Tanque.hpp"
#include "Nave.hpp"
#include "controleGrafico.hpp"
#include "controleGrafico.hpp"

//sempre que digitar N_NAVES ... É A MESMA COISA QUE DIGITAR "6"
#define N_NAVES 6


class Jogo {

   private:
           //o jogo tem um cenario
      Cenario *c;
      //tanques
      Tanque *t;
      //naves
      Nave *n[N_NAVES];
      //es essa porra de bitmap
      BITMAP *doublebmp;
      
   public:
      Jogo();
      ~Jogo();
      
      //funçao jogar
      void Jogar();
     
};

#endif
