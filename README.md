# Bugbird NestGate

Bugbird NestGate is an open source, security first access control system built with ESP32 door controllers and a Raspberry Pi server.

NestGate gives you full ownership of your access infrastructure without proprietary lock vendors, cloud dependencies, or opaque firmware.

This project is designed for real buildings, not demos.

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
```
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

## Repository Structure
```
.
├── server/ Raspberry Pi backend and dashboard
├── node/ ESP32 firmware
├── docs/ Architecture, wiring, deployment
├── CONTRIBUTING.md
├── SECURITY.md
└── LICENSE
```

---

## Want Bugbird to Set This Up for You?

NestGate is open source, but secure deployment takes experience.

If you want Bugbird to design, install, configure, and support NestGate for your business, contact us.

Professional setup and ongoing support is a paid service.

