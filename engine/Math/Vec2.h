//
// Created by Felipe Costa on 8/27/16.
//

#ifndef CROSSENGINEDESKTOP_VEC2_H
#define CROSSENGINEDESKTOP_VEC2_H

#import <iostream>

class Vec2 {
private:
    float x;
    float y;

public:
    Vec2(const float x, const float y);

    Vec2();

    Vec2(const Vec2 &vec2);

    virtual ~Vec2();

    const float getX() const;

    const float getY() const;

    Vec2 &operator=(const Vec2 &from);

    friend std::ostream &operator<<(std::ostream &out, const Vec2 &vec);
};


#endif //CROSSENGINEDESKTOP_VEC2_H
