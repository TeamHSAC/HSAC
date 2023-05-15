#ifndef _ATTACK_H

#define _ATTACK_H

#define HG 0
#define AR 1
#define SG 2
#define SR 3
#define BR 4
#define HGDAMAGE 15
#define ARDAMAGE 10
#define SGDAMAGE 50
#define SRDAMAGE 100
#define BRDAMAGE 200
#define WEAPONCOUNT 5

typedef struct {
	int bullet;
	int damage;
	int magazine;

	int lastShootTime;
	int weaponSetTime;
	int reload;

	int soundFile;
} WEAPON;

typedef struct {

	int oneMagazine;
} MAGAZINE;

WEAPON weapon[WEAPONCOUNT];
MAGAZINE magazine[WEAPONCOUNT];

int selectWeapon;
int reloadFrameSync;
int isReload;
int barrelCount;

void isBarrelExplode();
void removeBarrelExplode();
void attack(int* x, int* y, int _x, int _y, char wh);
void endAttack(int* x, int* y, int _x, int _y, char wh);

#endif