#include "main.h"

unsigned int delay = 20;
unsigned int wait_ir;
long long millis = 0;

ISR(TIMER1_COMPA_vect) {
	millis++;
	if (wait_ir) wait_ir--;
	else if (millis % delay == 0) rainbow(0.065, 1, 0, 600, 50);
}

void millis_timer_1_init() {
	cli();
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1  = 0;
	OCR1A  = (F_CPU / 1000) -1;
	TCCR1B |=  (1 << WGM12) | (1 << CS10);
	TIMSK1 |= (1 << OCIE1A);
	sei();
}

int main(void) {
	
	irr_init();
	led_init();
	millis_timer_1_init();
	uart_init(9600, 0);	
	char start[] = "UART OK\r\n";
	uart_send_string(start);

	while (1) {
		
		if (IR_HIGH) {
			wait_ir = 100;	
			unsigned int irrValueNow = irr_decode();
			
			if (irrValueNow) {
				char code_string[16];
				snprintf(code_string, 16, "CODE: 0x%02X\r\n", irrValueNow);
				uart_send_string(code_string);
			}
		}

	}
}
