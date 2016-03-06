#include "FastLED.h"


#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    7
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    12

CRGB leds[NUM_LEDS];

#define BRIGHTNESS          8
#define FRAMES_PER_SECOND  60

void setup() {
  delay(2000); // 3 second delay for recovery
  
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}

// List of patterns to cycle through
typedef void (*SimplePatternList[])();

SimplePatternList gPatterns = {rainbow};

// Index number of which pattern is current
uint8_t gCurrentPatternNumber = 0;

// rotating "base color" used by many of the patterns
uint8_t gHue = 0;
  
void loop()
{
    // Call the current pattern function once, updating the 'leds' array
    gPatterns[gCurrentPatternNumber]();

    // send the 'leds' array out to the actual LED strip
    FastLED.show();

    // insert a delay to keep the framerate modest
    FastLED.delay(1000/FRAMES_PER_SECOND);

    // slowly cycle the "base color" through the rainbow
    EVERY_N_MILLISECONDS( 40 ) { gHue++; }
    // change patterns periodically
    // EVERY_N_SECONDS( 10 ) { nextPattern(); }
}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

// add one to the current pattern number, and wrap around at the end
void nextPattern() {
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}

void rainbow() {
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
}
