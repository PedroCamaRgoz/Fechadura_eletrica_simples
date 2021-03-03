/*
 * File:   main.c
 * Author: Pedro
 *
 * Created on 25 de Fevereiro de 2021, 19:24
 */


#include <xc.h>
#include "config.h"
#include "display7seg.h"   // programa Display 7 seg + logica e configuração dos botões
#include "delay.h"


void main(void) 
{
    func_init();
    char cont=0;
        
    while(1)
    {
         
        if(borSub()) // se botao for apertado, proseguir para função do digitos7seg(cont)
        {    
            digitos7seg(cont);
            cont = ++cont  %16; 
            
        }
        
      if(cont==9 && confirma()==1) //cont==9 numero = 8, se cont for igual a posição 9 e botao confirmar estiver em 1, desligue o rele da bobina e ligue led verde 
        {
            led(0);
            rele(0);
            delay(1000);
            rele(1);
            led(1);          
        }
      

     if(cont!=9 && confirma()==1 ) // se cont for diferente da posição 9 e o botao confirmar for apertado, ligar led vermelho de aviso de falha/erro
        {
            ledv(0);
            delay(1000);
            ledv(1); 
        }
        
        rele(1);
        delay(1);
    }
}