# Logging and Audit Model

## Goals
- know who requested access
- know whether server approved it
- know whether controller executed it
- know resulting door state when available

## Event types
- auth.login.success
- auth.login.failed
- access.requested
- access.approved
- access.denied
- door.command.sent
- door.command.verified
- door.command.rejected
- door.unlocked
- door.opened
- door.closed
- device.online
- device.offline
- provisioning.started
- provisioning.completed

## Minimum fields
- timestamp
- event_type
- site_id
- door_id
- device_id
- user_id if applicable
- request_id
- result
- metadata

## Retention
Define retention per deployment:
- short-term operational logs
- longer-term audit logs

## Privacy
Do not log secrets, raw passwords, or full tokens.
Mask sensitive identifiers in installer-facing output where practical.
