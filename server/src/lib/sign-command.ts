import crypto from 'crypto';
import { env } from '../config/env.js';

type SignableCommand = {
  version: number;
  commandId: string;
  doorId: string;
  controllerId: string;
  action: 'unlock';
  issuedAt: number;
  expiresAt: number;
  nonce: string;
};

export function signCommand(payload: SignableCommand): string {
  const canonical = [
    payload.version,
    payload.commandId,
    payload.doorId,
    payload.controllerId,
    payload.action,
    payload.issuedAt,
    payload.expiresAt,
    payload.nonce
  ].join('.');

  return crypto.createHmac('sha256', env.COMMAND_SIGNING_KEY).update(canonical).digest('base64');
}
