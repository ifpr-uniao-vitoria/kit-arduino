#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>
  
#define YP A3 // Y+ is on Analog1 (use A3 para o 9341) (era A1)
#define XM A2 // X- is on Analog2 (use A2 para o 9341) (era A2)
#define YM 9 // Y- is on Digital7 (use 9 para o 9341)  (era 7)
#define XP 8 // X+ is on Digital6 (use 8 para o 9341)  (era 6)
  
#define TS_MINX 150 // Use 150 para o 9341 (era 170)
#define TS_MINY 120 // Use 120 para o 9341 (era 165)
#define TS_MAXX 920
#define TS_MAXY 940
  
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 100);
 
//Definicao de cores
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF
  
//PP_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
Adafruit_TFTLCD tft(A3, A2, A1, A0, A4);
  
// Armazena o estado dos botões
bool valor_botao1 = 0;
bool valor_botao2 = 0;
bool valor_botao3 = 0;
bool valor_botao4 = 0;
  
#define MINPRESSURE 10
#define MAXPRESSURE 1000
  
void setup(void) 
{
  Serial.begin(9600);
  Serial.println("TFT Test");
  //identifier == 0x9325;
  tft.reset();
  delay(500);
  //uint16_t identifier = tft.readID(0x0);
  //Serial.print("Driver encontrado: ");
  //Serial.println(identifier, HEX);
  
 //tft.begin(0x9341); //Use esta linha para o controlador 9341
 tft.begin(0x9325);
  //tft.initDisplay();
  tft.fillScreen(BLACK);
  tft.setRotation(1);
  
  // Inicio - Texto e botoes
  tft.drawRoundRect(5, 15, 312, 50, 5, WHITE);
  tft.drawRoundRect(255, 15, 62, 50, 5, WHITE);
  tft.setTextColor(YELLOW);
  tft.setTextSize(3);
  tft.setCursor(15, 30);
  tft.println("Led Amarelo");
  
  tft.drawRoundRect(5, 70, 312, 50, 5, WHITE);
  tft.drawRoundRect(255, 70, 62, 50, 5, WHITE);
  tft.setTextColor(GREEN);
  tft.setTextSize(3);
  tft.setCursor(15, 85);
  tft.println("Led Verde");
  
  tft.drawRoundRect(5, 125, 312, 50, 5, WHITE);
  tft.drawRoundRect(255, 125, 62, 50, 5, WHITE);
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.setCursor(15, 140);
  tft.println("Led Azul");
  
  tft.drawRoundRect(5, 180, 312, 50, 5, WHITE);
  tft.drawRoundRect(255, 180, 62, 50, 5, WHITE);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.setCursor(15, 195);
  tft.println("Led Vermelho");
  
  //Preenchimento OFF
  tft.setTextColor(WHITE);
  tft.setCursor(260, 30);
  tft.println("OFF");
  tft.setCursor(260, 85);
  tft.println("OFF");
  tft.setCursor(260, 140);
  tft.println("OFF");
  tft.setCursor(260, 195);
  tft.println("OFF");
}
  
void loop()
{
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  digitalWrite(XM, LOW);
  pinMode(YP, OUTPUT);
  digitalWrite(YP, HIGH);
  pinMode(YM, OUTPUT);
  digitalWrite(YM, LOW);
  pinMode(XP, OUTPUT);
  digitalWrite(XP, HIGH);
  
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE)
  {
    p.x = tft.width() - (map(p.x, TS_MINX, TS_MAXX, tft.width(), 0));
    p.y = tft.height() - (map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));
    if (p.y > 200)
    {
      Serial.print("py: ");
      Serial.print(p.y);
      Serial.print(" px: ");
      Serial.print(p.x);
  
      //Testa botao amarelo
      if (p.x > 235 & p.x < 295)
      {
        if (valor_botao1 == 0)
        {
          tft.fillRoundRect(256, 16, 60, 48, 5, YELLOW);
          mostra_on(269, 30);
          valor_botao1 = !valor_botao1;
        }
        else
        {
          tft.fillRoundRect(256, 16, 60, 48, 5, BLACK);
          mostra_off(260, 30);
          valor_botao1 = !valor_botao1;
        }
      }
  
      //Testa botao verde
      if (p.x > 160 & p.x < 198)
      {
        if (valor_botao2 == 0)
        {
          tft.fillRoundRect(256, 71, 60, 48, 5, GREEN);
          mostra_on(269, 85);
          valor_botao2 = !valor_botao2;
        }
        else
        {
          tft.fillRoundRect(256, 71, 60, 48, 5,  BLACK);
          mostra_off(260, 85);
          valor_botao2 = !valor_botao2;
  
        }
      }
  
      //Testa botao azul
      if (p.x > 65 & p.x < 126)
      {
        if (valor_botao3 == 0)
        {
          tft.fillRoundRect(256, 126, 60, 48, 5, BLUE);
          mostra_on(269, 140);
          valor_botao3 = !valor_botao3;
        }
        else
        {
          tft.fillRoundRect(256, 126, 60, 48, 5,  BLACK);
          mostra_off(260, 140);
          valor_botao3 = !valor_botao3;
        }
      }
  
      //Testa botao vermelho
      if (p.x > 0 & p.x < 58)
      {
        if (valor_botao4 == 0)
        {
          tft.fillRoundRect(256, 181, 60, 48, 5, RED);
          mostra_on(269,195);
          valor_botao4 = !valor_botao4;
        }
        else
        {
          tft.fillRoundRect(256, 181, 60, 48, 5,  BLACK);
          mostra_off(260,195);
          valor_botao4 = !valor_botao4;
        }
      }
    }
  }
}
  
void mostra_on(int x, int y)
{
  tft.setTextColor(BLACK);
  tft.setCursor(x, y);
  tft.println("ON");
  delay(100);
}
  
void mostra_off(int x, int y)
{
  tft.setTextColor(WHITE);
  tft.setCursor(x, y);
  tft.println("OFF");
  delay(100);
}
