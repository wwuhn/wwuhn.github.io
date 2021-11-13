#include "game.h"
Weapon::Weapon(string wnam, int f, double k):wname(wnam),force(f),killRange(k) {}
Weapon::Weapon(const Weapon &w):wname(w.wname),force(w.force),killRange(w.killRange) {}
string Weapon::getWname()
{
    return wname;
}
//∑µªÿ…±…À¡¶
int Weapon::getForce()
{
    return force;
}
//∑µªÿ…±…Àæ‡¿Î
double Weapon::getKillRange()
{
    return killRange;
}
void Weapon::setWeapon(string name,int f,double r)
{
    wname=name;
    force=f;
    killRange=r;
}
