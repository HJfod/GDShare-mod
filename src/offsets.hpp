#pragma once

#ifndef INCLUDE_SUBMODULES
#define INCLUDE_SUBMODULES

#pragma warning( push, 0 )
#include <GDMake.h>
#include <GUI/CCControlExtension/CCScale9Sprite.h>
#include <nfd.h>
#pragma warning( pop )

template<typename T>
static T getChild(cocos2d::CCNode* x, int i) {
    return static_cast<T>(x->getChildren()->objectAtIndex(i));
}

template <typename T, typename R>
T as(R const v) { return reinterpret_cast<T>(v); }

inline std::string operator"" _s (const char* _txt, size_t) {
    return std::string(_txt);
}

template<typename T, typename U> constexpr size_t offsetOf(U T::*member) {
    return (char*)&((T*)nullptr->*member) - (char*)nullptr;
}

inline cocos2d::CCSprite* makeSpriteOrFallback(const char* spr, const char* alt) {
    auto res = cocos2d::CCSprite::create(spr);
    if (!res)
        res = cocos2d::CCSprite::createWithSpriteFrameName(alt);
    
    return res;
}

typedef const char* nullstr_t;
static constexpr nullstr_t nullstr = "";

#endif
