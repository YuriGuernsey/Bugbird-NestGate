export type DoorAction = 'unlock';

export interface UnlockCommand {
  version: number;
  commandId: string;
  doorId: string;
  controllerId: string;
  action: DoorAction;
  issuedAt: number;
  expiresAt: number;
  nonce: string;
  signature: string;
}
