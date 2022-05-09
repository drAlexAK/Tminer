#include "Font.h"

Font::Font(int type, int color, int bg_color){
    this->type = type;
    this->color = color;
    this->bg_color = bg_color;
}

std::string Font::ToString(){
    return _ToString(type, color, bg_color);
}

std::string Font::_ToString(int _type, int _color, int _bg_color) {
    std::string ans;
    if (_type != -1) {
        ans.append(std::to_string(_type));
        if (_color != -1 || _bg_color != -1)ans.push_back(';');
    }
    if (_color != -1) {
        ans.append(std::to_string(_color));
        if (_bg_color != -1) ans.push_back(';');
    }
    if (_bg_color != -1) { ans.append(std::to_string(_bg_color)); }
    return ans;
}
