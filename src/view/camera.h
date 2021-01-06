#ifndef LINAL_EINDOPDRACHT_CAMERA_H
#define LINAL_EINDOPDRACHT_CAMERA_H

#include "view.h"
#include "world.h"

namespace view {
    class camera {
        view& view_;
        models::world& world_;
        models::point3d origin_;
    public:
        camera(view& view, models::world& world, const models::point3d& origin = {0,0,0});

        void transform(models::Matrix& m);

        void origin(double x, double y, double z);

        void draw();
        void drawObject(objects::object& obj);
    private:
        models::point3d direction() const;

        models::matrix_ptr translationMatrix();
    };
}

#endif //LINAL_EINDOPDRACHT_CAMERA_H
