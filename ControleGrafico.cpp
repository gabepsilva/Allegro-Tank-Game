#include "ControleGrafico.hpp"
#include "allegro.h"
#include "conio.h"
//contrutor
int ControleGrafico::IniciaAllegro()
{
    //inicia o allegro
    allegro_init();
    //..o teclado
	install_keyboard();
	 // .. 16 bits de cores
    set_color_depth(16); 

   // (set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 800, 600, 0, 0) != 0)
   //.. se criar a janela do jogo no tamanho de 640x480
   if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0)
   {  //.. sei la set alguma coisa
      set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
      //fala pro usuario que deu merda ..
      allegro_message("Nao foi possivel selecionar modo grafico algum.\n%s\n", allegro_error);
      return 0;
   }

   return 1;
}

//finaliza o allegro.
void ControleGrafico::FinalizaAllegro()
{
   allegro_exit();
}

