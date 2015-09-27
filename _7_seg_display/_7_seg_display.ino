// Programa : Contador crescente 0 a F
// Modificacoes e comentarios : Arduino e Cia
// Baseado no programa:
// Arduino 7 segment display example software
// http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
// License: http://www.opensource.org/licenses/mit-license.php (Go crazy)
// Define a ordem de ligação dos segmentos, dos digitos 0 a F
// Este padrão é para display de catodo comum
// Para display de anodo comum, modifique os valores de 0 para 1 e 
// de 1 para 0
// 1 = LED ligado, 0 = LED desligado, nessa ordem :
//                   Arduino pinos: 2,3,4,5,6,7,8

byte seven_seg_digits[16][7] = { { 1,1,1,1,1,1,0 },  // = Digito 0
                                 { 0,1,1,0,0,0,0 },  // = Digito 1
                                 { 1,1,0,1,1,0,1 },  // = Digito 2
                                 { 1,1,1,1,0,0,1 },  // = Digito 3
                                 { 0,1,1,0,0,1,1 },  // = Digito 4
                                 { 1,0,1,1,0,1,1 },  // = Digito 5
                                 { 1,0,1,1,1,1,1 },  // = Digito 6
                                 { 1,1,1,0,0,0,0 },  // = Digito 7
                                 { 1,1,1,1,1,1,1 },  // = Digito 8
                                 { 1,1,1,0,0,1,1 },  // = Digito 9
                                 { 1,1,1,0,1,1,1 },  // = Digito A
                                 { 0,0,1,1,1,1,1 },  // = Digito B
                                 { 1,0,0,1,1,1,0 },  // = Digito C
                                 { 0,1,1,1,1,0,1 },  // = Digito D
                                 { 1,0,0,1,1,1,1 },  // = Digito E
                                 { 1,0,0,0,1,1,1 } };  // = Digito F

void setup() {  
  //Pino 2 do arduino ligado ao segmento A, pino 3 ao B, ... , pino 8 ao G
  for (byte pin = 2; pin < 9; pin++) {  
  pinMode(pin, OUTPUT); 
  }
}

void sevenSegWrite(byte digit) { //Funcao que aciona o display
  
  byte pin = 2;

  //Percorre o array ligando os segmentos correspondentes ao digito
  for (byte segCount = 0; segCount < 7; ++segCount) { 
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;
  }
}

void loop() {
  //Contador de 0 a 15, ligando os segmentos correspondentes
  //0 a 9 = liga os segmentos correspondentes aos numeros
  //10 a 15 = Forma as letras A,B,C,D,E,F
  for (byte count = 0; count < 16; count++) {
     sevenSegWrite(count);
     delay(1000);
  }
}
