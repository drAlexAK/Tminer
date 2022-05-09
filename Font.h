#include <string>

// convertts color, type, bg_color to string for printf
struct Font {
private:
public:
    int type, color, bg_color;
    Font(int type, int color, int bg_color);
    std::string ToString();
    std::string _ToString(int _type, int _color, int _bg_color);
};