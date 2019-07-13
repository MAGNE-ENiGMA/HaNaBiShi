#ifndef __BOMB_H__
#define __BOMB_H__

#include "cocos2d.h"

USING_NS_CC;

//�L�����N�^�[���
class Bomb :public Node
{
public:
	float lifeTimer;

	//�����鎞��
	float lifeSpan;
	//����
	float startSpeed;
	//�ړ����x
	float speed;
	//�ړ�����
	Vec2 vector;
	//�摜
	Sprite* sprite;

	static Bomb* create(float spd =0 , Vec2 vec=Vec2(0,0));
	virtual bool init(float spd=0,Vec2 vec=Vec2(0,0));
	virtual void update(float delta);

	//�����݉�]
	Vec2 spin(Vec2 forward, float bent);

};



#endif //__BOMB_H__
