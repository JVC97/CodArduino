
//si usas esp32
#include <HTTPClient.h>
#include <WiFi.h>

//si usas esp8266
//#include <ESP8266WiFiMulti.h>
//#include <ESP8266HTTPClient.h>

const char* ssid = "Embebidos";
const char* password =  "embebidos123";

String Cadena;
String CuadranteS;
int Cuadrante;
String NumeroS;
int Numero;
String OcupadoS;
bool Ocupado;
String CadenaRespuesta;
int Cantidad1;
int Cantidad2;
String CantidadS1;
String CantidadS2;

void setup() {
  delay(10);
  Serial.begin(9600);


  WiFi.begin(ssid, password);

  Serial.print("Conectando...");
  while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    delay(500);
    //Serial.print(".");
  }

  //Serial.print("Conectado con éxito, mi IP es: ");
  //Serial.println(WiFi.localIP());

}

void loop() {

  if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status

    HTTPClient http;
    String datos_a_enviar = "user=" + user + "&pass=" + pass;

    http.begin("http://ioticos.org/esp-post.php");        //Indicamos el destino
    http.addHeader("Content-Type", "application/x-www-form-urlencoded"); //Preparamos el header text/plain si solo vamos a enviar texto plano sin un paradigma llave:valor.

    int codigo_respuesta = http.POST(cadena);   //Enviamos el post pasándole, los datos que queremos enviar. (esta función nos devuelve un código que guardamos en un int)

    if(codigo_respuesta>0){
      Serial.println("Código HTTP ► " + String(cadena));   //Print return code

      if(codigo_respuesta == 200){
        String cuerpo_respuesta = http.getString();
        //Serial.println("El servidor respondió ▼ ");
        //Serial.println(cuerpo_respuesta);

      }

    }else{

     //Serial.print("Error enviando POST, código: ");
     //Serial.println(codigo_respuesta);

    }

    http.end();  //libero recursos

  }else{

     //Serial.println("Error en la conexión WIFI");

  }

   delay(2000);
}
