int digito1 = 0;
int digito0 = 0;

//Catodo Comum

byte seven_seg_digits[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 0, 1, 1, 0, 1 },
  { 1, 1, 1, 1, 0, 0, 1 },
  { 0, 1, 1, 0, 0, 1, 1 },
  { 1, 0, 1, 1, 0, 1, 1 },
  { 1, 0, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 1, 1 }
};

//Anodo Comum

//byte seven_seg_digits[10][7] = {
//  { 0, 0, 0, 0, 0, 0, 1 },
//  { 1, 0, 0, 1, 1, 1, 1 },
//  { 0, 0, 1, 0, 0, 1, 0 },
//  { 0, 0, 0, 0, 1, 1, 0 },
//  { 1, 0, 0, 1, 1, 0, 0 },
//  { 0, 1, 0, 0, 1, 0, 0 },
//  { 0, 1, 0, 0, 0, 0, 0 },
//  { 0, 0, 0, 1, 1, 1, 1 },
//  { 0, 0, 0, 0, 0, 0, 0 },
//  { 0, 0, 0, 1, 1, 0, 0 }
//};

void writePonto(byte dot) {
  //Se for anodo comum, dot = 0 para acender o ponto
  //Se for catodo comum, dot = 1 para acender o ponto
  digitalWrite(9, dot);
}

void sevenSegWrite(byte digit) {
  byte pin = 2;
  for (byte segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;
  }
}

void erase() {
  //Catodo Comum
  for (byte pin = 2; pin < 9; pin++) {
    digitalWrite(pin, LOW);
  }
  //Anodo Comum
//  for (byte pin = 2; pin < 9; pin++) {
//    digitalWrite(pin, HIGH);
//  }
}

void setup() {
  // put your setup code here, to run once:
  for (byte pin = 2; pin < 10; pin++) {
    pinMode(pin, OUTPUT);
  }
  writePonto(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int count = 0; count < 100; count++) {
    digito1 = count / 10;
    digito0 = count % 10;
    erase();
    //Catodo Comum
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    sevenSegWrite(digito0);
    delay(10);
    erase();
    digitalWrite(11,LOW);
    digitalWrite(12, HIGH);
    sevenSegWrite(digito1);
    delay(10);
    digitalWrite(12, LOW);
    //Anodo Comum
//    digitalWrite(11,  LOW);
//    digitalWrite(12, HIGH);
//    sevenSegWrite(digito0);
//    delay(10);
//    erase();
//    digitalWrite(11,HIGH);
//    digitalWrite(12, LOW);
//    sevenSegWrite(digito1);
//    delay(10);
//    digitalWrite(12, HIGH);
    delay(1000);
  }
}
