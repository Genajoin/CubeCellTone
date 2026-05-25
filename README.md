# CCTone

Non-blocking tone (beep) library for **Heltec CubeCell** (ASR6502 + SX1262 LoRa) boards.

## Why

The standard Arduino `tone()` function isn't supported on the CubeCell platform. `CCTone` is a minimal PWM-based alternative: non-blocking, suitable for buzzer/piezo signalling in low-power LoRa nodes.

## Installation

### PlatformIO

```ini
lib_deps =
  https://github.com/Genajoin/CubeCellTone.git
```

### Arduino IDE

`Sketch → Include Library → Add .ZIP Library`, point to a downloaded zip of this repo.

## Usage

```cpp
#include "CCTone.h"

CCTone beeper(PWM2);  // any PWM-capable pin

void setup() {}

void loop() {
  if (beeper.checkInProgress())
    return;
  beeper.beep(1000, 5000, 1000);  // 1 kHz, 5 sec tone, 1 sec pause
}
```

Call `checkInProgress()` early in your `loop()` and return if it's `true` — that's what makes the call non-blocking. The next `beep()` will only start after the previous tone and its trailing pause are done.

## API

| Method | Description |
|---|---|
| `CCTone(pin)` | Construct and attach to a PWM-capable pin (calls `init()` internally) |
| `init()` | (Re-)initialise PWM clock; usually called by the constructor |
| `beep(freq_hz, duration_ms, pause_ms)` | Start a beep. `freq_hz` must be in **200-20000 Hz**, otherwise the output is silenced |
| `checkInProgress()` | Returns `true` while the beep or its trailing pause is still active |

## Hardware

Tested on Heltec CubeCell boards (HTCC-AB01, HTCC-AB02) with passive piezo buzzers driven from a PWM-capable pin.

## Author

Evgeny Istomin · gena@regimov.net

---

## Hire me

I take on commercial engineering work through **[Alpisto d.o.o.](https://alpisto.eu)** (Slovenia, EU) — MATLAB → Python migrations, power-systems algorithms, embedded BLE/RTOS firmware, and IoT backends.

→ [alpisto.eu/matlab-to-python](https://alpisto.eu/matlab-to-python) · **gena@alpisto.eu** · [LinkedIn](https://www.linkedin.com/in/evgenyistomin/)

