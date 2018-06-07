void goDockWithItem(int itemID){
    float subtractVal; //stuff subtracted from magnituide of final vector (min val + average of 2 points)
    float currentVec[3];//Current Vector to a point
    float targetPos[3];//x,y,z coordinates of the final position
    
    
    if (itemID == 0 || itemID == 1){
        subtractVal = 0.162;
    } else if (itemID == 2 || itemID == 3){
        subtractVal = 0.149;
    } else if (itemID == 4 || itemID == 5){
        subtractVal = 0.135;
    }
    
    subtractVal += 0.02; //Adds radius of sphere to the subtracted part
    
    game.getItemLoc(targetPos, itemID);
    
    mathVecSubtract(currentVec, targetPos, myPos, 3);//Vector to location
    
    float forcesTest[3];
    forcesTest[0] = player.vel[0]*=-1;
    forcesTest[1] = player.vel[1]*=-1;
    forcesTest[2] = player.vel[2]*=-1;
    
    float dir[3];
    dir[0] = targetPos[0];
    dir[1] = targetPos[1];
    dir[2] = targetPos[2];
    mathVecNormalize(dir, 3);
    
    if(distanceToStub(myPos, targetPos) > subtractVal + 0.05){
        api.setPositionTarget(targetPos);
        api.setAttitudeTarget(dir);
    }else{
        DEBUG(("Docking"));
        api.setForces(forcesTest);
        game.dockItem();
    }
    
}
