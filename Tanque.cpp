#include "Tanque.hpp"
#include <allegro.h>

//herda varios btmaps da entidade
//adicona lin, col, velocidade ... etc ...
Tanque::Tanque() : Entidade("Tanque.bmp","Tanque_esq.bmp","Tanque_dir.bmp","explosao.bmp")
{
   lin = SCREEN_H - img->h - 10;
   col = ( SCREEN_W / 2 ) - ( img->w / 2 );
   velocidade = 7;
   ti = new Tiro();
   pontos=0;
}

Tanque::~Tanque()
{
   delete ti;
   destroy_bitmap(img);
   destroy_bitmap(img2);
   destroy_bitmap(img3);
}

void Tanque::MovaEsquerda(BITMAP *db)
{
     //o tanqu nao sai da agua pelo lado esquerdo ..
     

   int r =  getr(getpixel(db, col-velocidade, lin)); 
   int g =  getg(getpixel(db, col-velocidade, lin));
   int b =  getb(getpixel(db, col-velocidade, lin));
   //essas 3 ultimas linhas ficam verificando a cor do lado do tanque ,,
   //se nao for o azul, nao deixa o tanque andar mais 

   if (r != 131 || g != 255 || b != 255)
     col-=velocidade;
}

void Tanque::MovaDireita(BITMAP *db)
{   

//aqui a mesma coisa ... so qe nao funciona nao  pq nao tem o maldito if ;;
   int r =  getr(getpixel(db, col+velocidade, lin));
   int g =  getg(getpixel(db, col+velocidade, lin));
   int b =  getb(getpixel(db, col+velocidade, lin));
    // Verifica colisão com lateral
   col+=velocidade;
   if ( col >= (SCREEN_W - img->w + 4) )
      col = SCREEN_W - img->w + 4; 
}

void Tanque::MovaCima(BITMAP *db)
	{
   // iden ...
   int r =  getr(getpixel(db, col-velocidade, lin));
   int g =  getg(getpixel(db, col-velocidade, lin));
   int b =  getb(getpixel(db, col-velocidade, lin));

   lin-=velocidade;
   //evia que o tanque saia  da tela por cima
   if ( lin <= 50 )
      lin = 50;
}

void Tanque:: MovaBaixo()
{
   lin+=velocidade;
//evia que saia por baixo...
   if ( lin >= (SCREEN_H - img->h) )
      lin = SCREEN_H - img->h;
}

void Tanque::MoveTiro()
{
     //faz o tiro ir subindo
   ti->Mover();
}

void Tanque::Atira()
{
     //posiciona o tiro da tanque bem no meio dele ...
     
   ti->Atirou(lin-1, col+20);
}

void Tanque::Imprimir(BITMAP* doublebmp)
{
   draw_sprite(doublebmp, img,col,lin);
   ti->Imprimir(doublebmp);
}

//funcao de colisao ca nave..
int Tanque::Colisao_Nave(Nave *nave)
{
    //se a nave ta tiva
   if ( nave->IsAlive() ) 
   {
        //fica pegando as posiçoes do tanque e tela
      int liNave = nave->getLin();
      int lfNave = nave->getLin() + nave->getAltura();
      int liTanque = lin;
      int lfTanque = lin + img->h;
    //fica pegando as posiçoes da nave e tela
      int ciNave = nave-> getCol();
      int cfNave = nave-> getCol() + nave->getLargura();
      int ciTanque= col;
      int cfTanque= col + img->w;
      int batidas=1;
      //fica verificando se elas estao na mesma area ...
      if ( ((liNave < lfTanque && liNave > liTanque) || ( lfNave > liTanque && lfNave < lfTanque)) &&
          ((ciNave < cfTanque && ciNave > ciTanque) || (cfNave  > ciTanque && cfNave < cfTanque)) )
      {
          // se sim .. colide . e mata
         nave->Morre();
         return 1;
      }
   }
   return 0;
}
