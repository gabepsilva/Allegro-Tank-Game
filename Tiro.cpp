#include "Tiro.hpp"

Tiro :: Tiro() : Entidade("Tiro.bmp")
{
   velocidade = 50;
   vivo = 0;
}
//contrutor do tiro..
//erda de entidade o .bmp a linha e coluna
//adicona o vivo e velocidade
Tiro :: Tiro(int lin, int col) : Entidade("Tiro.bmp", lin, col)
{
   velocidade = 9;
   vivo = 0;
}

Tiro :: ~Tiro()
{
    destroy_bitmap(img);
}

void Tiro :: Mover()
{//faz ele ir subindo
   if (vivo)
      lin -= velocidade;
//se tiver fora da ele o iro morre
   if ( vivo && lin <= (-1 * img->h) )
      vivo = 0;
}

void Tiro :: Atirou(int lin, int col)
{//coloca o tiro na tela se nao tiver nenhum outro tiro na tela
   if (!vivo) 
   {
      vivo = 1;
      this->lin = lin;
      this->col = col;
   }
}

int Tiro :: EstaVivo()
{
   return 0;
}

void Tiro :: Imprimir(BITMAP* bmp)
{
   if (vivo)
      draw_sprite(bmp, img, col, lin);
}

