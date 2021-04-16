#pragma once

#include "../offsets.hpp"

namespace gd {
    class TextInputDelegate {
        virtual void textChanged(void) {};
        virtual void textInputOpened(void) {};
        virtual void textInputClosed(void) {};
        virtual void textInputShouldOffset(float) {};
        virtual void textInputReturn(void) {};
        virtual bool allowTextInput(void) { return true; };
    };

    class UploadActionDelegate {
        virtual void uploadActionFinished(int, int) {};
        virtual void uploadActionFailed(int, int) {};
    };

    class UploadPopupDelegate {
        virtual void onClosePopup(void) {};
    };

    class SetIDPopupDelegate {
        virtual void setIDPopupClosed(int) {};
    };
}

class EditLevelLayer :
    public cocos2d::CCLayer,
    public gd::TextInputDelegate,
    public gd::FLAlertLayerProtocol,
    public gd::UploadActionDelegate,
    public gd::UploadPopupDelegate,
    public gd::SetIDPopupDelegate
{
    protected:
        PAD(0x4)
        gd::GJGameLevel* m_pLevel;
        PAD(0x30)

        static bool inline (__thiscall* init)(EditLevelLayer*, gd::GJGameLevel*);
        static bool __fastcall initHook(EditLevelLayer*, uintptr_t, gd::GJGameLevel*);
    
    public:
        void onExport(cocos2d::CCObject*);

        static bool loadHook() {
            return MH_CreateHook(
                (PVOID)(gd::base + 0x6f5d0),
                (LPVOID)EditLevelLayer::initHook,
                (LPVOID*)&EditLevelLayer::init
            ) == MH_OK;
        }
};
