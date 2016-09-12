//
// Created by Felipe Costa on 8/27/16.
//

#include "Vec2.h"

Vec2::Vec2(const float x, const float y) : x(x), y(y) {

}

Vec2::Vec2() : Vec2(0, 0) {

}


Vec2::Vec2(const Vec2 &vec2) : Vec2(vec2.getX(), vec2.getY()) {

}

Vec2::~Vec2() {

}

const float Vec2::getX() const {
    return x;
}

const float Vec2::getY() const {
    return y;
}

Vec2 &Vec2::operator=(const Vec2 &from) {
    if (this != &from) {
        x = from.x;
        y = from.y;
    }

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Vec2 &vec) {
    out << "Vec2(" << vec.x << ", " << vec.y << ")";
    return out;
}
