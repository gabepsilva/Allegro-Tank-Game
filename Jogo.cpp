#include "Jogo.hpp"

//JOGO ... hummm
Jogo::Jogo()
{
            
   int i;
   // t eh um tanque ... ele anda e tudo mais .. (ele tem as funçoes de mover
   t  = new Tanque();
   
   //cria as naves de acordo com o numero setado (i)
   for (i=0; i<N_NAVES; i++)
      n[i] = new Nave();
     // cria o cenario e c
   c  = new Cenario();
}

Jogo::~Jogo()
{
             //BASICAMENTE DELETA todas a naves
   int i;
   delete t;
   for (i=0; i<N_NAVES; i++)
      delete n[i];
}
//funçao jogar ... vamo jogar ?

void Jogo::Jogar()
{
     
   int ii=1;
   int acertos=0; 
//carrega o fundo
   BITMAP *fundo2 =load_bitmap("fundo2.bmp", NULL);
//imagen para fazer o double buffering
   BITMAP *doublebmp = create_bitmap(SCREEN_W, SCREEN_H);
/*
    n[ii]->setLin(1500);
    n[ii]->setCol(15);
    n[ii++]->setVelocidade(5);

    n[ii]->setLin(1250);
    n[ii]->setCol(10);
    n[ii++]->setVelocidade(5);
    
    n[ii]->setLin(1000);
    n[ii]->setCol(30);
    n[ii++]->setVelocidade(5);

    n[ii]->setLin(750);
    n[ii]->setCol(40);
    n[ii++]->setVelocidade(5);
    
    n[ii]->setLin(500);
    n[ii]->setCol(20);
    n[ii++]->setVelocidade(5);
*/   

// ano apertando esc ... 
   while(!key[KEY_ESC])
   {
 // cenario .. cria o cenrio ... desenhando o "fundo2" na tela
   c->CriaCenario(fundo2);

      draw_sprite(doublebmp, fundo2, 0, 0);
  
    //desenha o tanque ...
      t->Imprimir(doublebmp);
      
      //quando vc aperta os botao .. o tanque vai andar !!
      //Teclado Setas 
      if ( key[KEY_LEFT] )
         t->MovaEsquerda(doublebmp);
      if ( key[KEY_RIGHT] )
         t->MovaDireita(doublebmp);
      if ( key[KEY_UP] )
         t->MovaCima(doublebmp);
      if ( key[KEY_DOWN] )
         t->MovaBaixo();
    
      // ----------------------------------------------------------------------
    //vai movendo e desenhando as naves !!
      for (ii=0; ii<N_NAVES; ii++) 
      {
         n[ii]->Mover();
         n[ii]->Imprimir(doublebmp);
      }


      // ----------------------------------------------------------------------
     
     //se apertar a vai atirar ...
     // atira ... desenha o tiro na tela e vai movendo ele pra cima  ...
      if ( key[KEY_A] )
      {
         t->Atira();
      }

      // ----------------------------------------------------------------------
//movendo ...
      t->MoveTiro();
 
 // detecta a colizao
     int cont = 2 ;
     // ----------------------------------------------------------------------
      if (  t->Colisao_Nave(n[0]) == 1  || t->Colisao_Nave(n[1]) == 1 || t->Colisao_Nave(n[2]) == 1
         || t->Colisao_Nave(n[3]) == 1  || t->Colisao_Nave(n[4]) == 1 || t->Colisao_Nave(n[5]) == 1)
         
        // break;
        {

         cont--;
         if (cont == 0)
         {   
            rest(125000);
            break;
            
         }
      }

      // ----------------------------------------------------------------------
    //verifica se o bixo ta vivo ... ele morre quando colide ...
      if (!n[0]->EstaVivo() && !n[1]->EstaVivo()&&
          !n[2]->EstaVivo() && !n[3]->EstaVivo()&&
          !n[4]->EstaVivo() && !n[5]->EstaVivo()&&
          !n[6]->EstaVivo() && !n[7]->EstaVivo()&&
          !n[8]->EstaVivo()) 
      {
          //sei la ;;;
         rest(40000);
         //avisa q vc é um losser
         allegro_message("Fim de Jogo vc ganhou!!!");
         break;
      }

      
         blit(doublebmp, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
   }

   //libera a memoria do fundo e da imagem de double bufferig
   destroy_bitmap(fundo2);
   
   destroy_bitmap(doublebmp);
}

