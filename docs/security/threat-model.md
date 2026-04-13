# Threat Model

## Assets we are protecting
- physical door access
- device keys and signing secrets
- admin credentials
- audit logs
- access schedules and permission rules

## Trust boundaries
1. user device to NestGate server
2. server to door controller
3. controller to physical lock hardware
4. maintainer or installer workstation to deployed system

## Primary threats

### Replay attacks
Attacker captures an unlock command and replays it later.
Mitigation:
- short-lived commands
- nonce or request id
- server timestamp validation
- controller rejection of duplicates within replay window

### Man in the middle
Attacker intercepts traffic between server and door controller.
Mitigation:
- TLS for broker and API traffic
- signed payloads
- pinned broker certificate where possible

### Device impersonation
Rogue ESP32 pretends to be a valid door.
Mitigation:
- per-device credentials
- provisioning approval flow
- device allowlist on server

### Physical tampering
Attacker opens enclosure, shorts relay, or accesses debug pins.
Mitigation:
- tamper switch in future hardware revision
- potting or shield for critical traces
- disable or protect flashing headers in production
- secure enclosure fasteners

### Credential leakage
Secrets leak from repository, backups, or installer machines.
Mitigation:
- never commit secrets
- rotate keys after install
- use per-site secrets, not global ones

### Broker abuse
Unauthorized publisher sends unlock messages over MQTT.
Mitigation:
- dedicated broker credentials
- ACLs scoped by topic
- controller verifies command signature before actuation

### Power and network failures
System behaves unsafely during outage.
Mitigation:
- explicit fail-open or fail-closed policy per door
- UPS for server and network if required
- documented offline behaviour

## Security goals
- no user device directly unlocks a door
- no single captured packet should unlock later
- controllers should execute only server-authorized, time-bound actions
- logs should be reliable enough for incident review
