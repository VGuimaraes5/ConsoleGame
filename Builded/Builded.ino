#include <TVout.h>
#include <fontALL.h>

#define direita 3
#define esquerda 4
#define disparo 5

int lMaxima, aMaxima;
int pontos = 3;



TVout tv;
PROGMEM const unsigned char img[] =
{ 120, 67,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x00, 0xf8, 0x00, 0x73, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf8, 0x00, 0xf8, 0x00, 0x63, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xf8, 0x00, 0xf8, 0x00, 0x63, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xf8, 0xf1, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xf8, 0xf1, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
  0xe1, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xe1, 
  0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xe3, 0x1f, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xe3, 0x3f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xe7, 0x3f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xc7, 0x7f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xc6, 0x7f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0x86, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0x86, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x8e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x9c, 0xfc, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xc7, 0x9c, 0xfc, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x87, 0x1c, 0xfc, 0x00, 0x1f, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0x8f, 0x18, 0xfc, 0x00, 0x1f, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0x8f, 0x18, 0xfc, 0x7f, 0xff, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x8f, 0x18, 0xfc, 0x7f, 0xff, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 
  0x39, 0xfc, 0x7f, 0xff, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x71, 
  0xfc, 0x7f, 0xff, 0x00, 0x70, 0x01, 0xf0, 0x07, 0xf8, 0x07, 0xff, 0xff, 0xfe, 0x1e, 0x71, 0xfc, 
  0x7f, 0xfe, 0x00, 0x30, 0x01, 0xf0, 0x07, 0xf0, 0x03, 0xff, 0xff, 0xfe, 0x3e, 0x61, 0xfc, 0x7f, 
  0xfc, 0x3c, 0x18, 0x01, 0xc3, 0xc7, 0xe1, 0xc3, 0xff, 0xff, 0xfe, 0x3e, 0x61, 0xfc, 0x00, 0x3c, 
  0x3e, 0x1f, 0x1f, 0xc7, 0xe3, 0xc3, 0xe3, 0xff, 0xff, 0xfe, 0x3e, 0x63, 0xfc, 0x00, 0x3c, 0x7f, 
  0x1e, 0x1f, 0xcf, 0xf3, 0xc7, 0xf3, 0xff, 0xff, 0xfe, 0x00, 0xe3, 0xfc, 0x00, 0x3f, 0xff, 0x1e, 
  0x1f, 0xcf, 0xf3, 0xc7, 0xf3, 0xff, 0xff, 0xfe, 0x00, 0xe7, 0xfc, 0x7f, 0xff, 0xff, 0x1e, 0x1f, 
  0xcf, 0xf3, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xfc, 0x7f, 0xff, 0x00, 0x1e, 0x1f, 0xc0, 
  0x03, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xfc, 0x7f, 0xfc, 0x00, 0x1e, 0x1f, 0xc0, 0x03, 
  0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0x87, 0xfc, 0x7f, 0xfc, 0x3f, 0x1e, 0x1f, 0xcf, 0xff, 0xc7, 
  0xff, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xfc, 0x7f, 0xf8, 0x3f, 0x1e, 0x1f, 0xcf, 0xff, 0xc7, 0xf3, 
  0xff, 0xff, 0xff, 0xe0, 0x0f, 0xfc, 0x7f, 0xf8, 0x7f, 0x1f, 0x1f, 0xcf, 0xf3, 0xc7, 0xf3, 0xff, 
  0xff, 0xff, 0xc0, 0x0f, 0xfc, 0x7f, 0xf8, 0x7c, 0x1f, 0x1f, 0xcf, 0xf3, 0xc7, 0xf3, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x7f, 0xfc, 0x00, 0x1f, 0x01, 0xe0, 0x07, 0xe0, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfc, 0x7f, 0xfc, 0x03, 0x1f, 0xc1, 0xf0, 0x07, 0xf8, 0x07, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xfc, 0x7f, 0xff, 0x0f, 0x1f, 0xe1, 0xf0, 0x0f, 0xf8, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,

};

class Posicao
{
  public:
    int posX;
    int posY;
};

class Nave: public Posicao
{
  public:
    int jumping = 0;
    int jumpFrame = 0;
     
    void begin(int x, int y)
    {
      posX = x;
      posY = y;
    }

    void desenhaNave()
    {
      tv.println(posX, posY - 10, "A");
      tv.draw_rect(posX - 3, posY - 5, 2, 4, WHITE, WHITE);
      tv.draw_rect(posX + 3, posY - 5, 2, 4, WHITE, WHITE);
      tv.draw_rect(posX - 1, posY - 6, 2, 7, WHITE, WHITE);
      tv.draw_rect(posX - 2, posY, 1, 4, WHITE, WHITE);
      tv.draw_rect(posX + 2, posY, 1, 4, WHITE, WHITE);
     }
   
    void moverNaveDireita() 
    {
      //GARANTE QUE A NAVE NÃO SAIA DO CAMPO E A MOVIMENTA PARA A DIREITA
      if (posX < lMaxima - 16)
      {
          posX += 1;
      }
    }
    
    void moverNaveEsquerda()
    {
      //GARANTE QUE A NAVE NÃO SAIA DO CAMPO E A MOVIMENTA PARA A ESQUERDA
      if (posX > 16)
      {
        posX -= 1;
      }
    }

    void pula () 
    {
       
       if (jumpFrame < 8 && jumping) {
          jumpFrame++;
          posY -= 2;
       } else if (jumpFrame < 16 && jumping){
          jumpFrame++;
          posY += 2;
       } else {
         jumping = 0;
         jumpFrame = 0;
       }
    }
};
Nave nave;


/* class Missil:public Posicao
{
  public:
  boolean estado;
  void desenhaMissil()
  {
    //VERIFICA SE O MISSIL ESTA ATIVO E SE ELE STA DENTRO DO CAMPO
    if(this->estado && this->posY > 3)
    {
      this->posY -=3;
      tv.println(posX, posY, "*");
    }
    else
    {
      this->estado = 0;
      this->posX = nave.posX+4;
      this->posY = nave.posY;
    }
  }
};
Missil missil; */

class Asteroid:public Posicao
{
  public:
  boolean estado;
  int posicaoInicial = lMaxima;
  
  void desenhaAsteroid()
  {
    if(this->estado && this->posX > 10 )
    {
       tv.println(posX, posY, "*");
       this->posX--;
    }
    else
    {
      this->posX = posicaoInicial;
      this->posY = 75;
      this->estado = 1;
    }

    //VERIFICA SE A NAVE ATINGIU O ASTEROID
    if(nave.posY > 70 && this->posX == nave.posX)
    {
        this->estado = 0;
        pontos --;
    }
    
  }
};
Asteroid asteroid;

//DESENHA BORDA - LIMITE DO CAMPO
void desenhaCampo() 
{
  tv.draw_rect(0, 0, lMaxima, aMaxima, WHITE);
  tv.draw_rect(200, 50 - pontos, 2, pontos, WHITE);
  
  //canto esquerdo
  tv.println(20, 10, "_");
  tv.println(24, 10, "_");
  tv.println(20, 70, "_");
  tv.println(24, 70, "_");
  
 //canto direito
  tv.println(80, 10, "_");
  tv.println(84, 10, "_");
  tv.println(80, 70, "_");
  tv.println(84, 70, "_");

  //canto meio
  tv.println(50, 30, "_");
  tv.println(54, 30, "_");
  tv.println(50, 50, "_");
  tv.println(54, 50, "_");

}

void campolimpo() 
{
  tv.draw_rect(0, 0, lMaxima, aMaxima, WHITE);
  tv.draw_rect(200, 50 - pontos, 2, pontos, WHITE);  
}


void placar()
{
  tv.select_font(font4x6);
  tv.println(2, 2, pontos);
}



void setup() 
{
  pinMode(direita, INPUT_PULLUP);
  pinMode(esquerda, INPUT_PULLUP);
  pinMode(disparo, INPUT_PULLUP);
 
  tv.begin(NTSC, 120, 96);

  lMaxima = tv.hres() - 10;
  aMaxima = tv.vres() - 3;

  Serial.begin(9600);

  //POSICIONA A NAVE NO CENTRO INFERIOR DO CAMPO
   nave.begin(20, 75);
 


  tv.select_font(font4x6);
  tv.bitmap(10, 10, img);

  tv.println(0, 0, "JOGOS DIGITAIS PARA CONSOLE\n");
  tv.println(40, 80, "FATEC - AMERICANA");
  tv.delay(5000);
  tv.clear_screen();
  tv.println(25, 55, "Boa Sorte!!");

  tv.delay(2500);

  tv.clear_screen();

}

void loop()
{
  tv.clear_screen();
  placar();
  campolimpo();
  nave.desenhaNave();
  nave.pula();
 

  if (pontos == 0)
  {
      tv.println(30, 60, "VOCE PERDEU!!!");
      tv.println(10, 30, "FATEC - AMERICANA");
      tv.delay(5000);
  }
   

  asteroid.desenhaAsteroid();
  if (digitalRead(direita) == LOW) nave.moverNaveDireita();
  if (digitalRead(esquerda) == LOW) nave.moverNaveEsquerda();
  if (digitalRead(disparo) == LOW) nave.jumping = 1;
  delay(25);
 
}
