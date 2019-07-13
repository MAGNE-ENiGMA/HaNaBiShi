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

	Sprite* backGrouind = Sprite::create("background.jpg");
	backGrouind->setPosition(designResolutionSize*0.5f);
	addChild(backGrouind);
/*
	for (int i = 0; i < 3; i++) 
	{	
		Bomb* bomb = BombLauncher::create();
		bomb->setPosition(i*100 + 50, 50);
		addChild(bomb);
	}*/


	//タッチ判定
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// 対象のイベントが実行された後、下位のイベントは発動されなくする
	//listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(TestFieldScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(TestFieldScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(TestFieldScene::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
};

bool TestFieldScene::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
	Bomb* bomb = BombLauncher::create();
	bomb->setPosition(pTouch->getLocation());
	addChild(bomb);
	return true;
};


void TestFieldScene::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{

};


void TestFieldScene::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{

};


