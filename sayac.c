#include<LiquidCrystal.h>
//Bu program ile kişi sayısı bulunabilir fakat X sayısını geçince alarm çalmaz (üstüne biraz daha kod eklenmesi lazım.)
// LCD Ekran için (Pin): LiquidCrystal lcd(13,12,11,10,9,8);
#define in 14
#define out 19
#define relay 2
int count = 0; 
// Ekran için, odadaki kişi saysını ekrana göstermek amaçlı.
void IN()
{
    count++;
    lcd.clear();
    lcd.print("Kişi Sayısı");
    lcd.setCursor(0,1);
    lcd.print(count); 
    delay(1000);
}
void OUT()
{
    count--;
    lcd.clear();
    lcd.print("Kişi Sayısı");
    lcd.setCursor(0,1);
    lcd.print(count); 
    delay(1000);
}
void setup()
{
    lcd.begin(16,2);
    lcd.print("Kişi Sayısı");
    delay(2000);
    pinMode(in, INPUT);
    pinMode(out, INPUT);
    pinMode(relay, OUTPUT);
}
void loop(){
    if(digitalRead(in))
    IN();
    if(digitalRead(out))
    OUT();

    if(count <= 0)
    {
        lcd.clear();
        digitalWrite(relay, LOW);
        lcd.clear();
        lcd.print("Kimse yok.");
        lcd.setCursor(0,1);
        LCD.print("Işıklar Kapalı");
        delay(200);
    }
    else
    digitalWrite(relay, HIGH)
}
}
