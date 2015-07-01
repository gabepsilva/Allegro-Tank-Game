#include "Nave.hpp"
#include <allegro.h>

//vamo que vamo ..

//a nave tem uma imagem chamada toco e  mais vel, direcao e se esta vivo ...
Nave :: Nave() : Entidade("toco.bmp",5,5)
{
   velocidade = 3;
   direcao    = 1;
   vivo       = 1;
}

Nave :: ~Nave()
{//delete
   destroy_bitmap(img);
}
//essa eh a fnçao que move a nave..
void Nave :: Mover()
{ 
     // se tiver vivo
   if (vivo) 
   {
             
     if (direcao == 1)
     {
                 //vai sempre incrementando 2 na lina e colina da nave
         col += velocidade;
         lin += velocidade;
     }
     else
      {
         lin += velocidade;
         col += velocidade;
       }  
       //evita que a vane sai da tela
       if ( direcao == 0 && col <= 0 )
          direcao = 1;
     else 
       if ( direcao == 1 && col >= (SCREEN_W - img->w) )
         direcao = 0;
        
     if (direcao == 1)
       lin += velocidade  ;
       
     if ( lin >= (SCREEN_H - img->h) )
      lin = 1;
   }
}
//imprime
void Nave :: Imprimir(BITMAP* bmp)
{
     //se ta vivo ...
   if (vivo)
   {
            //bota o trco na tela
            
      draw_sprite(bmp, img, col, lin);
   }
}

void Nave :: Morre()
{
     // mata a nave
   vivo = 0;
}

void Nave :: Colisao(Tiro *t)
{ //se o a nave iver viva e e tanque tb ,,,
   if ( vivo && t->EstaVivo() ) 
   {
        //verifica se eles colidira, ...
        // ou seja .. se as imagens esiverm no mesmo espaço ...
      if ( t->getLin() < img->h && t->getCol() >= col && t->getCol() <= (col + img->w) ) 
      {  
           //se estiverem .. eh pq colidio .. mata
         vivo = 0;
         //t morreu :(
         t->Morreu();
      }
   }
}
