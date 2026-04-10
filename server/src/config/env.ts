import dotenv from 'dotenv';
import { z } from 'zod';

dotenv.config();

const envSchema = z.object({
  PORT: z.coerce.number().default(3000),
  NODE_ENV: z.enum(['development', 'test', 'production']).default('development'),
  JWT_SECRET: z.string().min(8),
  MQTT_URL: z.string().min(1),
  MQTT_USERNAME: z.string().optional().default(''),
  MQTT_PASSWORD: z.string().optional().default(''),
  COMMAND_SIGNING_KEY: z.string().min(8),
  ALLOWED_ORIGIN: z.string().default('*')
});

export const env = envSchema.parse(process.env);
