//
//  ChatScene.h
//  GeoChat
//
//  Created by 橋本 大輔 on 4/4/14.
//
//

#ifndef __GeoChat__ChatScene__
#define __GeoChat__ChatScene__

#include "cocos2d.h"

class ChatScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    bool onTouchBegan(cocos2d::Ref* pSender);
    void onTouchEnded(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(ChatScene);
};

#endif /* defined(__GeoChat__ChatScene__) */
