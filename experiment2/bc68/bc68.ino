
static char retmcu[256] = {'\0'};

void setup() {
    Serial.begin(9600);                  
    Serial.println("Starting ...... ");
    Serial.println("Waitiing for ue attach ...... ");
    delay(3000);
    serial_read();
    delay(3000);
    serial_read();
    delay(3000);
    Serial.println("AT+NSOCR=DGRAM,17,0,1");
    serial_read();
    delay(1000);
    Serial.println("AT+CMEE=1");
    serial_read();
    delay(1000);
}

void loop() {
    Serial.println("AT+NPING=8.8.8.8");
    serial_read();
    delay(1000);

    //Send sensor by UDP socket
    snprintf(retmcu, sizeof(retmcu), "AT+NSOST=1,140.123.230.10,6000,5,313233340A");
    Serial.println(retmcu);
    serial_read();
    delay(1000);
}

void serial_read(){
    int i = 0;
    memset(retmcu, 0, sizeof(retmcu));
    Serial.flush();              //Waits for the transmission of outgoing serial data to complete.
    delay(1000);                     //Waits for respones from server
    while(Serial.available() && i < sizeof(retmcu) - 1) {
        retmcu[i] = Serial.read();//read return's value and strage in this array
        i++;
    }
    
    Serial.println("retmcu: ");      //for debug
    Serial.println(retmcu);      //for debug
}
