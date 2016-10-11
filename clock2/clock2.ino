//https://github.com/Makuna/Rtc/tree/master/examples/DS1307_Simple
//http://pdacontrolenglish.blogspot.com.co  
//http://pdacontrol.blogspot.com.co

//SDA - D3 -- GPIO0
//SCL - D4 -- GPIO2

#include <Wire.h>
#include <SPI.h>
#include <RTClib.h>

RTC_DS1307 RTC;
void setup () {
Wire.begin(0,2); // Inicia el puerto I2C
RTC.begin(); // Inicia la comunicación con el RTC
delay(500);
  // Check to see if the RTC is keeping time.  If it is, load the time from your computer.
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // This will reflect the time that your sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
delay(1000);
Serial.begin(115200); // Establece la velocidad de datos del puerto serie

}
void loop(){
DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC
  
Serial.print(now.year(), DEC); // Año
Serial.print('/');
Serial.print(now.month(), DEC); // Mes
Serial.print('/');
Serial.print(now.day(), DEC); // Dia
Serial.print(' ');
Serial.print(now.hour(), DEC); // Horas
Serial.print(':');
Serial.print(now.minute(), DEC); // Minutos
Serial.print(':');
Serial.print(now.second(), DEC); // Segundos
Serial.println();
delay(1000); // La información se actualiza cada 1 seg.
}
