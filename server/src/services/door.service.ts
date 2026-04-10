import { randomUUID } from 'crypto';
import { signCommand } from '../lib/sign-command.js';
import { mqttService } from './mqtt.service.js';
import type { UnlockCommand } from '../types/domain.js';

export function publishUnlockCommand(input: { doorId: string; controllerId: string }): UnlockCommand {
  const issuedAt = Math.floor(Date.now() / 1000);
  const expiresAt = issuedAt + 30;

  const unsigned = {
    version: 1,
    commandId: randomUUID(),
    doorId: input.doorId,
    controllerId: input.controllerId,
    action: 'unlock' as const,
    issuedAt,
    expiresAt,
    nonce: randomUUID().replace(/-/g, '')
  };

  const command: UnlockCommand = {
    ...unsigned,
    signature: signCommand(unsigned)
  };

  mqttService.publish(`nestgate/door/${input.controllerId}/command`, command);
  return command;
}
