#include "Character.h"

Character* Character::create() 
{
	Character *pRet = new Character();
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

bool Character::init() 
{
	if (!Node::init())
	{
		return false;
	}

	Sprite* sp = Sprite::create("black.png");
	addChild(sp);

	speed = random() % 100;
	speed /= 10;


	while (vector == Vec2::ZERO) 
	{
		vector.x = random() % 300 - 100;
		vector.y = random() % 300 - 100;
	}
	vector.normalize();

	scheduleUpdate();


	return true;
}

void Character::update(float delta) 
{
	setPosition(getPosition() + vector*speed);
	setRotation(getRotation() + 3);

	if (getPositionY() >= 600) {
		setPosition(random() % 800, 0);
	}
	if (getPositionY()<= - 200) {
		setPosition(random()%800, 500);
	}
}

void Character::Attack(float atk) 
{

}

void Character::Damage(float damage) 
{
	hp -= damage;
}

bool Character::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
	return true;
};

void Character::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{

};

void Character::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{

};



