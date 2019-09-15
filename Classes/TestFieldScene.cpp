#include "TestFieldScene.h"
TestFieldScene* TestFieldScene::createScene() 
{
	TestFieldScene *pRet = new TestFieldScene();
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

bool TestFieldScene::init()
{
	if (!Scene::init())return false;

	Layer* la = LayerColor::create(Color4B::WHITE);
	addChild(la);

	Sprite* backGrouind = Sprite::create("background.png");
	backGrouind->setPosition(designResolutionSize*0.5f);
	addChild(backGrouind);
/*
	for (int i = 0; i < 3; i++) 
	{	
		Bomb* bomb = BombLauncher::create();
		bomb->setPosition(i*100 + 50, 50);
		addChild(bomb);
	}*/


	player = Character::create();
	addChild(player,5);
	player->setPosition(300, 100);

	//bike = Bike::create();
	//addChild(bike);
	//bike->setPosition(300, 100);

	CraftSquare* craftSquare = CraftSquare::create();
	//addChild(craftSquare);
	craftSquare->setPosition(500, 500);

	//タッチ判定
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// 対象のイベントが実行された後、下位のイベントは発動されなくする
	//listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(TestFieldScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(TestFieldScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(TestFieldScene::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	EventListenerKeyboard* keyboard = EventListenerKeyboard::create();
	keyboard->onKeyPressed = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* keyEvent)
	{
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		{
			cocos2d::log("left");
		}
		else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		{
			cocos2d::log("right");
		}
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboard, this);

	return true;
};

void TestFieldScene::update(float delta) 
{

}

bool TestFieldScene::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
	if (bike != nullptr)
	{
		if (pTouch->getLocation().x > designResolutionSize.width / 2)
		{
			bike->drive(true);
		}
		else
		{
			bike->brake(true);
		}
	}
	return true;
};


void TestFieldScene::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
	if (player != nullptr) {
		player->setVECTOR(pTouch->getDelta());
	}
};


void TestFieldScene::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
	if (bike != nullptr) {
		bike->drive(false);
	}
};


