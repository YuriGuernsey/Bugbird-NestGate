import mqtt, { MqttClient } from 'mqtt';
import { env } from '../config/env.js';

class MqttService {
  private client: MqttClient | null = null;

  async connect() {
    if (this.client) return;

    this.client = mqtt.connect(env.MQTT_URL, {
      username: env.MQTT_USERNAME || undefined,
      password: env.MQTT_PASSWORD || undefined
    });

    await new Promise<void>((resolve, reject) => {
      this.client?.once('connect', () => resolve());
      this.client?.once('error', reject);
    });
  }

  publish(topic: string, payload: object) {
    if (!this.client) throw new Error('MQTT client not connected');
    this.client.publish(topic, JSON.stringify(payload), { qos: 1 });
  }
}

export const mqttService = new MqttService();
