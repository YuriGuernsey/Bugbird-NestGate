# Device Provisioning

## Goal
Provision a fresh door controller so it can securely join a NestGate site.

## Recommended provisioning flow
1. flash controller with base firmware
2. connect over USB serial or temporary setup AP
3. assign device id, door id, and site id
4. inject WiFi credentials
5. inject broker endpoint and credential
6. inject per-device verification secret
7. register device in server
8. run a signed unlock dry-run and status check

## Minimum metadata
- device_id
- door_id
- site_id
- firmware_version
- relay_pin
- sensor_pin
- strike_mode
- offline_policy

## Provisioning methods
### USB serial
Best for early installs.
Pros:
- simple
- reliable
- no temporary wireless exposure

### Temporary setup AP
Good for installers in the field.
Pros:
- easy onboarding
Cons:
- must be tightly time-limited
- should require physical button hold

## Rules
- provisioning mode should require physical presence
- production devices should not stay in provisioning mode
- default credentials must be rotated or removed immediately

## Post-provision tests
- controller can authenticate to broker
- controller receives status requests
- controller verifies signed command
- door sensor reports expected state
- relay pulse length matches strike requirements
