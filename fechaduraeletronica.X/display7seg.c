/*
 * File:   display7seg.c
 * Author: Pedro
 *
 * Created on 25 de Fevereiro de 2021, 19:28
 */

#include <xc.h>
#include <pic16f887.h>
#include "config.h"
#include "delay.h"

#define BOTAO PORTBbits.RB0 
#define CONFIRMA PORTBbits.RB1
#define RELE PORTBbits.RB3
#define LED PORTBbits.RB2
#define LEDVERMELHO PORTBbits.RB4

char numeros[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

void func_init(void)
{
    TRISD=0x00;
    PORTD=0;
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB3 = 0;
    TRISBbits.TRISB4 = 0;
    PORTBbits.RB4 = 1;
    PORTBbits.RB2 = 1;
    PORTBbits.RB3 = 1;
    ANSELH = 0x00;
    
    PORTD = 0XFF;
}

int botao (void)
{
    return(BOTAO);
}

int confirma (void)
{
    return(CONFIRMA);
}

 ////////////////////////////

void digitos7seg (char num)
{
  PORTD =(num < 16) ? numeros[num] : 0;
}

void led (unsigned char t)
{
    LED = t;    
}

void ledv (unsigned char t)
{
    LEDVERMELHO = t;    
}

void rele (unsigned char t)
{
    RELE= t;
}

/////////////////////////////////////////////

char bAnt = 0;

char borSub (void)
{  
    char aux;
    
    aux = BOTAO && !bAnt;
    bAnt = BOTAO;
    return(aux);    
}

char borDes (void)
{
 
    char aux;
    
    aux = !BOTAO && bAnt;
    bAnt = BOTAO;
    return(aux);
   
}

char bordas (void)
{
    char aux;
 
    aux = (BOTAO && !bAnt) || (!BOTAO && bAnt);
    bAnt = BOTAO;
    return(aux);
    
}