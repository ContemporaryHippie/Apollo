#include <uspeech.h> //speech recognition. will be used to close curtains

#include <EthernetServer.h>
#include <util.h>
#include <Dhcp.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <Dns.h>
#include <EthernetUdp.h>

#include <TimeLib.h>
#include <Time.h>

#include <TimeAlarms.h>

time_t getNtpTime();
void digitalClockDisplay();
void printDigits(int digits);
void sendNTPpacket(IPAddress &address);



int motor = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Ethernet.begin(mac,192.168.1.5); //mac is to be the mac address of the shield
  
  setSyncProvider(getNtpTime);
  setSyncInterval(3600);
  
  pinMode(motor, OUTPUT); //motor directional component will go in this block
  
  Alarm.alarmRepeat(dowMonday,8,30,00,MoCurt); //curtains at 8:30 Monday
  Alarm.alarmRepeat(dowTuesday,8,30,00,TuCurt); //curtains at 8:30 Tuesday
  Alarm.alarmRepeat(dowWednesday,10,00,00,WeCurt); //curtains at 10:00 Wednesday
  Alarm.alarmRepeat(dowThursday,8,30,00,ThCurt); //curtains at 8:30 Thursday
  Alarm.alarmRepeat(dowThursday,9,30,00,Test); //test case

}

void loop() {
  // put your main code here, to run repeatedly: 
  

  
}

void MoCurt(){
  digitalWrite(motor, HIGH); //rudimentary motor activation. will improve with h circuit and appropriate pin activation
  delay(5000);
  digitalWrite(motor, LOW);  
}

void TuCurt(){
  digitalWrite(motor, HIGH); //rudimentary motor activation. will improve with h circuit and appropriate pin activation
  delay(5000);
  digitalWrite(motor, LOW);   
}

void WeCurt(){
  digitalWrite(motor, HIGH); //rudimentary motor activation. will improve with h circuit and appropriate pin activation
  delay(5000);
  digitalWrite(motor, LOW);   
}

void ThCurt(){
  digitalWrite(motor, HIGH); //rudimentary motor activation. will improve with h circuit and appropriate pin activation
  delay(5000);
  digitalWrite(motor, LOW);   
}

void Test(){
  digitalWrite(motor, HIGH); //rudimentary motor activation. will improve with h circuit and appropriate pin activation
  delay(5000);
  digitalWrite(motor, LOW);   
}

