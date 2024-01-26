# Arduino Sumo Bot

This Arduino project is a fully automated sumo bot designed for competitive sumo wrestling in a controlled arena. The bot utilizes line following sensors, an ultrasonic sensor, two motors, a 3D printed chassis, and an Arduino board to navigate and make strategic decisions during matches.

## Features

- **Line Following Sensors:** Detects arena boundaries to prevent the bot from going out of bounds.
- **Ultrasonic Sensor:** Detects other sumo bots within the arena.
- **Motor Control:** Two motors for precise movement and maneuverability.
- **3D Printed Chassis:** Provides a sturdy and customizable frame for the bot.
- **Autonomous Decision-making:** The bot autonomously decides whether to avoid the arena boundary or attack other bots based on sensor inputs.

## Getting Started

### Prerequisites

- Arduino IDE installed on your computer
- Arduino board (compatible with the code)
- Line following sensors
- Ultrasonic sensor
- Two motors
- 3D printed chassis components

### Installation

1. Clone this repository to your local machine:

    ```bash
    git clone https://github.com/alexis-fernandez/SumoBot.git
    ```

2. Open the Arduino IDE and navigate to the project folder.

3. Connect your Arduino board to your computer.

4. Upload the code to the Arduino board.

## Usage

Ensure all sensors are correctly connected. Power on the sumo bot, and it will autonomously navigate the arena. The bot will either avoid the boundary or attack other bots, attempting to push them out of the ring and secure victory.

## Configuration

Customize the following parameters in the code:

- Sensor calibration values
- Motor speed and control parameters
- Decision-making thresholds



## Acknowledgments

- Source for Ultrasonic Sensor guidance: https://www.youtube.com/watch?v=n-gJ00GTsNg&ab_channel=ScienceBuddies
- Source for line tracking sensor guidance: https://www.youtube.com/watch?v=er_i-MaEoKU&ab_channel=Fungineers

## Authors

- Alexis Fernandez
