#!/usr/bin/env bash
set -euo pipefail

if ! command -v pio >/dev/null 2>&1; then
  echo "PlatformIO is required"
  exit 1
fi

PORT="${1:-/dev/ttyUSB0}"
echo "Flashing ESP32 on ${PORT}"
cd "$(dirname "$0")/../node"
pio run -t upload --upload-port "${PORT}"
