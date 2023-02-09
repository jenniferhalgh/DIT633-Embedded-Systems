const int row1 = 11; // digital pin for steering row 1
const int row2 = 10; // digital pin for steering row 2
const int row3 = 9; // digital pin for steering row 3
const int row4 = 8; // digital pin for steering row 4

const int col1 = 7;	// digital pin for column 1
const int col2 = 6; // digital pin for column 2
const int col3 = 5; // digital pin for column 1
const int col4 = 4; // digital pin for column 1

void setup()
{
 
  pinMode(row1, OUTPUT); // send signal through row1
  pinMode(row2, OUTPUT); // send signal through row2
  pinMode(row3, OUTPUT); // send signal through row3
  pinMode(row4, OUTPUT); // send signal through row4
  
  pinMode(col1, INPUT); // receive signal through column1
  pinMode(col2, INPUT); // receive signal through column2
  pinMode(col3, INPUT); // receive signal through column3
  pinMode(col4, INPUT); // receive signal through column4
  
  Serial.begin(9600); // passing 9600 in the speed parameter to exchange messages with the Serial Monitor at a data rate of 9600 bits per second
}

void loop()
{
  digitalWrite(row1, LOW); // send a signal through row 1
  int r1c1 = digitalRead(col1); // read column 1
  int r1c2 = digitalRead(col2); // read column 2
  int r1c3 = digitalRead(col3); // read column 3
  int r1c4 = digitalRead(col4); // read column 4
  digitalWrite(row1, HIGH);	// reset row 1
  
  digitalWrite(row2, LOW); // send a signal through row 2
  int r2c1 = digitalRead(col1); // read column 1
  int r2c2 = digitalRead(col2); // read column 2
  int r2c3 = digitalRead(col3); // read column 3
  int r2c4 = digitalRead(col4); // read column 4
  digitalWrite(row2, HIGH);	// reset row 2
  
  digitalWrite(row3, LOW); // send a signal through row 3
  int r3c1 = digitalRead(col1); // read column 1
  int r3c2 = digitalRead(col2); // read column 2
  int r3c3 = digitalRead(col3); // read column 3
  int r3c4 = digitalRead(col4); // read column 4
  digitalWrite(row3, HIGH);	// reset row 3
  
  digitalWrite(row4, LOW); // send a signal through row 3
  int r4c1 = digitalRead(col1); // read column 1
  int r4c2 = digitalRead(col2); // read column 2
  int r4c3 = digitalRead(col3); // read column 3
  int r4c4 = digitalRead(col4); // read column 4
  digitalWrite(row4, HIGH);	// reset row 4
  
  // check if 1 was pressed
  if (r1c1 == 0)
  {
    Serial.println('1'); // print 1 in the serial monitor
    delay(1000); // delay for one second 
  }  
  
  // check if 2 was pressed
  if (r1c2 == 0)
  {
    Serial.println('2'); // print 2 in the serial monitor
    delay(1000); // delay for one second
  }
  
  // we check if 3 was pressed
  if (r1c3 == 0)
  {
    Serial.println('3'); // print 3 in the serial monitor
    delay(1000); // delay for one second
  } 
  
  // check if 4 was pressed
  if (r2c1 == 0)
  {
    Serial.println('4'); // print 4 in the serial monitor
    delay(1000); // delay for one second
  } 
  
  // check if 5 was pressed
  if (r2c2 == 0)
  {
    Serial.println('5'); // print 5 in the serial monitor
    delay(1000); // delay for one second
  } 
  
  // check if 6 was pressed
  if (r2c3 == 0)
  {
    Serial.println('6'); // print 6 in the serial monitor
    delay(1000); // delay for one second
  } 
  
  // check if 7 was pressed
  if (r3c1 == 0)
  {
    Serial.println('7'); // print 7 in the serial monitor
    delay(1000); // delay for one second
  } 
  
  // check if 8 was pressed
  if (r3c2 == 0)
  {
    Serial.println('8'); // print 8 in the serial monitor
    delay(1000); // delay for one second
  }
  
  // check if 9 was pressed
  if (r3c3 == 0)
  {
    Serial.println('9'); // print 9 in the serial monitor
    delay(1000); // delay for one second
  }
  
  // check if 0 was pressed
  if (r4c2 == 0)
  {
    Serial.println('0'); // print 0 in the serial monitor
    delay(1000); // delay for one second
  }
  
  // check if * was pressed
  if (r4c1 == 0)
  {
    Serial.println('*'); // print * in the serial monitor
    delay(1000); // delay for one second
  }
  
  // check if # was pressed
  if (r4c3 == 0)
  {
    Serial.println('#'); // print # in the serial monitor
    delay(1000); // delay for one second
  }
  
  // check if A was pressed
  if (r1c4 == 0)
  {
    Serial.println('A'); // print A in the serial monitor
    delay(1000); // delay for one second
  }
  
  // check if B was pressed
  if (r2c4 == 0)
  {
    Serial.println('B'); // print B in the serial monitor
    delay(1000); // delay for one second
  }
  
  // check if C was pressed
  if (r3c4 == 0)
  {
    Serial.println('C'); // print C in the serial monitor
    delay(1000); // delay for one second
  }
  
  // check if D was pressed
  if (r4c4 == 0)
  {
    Serial.println('D'); // print D in the serial monitor
    delay(1000); // delay for one second
  }
}