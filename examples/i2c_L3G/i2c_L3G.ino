#include <Wire.h>
#include "i2c.h"

#include "i2c_L3G.h"
L3G l3g;


void setup()
{
    Serial.begin(115200);
    Serial.println("READ L3G");

    if (l3g.initialize()) Serial.println("Sensor found!");
    else
    {
        Serial.println("Sensor missing");
        while(1) {};
    }
}

void loop()
{
    float xyz_dps[3];

    l3g.getValue(xyz_dps);

    Serial.print(" X: ");
    Serial.print(xyz_dps[0],2);
    Serial.print(" \tY: ");
    Serial.print(xyz_dps[1],2);
    Serial.print(" \tZ: ");
    Serial.print(xyz_dps[2],2);
    Serial.println("");
    delay(20);

}


