#include "BombLauncher.h"

BombLauncher* BombLauncher::create() {
	{
		BombLauncher *pRet = new BombLauncher();
		if (pRet && pRet->init())
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			delete pRet;
			pRet = nullptr;
			return nullptr;
		}
	}
}

 bool BombLauncher::init()
{
	if (!Node::init())
	{
		return false;
	}

	Sprite* sp = Sprite::create("black.png");
	addChild(sp);

	speed = random() % 100 / 100 + 2.0f;

	vector = Vec2(0, 1);

	lifeSpan = (float)(random() % 100) / 50.0f * 0.8f + 3.0f;

	lifeTimer = 0;

	bent = 0;

	scheduleUpdate();

	return true;
}

 void BombLauncher::update(float delta)
 {
	 bent += 12.0f;
	 if (bent >= 360.0f) {
		 bent = 0.0f;
	 }
	 log("forward=[%0.2f,%0.2f]", vector.x, vector.y);

	 setPosition(speed* spin(vector, bent)+ getPosition());

	 lifeTimer += delta;

	 if (lifeTimer >= lifeSpan) {
		 for (int i = 0; i < 18; i++)
		 {
			 float ax = cos(i) - sin(i);
			 float ay = sin(i) + cos(i);

			 Vec2 vec = Vec2(ax*M_PI*18, ay*M_PI*18);
			 vec.normalize();

			 Bomb* bomb = Bomb::create(i % 5 + 1, Vec2(vec));
			 bomb->setPosition(getPosition());
			 getParent()->addChild(bomb);
		 }
		 removeAllChildrenWithCleanup(true);
		 unscheduleUpdate();
	 }
 }
