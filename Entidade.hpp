#ifndef __ENTIDADE_HPP__
#define __ENTIDADE_HPP__

#include <allegro.h>

//esta eh a classe que vai passar suas funçoes (metodos) e variaveis (atributos) 
//para as classe que herdam ...
//quem herda de entidade herda isso aqui ... 

class Entidade {

   protected:
     //algumas variaveis ..
     
      int lin, col; // tipo inteiro
      BITMAP *img;  // tipo BITMAP .. é coisa do allegro
      BITMAP *img2;
      BITMAP *img3;
      BITMAP *explode;
      int velocidade;

   public:
          //ALGUNS METODOS ... tudo contrutor
      Entidade();
      Entidade(char *nomeImg);
      Entidade(char *nomeImg,char *nomeImg2,char *nomeImg3,char *nomeImg3);
      Entidade(char *nomeImg, int lin, int col);
      // esse é um destrutor ...
      ~Entidade();

      //mais metodoes com implementaçao rapida  "inline"
      inline int  getLin()        {return lin;}; //retona lin ... deve ser lin de linha
      inline void setLin(int lin) {this->lin = lin;}; //seta lin
      inline int  getCol()        {return col;}; // retorna o valor de col
      inline void setCol(int col) {this->col = col;}; //seta
      inline void setVelocidade(int velocidade) {this->velocidade = velocidade;}; //seta velocidade
};

#endif
