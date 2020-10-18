# iot-learning

## Linkit 7697 for Arduino
last modified: 2020/05/09  
email: michael_7150@yahoo.com.tw  

---

## Environment

OS: Windows 10 version 1909  
IDE: Arduino IDE 1.8.12 -> [Download Arduino IDE](https://www.arduino.cc/en/Main/Software)  

PS,如果照流程操作有任何問題，極有可能是因為板子或是傳輸線沒有插好，請把所有相關裝置重新拔掉插好

## Setup

### 1. Install Arduino IDE
### 2. Add Linkit 7697 Support Package
由於 Arduino IDE 預設沒有支援 Linkit 7697  
所以需要手動加入 Linkit 7697 Support Package  

The board support package URL for LinkIt 7697 is as follows:  
```
http://download.labs.mediatek.com/package_mtk_linkit_7697_index.json
```

a. Open File > Preferences dialog, as shown below:  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878161/12878160/3/1490173858177/file_preferences_menu.png)

b. Add the following URL to the Additional Boards Manager URLs field:  
```
http://download.labs.mediatek.com/package_mtk_linkit_7697_index.json
```  
![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878161/12878182/1/1490171727851/preferences_dialog.png)  

c. Click "OK" to end the dialog.  

d. Select Tools > Board > Boards Manager... to open the Boards Manager dialog:  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878161/12878239/1/1490246867677/tools_board_menu.png)  

e. Wait for the board manager to download the package information from the URL you just provided. After completion, you'll find a LinkIt 7697 by MediaTek Labs board package in the list. You can also type LinkIt in the search box, as shown below:  
'![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878161/12878241/1/1490246920554/search_for_linkit.png)  

f. Click on the LinkIt 7697 item, and then click the Install button, as shown below:  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878161/12878240/1/1490246907913/install_board_package.png)  

g. The IDE should start downloading the required tools and software packages. Wait for its completion, and click Close to end the dialog.  

h. Once the package is installed, you should see a LinkIt 7697 item appear in the bottom of the Tools > Board menu, as shown below:  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878161/12878242/1/1490246984803/board_menu.png)  

i. Now that you've installed the board support package, you are ready to connect LinkIt 7697 board to your computer.  

### 3. Install CP2102N Driver on Windows  

a. Download and Install the Driver  

Download and install the CP2102N USB to UART Bridge VCP driver.  
Choose the Download VCP option according to your operating system version. [Downlaod CP2102N Driver](http://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)  

b. Connect LinkIt 7697 to Computer  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878250/12879244/1/1495605558797/board.jpg)  

c. Confirm Driver Installation  

After connecting the board to the computer, follow the steps below to confirm if the driver is installed properly:  

- Open Device Manager from the control panel.  
- In the Ports (COM & LPT) section, an item named Silicon Labs CP210x USB to UART Bridge (COMXYZ) should appear.  
- The number XYZ can be different on each computer.  
- This is the COM port you'll be using to program and interact with the LinkIt 7697 board.  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878248/12878254/1/1490247715367/windows_device_manager.png)  

- Open Arduino IDE and a LinkIt 7697 item should appear under the Tools > Port menu:  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878248/12878255/1/1490247794500/board_port_selection.png)  

You're now ready to download sketches to the LinkIt 7697 board.  

### 4. Run Your First Sketch  

After setting up the IDE, we now upload a basic sketch to make sure everything is working properly.  

## The Blink Example  

This is the most basic example sketch from the board - blink the onboard USR LED. To run the example, follow the below steps:  

a. Connect the board to your computer, as instructed in the previous chapter.  
b. Select  LinkIt 7697 from the board: go to Tools > Board.  
c. Select Tools > Port: menu, and then select COM XYZ (LinkIt 7697). The number XYZ  can be different on each computer. The screenshot below is an example:  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12881349/12881348/1/1502782296559/board_port_selection.png)  

d. Now select the Blink example from File > Examples > 01. Basics > Blink, as shown below:  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12881349/12881347/1/1502782296587/blink_example.png)  

e. Click the  Upload  button on the toolbar, as shown below:  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12881349/12881346/1/1502782296603/click_upload.png)  

f. It may take some time to compile and upload the sketch. During the uploading process, the board's  TX  and  RX  LEDs will blink rapidly. Once the uploading completes, the IDE shows Done uploading. as shown below:  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12881349/12881345/1/1502782296623/done_uploading.png)  

g. The board will automatically reboot, and the USR LED should start to blink once every second.  

Note that unlike Arduino Uno, the USR LED maps to P7 instead of P13 on the LinkIt 7697 board. Therefore the functional call:  

```
digital_write(LED_BUILTIN, HIGH);
```
is equal to:
```
digital_write(7, HIGH); // 7 maps to P7 on LinkIt 7697 board
```

Refer to the pinout diagram to find other pin mapping definitions.  