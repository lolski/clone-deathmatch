/* 
 * File:   debug.h
 * Author: lolski
 *
 * Created on August 21, 2009, 8:36 PM
 */

#ifndef _DEBUG_H
#define	_DEBUG_H

#include <irrlicht.h>
#include <iostream>
#include <string>

template <class T>
void pVec2d(std::string label, irr::core::vector2d<T> &vec, bool newline = true) {
    std::cout<<label<<": "<<vec.X<<" "<<vec.Y<<" ";
    if (newline)
        std::cout<<std::endl;
}

template <class T>
void pVec3d(irr::core::vector3d<T> const &vec, std::string label = "", bool newline = true) {
    if (label == "") {
        std::cout<<"label:"<<": "<<vec.X<<" "<<vec.Y<<" "<<vec.Z;
    }
    else {
        std::cout<<label<<": "<<vec.X<<" "<<vec.Y<<" "<<vec.Z;
    }
    if (newline)
        std::cout<<std::endl;
}

extern void pUInt(std::string label, unsigned int num, bool newline = true);

class Debug {
public:
    Debug(irr::gui::IGUIEnvironment *guienv);
    virtual ~Debug();
    void setText(const wchar_t *msg);
    void setPos(irr::core::dimension2d<float> dim);
    void setText(bool expr);
    void setText(int num);
    void setText(unsigned int num);
    void setText(const irr::core::stringw &msg);

    template <class T>
    void setText(const irr::core::vector3d<T> &vec) {
        irr::core::stringw msg;
        msg += vec.X;
        msg += " ";
        msg += vec.Y;
        msg += " ";
        msg += vec.Z;
        text->setText(msg.c_str());
    }
    
private:
    irr::core::rect<int> rect;
    irr::gui::IGUIEnvironment *guiEnv;
    irr::gui::IGUIStaticText *text;
    irr::gui::IGUIFont *font;
};
#endif	/* _DEBUG_H */

