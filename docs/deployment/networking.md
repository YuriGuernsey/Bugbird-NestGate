# Networking Guide

## Recommended topology
- Raspberry Pi server on trusted LAN
- MQTT broker on same host or same trusted subnet
- door controllers on isolated IoT VLAN where possible
- admin dashboard restricted to admin subnet or VPN

## IP strategy
- server: static IP or DHCP reservation
- broker: static IP or DNS name
- controllers: DHCP reservation preferred for easier inventory

## Firewall guidance
Allow only what is needed:
- HTTPS to server admin/API
- MQTT over TLS from controllers to broker
- SSH only from trusted admin network

Block:
- direct inbound access from public internet unless behind VPN or reverse proxy with hardening
- controller-to-controller traffic unless required

## DNS
Use stable internal DNS names if possible:
- nestgate.local
- mqtt.nestgate.local

## Remote access
Prefer:
- WireGuard or equivalent VPN
Avoid:
- exposing admin UI directly to the internet without additional controls

## Reliability
- use decent WiFi coverage for controller locations
- avoid weak signal at metal doors or service entrances
- consider Ethernet-capable nodes for difficult environments
