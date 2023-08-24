/*Arduino speaker song tutorial
* The song is played on the speaker connected to pin 3 and GND.
* by Akshay James, modified by roza
*/

#include"pitches.h"

int melody[] = {
NOTE_C3, NOTE_DS3, NOTE_F3, NOTE_GS2, 
NOTE_GS2, NOTE_DS3, NOTE_F3, NOTE_DS3, NOTE_C3, NOTE_C3,
NOTE_C3, NOTE_C3, NOTE_F2, NOTE_GS2, NOTE_AS2, NOTE_AS2, NOTE_C3, NOTE_AS2, NOTE_GS2, NOTE_G2,

NOTE_C3, NOTE_DS3, NOTE_F3, NOTE_GS2, 
NOTE_GS2, NOTE_DS3, NOTE_F3, NOTE_DS3, NOTE_DS3, NOTE_C3,
NOTE_GS2, NOTE_C3, NOTE_GS2, NOTE_GS2, NOTE_AS2, NOTE_AS2, NOTE_C3, NOTE_AS2, NOTE_GS2, NOTE_G2,

NOTE_GS2, NOTE_G2,
NOTE_GS2, NOTE_G2,
NOTE_GS2, NOTE_G2,
NOTE_GS2, NOTE_G2, NOTE_G2, NOTE_F2,

NOTE_GS2, NOTE_G2,
NOTE_GS2, NOTE_G2,
NOTE_GS2, NOTE_G2,
NOTE_GS2, NOTE_G2, NOTE_G2, NOTE_F2,

NOTE_GS2, NOTE_G2,
NOTE_GS2, NOTE_G2,
NOTE_GS2, NOTE_G2,
NOTE_GS2, NOTE_G2, NOTE_G2, NOTE_F2,

NOTE_GS2, NOTE_G2,
NOTE_GS2, NOTE_G2,
NOTE_GS2, NOTE_G2,
NOTE_GS3, NOTE_GS3, NOTE_G3, NOTE_F3, BREAK,

NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_GS3, BREAK,
NOTE_CS3, NOTE_CS3, NOTE_CS3, NOTE_C3, BREAK,
NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_GS3, BREAK,
NOTE_GS3, NOTE_G3, NOTE_G3, NOTE_F3, BREAK,
NOTE_GS3, NOTE_G3, NOTE_G3, NOTE_F3, BREAK,
NOTE_GS3, NOTE_G3, NOTE_G3, NOTE_F3, BREAK,
NOTE_GS3, NOTE_G3, NOTE_G3, NOTE_F3, BREAK,

END
};

// note durations: 8 = quarter note, 4 = 8th note, etc.
int noteDurations[] = {       //duration of the notes
4, 12, 4, 12, 
4, 4, 4, 4, 4, 12, 
4, 12, 4, 12, 
4, 4, 4, 4, 4, 12, 

4, 12, 4, 12, 
4, 4, 4, 4, 4, 12,
4, 12, 4, 12, 
4, 4, 4, 4, 4, 12, 

4, 12,
4, 12,
4, 12, 
4, 4, 4, 8,

4, 12,
4, 12,
4, 12, 
4, 4, 4, 8,

4, 12,
4, 12,
4, 12, 
4, 4, 4, 8,

4, 12,
4, 12,
4, 8, 4, 4, 12, 8, 4,

4, 4, 12, 8, 4,
4, 4, 12, 8, 4,
4, 4, 12, 8, 4,
4, 4, 12, 8, 4,
4, 4, 12, 8, 4,
4, 4, 12, 8, 4,
4, 4, 12, 56

};

int speed=50;  //higher value, slower notes
void setup() {

Serial.begin(9600);
for (int thisNote = 0; melody[thisNote]!=-1; thisNote++) {

int noteDuration = speed*noteDurations[thisNote];
// Function: tone (pin, frequency, duration)
// the frequency of the tone in hertz - unsigned int
// the duration of the tone in milliseconds (optional) - unsigned long
tone(3, melody[thisNote],noteDuration*.95);
Serial.println(melody[thisNote]);

delay(noteDuration);

noTone(3);
}
}

void loop() {
  // put your main code here, to run repeatedly:

}
