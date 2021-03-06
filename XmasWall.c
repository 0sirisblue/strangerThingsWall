// These two libraries are required for basic functionality
#include <FastLED.h>
#include <PS2Keyboard.h>

// These lines define parameters for number of LEDs,and the PIN they get data from
#define NUM_LEDS 42
#define DATA_PIN 5

// These lines set needed data/clock pin inputs for PS2keyboard communicating w/arduino
const int DataPin = 8;
const int IRQpin =  3; /* for the love of god don't change this */

//These lines are defining some oft-used variables to neaten up the code
const int showTimer = 1000;
const int offTimer = 150;
const int fastShowTimer = 750;
const int fastOffTimer = 50;

const int A = 2;
const int B = 3;
const int C = 5;
const int D = 6;
const int E = 8;
const int F = 9;
const int G = 10;
const int H = 11;
const int I = 15;
const int J = 17;
const int K = 18;
const int L = 19;
const int M = 21;
const int N = 22;
const int O = 23;
const int P = 24;
const int Q = 26;
const int R = 30;
const int S = 31;
const int T = 32;
const int U = 34;
const int V = 35;
const int W = 36;
const int X = 38;
const int Y = 39;
const int Z = 40;

int count = 0;
int fortNum = 0;
int longLoop =0;
int rep = 0;
int snake = 0;


// This section is defining arrays for my macro light sequences
int hohoMacroArray[] = {H, O, H, O, H, O}; /* LEDs for "HOHOHO" */
int merryxmasMacroArray[] = {M, E, R, R, Y, C, H, R, I, S, T, M, A, S}; /* LEDs for "MERRYCHRISTMAS" */
int happyholidaysMacroArray[] = {H, A, P, P, Y, H, O, L, I, D, A, Y, S}; /* LEDs for "HAPPYHOLIDAYS" */
int runrunrudolphMacroArray[] = {R, U, N, R, U, N, R, U, D, O, L, P, H}; /* LEDs for "RUNRUNRUDOLPH" */
int onemainMacroArray[] = {O, N, E, M, A, I, N}; /* LEDs for "ONEMAIN" */
int strangerMacroArray[] = {S, T, R, A, N, G, E, R, T, H, I, N, G, S}; /* LEDs for "STRANGERTHINGS" */
int haveastrangeMacroArray[] = {H, A, V, E, A, S, T, R, A, N, G, E, X, M, A, S}; /* LEDs for "HAVEASTRANGEXMAS" */
int bahhumbugMacroArray[] = {B, A, H, H, U, M, B, U, G}; /* LEDs for "BAHHUMBUG" */
int sonofanutMacroArray[] = {S, O, N, O, F, A, N, U, T, C, R, A, C, K, E, R}; /* LEDs for "SONOFANUTCRACKER" */
int callmesantaMacroArray[] = {C, A, L, L, M, E, S, A, N, T, A}; /* LEDs for "CALLMESANTA" */
int dontblinkMacroArray[] = {D, O, N, T, B, L, I, N, K}; /* LEDs for "DONTBLINK" */
int yesMacroArray[] = {Y, E, S}; /* LEDs for "YES" */
int noMacroArray[] = {N, O}; /* LEDs for "NO" */
int wtfMacroArray[] = {W, T, F}; /* LEDs for "WTF" */

// Defines array for holding LED data
CRGB leds[NUM_LEDS];

// Creates the actual keyboard object
PS2Keyboard keyboard;


// This creates a clear function to reset all LEDs to black
void clear() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
    }
  FastLED.show();
}

// This function standardizes the "lighting" of an LED and the time between characters
void showLED() {
  FastLED.show();
  delay(showTimer);
  clear();
  delay(offTimer);
}

void fastShowLED() {
  FastLED.show();
  delay(750);
  clear();
  delay(50);
}

/* void flickerLED() {
  FastLED.show();
  delay(showTimer);
  clear();
  delay(offTimer);
} */


// This is the setup code to initialize the LEDs and begin listening for key input
void setup() {

  // This line initializes the LEDs
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
  
  //This reads a random pin for a better random number generator
  randomSeed(analogRead(0));

  // These lines initialize the keyboard.
  delay(3000);
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  
}

void loop() { /* Main program body below here */
  
  char key;

// This checks to see if a key has been pressed, and assigns that value to 'key' variable
  if (keyboard.available()) {
    key = keyboard.read();
  }

  clear(); /* clears any led assignment */

// This switch statement will allow me to program 'macros' ie one key = several 
// actions, or a single activation for an individual letter key press
  switch (key) { 
    case ('1'):
    for (rep = 0; rep < 2; rep++) {
      for (count = 0; count < 6; count++) { /*  hohoho x3  */
        leds[hohoMacroArray[count]] = CRGB::Ivory;
        fastShowLED();
        delay(900);
        }
      }
      break;
    case ('2'):
    for (count = 0; count < 14; count++) { /* merry christmas */
      leds[merryxmasMacroArray[count]] = CRGB::Ivory;
      fastShowLED();
      }
      break;
    case ('3'):
    for (count = 0; count < 13; count++) { /*  happy holidays  */
      leds[happyholidaysMacroArray[count]] = CRGB::Ivory;
      showLED();
      }
      break;
    case ('4'):
    for (count = 0; count < 13; count++) { /*  run run rudolph */
      leds[runrunrudolphMacroArray[count]] = CRGB::Ivory;
      fastShowLED();
      }
      break;
    case ('5'):
    for (count = 0; count < 7; count++) { /*  onemain  */
      leds[onemainMacroArray[count]] = CRGB::Ivory;
      showLED();
      }
      break;
    case ('6'):
    for (count = 0; count < 14; count++) { /*  stranger things  */
      leds[strangerMacroArray[count]] = CRGB::Ivory;
      fastShowLED();
      }
      break;
    case ('7'):
    for (count = 0; count < 16; count++) { /*  have a strange xmas  */
      leds[haveastrangeMacroArray[count]] = CRGB::Ivory; 
      fastShowLED();
      }
      break;
    case ('8'):
    for (count = 0; count < 9; count++) {
      leds[bahhumbugMacroArray[count]] = CRGB::Ivory;  /* bah humbug */
      showLED();
      }
      break;
    case ('9'):
    for (count = 0; count < 16; count++) {
      leds[sonofanutMacroArray[count]] = CRGB::Ivory;  /* son of a nutcracker */
      fastShowLED();
      }
      break;
    case ('0'):
    for  (int snake = 0; snake < NUM_LEDS; snake++) {
       /*            -------      try and figure this out in the morning       ------          */ 
      break;
    }
    case ('a'):
      leds[A] = CRGB::Blue;
      showLED();
      break;
    case ('b'):
      leds[B] = CRGB::Lime;
      showLED();
      break;
    case ('c'):
      leds[C] = CRGB::Orange;
      showLED();
      break;
    case ('d'):
      leds[D] = CRGB::Blue;
      showLED();
      break;
    case ('e'):
      leds[E] = CRGB::Orange;
      showLED();
      break;
    case ('f'):
      leds[F] = CRGB::Lime;
      showLED();
      break;
    case ('g'):
      leds[G] = CRGB::Red;
      showLED();
      break;
    case ('h'):
      leds[H] = CRGB::Ivory;
      showLED();
      break;
    case ('i'):
      leds[I] = CRGB::Orange;
      showLED();
      break;
    case ('j'):
      leds[J] = CRGB::Blue;
      showLED();
      break;
    case ('k'):
      leds[K] = CRGB::Lime;
      showLED();
      break;
    case ('l'):
      leds[L] = CRGB::Red;
      showLED();
      break;
    case ('m'):
      leds[M] = CRGB::Orange;
      showLED();
      break;
    case ('n'):
      leds[N] = CRGB::Blue;
      showLED();
      break;
    case ('o'):
      leds[O] = CRGB::Red;
      showLED();
      break;
    case ('p'):
      leds[P] = CRGB::Lime;
      showLED();
      break;
    case ('q'):
      leds[Q] = CRGB::Ivory;
      showLED();
      break;
    case ('r'):
      leds[R] = CRGB::Lime;
      showLED();
      break;
    case ('s'):
      leds[S] = CRGB::Orange;
      showLED();
      break;
    case ('t'):
      leds[T] = CRGB::Ivory;
      showLED();
      break;
    case ('u'):
      leds[U] = CRGB::Red;
      showLED();
      break;
    case ('v'):
      leds[V] = CRGB::Blue;
      showLED();
      break;
    case ('w'):
      leds[W] = CRGB::Ivory;
      showLED();
      break;
    case ('x'):
      leds[X] = CRGB::Lime;
      showLED();
      break;
    case ('y'):
      leds[Y] = CRGB::Red;
      showLED();
      break;
    case ('z'):
      leds[Z] = CRGB::Ivory;
      showLED();
      break;
    default:
      delay (1000);
      
    }
}
