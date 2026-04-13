#!/usr/bin/env bash
set -euo pipefail

sudo apt update
sudo apt install -y docker.io docker-compose-plugin mosquitto mosquitto-clients git

sudo systemctl enable docker
sudo systemctl enable mosquitto

echo "Base Pi setup complete"
echo "Next:"
echo "1. copy server env"
echo "2. provision TLS certs"
echo "3. configure broker ACLs"
