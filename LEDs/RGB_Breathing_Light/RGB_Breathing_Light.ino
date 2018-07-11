/**************************************************************************************************
 *    _____    __      __        __           __        ______   _______   _        _    ___     _
 *  / _____)  /  \    /   \     /  \         / /       / _____) |   ____| | |      | |  |   \   | |
 * | |_____  | |\ \  / /| |    / /\ \       / /____   | |_____  |  |____  | |      | |  | |\ \  | |
 * |  _____| | | \ \/ / | |   / /  \ \     / / ___/   | |_____| |  |____| | |      | |  | | \ \ | |
 * | |_____  | |  \__/  | |  / /****\ \   / /\ \____  | |_____  |  |      | \______/ |  | |  \ \| |
 *  \______) |_|        |_| /_/      \_\ /_/  \_____\  \______) |__|       \ ______ /   |_|   \___|
 *
 *
 * Emakefun Tech firmware
 *
 * Copyright (C) 2015-2020
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, in version 3.
 * learn more you can see <http://www.gnu.org/licenses/>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * [Title]:   RGB breathing light
 * [Diagram]
 *         Arduino PIN 9   ===================  RGB pin1 red
 *         Arduino PIN 10  ===================   RGB pin3 green
 *         Arduino PIN 11  ===================    RGB pin4 blue
 *         Arduino 5V     ===================   RGB pin2  5V
 *
 */
#define RGB_RED    8
#define RGB_GREEN  9
#define RGB_BLUE   10

int fadeDelay = 20;

void setup()
{
    pinMode(RGB_RED,OUTPUT);
    pinMode(RGB_GREEN,OUTPUT);
    pinMode(RGB_BLUE,OUTPUT);
}

void setColor(int red,int green,int blue)
{
    analogWrite(RGB_RED,red);
    analogWrite(RGB_GREEN,green);
    analogWrite(RGB_BLUE,blue);
}

void loop()
{
    int i;
    for (i=0; i<256; i++)
    {
        setColor(i, 0, 0);
        delay(fadeDelay);
    }
    delay(500);           //turn the RGB LED red smoothly

    for (i=0; i < 256; i++)
    {
        setColor(0, i, 0);
        delay(fadeDelay);
    }
    delay(500);           //turn the RGB LED green smoothly

    for (i=0; i < 256; i++)
    {
        setColor(0, 0, i);
        delay(fadeDelay);
        // BONUS: make blue fade off smoothly
    }
    delay(500);           //turn the RGB LED blue smoothly
}
