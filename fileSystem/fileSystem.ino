#include "FS.h"

File f;


void setup() {
  Serial.begin(250000);
  SPIFFS.begin();
}
void readFile(String donde){
  SPIFFS.begin();
  String fi = "/" + donde;
  // always use this to "mount" the filesystem
  bool result = SPIFFS.begin();
  
  Serial.println("SPIFFS opened: " + result);
  // this opens the file "f.txt" in read-mode
  f = SPIFFS.open(fi, "r");

  if(f){
    Serial.println("File already exists");
      // we could open the file
      while(f.available()) {
        //Lets read line by line from the file
        String line = f.readStringUntil('\n');
        Serial.println(line);
    }
  }
  f.close();
  }
  
  void writeFile(String donde, String text){
    SPIFFS.begin();
    // open the file in write mode
    String fi = "/" + donde;
    // open the file in write mode
    f = SPIFFS.open(fi, "w");
    if (!f) {
      Serial.println("file creation failed");
    }else{
      Serial.println("writing file");
      f.println(text);  
    }
    f.close();
  }
  void writeFileA(String donde, String text){
    SPIFFS.begin();
    // open the file in write mode
    String fi = "/" + donde;
    f = SPIFFS.open(fi, "a");
    if (!f) {
      Serial.println("file creation failed");
    }else{
      Serial.println("writing file");
      f.println(text);  
    }
    f.close();
  }
  void delFile(String donde){
    SPIFFS.begin();
    String fi = "/" + donde;
    SPIFFS.remove(fi);
    Serial.print("eliminado : ");
    Serial.println(SPIFFS.exists(fi));
    }
  void formatSys(){
    SPIFFS.begin();
    SPIFFS.format();
    
  }
  void listFiles(){
    SPIFFS.begin();
    String str = "";
    Dir dir = SPIFFS.openDir("/");
    while (dir.next()) {
      str += dir.fileName();
      str += " / ";
      str += dir.fileSize();
      str += "\r\n";
    }
    Serial.println(str); 
  }
  char hacer ;
  String texto;
void loop() {

  
  String content = "";
  String where = "";
  char character;
  char x;
  
  Serial.println("Dame una orden : r read, w write, a writeAppend, d delete, f format, l list dirs");

  while(Serial.available() == 0) { }  // There really is nothing between the {} braces
  x = Serial.read(); 

  if(x == 'r'){
    Serial.println("Se procede a leer");

    Serial.println("nombre archivo");
    while(Serial.available() == 0) {}
    where = Serial.readString();
    readFile(where);
  }
  else if(x == 'w'){
    Serial.println("nombre archivo");
    while(Serial.available() == 0) {}
    where = Serial.readString();

    Serial.println("Texto");
    while(Serial.available() == 0) {}  // There really is nothing between the {} braces  
    content = Serial.readString();
    
    Serial.println("after, waiting");
    if (content != "") {    
      Serial.println("Se va a escribir:");
      Serial.println(content);
      writeFile(where, content);
    }else{
      Serial.println(">>> NO HAY CONTENIDO <<<");
    }
  }
    else if(x == 'a'){
    Serial.println("nombre archivo");
    while(Serial.available() == 0) {}
    where = Serial.readString();

    Serial.println("Texto");
    while(Serial.available() == 0) {}  // There really is nothing between the {} braces  
    content = Serial.readString();
    
    Serial.println("after, waiting");
    if (content != "") {    
      Serial.println("Se va a escribir:");
      Serial.println(content);
      writeFileA(where, content);
    }else{
      Serial.println(">>> NO HAY CONTENIDO <<<");
    }
  }
  else if(x == 'd'){
    Serial.println("nombre archivo");
    while(Serial.available() == 0) {}
    where = Serial.readString();
    delFile(where);  
  }
  else if(x == 'f'){
    formatSys();  
  }
  else if(x == 'l'){
    listFiles();  
  }
}
