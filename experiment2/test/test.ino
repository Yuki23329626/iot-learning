
#include <string.h>
#include <stdio.h>
static char retmcu[256] = {'\0'};

// 只適用於字串為 0-9, A-F
int hex_to_int(char c){
        int first = c / 16 - 3;
        int second = c % 16;
        int result = first*10 + second;
        if(result > 9) result--;
        return result;
}

// printf 的 %c 可以直接吃數字，並印出相對的 ascii 
// 因為 hex string 為兩兩一組且為16進制，所以要算出他在10進制的總和，並回傳
int hex_to_ascii(char c, char d){
        int high = hex_to_int(c) * 16;
        int low = hex_to_int(d);
        return high+low;
}

void setup() {
    Serial.begin(9600);                  
    Serial.println("Starting ...... ");
    Serial.println("Waitiing for ue attach ...... ");
    delay(10000);
    serial_read();
    delay(1000);

    Serial.println("AT+NSOCR=DGRAM,17,0,1");
    serial_read();
    delay(1000);
    
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
    delay(1000);
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
    char* response_data = response[4];
    int length = strlen(response_data);
    char buf = 0;
    for(i = 0; i < length; i++){
            if(i % 2 != 0){
                    snprintf(retmcu, sizeof(retmcu), "%c", hex_to_ascii(buf, response_data[i]));
                    Serial.print(retmcu);
            }else{
                    buf = response_data[i];
            }
    }
    Serial.println("\n===== End of Response =====");
      
}

void serial_read(){
    int i = 0;
    memset(retmcu, 0, sizeof(retmcu));
    //Waits for the transmission of outgoing serial data to complete.
    Serial.flush();
    //Waits for respones
    delay(1000);
    while(Serial.available() && i < sizeof(retmcu) - 1) {
        retmcu[i] = Serial.read();//read return's value and strage in this array
        i++;
    }

    // for debug
    Serial.println("retmcu: ");
    Serial.println(retmcu);
}
