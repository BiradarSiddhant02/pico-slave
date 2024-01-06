#include <stdio.h>
#include <stdlib.h>
#include <pico/stdlib.h>
#include <math.h>
#include <stdint.h>
#include "hardware/spi.h"
#include "pico/binary_info.h"
#include "hardware/watchdog.h"
#include "hardware/gpio.h"
#include "slave.h"

int main(){

	init_spi();
	init_reset();
    	stdio_init_all();
	
	init_led();
	init_led();

	double sample, filtered;

	double prev_output = 0;
	double prev_input = 0;

	uint8_t packed_sample[8], incoming[8];

	sleep_ms(SAMPLE_RATE * 2);

	while (1) {

	    gpio_put(LED_PIN, 1);
	    
	    spi_write_read_blocking(spi_default, incoming, packed_sample, BUFFER_LEN);
	    sample = convertArrayToDouble(packed_sample);
	
	 
	        // Filtering
	    filtered = filter(prev_output, prev_input, sample);

	    sleep_ms(1);
	    prev_output = filtered;
	    prev_input = sample;

	    printf("%f %f\n", filtered, sample);
	}
	return 0;
}
