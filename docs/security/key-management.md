# Key Management

## Principles
- every door controller gets its own credential
- secrets are generated per site
- compromise of one node should not compromise all nodes

## Key types
- API signing secret for server-side session and admin operations
- per-controller device secret for command verification
- broker username and password or client certificate
- TLS private keys for HTTPS and MQTT

## Generation
Generate secrets on a trusted admin workstation during installation or provisioning.

Suggested minimums:
- HMAC secrets: 32 random bytes minimum
- JWT secret: 32 random bytes minimum
- TLS: modern key sizes and current best practice ciphers

## Storage
- server secrets in environment variables or secret manager
- device secrets flashed at provisioning time
- never store secrets in public repo files
- never reuse demo credentials in production

## Rotation
Rotate:
- immediately after suspected compromise
- after maintainer turnover
- during periodic security maintenance

Recommended capability:
- server supports two active controller secrets during rotation window
- controller receives new secret only after authenticated maintenance action

## Revocation
If a device is stolen or compromised:
1. disable the device record in server
2. revoke broker access
3. rotate relevant secret
4. review logs for suspicious unlocks

## Future improvement
Move from shared HMAC keys to asymmetric signing or mTLS device identity where practical.
