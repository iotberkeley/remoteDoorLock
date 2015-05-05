char code[] = {3, 3, 3, 3};
int current[] = {-1, -1, -1, -1};
int incomingByte;
int currentPos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);


}

void loop() {
  
   if (Serial.available() > 0) {
      // read the incoming byte:
      incomingByte = Serial.read();
      incomingByte -= 48;
      // Serial.println(incomingByte);
      current[currentPos] = incomingByte;
      currentPos += 1;
      Serial.print("received: ");
      Serial.println(incomingByte);
     
      
      int n = 0;
      while (current[n] == code[n]) {
        if (n == sizeof(code) - 1) {
          openLock(2000); 
          break;
        }
        n++;
      }
      if (current[n] != -1) {
        memset(current, -1, sizeof(current));
        currentPos = 0;
      }
     for (int i = 0; i < 4; i ++ ) {
      Serial.print(current[i]);
      Serial.print(" ");
      }
      Serial.println("");
    }
  
  delay(100);
}

void openLock(int time) {
  Serial.println("Code validated. Opening lock.");
  digitalWrite(5, HIGH);
  delay(time);
  digitalWrite(5, LOW);
  
}