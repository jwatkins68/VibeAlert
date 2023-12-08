# VibeAlert
### ECE 4180 Final Project - Echo Location Device

#### Creators: Davia Mckenzie, Auric Saha, and John Watkins

# About VibeAlert
Our echo location devices uses the HC-SR04 Sonar Sensor to detect the distance of unanimous object in front of the user. When the user enters a specific range away from any object in front of them, the echo location device will sound an alarm sound - using headphones - and alert the user with vibrations – using the grove vibration motor. This device is intended for the hearing impaired. If the user enters a close range to the object in front of them, the alarm sound and vibration will become intense.
<pre>
The ranges of the VibeAlert are:
 <summary>4 – 6ft: vibrates at a steady pace​</summary>
 <summary>2 – 4ft: vibrates at a faster pace while playing audio​</summary>
 <summary>0 – 2ft: vibrates even faster while playing audio faster as well​</summary>

Also includes an on/off button which allows the user to turn 
the alarm/ vibration off when in the proximity of other objects.
</pre>

<p align="center">
<img src = "https://github.com/jwatkins68/VibeAlert/assets/152657384/cd8f4e3f-e454-4707-9c9c-a01db82b4533" />


VibeAlert is a device designed to empower and enhance the mobility of visually impaired individuals. It is a compact tool that serves with the purpose of being a reliable companion for navigating the world with confidence and safety.​



<!--- Block Diagram --->

### Figure 1 : Block Diagram showing the I/O pin connections
<p align="center">
<img src = "https://github.com/jwatkins68/VibeAlert/assets/152657384/2ebe7f63-29ad-4fb0-9667-5e87564ab80a" />

The VibeAlert uses five I/O devices - HC-Sonar Ultrasound Sensor, TRSS Breakout, Grove Vibration Motor, SD Card Reader, and a Push button. The block diagram of these devices can be seen in Figure 1. We implemented a portable charger to power the mbed so that the device can be used while walking.

# Parts Information

### HC-Sonar SR04 Ultrasound Sensor
![image](https://github.com/jwatkins68/VibeAlert/assets/152657384/95a1e81b-39f5-49af-9337-d12ec3f891f1)
  <summary>Low-cost sonar-based distance sensor​</summary>
  <summary>Using a 40 kHz ultrasonic ping, the sensor uses soundwaves to echo the   ping off of  objects​</summary>
  <summary>The delay of the reflected signal to echo is used to measure the         distance​</summary>
  <summary>Detection range is 3-400cm (0 ft - 13 ft)​</summary>

### TRSS Breakout
![image](https://github.com/jwatkins68/VibeAlert/assets/152657384/75bcc0f0-573f-4a0c-b653-3ae823febb33)
  <summary>3.5 mm breakout​​</summary>
  <summary>Used for audio output via headphones for personal use​</summary>

### Grove Vibration Motor
![image](https://github.com/jwatkins68/VibeAlert/assets/152657384/4b88c30d-3ab9-4906-b8cb-19f612e39a2c)
  <summary>A high sensitivity non-directional vibration sensor​​​</summary>
  <summary>The device uses PWM signals - driven high, the output is turned on​</summary>
  <summary>The sensitivity of the device is adjustable​</summary>

### SD Card Reader
![image](https://github.com/jwatkins68/VibeAlert/assets/152657384/41afdb64-6c0a-4e1c-97d6-ee5f180a2b4d)
  <summary>SD Cards are used for storage; phones, mp3 players, pc's etc​​​​</summary>
  <summary>Store non-volatile data (data is not lost when power is off)</summary>
  <summary>Ideal for data logging and storing audio/images​​</summary>

### Push Button
![image](https://github.com/jwatkins68/VibeAlert/assets/152657384/42a35c4f-db99-433f-8e7a-2b8636fffa30)
  <summary>A low cost SPST normally open pushbutton​​​​​</summary>
  <summary>Push button includes debouncing with interrupts and a callback function​</summary>

### Figure 2 : VibeAlert on the Breadboard
![image](https://github.com/jwatkins68/VibeAlert/assets/152657384/2688b92d-f2d0-4106-ba77-67e818cf177a)

https://github.com/jwatkins68/VibeAlert/assets/152657384/c3ea062f-2153-4024-8d2c-4c879f306636

https://gtvault.sharepoint.com/sites/4180Project/_layouts/15/embed.aspx?UniqueId=490fafca-cb0c-442c-89f1-7cd59acfb6b7&embed=%7B%22ust%22%3Atrue%2C%22hv%22%3A%22CopyEmbedCode%22%7D&referrer=StreamWebApp&referrerScenario=EmbedDialog.Create

# Code Used for Implementation
<!--- Insert Code Here --->
In this section, we will explain portions of the code. The entire code can be downloaded via the [main.cpp](https://github.com/jwatkins68/VibeAlert/blob/main/main.cpp) file. The VibeAlert has a push button to turn on/off the HC-SR04 Ultrasonic Sonar Sensor allowing the user to stand stationary in front of object without the alarm sound and vibration. To incorporate this push button, we implemented a PinDetect and Callback function. 

### PinDect Code
```

    // Use internal pullups for pushbutton
    pb.mode(PullUp);    
    // Delay for initial pullup to take effect
    wait(.01);
    // Setup Interrupt callback functions for a pb hit
    pb.attach_deasserted(&power_on);
    // Start sampling pb inputs using interrupts
    pb.setSampleFrequency();

```

### Callback Function Code
```

void power_on(void) {
    if (power == 0) {
        power = 1;
    }
    else {
        power = 0;
    }
}

```
To make debugging and understand how the HC-SR04 Ultrasound Sonar Sensor works, we implemeneted code to convert the sensor from milimeters to feet. To enhance your persoanl code, we recommend changing this code to your desired units of distance.

### Callback Function Code
```

// Helper Functions
void dist(int distance) {
    // Convert distance from millimeters to feet
    global_distance = static_cast<float>(distance) / 1000.0 / 0.3048;

```




<!--- Adding a Dropdown
<details>
<summary>Code used for implementation</summary>
  

<!---
  Suprise MF!
  --->
</details>

<!--- Adding a Table 

| Rank | Languages |
|-----:|-----------|
|     1| Javascript|
|     2| Python    |
|     3| SQL       |

--->
