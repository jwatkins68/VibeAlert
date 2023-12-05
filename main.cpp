#include "mbed.h"
#include "rtos.h"
#include "SDFileSystem.h"
#include "wave_player.h"
#include "ultrasonic.h"
#include "PinDetect.h"

// Global Variables
volatile float global_distance = 4180;
volatile int power = 0;

// Helper Functions
void dist(int distance) {
    // Convert distance from millimeters to feet
    global_distance = static_cast<float>(distance) / 1000.0 / 0.3048;
    
    // Print the distance in feet (For Debugging)
    // printf("Distance %.2f feet\r\n", global_distance);
}

void power_on(void) {
    if (power == 0) {
        power = 1;
    }
    else {
        power = 0;
    }
}

// Thread Initialization
Thread threadspeak;
Thread threadvibe;

// Pushbutton Initialization
PinDetect pb(p14);

// SD Card Initialization
SDFileSystem sd(p5, p6, p7, p8, "sd");
AnalogOut DACout(p18);
wave_player waver(&DACout);

// Sonar Initialization
ultrasonic mu(p12, p13, 0.25, 1, &dist);

// Vibration Initialization
PwmOut vibe(p22);

// Speaker Thread
void thread_speaker() {
    while (1) {
        if (power == 1) {
            if (global_distance > 2 && global_distance < 4) {
                FILE *wave_file;
                wave_file=fopen("/sd/drip3.wav","r");
                waver.play(wave_file);
                fclose(wave_file);
                Thread::wait(500);
            }
            else if (global_distance < 2) {
                FILE *wave_file;
                wave_file=fopen("/sd/drip3.wav","r");
                waver.play(wave_file);
                fclose(wave_file);
                Thread::wait(250);
            }
        }
    }
}

// Vibration Thread
void thread_vibration() {
    float timer = 1;
    while (1) {
        if (power == 1) {
            if (global_distance > 4 && global_distance < 6) {
                vibe = 1.0f;
                wait(timer);
                vibe = 0;
                wait(timer);
            }
            else if (global_distance > 2 && global_distance < 4) {
                vibe = 1.0f;
                wait(timer/4);
                vibe = 0;
                wait(timer/4);
            }
            else if (global_distance < 2) {
                vibe = 1.0f;
                wait(timer/10);
                vibe = 0;
                wait(timer/10);
            }
        }
        Thread::wait(500);
    }
}

int main() {
    // Use internal pullups for pushbutton
    pb.mode(PullUp);    
    // Delay for initial pullup to take effect
    wait(.01);
    // Setup Interrupt callback functions for a pb hit
    pb.attach_deasserted(&power_on);
    // Start sampling pb inputs using interrupts
    pb.setSampleFrequency();
    
    threadspeak.start(thread_speaker);
    threadvibe.start(thread_vibration);

    // Sensor Thread
    mu.startUpdates();
    while (1) {
        if (power == 1) {
            mu.checkDistance();
            Thread::wait(10);
        }
    }    
}