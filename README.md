# robot_wifi
**rc_controller.ino** is identical to the Arduino sketch from the Bluetooth control repository.  

**rc_controller_esp.ino** controls the ESP8266 Wi-fi module. This project uses an Adafruit Huzzah module which does not require any additional circuitry to accommodate the 3.3v / high current requirements of the ESP8266 module. Add your own Wi-fi network name and password as well as the URL for your direction.php file.  

**index.php** is a simple left, right, forward, backward, and stop controller file. When the user presses one of the directional buttons, the corresponding directional letter is copied to a MySQL database.  

**direction.php** reads and displays the directional letter from the MySQL database.
