#include "world.h"

#include <iostream>
#include <algorithm>

namespace models {
    world::world(const models::point3d& origin, const objects::spaceship& spaceship)
        :   origin_{origin}, spaceship_{spaceship}
    {

    }

    std::vector<std::unique_ptr<objects::object>> & world::objects() {
        return objects_;
    }

    void world::addObject(std::unique_ptr<objects::object> obj) {
        objects_.emplace_back(std::move(obj));
    }

    void world::scale(double scale) {
        auto m {*std::move(models::matrix::worldSpaceScalingMatrix(scale, scale, scale))};

        spaceship_.transform(m);
        spaceship_.origin().transform(m);

        for (auto& object : objects_) {
            object->transform(m);
            object->origin().transform(m);
        }
    }

    objects::spaceship& world::spaceship() {
        return spaceship_;
    }

    point3d world::origin() const {
        return origin_;
    }

    void world::origin(double x, double y, double z) {
        origin_.x(x);
        origin_.y(y);
        origin_.z(z);
    }

    void world::print() {
        std::cout << "====================== WORLD ======================" << "\n";
        std::for_each(objects_.begin(), objects_.end(), [](auto& obj){ obj->print(); });
        std::cout << "==================================================" << "\n";
    }
}