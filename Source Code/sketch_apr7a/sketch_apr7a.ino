#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "WebSV.h"
#include <DHT.h>
#include <BH1750.h>
#include <Wire.h>
#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#define led1 D6
#define led2 D3
#define ledlux D7
#define cb A0
BH1750 lightMeter;

const String wifi = "UiTiOt-Staff";
const String pass = "UiTiOtAP";

ESP8266WebServer server(80);



void ketnoi()
{
  String s = MAIN_page;
  server.send(200,"text/html",s);
}


void led_1off()
{
  digitalWrite(led1,LOW);
  server.send(200,"text/plane","OFF");
}


void led_1on()
{
  digitalWrite(led1,HIGH);
  server.send(200,"text/plane","ON");
}


void docnhietdo()
{
  float nhietdo = dht.readTemperature();
  String snhietdo = String(nhietdo);
  if(isnan(nhietdo))
  {
    server.send(200,"text/plain","Cam bien khong hoat dong");
  }
  else {
    server.send(200,"text/plain",snhietdo);
  }
}

void docdoam()
{
  float doam = dht.readHumidity();
  String sdoam = String(doam);
  if(isnan(doam))
  {server.send(200,"text/plain","Cam bien khong hoat dong");
  }
  else {
    server.send(200,"text/plain",sdoam);
  }
}

void docanhsang()
{
  float anhsang = lightMeter.readLightLevel();
  String sanhsang = String(anhsang);
  if(isnan(anhsang))
  {
    server.send(200,"text/plain","Cam bien khong hoat dong");
  }
  else {
    server.send(200,"text/plain",sanhsang);
  }
  if(anhsang<=40)
    {
      digitalWrite(ledlux, HIGH);
    }
    else
    {
      digitalWrite(ledlux, LOW);
    }
}

void docdoamdat()
{
  float doam = analogRead(cb);
  int doamao = map(doam, 0, 1023, 0, 100);
  int doamdat = 100-doamao;
  String sdoamdat = String(doamdat);
  if(isnan(doamdat))
  {
    server.send(200,"text/plain","Cam bien khong hoat dong");
  }
  else {
    server.send(200,"text/plain",sdoamdat);
  }
  if(doamdat<=40)
    {
      digitalWrite(led2, HIGH);
    }
    else
    {
      digitalWrite(led2, LOW);
    }
}


void setup()
{
  Serial.begin(9600);
  pinMode(D4,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(ledlux,OUTPUT);
  pinMode(cb, INPUT);
  pinMode(led2,OUTPUT);
  digitalWrite(led1,LOW);
  dht.begin();
  Wire.begin();
  lightMeter.begin();
  Serial.println(" ");
  Serial.print("ket noi den wifi: ");
  Serial.println(wifi);
  WiFi.begin(wifi, pass);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(200);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Wf da ket noi");
  Serial.println("Dia chi IP: ");
  Serial.println(WiFi.localIP());
  
  server.on("/",ketnoi );
  server.on("/led1off",led_1off);
  server.on("/led1on",led_1on);
  server.on("/docnhietdo",docnhietdo);
  server.on("/docdoam",docdoam);
  server.on("/docanhsang",docanhsang);
  server.on("/docdoamdat",docdoamdat);
  server.begin();
}
void loop()
{
  server.handleClient();
}




