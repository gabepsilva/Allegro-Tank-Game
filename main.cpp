#include "allegro.h"
#include "Jogo.hpp"

//depois de tudo implementado a gente vem pra ca ...

int main()
{
    //criamos um objeto da classe qie vai inicializar o alegro ...
  ControleGrafico *cg = new ControleGrafico();
     
   // eu a funçao retonar algo diferente de 1  mata o mais ... retorna 1 e cabouse ...
   if ( cg->IniciaAllegro() != 1 )
      return 1;
    //vai al .. cria o nosso jogo ....
   Jogo *j = new Jogo();
   //chama a funçao jogar
   j->Jogar();
   //depois que jogou o jogo ... livra a memoria ...
   delete j;

   //finaliza o alegro
   cg->FinalizaAllegro();
   delete cg;

   return 0;
  
}
END_OF_MAIN()
// sempre va acompanhando o que as funçoes fazem  .... quando chamar uma funçao ..
//vc vai la no .cpp dele e leia o que ele faz.
