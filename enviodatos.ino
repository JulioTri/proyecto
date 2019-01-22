#include <ESP8266WiFi.h>

const char* ssid    ="CANO 2";
const char* password="170360HERMANCANO";

const char* host="192.168.0.104";

void setup(){
    Serial.begin(115200);
    delay(10);
    Serial.println();
    Serial.println();
    Serial.print("Connecting to...");
    Serial.println(ssid);
    
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address");
    Serial.println(WiFi.localIP());
}

int value=0;

void loop(){
    delay(200);
    ++value;
    Serial.print("Connecting to");
    Serial.println(host);

    WiFiClient client;
    const int httport=80;
    
    if (!client.connect(host,httport)) {
        Serial.println("Connection failde");
        return;
    }

    String url="http://192.168.1.104/Basedatos.php";
    String data="Serie=777&temp=33";

    Serial.println("Requesting url:");
    Serial.println(url);

    client.print(String("POST ")+url+"HTTP/1.0\r\n"+
    "Host: " +host+"\r\n"+
    "Acept: *"+"/"+"*\r\n"+
    "Content-Length: "+data.length()+"\r\n"+
    "content-Type: application/x-www-form-urlencoded\r\n"+
    "\r\n"+data);
    delay(10);

    Serial.println("Respond: ");
    
    while(client.available()){
        String line=client.readStringUntil('\r');
        Serial.print(line);
    }

    Serial.println();
    Serial.println("Closing connection");
}