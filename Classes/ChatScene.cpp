//
//  ChatScene.cpp
//  GeoChat
//
//  Created by 橋本 大輔 on 4/4/14.
//
//


#include "ChatScene.h"

#include <gui/CCControlExtension/CCScale9Sprite.h>
#include <gui/CCControlExtension/CCControlButton.h>
#include <ccMacros.h>

USING_NS_CC;
using namespace cocos2d;

#define COCOS2D_DEBUG 1

cocos2d::Scene* ChatScene::createScene()
{
    CCLOG ("ChatScene::createScene");
    
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = ChatScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ChatScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    // 一番上のレイヤー
    auto uLayer = Layer::create();
    addChild(uLayer);
    
    // テキスト
    auto uLabel = Label::create();
    uLabel->setString("Hello Cocos!");
    uLabel->setFontName("Marker Felt");
    uLabel->setFontSize(30);
    uLabel->setColor(Color3B(159, 168, 176));
    uLabel->setPosition(Point(visibleSize.width / 2, visibleSize.height * 3 / 4));
    uLayer->addChild(uLabel);
    
    // ボタン
    extension::Scale9Sprite* sprite = extension::Scale9Sprite::create("button.jpg");
    LabelTTF* label = LabelTTF::create("小さいボタン", "Arial", 24);
    extension::ControlButton* pCCButton = extension::ControlButton::create(label, sprite);
    pCCButton->setPosition(Point(visibleSize.width / 2, visibleSize.height / 4));
    pCCButton->setPreferredSize(Size(30, 30));
    uLayer->addChild(pCCButton);
    
    auto listener = EventListenerTouchOneByOne::create();
    
    listener->onTouchBegan = CC_CALLBACK_1(ChatScene::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_1(ChatScene::onTouchEnded, this);
    
    sprite->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 3);
    
    return true;
}

bool ChatScene::onTouchBegan(Ref* pSender)
{
    CCLOG ("ChatScene::onTouchBegan");
    return true;
}


void ChatScene::onTouchEnded(Ref* pSender)
{
    CCLOG ("ChatScene::onTouchEnded");
}
