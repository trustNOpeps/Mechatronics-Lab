# Mechatronics Lab

Arduino circuit simulations, sensor–actuator experiments, and a documented Tinkercad workflow by [Hamka / trustNOpeps](https://github.com/trustNOpeps).

> **Status:** educational virtual-simulation case study and independently reconstructed example sketch. Not a physically validated device or a fully autonomous AI agent.

## Ultrasonic sensor → servo motor

The earlier Tinkercad practical used an **Arduino Uno**, **HC-SR04** ultrasonic sensor, and **SG90** servo. Its Word report recorded two virtual test observations: an object at **10 cm → servo 90°**, and an object at **30 cm → servo 0°**. Those observations refer to the original Tinkercad simulation; they have **not been reproduced or retested** as part of this repository publication.

This repo includes a **fresh, self-contained example** that demonstrates the same qualitative behavior:

- Trigger HC-SR04 every 150 ms; measure echo duration with a 30 ms timeout.
- Convert echo duration to approximate distance in centimeters.
- Set servo to 90° for valid readings **1–20 cm**, otherwise to 0°.
- Keep servo at 0° when the echo times out or the reading is invalid.

The **20 cm threshold and GPIO pin selection are example implementation choices**. They are not claimed as exact readbacks from the original simulation or as measured/calibrated hardware settings.

### Wiring for the example

| Device terminal | Arduino Uno connection |
|---|---|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| SG90 signal | D6 |
| SG90 VCC | 5V (simulation only) |
| SG90 GND | GND |

For a **physical** servo, use suitable motor power and a common ground; do not assume the Uno 5V pin can safely supply every servo/load. Physical wiring and power behavior have not been tested here.

### Files

```text
arduino/ultrasonic_servo/
  ultrasonic_servo.ino   # Arduino example sketch
  controller.h           # Pure threshold / no-echo logic
tests/
  controller.test.cpp    # Dependency-free host logic checks
docs/
  tinkercad-workflow.md  # Process and provenance
```

### Verify the control logic

With `g++` installed:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic tests/controller.test.cpp -o controller-test
./controller-test
```

Open `arduino/ultrasonic_servo/ultrasonic_servo.ino` in the Arduino IDE, select Arduino Uno, and install the built-in/compatible Servo library. Recreate the seven connections above in Tinkercad Circuits to simulate. **No Arduino CLI compile or fresh Tinkercad run is claimed in this publication.**

## Automation workflow: scope and attribution

In the earlier workflow, a Tinkercad Circuits MCP integration was configured and its connection/authentication checked. The original open-source integration is [netchuu/tinkercad-circuits-mcp](https://github.com/netchuu/tinkercad-circuits-mcp), **not software authored by this account**. The workflow is documented in [docs/tinkercad-workflow.md](docs/tinkercad-workflow.md).

The intended broader pipeline (task/photo/PDF → circuit → sketch → simulation → report) remains a **future integration goal**. This repository does not contain a general-purpose agent that completes that sequence autonomously.

## Boundaries

- Only virtual practical observations are documented; no physical prototype, calibration, reliability testing or safety certification.
- The example is for learning rather than controlling real machinery or safety-critical equipment.
- No login details, Tinkercad access tokens or private student/client materials are committed.
- AI assisted the workflow and documentation; source ownership and limitations are stated explicitly.

[Portfolio](https://trustnopeps.github.io/trustNOpeps/) · [GitHub profile](https://github.com/trustNOpeps)
