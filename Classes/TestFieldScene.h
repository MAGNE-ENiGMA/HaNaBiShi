#ifndef __TEST_FIELD_SCENE_H__
#define __TEST_FIELD_SCENE_H__

#include "cocos2d.h"
#include "Bomb.h"
#include "BombLauncher.h"
#include "GameConfig.h"

using namespace cocos2d;

class TestFieldScene :public Scene {
public:
	static TestFieldScene* createScene();
	bool init();


	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);


};


#endif // !__TEST_FIELD_H__
