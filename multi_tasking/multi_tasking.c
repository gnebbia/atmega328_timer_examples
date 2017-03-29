void setup(){
	time=millis();
	letturaluce_time=millis();
	servotime=millis();
	letturadati=millis();
}

void loop(){
	time=millis();

// even the condition  if(time>letturaluce_time+5) works, but doesn't handle as well the timer0 overflows //
/* even still better if we do like this, if ((unsigned long)(millis() - previousMillis) >= interval) */
	if((time - letturaluce_time) >= 5){
		luce1=analogRead(SENSORELUCE1);
		letturaluce_time=millis();
	}

	if((time - servotime1) >= 15){
		servo1.write(posservo1);
		servotime1=millis();
	}

	if((time - letturadati) >= 3000){
		Serial.print("Sensore 1 : ");
		Serial.print(letturaluce1,DEC);
		Serial.print("  Posizione motore 1 : ");
		Serial.println(posservo1,DEC);
		Serial.print("  Differenza : ");
		Serial.println(letturaluce1-letturaluce2);
		letturadati=millis();
	}
}
