#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cocos2d.h"

USING_NS_CC;

//キャラクター基底
class Character :public Node
{
protected:

	//体力
	CC_SYNTHESIZE(int, hp, HP);
	
	//名前
	CC_SYNTHESIZE(String*, name, NAME);
	
	//攻撃力
	CC_SYNTHESIZE(float, attack, ATTACK);
	
	//防御力
	CC_SYNTHESIZE(float, defence, DEFENCE);
	
	//速度
	CC_SYNTHESIZE(float, speed, SPEED);
	
	//方向
	CC_SYNTHESIZE(Vec2, vector, VECTOR);

public:

	//ステート
	enum CHARACTER_STATUS {
		NONE, STAND, WALK, ATACK, RUN, JUMP, DEAD
	};
	CHARACTER_STATUS characterStatus;


	static Character* create();
	bool virtual init();
	void virtual update(float delta);

	//行動系
	void virtual Attack(float atk);
	void virtual Damage(float damage);



	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);

};



#endif //__CHARACTER_H__
