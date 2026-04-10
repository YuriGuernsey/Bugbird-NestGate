# Contributing to Bugbird NestGate

Thanks for contributing.

## Before You Start

Please:
- read the architecture and security docs
- avoid pushing insecure shortcuts into auth or unlock flows
- open an issue before large design changes

## Development Setup

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
```

## Pull Request Guidelines

- keep PRs focused
- include tests where possible
- update docs when behaviour changes
- describe hardware impact clearly if pins, power, or timing changes
- never commit secrets or production keys

## Security Sensitive Areas

Please be extra careful when editing:
- command signing
- MQTT topics
- offline unlock logic
- cached permissions
- audit logging

## Recommended First Issues

- docs improvements
- hardware diagrams
- integration tests
- admin dashboard polish
- additional ESP32 drivers
