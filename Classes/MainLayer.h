#pragma once

#include "cocos2d.h"

class MainLayer : public cocos2d::Layer
{
public:
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainLayer);
};

