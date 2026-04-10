#pragma once

class RelayController {
public:
  void begin();
  void unlock();
  void loop();

private:
  bool unlocking = false;
  unsigned long unlockStartedAt = 0;
};
