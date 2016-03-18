/*
  https://github.com/NicoHood/MSGEQ7
*/

// MSGEQ7
#include "MSGEQ7.h"
#include "Fastled.h"

#define pinAnalog A0
#define pinReset 6
#define pinStrobe 4
#define MSGEQ7_INTERVAL ReadsPerSecond(50)
#define MSGEQ7_SMOOTH 191 // Range: 0-255
CMSGEQ7<MSGEQ7_SMOOTH, pinReset, pinStrobe, pinAnalog> MSGEQ7;

#define DATA_PIN    8
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    30
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120

void setup() {

    delay(1000); // 3 second delay for recovery

    // tell FastLED about the LED strip configuration
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

    // set master brightness control
    FastLED.setBrightness(BRIGHTNESS);

    // clear all
    FastLED.show();

    // This will set the IC ready for reading
    MSGEQ7.begin();

    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
    delay(2000);
}

void loop() {

    bool newReading = MSGEQ7.read(MSGEQ7_INTERVAL);
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    // Led output
    if (newReading) {
        CRGB a = 0x610061;
        a.nscale8_video(mapNoise(MSGEQ7.get(MSGEQ7_0)));
        leds[0] = a;
        leds[1] = a;

        CRGB b = 0x4600ff;
        b.nscale8_video(mapNoise(MSGEQ7.get(MSGEQ7_1)));
        leds[2] = b;
        leds[3] = b;

        CRGB c = 0x0090ff;
        c.nscale8_video(mapNoise(MSGEQ7.get(MSGEQ7_2)));
        leds[4] = c;
        leds[5] = c;

        CRGB d = 0x80ff00;
        d.nscale8_video(mapNoise(MSGEQ7.get(MSGEQ7_3)));
        leds[6] = d;
        leds[7] = d;

        CRGB e = 0xffff00;
        e.nscale8_video(mapNoise(MSGEQ7.get(MSGEQ7_4)));
        leds[8] = e;
        leds[9] = e;

        CRGB f = 0xff8000;
        f.nscale8_video(mapNoise(MSGEQ7.get(MSGEQ7_5)));
        leds[10] = f;
        leds[11] = f;

        CRGB g = 0xff0000;
        g.nscale8_video(mapNoise(MSGEQ7.get(MSGEQ7_6)));
        leds[12] = g;
        leds[13] = g;


//        Serial.println(input);


//        CRGB color = CRGB::Blue;
//        color.nscale8_video(low);
//        fill_solid(leds, NUM_LEDS, color);

        // update Leds
        FastLED.show();
    }

}

