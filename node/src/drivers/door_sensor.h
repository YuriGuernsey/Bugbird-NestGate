#pragma once

class DoorSensor {
public:
  void begin();
  bool isOpen() const;
};
