import type { Request, Response } from 'express';
import { z } from 'zod';
import { publishUnlockCommand } from '../services/door.service.js';

const unlockSchema = z.object({
  doorId: z.string().min(1),
  controllerId: z.string().min(1)
});

export function unlockDoor(req: Request, res: Response) {
  const parsed = unlockSchema.safeParse(req.body);

  if (!parsed.success) {
    return res.status(400).json({ error: 'Invalid payload', details: parsed.error.flatten() });
  }

  const command = publishUnlockCommand(parsed.data);
  return res.status(202).json({ status: 'queued', command });
}
