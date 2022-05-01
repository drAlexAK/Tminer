#include "Font.h"

Font::Font(int type, int color, int bg_color){
    this->type = type;
    this->color = color;
    this->bg_color = bg_color;
}

std::string Font::ToString() {
    return ToString(type, color, bg_color);
}

std::string Font::ToString(int type, int color, int bg_color) {
    std::string ans;
    if (type != -1) {
        ans.append(std::to_string(type));
        if (color != -1 || bg_color != -1)ans.push_back(';');
    }
    if (color != -1) {
        ans.append(std::to_string(color));
        if (bg_color != -1) ans.push_back(';');
    }
    if (bg_color != -1) { ans.append(std::to_string(bg_color)); }
    return ans;
}