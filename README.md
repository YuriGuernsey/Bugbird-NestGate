# Bugbird NestGate

Bugbird NestGate is an open source, security first access control system built with ESP32 door controllers and a Raspberry Pi server.

NestGate gives you full ownership of your access infrastructure without proprietary lock vendors, cloud dependencies, or opaque firmware.

This project is designed for real buildings, not demos.

## What NestGate Is

NestGate is a server authoritative access system.

Phones, fobs, and browsers never unlock doors directly.

Instead:
- users authenticate with the NestGate server
- the server evaluates permissions and schedules
- door controllers execute only signed, short lived commands

## Core Features

- centralised access control
- clearance levels and door groups
- time based schedules
- full audit logs
- NFC fob support
- web based unlock via QR
- local infrastructure
- hardware you own
- software you can audit

## Repository Structure

```text
.
├── docs/
│   ├── api/
│   ├── architecture/
│   ├── deployment/
│   ├── hardware/
│   ├── security/
│   └── testing/
├── server/
│   ├── src/
│   └── scripts/
├── node/
│   ├── include/
│   └── src/
├── examples/
├── .github/
├── CONTRIBUTING.md
├── CODE_OF_CONDUCT.md
├── SECURITY.md
└── docker-compose.yml
```

## Quick Start

### Server

```bash
cd server
cp .env.example .env
npm install
npm run dev
```

### ESP32 firmware

```bash
cd node
cp include/config.example.h include/config.h
pio run
pio run --target upload
```

## Current Status

This scaffold gives you:
- the open source project structure
- a Node.js + TypeScript server skeleton
- an ESP32 PlatformIO firmware skeleton
- protocol, security, deployment, and testing docs

You still need to wire in your real hardware pin numbers, production secrets, and final auth flows.

## Open Source Project Standards

This repo includes:
- contribution guidelines
- security reporting guidance
- issue and PR templates
- a CI workflow
- architecture and protocol docs

## Hardware

See `docs/hardware/` for the prototype hardware pack, BOM, and build guide.

## Want Bugbird to Set This Up for You?

NestGate is open source, but secure deployment takes experience.

If you want Bugbird to design, install, configure, and support NestGate for your business, contact Bugbird.
