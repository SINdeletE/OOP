//
// Created by nuelex on 21/05/25.
//

#ifndef CAMERAPTUTRANSFORMER_HPP
#define CAMERAPTUTRANSFORMER_HPP
#include "../BaseCameraTransformer.hpp"
#include "../../../BaseObject/Camera/CameraPTU.hpp"

class CameraPTUTransformer : public BaseCameraTransformer
{
public:
    CameraPTUTransformer() = delete;
    explicit CameraPTUTransformer(const std::shared_ptr<Camera> &camera);
    ~CameraPTUTransformer() override = default;

    [[nodiscard]] Point transform(const Point &other) const override;

private:
    std::shared_ptr<CameraPTU> _camera;

    [[nodiscard]] Point toPerspective(const Point &point) const;
};



#endif //CAMERAPTUTRANSFORMER_HPP
