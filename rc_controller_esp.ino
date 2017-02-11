#include <ESP8266WiFi.h>

const char* ssid     = "";
const char* password = "";

const char* host = "ezchx.com";
String inputPuffer;
String url;

const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data
boolean newData = false;

void setup() {
  
  Serial.begin(9600); // was 115200
  delay(100);

  // We start by connecting to a WiFi network
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  delay(5000);

}


void loop() {

  // Read data from Arduino
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;
  while (Serial.available() > 0 && newData == false) {
      rc = Serial.read();

      if (rc != endMarker) {
          receivedChars[ndx] = rc;
          ndx++;
          if (ndx >= numChars) {
              ndx = numChars - 1;
          }
      }
      else {
          receivedChars[ndx] = '\0'; // terminate the string
          ndx = 0;
          newData = true;
      }
  }

  inputPuffer = receivedChars;

  if (inputPuffer != "") {

    // Use WiFiClient class to create TCP connections
    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort)) {
      Serial.println("connection failed");
      return;
    }

    // We now create a URL for the request
    url = "/ai_robotics/index.php?direction=" + inputPuffer;
  
    // This will send the request to the server
    client.print(String("POST ") + url + " HTTP/1.1\r\n" +
             "Host: " + host + "\r\n" + 
             "Connection: close\r\n\r\n");
    delay(5000);
    inputPuffer = "";
    newData = false;
             
  }

}
