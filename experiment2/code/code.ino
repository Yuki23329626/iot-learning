
#include <string.h>
#include <stdio.h>
static char retmcu[256] = {'\0'};

void setup() {
    Serial.begin(9600);                  
    Serial.println("Starting ...... ");
    Serial.println("Waitiing for ue attach ...... ");
    delay(12000);
    serial_read();
    delay(1000);

    // UDP socket
    Serial.println("AT+NSOCR=DGRAM,17,0,1");
    serial_read();
    delay(1000);

    // Error message in detail
    Serial.println("AT+CMEE=1");
    serial_read();
    delay(1000);
}

void loop() {
    // 測試連線是否正常
    Serial.println("AT+NPING=8.8.8.8");
    serial_read();
    delay(1000);

    // Send data by UDP socket
    snprintf(retmcu, sizeof(retmcu), "AT+NSOST=1,140.123.230.10,6000,9,363038343130313137,1");
    Serial.println(retmcu);
    serial_read();
    delay(1000);

    // Receive data from UDP server
    Serial.println("AT+NSORF=1,16");
    serial_read();
    delay(1000);

    // 字串分割，把收到的 response 裡面的 payload 取出來
    char* response[6] ;
    char* s = strtok(retmcu, ",");
    int i=0;
    while(s)
    {
      response[i] = s;
      s = strtok(NULL, ",");
      i++;
    }

    // 接收 UDP server 的 response，並且將 hex string 轉換成 ascii string
    Serial.println("===== Response: =====");
    char *data = response[4];
    for(i = 0; i < strlen(data); i+=2){
       char str[] = "00";
       str[0] = data[i];
       str[1] = data[i+1];
       char text = strtol(str, 0, 16);
       Serial.print(text);
    }
    Serial.println("\n===== End of Response =====");
      
}

void serial_read(){
    int i = 0;
    memset(retmcu, 0, sizeof(retmcu));
    //Waits for the transmission of outgoing serial data to complete.
    Serial.flush();
    //Waits for respones
    delay(2000);
    while(Serial.available() && i < sizeof(retmcu) - 1) {
        retmcu[i] = Serial.read();//read return's value and strage in this array
        i++;
    }

    // for debug
    Serial.println("retmcu: ");
    Serial.println(retmcu);
}
