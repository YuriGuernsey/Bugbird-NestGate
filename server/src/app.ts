import cors from 'cors';
import express from 'express';
import helmet from 'helmet';
import { env } from './config/env.js';
import { authRoutes } from './routes/auth.routes.js';
import { doorRoutes } from './routes/door.routes.js';

export function createApp() {
  const app = express();

  app.use(helmet());
  app.use(cors({ origin: env.ALLOWED_ORIGIN }));
  app.use(express.json());

  app.get('/health', (_req, res) => {
    res.json({ ok: true, service: 'nestgate-server' });
  });

  app.use('/auth', authRoutes);
  app.use('/doors', doorRoutes);

  return app;
}
