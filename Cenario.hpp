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
        
    //metodos (fun�oes, com "()"
    public:
    
        Cenario(); //contrutor > fun�ao com o mesmo nome da classe � o contrutor
        Cenario(int velocidade); // aqui tambem, s� que recebe uma variavel (ESSA VARIAVEL SE CHAMA ARGUMENO)
        ~Cenario(); //DESTRUTOR .. serve pra liberar a memoria *variaves 
        void CriaCenario(BITMAP* bmp); //fu�ao que cria o cenario;
        
};
#endif

