#include "signature.h"
#include "config.h"

String canonicaliseCommand(const String& commandId,
                           const String& doorId,
                           const String& controllerId,
                           const String& action,
                           long issuedAt,
                           long expiresAt,
                           const String& nonce,
                           int version) {
  return String(version) + "." + commandId + "." + doorId + "." + controllerId + "." + action + "." + String(issuedAt) + "." + String(expiresAt) + "." + nonce;
}

bool verifySignature(const String& expectedBase64, const String& payload) {
  // TODO: replace with a real HMAC-SHA256 implementation for production.
  // This placeholder exists so the project compiles while the security spec is wired in.
  (void)payload;
  return expectedBase64.length() > 0;
}
