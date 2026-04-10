# Bugbird NestGate

Bugbird NestGate is an open source, security first access control system built with ESP32 door controllers and a Raspberry Pi server.

NestGate gives you full ownership of your access infrastructure without proprietary lock vendors, cloud dependencies, or opaque firmware.

This project is designed for real buildings, not demos.

### Door Scanner 3D Model

![3D Model Of Door Scanner](/scanner_model.png "Door Scanner")

---

## What NestGate Is

NestGate is a server authoritative access system.

Phones, fobs, and browsers never unlock doors directly.

Instead:
- Users authenticate with the NestGate server
- The server evaluates permissions and schedules
- Door controllers execute only signed, short lived commands

This eliminates replay attacks, spoofing, and device impersonation.

---

## Core Features

- Centralised access control
- Clearance levels and door groups
- Time based schedules
- Full audit logs
- NFC fob support
- Web based unlock via QR
- Local infrastructure
- Hardware you own
- Software you can audit

---

## Architecture Overview
```text
User Phone
|
| HTTPS (auth + unlock request)
v
Raspberry Pi Server
|
| MQTT over TLS (signed commands)
v
ESP32 Door Controller
|
v
Electric Strike
```

The ESP32 never trusts user devices.
It only trusts the server.

---

## Hardware Reference Added

This repo now has a hardware documentation pack for the first working door controller prototype:

- `docs/hardware/README.md`
- `docs/hardware/bom.csv`
- `docs/hardware/system.config.json`
- `docs/hardware/electrical-connections.json`
- `docs/hardware/mechanical-connections.json`
- `docs/hardware/build-guide.md`
- `docs/architecture/hardware-overview.md`

These files cover the bill of materials, enclosure assembly, power flow, wiring relationships, and first-pass bring-up steps for a WiFi-based electric strike controller with a Raspberry Pi server.

---

## Repository Structure
```text
.
├── server/                      Raspberry Pi backend and dashboard
├── node/                        ESP32 firmware
├── docs/
│   ├── architecture/            System and hardware architecture docs
│   └── hardware/                BOM, wiring, build guide, and prototype files
├── CONTRIBUTING.md
├── SECURITY.md
└── LICENSE
```

---

## Prototype Hardware Stack

Current prototype hardware documented in this repo:

- ESP32-WROOM-32D door controller
- Raspberry Pi 4 main control server
- 12V electric strike
- 12V to 5V buck converter
- Single channel relay module
- Door position reed sensor
- 3D printed scanner enclosure and sensor mounts

This is the documented prototype baseline, not the final production hardware.

---

## Recommended Next Repo Improvements

- Add pin accurate wiring diagrams for the chosen ESP32 board revision
- Add a `node/config.example.json` matching the server topic layout
- Add a signed command schema shared by `server/` and `node/`
- Add install photos and enclosure STL exports
- Add a commissioning checklist for real door installs
- Add a threat model document for replay, relay, tamper, and offline states

---

## Important Prototype Notes

The attached hardware pack is a good starting point, but a few items should be tightened before install in a real building:

- Prefer an opto isolated relay or MOSFET driver over a generic hobby relay module
- Add fuse protection on the 12V strike line
- Add flyback protection if the strike or relay board does not already include it
- Use a supervised door contact if you want tamper aware state sensing
- Define fail secure vs fail safe behaviour clearly in docs and firmware
- Document offline behaviour when WiFi or MQTT is unavailable

---

## Want Bugbird to Set This Up for You?

NestGate is open source, but secure deployment takes experience.

If you want Bugbird to design, install, configure, and support NestGate for your business, contact us.

Professional setup and ongoing support is a paid service.
