#pragma once
#include "includes.h"

class OverlayLayer : public gd::FLAlertLayer, public CCTextFieldDelegate {
    gd::CCTextInputNode* m_fps_input;
    CCLabelBMFont* m_replay_info;

    inline void _update_default_fps();
public:
    static auto create() {
        auto node = new OverlayLayer;
        if (node && node->init()) {
            node->autorelease();
        } else {
            CC_SAFE_DELETE(node);
        }
        return node;
    }

    virtual bool init();

    void update_info_text();

    void open_btn_callback(CCObject*) {
        auto node = create();
        CCDirector::sharedDirector()->getRunningScene()->addChild(node);
    }

    void close_btn_callback(CCObject*) {
        keyBackClicked();
    }

    // maybe do like on_btn_record idk
    void on_record(CCObject*);
    void on_play(CCObject*);
    void on_save(CCObject*);
    void on_load(CCObject*);

    virtual void keyBackClicked();
};