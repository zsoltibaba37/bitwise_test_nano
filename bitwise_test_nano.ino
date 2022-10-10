// -------------- MASK LIST --------------
constexpr uint8_t mask0{ 0b00000001 };
constexpr uint8_t mask1{ 0b00000010 };
constexpr uint8_t mask2{ 0b00000100 };
constexpr uint8_t mask3{ 0b00001000 };
constexpr uint8_t mask4{ 0b00010000 };
constexpr uint8_t mask5{ 0b00100000 };
constexpr uint8_t mask6{ 0b01000000 };
constexpr uint8_t mask7{ 0b10000000 };

// -------------- Flag --------------
//              76543210
uint8_t flag0{ 0b00101001 };
uint8_t initFlag = flag0;

// Analog pin
// constexpr int8_t pot{ A7 };
// int t{};

// 9 pin
constexpr uint8_t pin9 { 0b00000010 };  // 9 pin the led
int64_t timing1{ 100000 };              // led blink treshold

// ------------------ CLASS ------------------
// ------------------ CLASS ------------------
class LedTimer {

public:
  LedTimer(int64_t _teshold, uint8_t _led);
  void change();

private:
  uint64_t initTime{ micros() };
  uint64_t treshold;
  uint8_t led;
  uint8_t mask;
};

LedTimer::LedTimer(int64_t _treshold, uint8_t _led)
  : treshold(_treshold),
    led(_led) {}
    

void LedTimer::change(){
  if(micros() - initTime >= treshold){
    initTime = micros();
    //PORTB ^= mask1;
    PORTB ^= pin9;
  }
}

// ------------------ INIT Obj ------------------
LedTimer LED9(timing1, pin9);

// -------------- SETUP --------------
// -------------- SETUP --------------
void setup() {
  //             98
  //DDRB |= B00000011;  // 9 pin set to output OR
  DDRB |= pin9;         // 9 pin set to output

  //pinMode(pot, INPUT);

  Serial.begin(115200);
  Serial.println("--------------------------------");
  Serial.println("Bitwise test");
  Serial.println("--------------------------------");
  delay(1000);
}

// -------------- LOOP --------------
// -------------- LOOP --------------
void loop() {

  LED9.change();
  
  // redout flag0
  Serial.println("Initial flag0");
  Serial.println(flag0, BIN);
  Serial.println("--------------------------------");

  // set 1 and 2 bit
  flag0 |= (mask1 | mask2);
  Serial.println("set 1 and 2 bit");
  Serial.println(flag0, BIN);
  Serial.println("--------------------------------");

  // reset 3 and 5 bit
  flag0 &= ~(mask3 | mask5);
  Serial.println("reset 3 and 5 bit");
  Serial.println(flag0, BIN);
  Serial.println("--------------------------------");

  // reset all bit
  flag0 &= ~(mask0 | mask1 | mask2 | mask3 | mask4 | mask5 | mask6 | mask7);
  Serial.println("reset all bit");
  Serial.println(flag0, BIN);
  Serial.println("--------------------------------");

  // flip all bit
  flag0 ^= (mask0 | mask1 | mask2 | mask3 | mask4 | mask5 | mask6 | mask7);
  Serial.println("flip all bit");
  Serial.println(flag0, BIN);
  Serial.println("--------------------------------");

  Serial.println("reset flag0 to initFlag state");
  flag0 = initFlag;
  Serial.println("--------------------------------");
  //delay(3000);

  // this just a port test
  /*
  t = map(analogRead(pot), 0, 1024, 100, 1500);  
  PORTB ^= mask1;
  PORTB |= mask1;  // set 9 to hign
  delay(t);
  PORTB &= ~B00000010;  // set 9 to low
  PORTB &= ~mask1;  // set 9 to low
  delay(t);
  */
}