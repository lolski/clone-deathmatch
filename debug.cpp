#include "debug.h"

void pUInt(std::string label, unsigned int num, bool newline) {
    std::cout<<label<<": "<<num;
    if (newline) {
        std::cout<<std::endl;
    }
}

Debug::Debug(irr::gui::IGUIEnvironment *guienv) : rect(0, 0, 200, 100) {
    this->guiEnv = guienv;
    this->font = guienv->getBuiltInFont();
    text = guiEnv->addStaticText(L"", rect, true, true, NULL, -1, true);
    text->setBackgroundColor(irr::video::SColor(255, 255, 255, 255));


}

Debug::~Debug() {
}

void Debug::setText(const wchar_t *msg) {
    text->setText(msg);
}

void Debug::setPos(irr::core::dimension2d<float> dim) {
    int x1, y1, x2, y2;
    x1 = dim.Width;
    x2 = dim.Height;
    y1 = dim.Height / 640;
    y2 = dim.Width / 320;
}

void Debug::setText(bool expr) {
    irr::core::stringw msg;
    if (expr) {
        msg = "true";
    } else {
        msg = "false";
    }
    text->setText(msg.c_str());
}

void Debug::setText(int num) {
    irr::core::stringw msg;
    msg += "";
    msg += num;
    text->setText(msg.c_str());
}

void Debug::setText(unsigned int num) {
    irr::core::stringw msg;
    msg += "";
    msg += num;
    text->setText(msg.c_str());
}

void Debug::setText(const irr::core::stringw &msg) {
    text->setText(msg.c_str());
}