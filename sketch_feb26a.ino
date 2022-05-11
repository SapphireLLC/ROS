#include <TVout.h>
#include <fontALL.h>
#include <font4x6.h>

TVout TV;

boolean introDone = false;
boolean isStarted = false;
void setup() {
  Serial.begin(9600);
  TV.begin(NTSC,120,96);
  //White scrren pin, digitalWrite(2,HIGH) will make the screen white
  
  pinMode(12,OUTPUT);
  pinMode(6,OUTPUT);

 TV.clear_screen();
 TV.select_font(font4x6);
 TV.print(0,0,"Ruby8 AGS Boot util 1.01");

 delay(40000);

 TV.print(0,7,"Booting location:");
 TV.print(0,14,"Internal flash memory");
 TV.print(0,21,"Booting...");

 delay(20000);

 TV.print(0,28,"128K flash");
 TV.print(0,35,"10MB temp storage");
 TV.print(0,42,"ATmel ATmega 2560");
 delay(200000);

 
}

void loop() {
  Serial.println(digitalRead(2));

 if(introDone == false){
    intro();
    introDone == true;
  }else{
    if(digitalRead(5) == 1 && isStarted == false){
          programMenu();  
      isStarted = true;  
     }else{
        Serial.println("Done");
      }
   }
}
void terminal(){
 TV.clear_screen();
 TV.println(0,0,"-*Ruby Development Terminal*-");
 TV.print(0,2,"\n\nRuby8:");
 TV.print("_");
 delay(1000);
 TV.print(" ");
 delay(1000);
 }

void intro(){

 TV.clear_screen();
 TV.draw_line(35,35,55,70,WHITE);
 TV.draw_line(75,35,55,70,WHITE);
 TV.draw_line(35,35,75,35,WHITE);
 TV.draw_line(35,35,45,20,WHITE);
 TV.draw_line(75,35,65,20,WHITE);
 TV.draw_line(55,20,55,70,WHITE);
 TV.draw_line(45,20,65,20,WHITE);

 //delay(2000);
 TV.select_font(font4x6);
 TV.print(24,10,"Ruby Development");
 TV.print(49,80,"Ruby 8");
 TV.print(12,90,"Advanced gaming system");
 TV.print(16,95,"Now loading");
 
for(int i=0;i<=20; i++){
    writeOne(i / 4);
    delay(500);
  }
  for(int i=0;i<=20; i++){
    writeTwo(i / 4);
    delay(500);
  }
  for(int i=20;i<=0; i--){
    writeThree(i / 4);
    delay(500);
  }
  for(int i=20;i<=0; i--){
    writeFour(i / 4);
    delay(500);
  }

  delay(600000);

  introDone = true;

  Serial.println(introDone);

  terminal();
  
}

void enableAudio(){
  analogWrite(3,0.00);  
  analogWrite(4,0.00);  
  analogWrite(5,0.00);  
  analogWrite(6,0.00);  
  digitalWrite(12,HIGH);
}

void disableAudio(){
  analogWrite(3,0.00);  
  analogWrite(4,0.00);  
  analogWrite(5,0.00);  
  analogWrite(6,0.00);  
  digitalWrite(12,LOW);
}
void writeOne(double a){
   analogWrite(3,a);  
}
void writeTwo(double a){
   analogWrite(4,a);  
}
void writeThree(double a){
   analogWrite(5,a);  
}
void writeFour(double a){
   analogWrite(6,a);  
}
void clearSound(){
  analogWrite(3,0.00);  
  analogWrite(4,0.00);  
  analogWrite(5,0.00);  
  analogWrite(6,0.00);  
}

void ros(){
    TV.clear_screen();
    //TV.fill(WHITE);
    //TV.delay(500);
    TV.select_font(font4x6);
    TV.print(62,20,"Ruby 8");
    //TV.print(62,32,"v1.00");
    delay(200);
    TV.select_font(font8x8);
    TV.print(62,26,"ROS");
    TV.select_font(font4x6);
    TV.print(49,76,"Ruby 8");
    TV.print(12,86,"Program Menu");
    delay(10000);

  TV.draw_line(15,35,35,70,WHITE);
  TV.draw_line(55,35,35,70,WHITE);
  TV.draw_line(15,35,55,35,WHITE);
  TV.draw_line(15,35,25,20,WHITE);
  TV.draw_line(55,35,45,20,WHITE);
  //TV.draw_line(35,20,25,70,WHITE);
  TV.draw_line(25,20,45,20,WHITE);
  
  delay(30000);
  TV.draw_rect(4,4,114,91,WHITE);
    
}
void programMenu(){
  TV.clear_screen();  
  TV.select_font(font6x8);
  TV.print(0,0,"Program Menu");
}
