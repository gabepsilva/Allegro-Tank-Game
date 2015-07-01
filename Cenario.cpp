#include "Cenario.hpp"
#include <allegro.h>

//cenario esta herdando a classe entidade.
//ou seja a classe cenario passa a ter as mesmas variaveis  e funçoes da classe 
//entidade, mais as susas proprias funçoes e variaveis .
//implementando cosntrutor 
Cenario::Cenario() : Entidade("fundo2.bmp")
{
    velocidade = 2; //velocidade com que o cenario desce
    linhaTela = img->h - SCREEN_H; // inicializa essa var.
}
//implementando outro cosntrutor  ...
Cenario::Cenario(int velocidade)
{
    this->velocidade=velocidade;
    linhaTela = img->h - SCREEN_H;
}
//criando no cenario ...
void Cenario::CriaCenario(BITMAP* bmp)
{
   //sei nao
   linhaTela -= velocidade;

   //se for 0
   if (linhaTela <= 0) 
   {  //desenha o cenario na tela (o rio com pedras)
      blit(img, bmp, 0, img->h + linhaTela, 0, 0, bmp->w, -linhaTela);
      blit(img, bmp, 0, 0, 0, -linhaTela, bmp->w, SCREEN_H + linhaTela);
      //sei nao
      if ( -linhaTela >= SCREEN_H )
         linhaTela = img->h - SCREEN_H;

   } else {
          //desenha cenario tb.
      blit(img, bmp, 0, linhaTela, 0, 0, bmp->w, bmp->h);
   }
}

