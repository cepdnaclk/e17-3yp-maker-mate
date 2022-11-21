// Code for Locker 1(index used 0) ESP01 s 
// E/17/201 Madushani W.T

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <time.h>
#include <TZ.h>
#include <FS.h>
#include <LittleFS.h>
#include <CertStoreBearSSL.h>

// -D3 in Node mcu- GPIO0 pin is used, as it is the one connected to relay
#define LED  D3

// Credentials to connect to Wifi 
const char* ssid = "Eng-Student";
const char* password = "3nG5tuDt";

// MQTT server address
const char* mqtt_server = "ff907ed6936f429bb7cceacada6c31ba.s2.eu.hivemq.cloud";
const int mqtt_port = 8883;
const char* mqttUser = "makermate";
const char* mqttPassword = "makermate";

// A single, global CertStore which can be used by all connections.
// Needs to stay live the entire time any of the WiFiClientBearSSLs
// are present.
BearSSL::CertStore certStore;

PubSubClient * client;

WiFiClient espClient;
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (500)
char msg[MSG_BUFFER_SIZE];
int value = 0;

void setDateTime() {
  // You can use your own timezone, but the exact time is not used at all.
  // Only the date is needed for validating the certificates.
  configTime(TZ_Europe_Berlin, "pool.ntp.org", "time.nist.gov");

  Serial.print("Waiting for NTP time sync: ");
  time_t now = time(nullptr);
  while (now < 8 * 3600 * 2) {
    delay(100);
    Serial.print(".");
    now = time(nullptr);
  }
  Serial.println();

  struct tm timeinfo;
  gmtime_r(&now, &timeinfo);
  Serial.printf("%s %s", tzname[0], asctime(&timeinfo));
}

void setup() 
{
  pinMode(LED, OUTPUT);
  delay(1000);
  LittleFS.begin();
  pinMode(D4,INPUT_PULLUP);                             //GPIO2 pin used - Node mcu D4-
  Serial.begin(115200);
  Serial.println("Start");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.print("Connected to WiFi :");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.SSID());
  setDateTime();
  int numCerts = certStore.initCertStore(LittleFS, PSTR("/certs.idx"), PSTR("/certs.ar"));
  Serial.printf("Number of CA certs read: %d\n", numCerts);
  if (numCerts == 0) {
    Serial.printf("No certs found. Did you run certs-from-mozilla.py and upload the LittleFS directory before running?\n");
    return; // Can't connect to anything w/o certs!
  }

  BearSSL::WiFiClientSecure *bear = new BearSSL::WiFiClientSecure();
  // Integrate the cert store with this connection
  bear->setCertStore(&certStore);

  client = new PubSubClient(*bear);
  
  client->setServer(mqtt_server, mqtt_port);
  client->setCallback(MQTTcallback);
  
  while (!client->connected()) 
  {
    Serial.println("Connecting to MQTT...");
    if (client->connect("ESP8266", mqttUser, mqttPassword ))
    {
      Serial.println("connected");
    }
    else
    {
      Serial.print("failed with state ");
      Serial.println(client->state());
      delay(2000);
    }
  }
  // Subscribed to topic
  client->subscribe("makermate/locker/0"); 
}

void MQTTcallback(char* topic, byte* payload, unsigned int length) 
{
  Serial.print("Message received in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  String message;
  for (int i = 0; i < length; i++) 
  {
    message = message + (char)payload[i];
  }
  Serial.println(message);
  if (message == "unlock") 
  {
    digitalWrite(LED, HIGH);
    delay(800);
    digitalWrite(LED, LOW);    
    Serial.println("Received ON");
  }
  else if (message == "lock") 
  {
    digitalWrite(LED, LOW);
    Serial.println("Received OFF");
  }
  Serial.println();
  Serial.println("-----------------------");
}

void loop() 
{
  
  if(digitalRead(D4)==0)
  {
    // Published to topic
    client->publish("makermate/locker_out/0", "Msg from ESP01 module from locker 1.");
    delay(1000);
  }
  else;
  client->loop();
}
