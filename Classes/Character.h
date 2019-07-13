#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cocos2d.h"

USING_NS_CC;

//�L�����N�^�[���
class Character :public Node
{
protected:

	//�̗�
	CC_SYNTHESIZE(int, hp, HP);
	
	//���O
	CC_SYNTHESIZE(String*, name, NAME);
	
	//�U����
	CC_SYNTHESIZE(float, attack, ATTACK);
	
	//�h���
	CC_SYNTHESIZE(float, defence, DEFENCE);
	
	//���x
	CC_SYNTHESIZE(float, speed, SPEED);
	
	//����
	CC_SYNTHESIZE(Vec2, vector, VECTOR);

public:

	//�X�e�[�g
	enum CHARACTER_STATUS {
		NONE, STAND, WALK, ATACK, RUN, JUMP, DEAD
	};
	CHARACTER_STATUS characterStatus;


	static Character* create();
	bool virtual init();
	void virtual update(float delta);

	//�s���n
	void virtual Attack(float atk);
	void virtual Damage(float damage);



	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);

};



#endif //__CHARACTER_H__
