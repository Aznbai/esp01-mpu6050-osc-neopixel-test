void mapColors()
{
    // AcX, AcY, AcZ, GyX, GyY, GyZ
    // map(value, fromLow, fromHigh, toLow, toHigh)
    colAcX = map(AcX, -33000, 33000, 1, 255);
    colAcY = map(AcY, -33000, 33000, 1, 255);
    colAcZ = map(AcZ, -33000, 33000, 1, 255);
    colGyX = map(GyX, -33000, 33000, 1, 255);
    colGyY = map(GyY, -33000, 33000, 1, 255);
    colGyZ = map(GyZ, -33000, 33000, 1, 255);
}
void setPixels()
{
    // basic operations:
    // leds[0] = CRGB::Red; // set color of first led
    // leds[0] = CHSV(hue++,255,255); // set color of first leds
    // leds.fadeToBlackBy(NUM_LEDS); // turn off all leds
    mapColors();
    int firstPixel;
    if (GyX < 0)
    {
        // firstPixel = 0;
        for (int i = 0; i < 12; i++)
        {
            leds[i] = CHSV(colGyX, colGyY, colGyZ);
        }
    }
    if (GyX > 0)
    {
        // firstPixel = 3;
        for (int i = 0; i < 12; i++)
        {
            leds[i] = CHSV(colGyY, colGyX, colGyZ);
        }
    }
    if (GyY < 0)
    {
        // firstPixel = 6;
        for (int i = 0; i < 12; i++)
        {
            leds[i] = CHSV(colGyZ, colGyX, colGyY);
        }
    }
    if (GyY > 0)
    {
        // firstPixel = 9;
        for (int i = 0; i < 12; i++)
        {
            leds[i] = CHSV(colGyZ, colGyY, colGyX);
        }

        // for (int i = firstPixel; i < firstPixel + 3; i++)
        // {
        //     leds[i] = CHSV(colAcX - colGyZ, colGyX, colGyY);
        // }
        FastLED.show();
    }
