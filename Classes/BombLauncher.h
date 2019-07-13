#ifndef __BOMB_LAUNCHER_H__
#define __BOMB_LAUNCHER_H__

#include "cocos2d.h"
#include "Bomb.h"

USING_NS_CC;

//キャラクター基底
class BombLauncher :public Bomb
{
public:
	Vector<Bomb*> bombs;

	Vec2 vec;

	float bent = 0;

	static BombLauncher* create();

	bool init();
	void update(float delta);

};



#endif //__BOMB_LAUNCHER_H__
