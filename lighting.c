#include "lighting.h"

unsigned int offset = 0;
unsigned char palette[3][360];

unsigned char remake_palette = 1;

void rainbow(double brightness, double saturation, unsigned char reverse, unsigned int chain, unsigned int segment) {
	
	if (remake_palette) {
		
		for (unsigned int i = 0; i < 360; i++) {
			rgb = hsv_rgb(i, saturation, brightness);
			palette[0][i] = rgb.r; palette[1][i] = rgb.g; palette[2][i] = rgb.b;
		}
		remake_palette = 0;
	}
	
	if (reverse) {
		for (unsigned int i = 0; i < chain; i++) {
			unsigned int paletteIndex = ((360 / segment) * ((i + offset - 1) % segment));
			led_pixel(palette[0][paletteIndex], palette[1][paletteIndex], palette[2][paletteIndex]);
		}
		offset--;
		if (offset == 0) offset = segment;
	}
	else {
		for (unsigned int i = 0; i < chain; i++) {
			unsigned int paletteIndex = 359 - ((360 / segment) * ((i + offset) % segment));
			led_pixel(palette[0][paletteIndex], palette[1][paletteIndex], palette[2][paletteIndex]);
		}
		offset++;
		if (offset == segment) offset = 0;
	}
	led_reset();
}
