#include "Entidade.hpp"

// .. PUTS ..  caiu pipoca no teclado ,,, 

//constru ,,,
//todos els fazem a mema coisa  ... só que uns carregam algumas imagens a mais
Entidade::Entidade()
{
                    // sei inicializa
   img = NULL;
   lin = col = 0; // lin e col  = 0
   velocidade = 1;
}

Entidade::Entidade(char *nomeImg)
{
   img = load_bitmap(nomeImg, NULL); // carrega alguma imagem em img
   lin = col = 0; // lin e col  = 0
   velocidade = 1;
}

Entidade::Entidade(char *nomeImg,char *nomeImg2,char *nomeImg3,char *nomeImg4)
{
                        //carrega todas essas imagens
                        
   img = load_bitmap(nomeImg, NULL);
   img2= load_bitmap(nomeImg2, NULL);
   img3= load_bitmap(nomeImg3, NULL);
   explode= load_bitmap(nomeImg4, NULL);
   //seta valores 
   lin = col = 0;
   velocidade = 1;
}

Entidade::Entidade(char *nomeImg, int lin, int col)
{
                        // idem ...
   img = load_bitmap(nomeImg, NULL);
   this->lin = lin;
   this->col = col;
   velocidade = 10;//1
}

//DESTRUTOr .. LIBERA A MEMORIA QUE ESSAS IMAGEN OCUPAVAM ...
//OU SEJA .. DELETE 
Entidade::~Entidade()
{
   destroy_bitmap(img);
   destroy_bitmap(img2);
   destroy_bitmap(img3);
   destroy_bitmap(explode);
}

