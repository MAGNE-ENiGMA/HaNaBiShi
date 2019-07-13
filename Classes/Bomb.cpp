#include "Bomb.h"

Bomb* Bomb::create(float spd ,Vec2 vec) {
	{
		Bomb *pRet = new Bomb();
		if (pRet && pRet->init(spd,vec))
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

bool Bomb::init(float spd,Vec2 vec)
{
	if (!Node::init())
	{
		return false;
	}

	sprite = Sprite::create("white.png");
	addChild(sprite);

	sprite->setColor(Color3B(random() % 127 + 127, random() % 127 + 127, random() % 127 + 127));

	speed = random() % 100 / 100 + spd;
	startSpeed = speed;

	vector.normalize();

	lifeSpan = (float)(random()%100) / 50.0f * 0.8f + 3.0f;

	lifeTimer = 0;

	vector = vec;

	scheduleUpdate();

	return true;
}

void Bomb::update(float delta)
{
	setRotation(lifeTimer*1000);

	setPosition(speed*vector+getPosition());

	vector.y -= 0.005f;
	speed -= float(random() % 10) /300.0f;


	if (speed <= 0.0f) {
		speed = 0.0f;
	}

	sprite->setOpacity((speed/startSpeed)*255);


	lifeTimer += delta;

	if (lifeTimer >= lifeSpan) {
		removeAllChildrenWithCleanup(true);		
		unscheduleUpdate();
	}
}

//êçùÜÇ›âÒì]
Vec2 Bomb::spin(Vec2 forward, float bent) 
{
	float ax = cos(bent) - sin(bent);
	float ay = sin(bent) + cos(bent);

	log("%0.2f,%0.2f", ax+forward.x, forward.y);

	return Vec2(ax, 0)+forward;
}

