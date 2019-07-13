#include "BattleSonic.h"

BattleSonic* BattleSonic::create()
{
	BattleSonic *pRet = new BattleSonic ();
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

};

bool BattleSonic::init()
{
	if (!Node::init()) 
	{
		return false;
	}

	return true;
};

void  BattleSonic::update(float delta) 
{

};

//çsìÆån
void BattleSonic::Attack(float atk) 
{

};

void BattleSonic::Damage(float damage) 
{

};

bool BattleSonic::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) 
{
	return true;
};

void BattleSonic::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) 
{

};

void BattleSonic::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) 
{

};
