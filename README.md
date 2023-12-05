# VibeAlert
### ECE 4180 Final Project - Echo Location Device

#### Creators: Davia Mckenzie, Auric Saha, and John Watkins

# About VibeAlert
Our echo location devices uses the HC-SR04 Sonar Sensor to detect the distance of unanimous object in front of the user. When the user enters a specific range away from any object in front of them, the echo location device will sound an alarm sound - using headphones - and alert the user with vibrations – using the grove vibration motor. This device is intended for the hearing impaired. If the user enters a close range to the object in front of them, the alarm sound and vibration will become intense.

<p align="center">
<img src = "https://github.com/jwatkins68/VibeAlert/assets/152657384/cd8f4e3f-e454-4707-9c9c-a01db82b4533" />


VibeAlert is a device designed to empower and enhance the mobility of visually impaired individuals. It is a compact tool that serves with the purpose of being a reliable companion for navigating the world with confidence and safety.​



<!--- Block Diagram --->

### Figure 1 : Block Diagram showing the I/O pin connections
![image](https://github.com/jwatkins68/VibeAlert/assets/152657384/d4d04bed-1a7d-460b-9b88-636a6888eb75)

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

# Code Used for Implementation
<!--- Insert Code Here --->







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
