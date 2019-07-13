#ifndef __BATTLE_SONIC_H__
#define __BATTLE_SONIC_H__

#include "cocos2d.h"
#include "Character.h"

USING_NS_CC;

//キャラクター基底
class BattleSonic :public Character
{
public:

	static BattleSonic* create();
	bool init();
	void update(float delta);

	//行動系
	void Attack(float atk);
	void Damage(float damage);



	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);

};



#endif //__CHARACTER_H__
