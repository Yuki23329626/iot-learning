# iot-learning

## Linkit 7697 for Arduino
last modified: 2020/05/09  
email: michael_7150@yahoo.com.tw  

---

## Environment

操作系統: Windows 10 version 1909  
IDE: Arduino IDE 1.8.12 -> [Download Arduino IDE](https://www.arduino.cc/en/Main/Software)  

PS,如果照流程操作有任何問題，極有可能是因為板子或是傳輸線沒有插好，請把所有相關裝置重新拔掉插好

## Setup

### 1. 安裝 Arduino IDE
### 2. Add Linkit 7697 Support Package
由於 Arduino IDE 預設沒有支援 Linkit 7697  
所以需要手動加入 Linkit 7697 Support Package  

The board support package URL for LinkIt 7697 如下:  
```
http://download.labs.mediatek.com/package_mtk_linkit_7697_index.json
```

a. 打開工具列的 File > Preferences 對話框, 如下:  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878161/12878160/3/1490173858177/file_preferences_menu.png)

b. 把下方的 URL to 加到 Additional Boards Manager URLs 框裡:  
```
http://download.labs.mediatek.com/package_mtk_linkit_7697_index.json
```  
![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878161/12878182/1/1490171727851/preferences_dialog.png)  

c. 點擊 "OK" 結束對話框  

d. 選擇 Tools > Board > Boards Manager... 來打開 Boards Manager 對話框:  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878161/12878239/1/1490246867677/tools_board_menu.png)  

e. 等待 board manager 下載完您剛剛提供的URL下載軟件包信息。完成後，您將在列表中找到 MediaTek Labs 的 LinkIt 7697 開發板套件。您也可以在搜索框中鍵入LinkIt，如下所示：  
'![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878161/12878241/1/1490246920554/search_for_linkit.png)  

f. 點擊 LinkIt 7697 項，然後單擊 "Install" 按鈕，如下所示：:  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878161/12878240/1/1490246907913/install_board_package.png)  

g. IDE 會開始下載所需的工具和軟體。等待其完成，然後單擊 "Close" 以結束對話框。  

h. 安裝軟件包後，您應該會在 tool > board 的底部看到一個 LinkIt 7697 項，如下所示：  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878161/12878242/1/1490246984803/board_menu.png)  

i. 您已經安裝了 support package，可以將 LinkIt 7697 連接到 computer 了。  

### 3. Install CP2102N Driver on Windows  

a. 下載並安裝驅動  

Download and install the CP2102N USB to UART Bridge VCP driver.  
Choose the Download VCP option according to your operating system version. [Downlaod CP2102N Driver](http://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)  

b. 將 LinkIt 7697 用傳輸線連到 Computer  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878250/12879244/1/1495605558797/board.jpg)  

c. 確認驅動安裝完成   

將開發板連接到計算機後，請按照以下步驟確認驅動程序是否正確安裝：  

-從控制面板中打開設備管理器。  
-在 "port（COM＆LPT）" 部分中，應出現一個名為 Silicon Labs CP210x USB 至 UART bridge（COMXYZ）的項目。  
-每台計算機上的 XYZ 編號可以不同。  
-這是您用來對 LinkIt 7697 進行編程和交流的 COM port。  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878248/12878254/1/1490247715367/windows_device_manager.png)  

- 打開 Arduino IDE，LinkIt 7697 項應出現在 ""tool > port " menu 下：  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12878248/12878255/1/1490247794500/board_port_selection.png)  

現在您可以將 sketches 下載到 LinkIt 7697 板上。  

### 4. Run Your First Sketch  

設置IDE之後，我們現在上傳一個基本 sketches，以確保一切正常。  

## The Blink Example  

這是板上最基本的示例草圖-閃爍板上的USR LED。要運行該示例，請按照以下步驟操作：  

一個。按照上一章的說明將開發板連接到計算機。  
b。從開發板上選擇LinkIt 7697：轉到“工具”>“開發板”。  
C。選擇工具>端口：菜單，然後選擇COM XYZ（LinkIt 7697）。每台計算機上的XYZ號可以不同。下面的屏幕截圖是一個示例：  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12881349/12881348/1/1502782296559/board_port_selection.png)  

d. 現在選擇 Blink example 從工具列的 File > Examples > 01. Basics > Blink, 如下:  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12881349/12881347/1/1502782296587/blink_example.png)  

e. 點擊工具列中的  Upload  按鈕，如下:  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12881349/12881346/1/1502782296603/click_upload.png)  

f. 需要花點時間來確認跟上傳 sketch. 再上傳期間內，開發版的  TX  and  RX  LEDs 會快速閃爍. 一旦完成上傳, IDE 會顯示完成的訊息. 如下:  

![](https://docs.labs.mediatek.com/resource/linkit7697-arduino/files/en/12881349/12881345/1/1502782296623/done_uploading.png)  

g. 開發版將自動重啟，並且 USR LED 應開始每秒閃爍一次。  

請注意，與 Arduino Uno 不同，USR LED 映射到 LinkIt 7697 板上的 P7 而不是 P13 腳位。 因此 function call 要以如下方式撰寫：  

```
digital_write(LED_BUILTIN, HIGH);
```
is equal to:
```
digital_write(7, HIGH); // 7 maps to P7 on LinkIt 7697 board
```

請參考 pinout diagram，以找到其他 pin mapping definitions。