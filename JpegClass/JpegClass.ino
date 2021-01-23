#include <Arduino_GFX_Library.h>
#include "JpegClass.h"
#include <FS.h>
#include <SD.h>
#include <SPI.h>
 
 
#define MISO     2
#define SCLK    14  //SCL
#define MOSI    15  //SDA
#define SD_CS   13
#define TFT_CS   5
#define TFT_BLK 22
#define TFT_DC  27
#define TFT_RST 33
 
 
Arduino_DataBus *bus = new Arduino_HWSPI(TFT_DC, TFT_CS, SCLK, MOSI, MISO, true);
Arduino_GC9A01  *gfx = new Arduino_GC9A01(bus, TFT_RST, 1, true);
static JpegClass jpegClass;
 
 
void setup()
{
    Serial.begin(115200);
 
 
   //Init MicroSD
    SPI.begin(SCLK, MISO, MOSI, SD_CS);
    if( !SD.begin(SD_CS) )
    {
        Serial.println("Card Mount Failed");
        gfx->println(F("ERROR: Card Mount Failed!"));
        return;
    }
 
    uint8_t cardType = SD.cardType();
    if( cardType == CARD_NONE )
    {
        Serial.println("No SD card attached");
        gfx->println(F("ERROR: No SD card attached"));
        return;
    }
 
    Serial.print("SD Card Type: ");
    switch( cardType )
    {
        case CARD_MMC:  Serial.println("MMC");  break;
        case CARD_SD:   Serial.println("SDSC"); break;
        case CARD_SDHC: Serial.println("SDHC"); break;
        default:        Serial.println("UNKNOWN");
    }
 
 
    //Init Display
    gfx->begin();
    gfx->fillScreen(BLACK);
 
    #ifdef TFT_BLK
      pinMode(TFT_BLK, OUTPUT);
      digitalWrite(TFT_BLK, HIGH);
    #endif
}
 
 
 
void loop()
{
    unsigned long start = millis();
 
    File root = SD.open("/img");
    printDirectory(root, 0);
 
    Serial.printf("Time used: %lu\n", millis() - start);
}
 
 
 
void printDirectory(File dir, int numTabs)
{
    while( true )
    {
        File entry =  dir.openNextFile();
        if( !entry )
        {
            //No more files. Return to the first file in the directory
            dir.rewindDirectory();
            break;
        }
 
        for( uint8_t i=0 ; i<numTabs ; i++ )
        {
            Serial.print('\t');
        }
 
        Serial.print(entry.name());
 
        if( entry.isDirectory() )
        {
            Serial.println("/");
            printDirectory(entry, numTabs+1);
        }
        else
        {
            //Files have sizes, directories do not
            Serial.print("\t\t");
            Serial.println(entry.size(), DEC);
 
            jpegClass.draw(entry, jpegDrawCallback, true, 0, 0, gfx->width(), gfx->height());
            delay(5000);
        }
    }
}
 
 
 
 
static int jpegDrawCallback(JPEGDRAW *pDraw)
{
    gfx->draw16bitBeRGBBitmap(pDraw->x, pDraw->y, pDraw->pPixels, pDraw->iWidth, pDraw->iHeight);
}
