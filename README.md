  <h2>
  Let your Arduino play music
  </h2>
 <h4>Steps:</h4> 
  <ol>
    <li> Installation of the Arduino IDE</li>
    <li> Connect a speaker to the Arduino</li>
    <li> Telling the Arduino IDE to speak with the Arduino </li>
    <li>Uploading code to the Arduino</li>
    <li>Changing the music</li>
  </ol>
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
      <br><code>./APPIMAGE</code><br>
      Again, you need to exchange APPIMAGE for the name of your file, for example "arduino-ide_2.1.1_Linux_64bit.AppImage".
      The program will now open in another window. You need to leave the Terminal open as long as you want to use the program
    </li>
    <li>
      For other Operating Systems, follow the installation instructions on the Website https://www.arduino.cc/en/software
    </li>
    <li> Once you installed and opened the Arduino IDE, it will automatically create a new file for you. This file has a name ending with .ino and will contain the instructions for the Arduino. For now, it only contains these lines:<br> 
      
      void setup() {
      // put your setup code here, to run once:
      }
      
      void loop() {
        // put your main code here, to run repeatedly: 
      }
<br>
<li> Click on "save". It will ask you for a name of this project, you can call it something like "arduino-speaker.ino" or just leave the default name, which is "sketch_" followed by the date of today and the .ino ending.</li>
</ol>

  <h4>Connect a speaker to the Arduino</h4>
 <ol>
   <li>I roughly followed this tutorial: https://maker.pro/arduino/projects/arduino-speaker<br>
   About connecting the speaker, this tutorial says: "Connect a speaker or a piezo buzzer to the Arduino with one wire to the Digital pin 3 and the other one to the ground of the Arduino"</li>
   <li>I am using an old little speaker that was inside a grandma phone. It has one white cable and one green cable coming out of it. So I researched "speaker green and white cable" to find out which of those two cables is usually the power cable and which one is the ground cable. This website (https://www.systoncable.com/speaker-wire-color-codes/) suggested that White is for positive and Green is for ground. </li>
   <li>So I want to connect the white cable to Digital Pin 3 and the green cable to ground. For that, I first have to remove a little bit of the green/white plastic at the end of the cables, so some copper from the inside can stick out and successfully connect to the pins of the Arduino. I removed approx. 5mm of plastic.</li>
   <li> Then, I drill the copper wires that are inside the green/white cable a bit around each other, so they become one thingy. After that, I stick them into the holes Digital Pin 3 and Ground. How to find them? The Arduino has some parts on it that look like walls with holes in them from above. On the walls, there are white stripes with descriptions of what the holes (pins) in this part of the wall are for. You will find descriptions like "POWER", "ANALOG IN" and "DIGITAL". So Digital Pin 3 is the hole number 3 in the "DIGITAL" section. To find Ground, search for any hole named "GND".</li>
   <li> Connect the Arduino to your computer with the USB cable. </li>
 </ol>
  <h4> Telling the Arduino IDE to speak with the Arduino</h4>
  <ol>
    <li>Now we need to connect the Arduino IDE with the Arduino we just plugged in. First, we need to tell Arduino IDE which model we are using. Go to the menu "Tools" > "Board" > "Arduino AVR board" and select the name of your Arduino model. In my case, I have an "Arduino Uno" (actually, a cheaper version by another company, but it behaves just like an Arduino Uno).</li>
    <li>Then, we need to tell Arduino IDE where to find the Arduino (because you could have multiple similar devices plugged into your computer at the same time). Go to the menu "Tools" > "Port" and choose a port on which your Arduino is connected to your computer. On my computer, I can choose between the options "/dev/ttyS4", "/dev/ttyACM0", "/dev/ttyACM1", "/dev/ttyACM2" and "/dev/ttyACM3 (Arduino Uno)". So it automatically tells me which port the Arduino Uno is connected to, and I just choose this one (/dev/ttyACM3).</li>
    <li> Now your Arduino IDE can talk to your Arduino and write code on it!</li>
  </ol>
  <h4>Uploading code to the Arduino</h4>
  <ol>
    <li>Now, we need code that we can put on the Arduino. You could write that yourself, but for the start we'll just copy code from an existing project, for example the tutorial I mentioned above: https://maker.pro/arduino/projects/arduino-speaker <br>
    So we copy this code into our .ino file in the Arduino IDE:
    <br>
      
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
      
<br>
</li>
<li> Now, this looks quite complex. I will not explain all the code, and I don't understand everything that's written in it anyway :) But some basic things if you want to understand what it does: Every line starting with <code> // </code> is a comment, that means, just there to explain humans what's going on, but ignored by the computer. The same is true for blocks of lines starting with <code> /* </code> and ending with <code> */ </code> </li>. Then, quite at the beginning, we have a long list called <code> melody[]</code> that contains all the music notes. For example, <code> NOTE_D4 </code> means the Arduino will play a D note. The number 4 indicates which D note is played (a low one, middle one, high one etc.). The Arduino will look up what <code>NOTE_D4</code> in a second file called "pitches.h". We can see how in line 9 of the code (<code>#include"pitches.h"</code>), the .ino file is connected to the pitches.h file. As we will see later, the pitches.h file will make the connection between the name <code>NOTE_D4</code> and the corresponding frequency, that is 262 (Hertz).
<li> Now, we have a first file (the .ino file) with code for the Arduino in it. As the tutorial mentions, we need a second file too, the "pitches.h" file. To create it, we move to the three little dots in the right corner of our Arduino IDE window. We click on them, and choose "New Tab". We are asked for a name and enter "pitches.h". </li>
    <li>The tutorial tells us what needs to be in this file: <br>
      
    #define NOTE_B0  31
    #define NOTE_C1  33
    #define NOTE_CS1 35
    #define NOTE_D1  37
    #define NOTE_DS1 39
    #define NOTE_E1  41
    #define NOTE_F1  44
    #define NOTE_FS1 46
    #define NOTE_G1  49
    #define NOTE_GS1 52
    #define NOTE_A1  55
    #define NOTE_AS1 58
    #define NOTE_B1  62
    #define NOTE_C2  65
    #define NOTE_CS2 69
    #define NOTE_D2  73
    #define NOTE_DS2 78
    #define NOTE_E2  82
    #define NOTE_F2  87
    #define NOTE_FS2 93
    #define NOTE_G2  98
    #define NOTE_GS2 104
    #define NOTE_A2  110
    #define NOTE_AS2 117
    #define NOTE_B2  123
    #define NOTE_C3  131
    #define NOTE_CS3 139
    #define NOTE_D3  147
    #define NOTE_DS3 156
    #define NOTE_E3  165
    #define NOTE_F3  175
    #define NOTE_FS3 185
    #define NOTE_G3  196
    #define NOTE_GS3 208
    #define NOTE_A3  220
    #define NOTE_AS3 233
    #define NOTE_B3  247
    #define NOTE_C4  262
    #define NOTE_CS4 277
    #define NOTE_D4  294
    #define NOTE_DS4 311
    #define NOTE_E4  330
    #define NOTE_F4  349
    #define NOTE_FS4 370
    #define NOTE_G4  392
    #define NOTE_GS4 415
    #define NOTE_A4  440
    #define NOTE_AS4 466
    #define NOTE_B4  494
    #define NOTE_C5  523
    #define NOTE_CS5 554
    #define NOTE_D5  587
    #define NOTE_DS5 622
    #define NOTE_E5  659
    #define NOTE_F5  698
    #define NOTE_FS5 740
    #define NOTE_G5  784
    #define NOTE_GS5 831
    #define NOTE_A5  880
    #define NOTE_AS5 932
    #define NOTE_B5  988
    #define NOTE_C6  1047
    #define NOTE_CS6 1109
    #define NOTE_D6  1175
    #define NOTE_DS6 1245
    #define NOTE_E6  1319
    #define NOTE_F6  1397
    #define NOTE_FS6 1480
    #define NOTE_G6  1568
    #define NOTE_GS6 1661
    #define NOTE_A6  1760
    #define NOTE_AS6 1865
    #define NOTE_B6  1976
    #define NOTE_C7  2093
    #define NOTE_CS7 2217
    #define NOTE_D7  2349
    #define NOTE_DS7 2489
    #define NOTE_E7  2637
    #define NOTE_F7  2794
    #define NOTE_FS7 2960
    #define NOTE_G7  3136
    #define NOTE_GS7 3322
    #define NOTE_A7  3520
    #define NOTE_AS7 3729
    #define NOTE_B7  3951
    #define NOTE_C8  4186
    #define NOTE_CS8 4435
    #define NOTE_D8  4699
    #define NOTE_DS8 4978
    #define END -1

<br></li>
<li> Now, we have all the frequencies for the music notes, and the Arduino can look them up if needed.
<li> Now, we can upload our code to the Arduino. We click on the Tick symbol in the left corner (Verify). If no errors show up ("Done compiling"), we click on the Arrow symbol next to it (Upload). The Arduino IDE needs a little time to upload and informs you when finished ("Done uploading"). </li>
<li> You should already hear the music! <3 <3 </li>
  </ol>

  <h4> Changing the music</h4>
  <ol> 
    <li>The file "pitches.h" is connecting musical notes to frequencies. So it's always necessary to translate musical notes for the Arduino. What we can play around with now is the first file, the one with the .ino ending. It has a part starting with <code> int melody[] = </code> that describes the actual song (notes) that should be played. It also has a part <code> noteDurations[] </code> that says how long these notes should each be. The Arduino will take the first note from the melody list, and look up its duration (first number in noteDurations list).Then it will do the same with the second note etc.</li>
    <li>I changed the song from the one in the tutorial to "Smells Like Teen Spirit". For that, I looked up the piano notes of "Smells Like Teen Spirit" online. Then, I wrote down the notes in the format like in the pitches.h file, for example <code> NOTE_C3 </code> for a middle C. And additionally, I noted down the durations of these notes, for example quarter note, half note etc. You can find this file here: https://github.com/apfelminze/FTT/blob/main/sketch_aug24b.ino</li>
    <li> If you change your .ino file to my code, and verify and upload again, your Arduino will play Teen Spirit :) </li>
  </ol>














