# Security Policy

Bugbird NestGate is a security-sensitive access control project.
Please do not open public issues for vulnerabilities that could put real installs at risk.

## Supported versions

| Version | Supported |
| --- | --- |
| main | Yes |
| older snapshots | No |

## How to report a vulnerability

Send a private report to the project maintainers with:
- summary of the issue
- affected component
- reproduction steps
- impact
- suggested fix if available

Until a dedicated security mailbox exists, open a GitHub issue asking for a private contact path without posting exploit details.

## What we aim to do

- acknowledge receipt within 7 days
- assess severity
- work on a fix before public disclosure
- publish a changelog entry when patched

## Scope

Security reports are especially welcome for:
- command signing and verification
- MQTT/TLS configuration
- provisioning flows
- credential storage
- relay and strike control logic
- offline access behaviour
- audit log integrity

## Out of scope

- theoretical issues with no realistic exploit path
- local lab misconfiguration with secrets committed in plain text by the installer
- denial of service caused by physically cutting power or network cables
