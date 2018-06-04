#define PLAYER 1
#define ENEMY 2
#define PI 3.14159265359
#define BLUE_LARGE 0
#define BLUE_MEDIUM 2
#define BLUE_SMALL 4

#define RED_LARGE 1
#define RED_MEDIUM 3
#define RED_SMALL 5


float myState[12];
float myPos[3];
float myVelocity[3];

float enemyPos[3];
float enemyState[12];
float enemyVelocity[3];

typedef enum state {
    PLACING_SPS,
    DOCKING, 
    ASSEMBLY_DROPPING,
} states;

typedef struct sphere {
    int id;
    int blueOrRed; 
    float ZRState[12];
    float pos[3];
    float vel[3];
} Sphere;

Sphere player; 
Sphere enemy;

void init() {
    
}

void loop() {
    //move(target);
}

float angleBetween(float vec1[3], float vec2[3]) {
    int mag1 = mathVecMagnitude(vec1, 3);
    int mag2 = mathVecMagnitude(vec2, 3);
    float angle = acosf(mathVecInner(vec1, vec2, 3)/(mag1 * mag2));
    return angle;
}

void updateInfo() {
    api.getMyZRState(player.ZRState);
    api.getOtherZRState(enemy.ZRState);
    for (int i = 0; i < 3; i++) {
        player.pos[i] = player.ZRState[i];
        enemy.pos[i] = enemy.ZRState[i];
        player.vel[i] = player.ZRState[i+3];
        enemy.vel[i] = enemy.ZRState[i+3];
    }
}
