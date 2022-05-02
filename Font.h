#include <string>

// convertts color, type, bg_color to string for printf
struct Font {
private:
    int type, color, bg_color;
public:
    Font(int type, int color, int bg_color);
    std::string ToString();
    std::string ToString(int type, int color, int bg_color);
};