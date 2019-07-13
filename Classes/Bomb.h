#ifndef __BOMB_H__
#define __BOMB_H__

#include "cocos2d.h"

USING_NS_CC;

//キャラクター基底
class Bomb :public Node
{
public:
	float lifeTimer;

	//消える時間
	float lifeSpan;
	//初速
	float startSpeed;
	//移動速度
	float speed;
	//移動方向
	Vec2 vector;
	//画像
	Sprite* sprite;

	static Bomb* create(float spd =0 , Vec2 vec=Vec2(0,0));
	virtual bool init(float spd=0,Vec2 vec=Vec2(0,0));
	virtual void update(float delta);

	//錐揉み回転
	Vec2 spin(Vec2 forward, float bent);

};



#endif //__BOMB_H__
