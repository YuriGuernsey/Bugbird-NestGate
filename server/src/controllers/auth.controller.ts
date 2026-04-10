import type { Request, Response } from 'express';
import { issueToken } from '../services/auth.service.js';

export function login(_req: Request, res: Response) {
  const token = issueToken('demo-admin');
  res.json({ token });
}
