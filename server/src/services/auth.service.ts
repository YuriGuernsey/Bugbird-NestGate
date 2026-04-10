import jwt from 'jsonwebtoken';
import { env } from '../config/env.js';

export function issueToken(userId: string) {
  return jwt.sign({ sub: userId, role: 'admin' }, env.JWT_SECRET, { expiresIn: '1h' });
}
