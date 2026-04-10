#pragma once

#include <Arduino.h>

String canonicaliseCommand(const String& commandId,
                           const String& doorId,
                           const String& controllerId,
                           const String& action,
                           long issuedAt,
                           long expiresAt,
                           const String& nonce,
                           int version);

bool verifySignature(const String& expectedBase64, const String& payload);
