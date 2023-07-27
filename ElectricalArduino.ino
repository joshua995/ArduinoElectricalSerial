/*Joshua Liu
Arduino - Python Electrical
*/
#define photoresistor A0 //Plug in the photoresitor in pin A0
#define thermistor A1 //Plug in the thermistor in pin A1

String message = "";
int brightness = 0;
int lights = 3; //Digital PWM pin

int tempResistance = 0;
int fanSpeed = 0;
int fans = 4; //Digital PWN pin

bool isDark = false;

void setup() {
  Serial.begin(9600);
  pinMode(photoresistor, INPUT);
  pinMode(thermistor, INPUT);
  pinMode(lights, OUTPUT);
  pinMode(fans, OUTPUT);
  digitalWrite(lights, LOW);
}

void loop() {
  Serial.println("Photoresistor: " + String(analogRead(photoresistor)));

  tempResistance = analogRead(thermistor);
  fanSpeed = map(tempResistance, 0, 900, 255, 0);
  //Serial.print("fan speed: "); Serial.println(fanSpeed);
  analogWrite(fans, fanSpeed);
  delay(1000);
  if(analogRead(photoresistor) <= 50){
    if (!isDark){
      digitalWrite(lights, HIGH);
      isDark = true;
    }
  }else{
    isDark = false;
  }
  if(Serial.available()) {
    String data = Serial.readString();// Reads the serial data sent from the Python code
    brightness = map(data.toInt(), 0, 900, 50, 0);
    message = "Brightness: " + String(brightness);
    analogWrite(lights, brightness);
    delay(1000);
    Serial.println("Brightness: " + String(brightness));
  }
}
