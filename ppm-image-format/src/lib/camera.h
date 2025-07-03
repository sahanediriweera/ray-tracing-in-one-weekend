#ifndef CAMERA_H

#define CAMERA_H

#include "hittable.h"
#include "color.h"
#include "interval.h"

class camera
{
private:
    color ray_color(const ray &r, const hittable &world) const
    {
        hit_record rec;

        if (world.hit(r, interval(0, std::numeric_limits<double>::infinity()), rec))
        {
            return 0.5 * (rec.normal + color(1, 1, 1));
        }

        vec3 unit_direction = unit_vector(r.direction());
        auto a = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
    }
};

#endif