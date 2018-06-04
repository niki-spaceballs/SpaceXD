bool dockWithItem(int itemID) {
  // Docking code. Check requirements such as velocity and attitudeDirection. Use Rotate(float[3] attitudeVec)
  // if it doesn't meet the radian requirements. Returns true or false. True = 1. False = 0. 
  float vecBetween[3];
  float subtractVal; 
  mathVecSubtract(vecBetween, enemy.pos, player.pos, 3);
  if (itemID == BLUE_LARGE || itemID == RED_LARGE) {
      subtractVal = 0.162;
  } else if (itemID == BLUE_MEDIUM || itemID == RED_MEDIUM) {
      subtractVal = 0.149;
  } else if (itemID == BLUE_SMALL || itemID == BLUE_SMALL) {
      subtractVal = 0.135;
  }
  float magnitude = mathVecMagnitude(vecBetween, 3);
  float angle = atanf(vecBetween[1]/vecBetween[0]);
  angle*=(180/PI)
  int canDock;
  return canDock
}
