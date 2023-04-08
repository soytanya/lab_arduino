#include <TaskManagerIO.h>;
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

taskid_t task0 = taskManager.scheduleFixedRate(interval[0], [] {
		if (state[0] == LOW)
      {
        state[0] =  HIGH;
      }
      else 
      {
        state[0] = LOW;
      }
      digitalWrite(adresa[0], state[0]);
	}, TIME_MICROS);

  taskid_t task1 = taskManager.scheduleFixedRate(interval[1], [] {
		if (state[1] == LOW)
      {
        state[1] =  HIGH;
      }
      else 
      {
        state[1] = LOW;
      }
      digitalWrite(adresa[1], state[1]);
	}, TIME_MICROS);
  
  taskid_t task2 = taskManager.scheduleFixedRate(interval[2], [] {
    if (state[2] == LOW)
      {
        state[2] =  HIGH;
      }
      else 
      {
        state[2] = LOW;
      }
      digitalWrite(adresa[2], state[2]);
  }, TIME_MICROS);

  taskid_t task3 = taskManager.scheduleFixedRate(interval[3], [] {
    if (state[3] == LOW)
      {
        state[3] =  HIGH;
      }
      else 
      {
        state[3] = LOW;
      }
      digitalWrite(adresa[3], state[3]);
  }, TIME_MICROS);

  taskid_t task4 = taskManager.scheduleFixedRate(interval[4], [] {
    if (state[4] == LOW)
      {
        state[4] =  HIGH;
      }
      else 
      {
        state[4] = LOW;
      }
      digitalWrite(adresa[4], state[4]);
  }, TIME_MICROS);

  taskid_t task5 = taskManager.scheduleFixedRate(interval[5], [] {
    if (state[5] == LOW)
      {
        state[5] =  HIGH;
      }
      else 
      {
        state[5] = LOW;
      }
      digitalWrite(adresa[5], state[5]);
  }, TIME_MICROS);
}

void loop() {
  taskManager.runLoop();
}
