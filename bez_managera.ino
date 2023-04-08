const int adresa[] = { 3, 5, 6, 9, 10, 11 };
const int cnt = 6;

unsigned long* interval = new unsigned long[cnt];
unsigned long* last_time = new unsigned long[cnt];
int state[cnt];

void setup() {
  for (int i = 0; i < cnt; i++)
  {
    last_time[i] = 0;
    state[i] = LOW;
    pinMode(adresa[i], OUTPUT);
  }
  interval[0] =  100000;
  interval[1] =  200000;  
  interval[2] =  160000;  
  interval[3] =  300000;  
  interval[4] =  500000;    
  interval[5] =  190000;  
}
void loop() {
  unsigned long t = micros();

  for (int i = 0; i < cnt; i++)
  {
    if(t - last_time[i] >= interval[i])
    {
      last_time[i] = t;
      if (state[i] == LOW)
      {
        state[i] =  HIGH;
      }
      else 
      {
        state[i] = LOW;
      }
      digitalWrite(adresa[i], state[i]);
    }
  }
}