# Power Design

## Baseline
Current prototype assumes:
- 12V supply for electric strike
- buck conversion for low-voltage electronics
- ESP32 controller
- door sensor
- relay or safer strike driver stage

## Why this matters
Electric strikes are noisy loads. They can cause voltage sag, back EMF, and brownouts if the controller shares an unstable rail.

## Recommendations
- keep strike supply and logic supply electrically separated where practical
- use a buck converter sized with headroom
- add flyback protection where required by selected strike or driver topology
- use local decoupling near ESP32
- validate brownout behaviour during repeated unlock cycles

## Design checks
- measure idle current
- measure strike actuation current
- verify controller voltage during unlock pulse
- verify recovery after rapid repeated commands

## Future revision
Replace generic relay modules with a more robust driver stage and PCB layout designed for inductive loads.
