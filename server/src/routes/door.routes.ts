import { Router } from 'express';
import { unlockDoor } from '../controllers/door.controller.js';
import { requireAuth } from '../middleware/require-auth.js';

export const doorRoutes = Router();
doorRoutes.post('/unlock', requireAuth, unlockDoor);
