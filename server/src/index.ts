import { createApp } from './app.js';
import { env } from './config/env.js';
import { mqttService } from './services/mqtt.service.js';

async function bootstrap() {
  await mqttService.connect();

  const app = createApp();
  app.listen(env.PORT, () => {
    console.log(`NestGate server listening on port ${env.PORT}`);
  });
}

bootstrap().catch((error) => {
  console.error('Failed to start server', error);
  process.exit(1);
});
