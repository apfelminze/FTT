<html>
  <h2>
  Let your Arduino play "Smells Like Teen Spirit"
  </h2>
  <h4>Installation of the Arduino IDE:</h4>
  <ol> 
    <li>
    Download the software "Arduino IDE". It is used to write code for the Arduino and upload this code on the Arduino. You can download the program here: https://www.arduino.cc/en/software
  </li>
    <li>
      For Linux: After you downloaded the program as an AppImage (a file that is called something similar to "arduino-ide_2.1.1_Linux_64bit.AppImage"), you need to make it executable. You can do by going to your Download folder (or whereever you saved the AppImage file), right-click, choose "Open a Terminal here" and then enter the following command:
      <br><code>chmod +x APPIMAGE </code><br>
      where instead of APPIMAGE you have to write the name of the file, for example "arduino-ide_2.1.1_Linux_64bit.AppImage". Press Enter to execute this command. When there is no error message, it means this command has worked well.
    </li>
    <li>
      For Linux: Then you can start the program by writing another command to the terminal:
      <br><code>
        ./APPIMAGE
      </code><br>
      Again, you need to exchange APPIMAGE for the name of your file, for example "arduino-ide_2.1.1_Linux_64bit.AppImage".
      The program will now open in another window. You need to leave the Terminal open as long as you want to use the program
    </li>
    <li>
      For other Operating Systems, follow the installation instructions on the Website https://www.arduino.cc/en/software
    </li>
    <li> Once you installed and opened the Arduino IDE, it will automatically create a new file for you. For now, it only contains these lines: 
    <br><code>
      void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

</code><br>
    </li>
      <li> Click on "save". It will ask you for a name of this project, you can call it something like "arduino speaker" or just leave the default name, which is "sketch_" followed by the date of today.</li>
  </ol>
  <h4>Connect a speaker to the Arduino</h4>
 <ol>
   <li>I roughly followed this tutorial: https://maker.pro/arduino/projects/arduino-speaker<br>
   About connecting the speaker, this tutorial says: "Connect a speaker or a piezo buzzer to the Arduino with one wire to the Digital pin 3 and the other one to the ground of the Arduino"</li>
   <li>I am using an old little speaker that was inside a grandma phone. It has one white cable and one green cable coming out of it. So I researched "speaker green and white cable" to find out which of those two cables is usually the power cable and which one is the ground cable. This website (https://www.systoncable.com/speaker-wire-color-codes/) suggested that White is for positive and Green is for ground. </li>
   <li>So I want to connect the white cable to Digital Pin 3 and the green cable to ground. For that, I first have to remove a little bit of the green/white plastic at the end of the cables, so some copper from the inside can stick out and successfully connect to the pins of the Arduino. I removed approx. 5mm of plastic.</li>
   <li> Then, I drill the copper wires that are inside the green/white cable a bit around each other, so they become one thingy. After that, I stick them into the holes Digital Pin 3 and Ground. How to find them? The Arduino has some parts on it that look like walls with holes in them from above. On the walls, there are white stripes with descriptions of what the holes (pins) in this part of the wall are for. You will find descriptions like "POWER", "ANALOG IN" and "DIGITAL". So Digital Pin 3 is the hole number 3 in the "DIGITAL" section. To find Ground, search for any hole named "GND".</li>
   <li> Connect the Arduino to your computer with the correct cable. </li>
 </ol>
  <h4> Telling the Arduino IDE to speak with the Arduino</h4>
  <ol>
    <li>Now we need to connect the Arduino IDE with the Arduino we just plugged in. Go to the menu "Tools" > "Board" > "Arduino AVR board" and select the name of your Arduino model. In my case, I have an "Arduino Uno" (actually, a cheaper version by another company, but it behaves just like an Arduino Uno).</li>
    <li>Then, go to the menu "Tools" > "Port" and choose a port on which your Arduino is connected to your computer. On my computer, I can choose between the options "/dev/ttyS4", "/dev/ttyACM0", "/dev/ttyACM1", "/dev/ttyACM2" and "/dev/ttyACM3 (Arduino Uno)". So it automatically tells me which port the Arduino is connected to, and I just choose this one (/dev/ttyACM3).</li>
    <li> Now your Arduino IDE can talk to your Arduino and write code on it!</li>
  </ol>
  <h4>Uploading code to the Arduino</h4>
  <ol>
    <li>Now, we need code that we can put on the Arduino. You could write that yourself, but for the start we'll just copy code from an existing project, for example the tutorial I mentioned above: https://maker.pro/arduino/projects/arduino-speaker <br>
    So we copy this code into our Arduino IDE:
    <br><code>
/*Arduino speaker song tutorial
* This program will play the theme song of the Malayalam movie
* 'Ennu Ninte Moideen'. The song is 'Mukkathe Penne'.
* The song is played on the speaker connected to pin 3 and GND.
* 
* Created 26 Oct 2015
* by Akshay James
* Video at https://www.youtube.com/watch?v=LgtcUxe8fmA
*/

#include"pitches.h"

// notes in the song 'Mukkathe Penne'
int melody[] = {
NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
NOTE_G4, NOTE_C5, NOTE_AS4, NOTE_A4,                   
NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
NOTE_C4, NOTE_D4,0,                                 

NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
NOTE_G4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4,      //29               //8
NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
NOTE_C4, NOTE_D4,0,                                       

NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5,
NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_FS4, NOTE_D5, NOTE_C5,
NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_AS4,             //58

NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_G4,
NOTE_A4, 0, NOTE_AS4, NOTE_A4, 0, NOTE_G4,
NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, 0,

NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_DS4,
NOTE_C4, NOTE_D4, 0,
NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_DS4,
NOTE_C4, NOTE_D4, END

};

// note durations: 8 = quarter note, 4 = 8th note, etc.
int noteDurations[] = {       //duration of the notes
8,4,8,4,
4,4,4,12,
4,4,4,4,4,4,
4,16,4,

8,4,8,4,
4,2,1,1,2,1,1,12,
4,4,4,4,4,4,
4,16,4,

4,4,4,4,4,4,
4,4,4,12,
4,4,4,4,4,4,
4,4,4,12,

4,4,4,4,4,4,
2,1,1,2,1,1,4,8,4,
2,6,4,2,6,4,
2,1,1,16,4,

4,8,4,4,4,
4,16,4,
4,8,4,4,4,
4,20,
};

int speed=90;  //higher value, slower notes
void setup() {

Serial.begin(9600);
for (int thisNote = 0; melody[thisNote]!=-1; thisNote++) {

int noteDuration = speed*noteDurations[thisNote];
tone(3, melody[thisNote],noteDuration*.95);
Serial.println(melody[thisNote]);

delay(noteDuration);

noTone(3);
}
}

void loop() {
// no need to repeat the melody.
}
      </code><br>
    </li>
    <li> </li>
  </ol>
</html>













