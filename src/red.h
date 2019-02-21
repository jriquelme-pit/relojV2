#include "ESP8266WiFi.h"
#include "WiFiClientSecure.h"
#include "arduino_secrets.h"

char ssid[] = SECRET_SSID;     // your network SSID (name)
char password[] = SECRET_PASS;  // your network key

//Add a SSL client
WiFiClientSecure client;


class Red{
public:
    String connect(){
        WiFi.mode(WIFI_STA);
        WiFi.disconnect();
        delay(100);

        WiFi.begin(ssid, password);
        while (WiFi.status() != WL_CONNECTED) {
            Serial.print(".");
            delay(500);
        }
        IPAddress ip = WiFi.localIP();
        return ip.toString();
    }


    String getWeather() {

        //Serial.print("init obteniendo datos");
        String title = "";
        String headers = "";
        String body = "";
        bool finishedHeaders = false;
        bool currentLineIsBlank = true;
        bool gotResponse = false;
        long now;

        char host[] = HOST;

        if (client.connect(host, 443)) {
            //Serial.println("connected");
            String URL = URI;

            client.println("GET " + URL + " HTTP/1.1");
            client.print("Host: ");
            client.println(host);
            client.println("User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36");
            client.println("cache-control: max-age=0");
            client.println("");


            now = millis();
            // checking the timeout
            while (millis() - now < 1500) {
                while (client.available()) {
                    char c = client.read();
                    if (finishedHeaders) {
                        body=body+c;
                    } else {
                        if (currentLineIsBlank && c == '\n') {
                            finishedHeaders = true;
                        }
                        else {
                            headers = headers + c;
                        }
                    }

                    if (c == '\n') {
                        currentLineIsBlank = true;
                    }else if (c != '\r') {
                        currentLineIsBlank = false;
                    }
                    gotResponse = true;
                }
                if (gotResponse) {


                    title = body;
                    break;
                }
            }
        }
        //Serial.println(body);
        return title;
    }

};