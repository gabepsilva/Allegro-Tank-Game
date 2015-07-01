#ifndef __TANQUE_HPP__
#define __TANQUE_HPP__
#include "Nave.hpp"
#include "Entidade.hpp"
#include "Tiro.hpp"
#include "Nave.hpp"
#include "Cenario.hpp"

class Tanque : public Entidade{

   private:
      Tiro *ti;

   public:
      int pontos;
      Tanque();
      ~Tanque();
 
      inline Tiro * getTiro()   {return ti;};
 
      void MovaEsquerda(BITMAP *db);
      void MovaDireita(BITMAP *db);
      void MovaCima(BITMAP *db);
      void MovaBaixo();
      void Atira();
      void MoveTiro();
      void Imprimir(BITMAP* bmp);
      int Colisao_Nave(Nave *nave); 
      int Colisao_Tanque(Tanque *tanque);
};

#endif

