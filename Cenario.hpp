#ifndef __CENARIO_HPP__
#define __CENARIO_HPP__

#include "Entidade.hpp"

//declara classe cenario
class Cenario : public Entidade
{
      //atributos da classe (variaveis)
    protected:
                
        int velocidade;
        int linhaTela;
        
    //metodos (funçoes, com "()"
    public:
    
        Cenario(); //contrutor > funçao com o mesmo nome da classe é o contrutor
        Cenario(int velocidade); // aqui tambem, só que recebe uma variavel (ESSA VARIAVEL SE CHAMA ARGUMENO)
        ~Cenario(); //DESTRUTOR .. serve pra liberar a memoria *variaves 
        void CriaCenario(BITMAP* bmp); //fuçao que cria o cenario;
        
};
#endif

