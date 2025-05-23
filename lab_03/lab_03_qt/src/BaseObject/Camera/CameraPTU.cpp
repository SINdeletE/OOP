//
// Created by nuelex on 10/05/25.
//

#include "CameraPTU.hpp"

#include "../../Visitors/Visitor.hpp"

void CameraPTU::transform(const Rotater& rotater)
{

    auto radRotater = radFromDegree(rotater);
    radRotater.setCenter(this->getPosition());

    const Mover backMover = -radRotater.centerToMover();
    const Mover fwdMover = radRotater.centerToMover();

    _target.move(backMover.getDx(), backMover.getDy(), backMover.getDz());
    _target.rotate(radRotater.getOx(), radRotater.getOy(), radRotater.getOz());
    _target.move(fwdMover.getDx(), fwdMover.getDy(), fwdMover.getDz());
}

void CameraPTU::transform(const Mover& mover)
{
    _position.move(mover.getDx(), mover.getDy(), mover.getDz());
    _target.move(mover.getDx(), mover.getDy(), mover.getDz());
}

void CameraPTU::accept(const BaseDrawTemplateVisitor& visitor)
{
    if (const auto cv = dynamic_cast<const Visitor<BaseCameraPTU>*>(&visitor))
        cv->visit(*this);
}

Rotater CameraPTU::radFromDegree(const Rotater& rotater)
{
    return {rotater.getOx() * M_PI / 180,
            rotater.getOy() * M_PI / 180,
            rotater.getOz() * M_PI / 180,
            rotater.getCenter()};
}


