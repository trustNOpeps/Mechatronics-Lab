#ifndef TRUSTNOPEPS_MECHATRONICS_CONTROLLER_H
#define TRUSTNOPEPS_MECHATRONICS_CONTROLLER_H

// Example learning threshold; not calibrated against physical hardware.
constexpr int kDetectionThresholdCm = 20;

inline int targetServoAngle(int distanceCm, bool echoValid) {
  if (!echoValid || distanceCm <= 0) return 0;
  return distanceCm <= kDetectionThresholdCm ? 90 : 0;
}

#endif
