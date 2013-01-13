 /*************************************************** 
  This is Docracy's sketch to use with the Adafruit Thermal Printer
  
  See this tutorial as reference --> http://www.adafruit.com/products/597
  These printers use TTL serial to communicate, 2 pins are required

  (Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!)

  Original sketch written by Limor Fried/Ladyada for Adafruit Industries.
  Edits by Veronica Picciafuoco for Docracy Inc. http:www//docracy.com
 
  MIT license
 ****************************************************/


// this sketch works with Arduino 1.0 only
#include "SoftwareSerial.h"
#include "Adafruit_Thermal.h"
#include "adalogo.cpp"
#include "adaqrcode.cpp"

int printer_RX_Pin = 2;  // this is the green wire
int printer_TX_Pin = 3;  // this is the yellow wire

Adafruit_Thermal printer(printer_RX_Pin, printer_TX_Pin);


void setup(){
  Serial.begin(9600);
  printer.begin();
  
  ////////////////////////////////////////////////////////////////////
  //Following are in setup, but do not need to be. Use them anywhere. 
  //Just here so they do not just keep printing over and over
  //Printer will ignore commands during printing, so use delay(3000)
  //after prints to ensure it see everything you want to print.
  //SOME FUNCTIONS WILL FEED A LINE WHEN CALLED TO SOLIDIFY SETTING
  ////////////////////////////////////////////////////////////////////
 


  // test character double height on & off AND CENTERED
  printer.doubleHeightOn();
  printer.justify('C');
  printer.println("Contract for hackers \nwho hate contracts");
  printer.doubleHeightOff();
 
  //sets text justification (right, left, center) accepts 'L', 'C', 'R'
  printer.justify('L');
  printer.println("This agreement is between Hacker01 and Hacker02. We agree as follows:\n1) Each of us, individually, is free to use any programming concept shared, discovered, or created during the TC Disrupt Hackathon 2012.\n2) Each of us hereby grants a full, non-exclusive, free license to the other to use any code or binaries from the above project. This means that each of us, individually, is free to use anything we create for the project above as part of a separate larger project with a significant amount of additional functionality.\n3) In the event that the project above is successful, we'll take reasonable efforts to come to a new agreement with the goal of creating a separate entity to manage and develop the project further");
 
 
  //printer.justify('C'); 
  //printer.println("Center justified");
  
  printer.justify('L');  
  printer.println("Signatures:\n_______________\n_____________");
  
  printer.inverseOn();
  printer.println("This minicontract is legally binding, don't lose it! Execute it online for free by scanning the QR code below");
  printer.inverseOff();
  
  ///printer.boldOn();
  //printer.println("Bold text");
  //printer.boldOff();
  
  //printer.underlineOn(); 
  //printer.println("Underlined text ");
  //printer.underlineOff();

  //printer.setSize('L');      // set type size, accepts 'S', 'M', 'L'
  //printer.print("Large");    // print line
  //printer.setSize('M');      // setting the size adds a linefeed   
  //printer.print("Medium");    // print line
  //printer.setSize('S');      // setting the size adds a linefeed
  //printer.println("Small");    // print line
  
  //printer.justify('C'); 
  //printer.println("normal\nline\nspacing");
  //printer.setLineHeight(50);
  //printer.println("Taller\nline\nspacing");
  //printer.setLineHeight();    // reset to default
  //printer.justify('L');  



  // print the 57x57 pixel logo included in adalogo.cpp
  //printer.printBitmap(57, 57, adalogo);
  
  //print the 135 x 135 pixel QR code in adaqrcode.cpp
  printer.printBitmap(135, 135, adaqr);
  printer.println("Docracy.com");
  printer.feed(1);

  printer.sleep(); //Tell printer to sleep. MUST call wake before printing again, even if reset
  printer.wake(); //Wake printer.
  printer.setDefault(); //restore printer to defaults
}

void loop(){
}
