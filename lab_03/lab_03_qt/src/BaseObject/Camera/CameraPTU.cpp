//
// Created by nuelex on 10/05/25.
//

#include "CameraPTU.hpp"

#include "../../Visitors/Visitor.hpp"

void CameraPTU::transform(const Rotater& rotater)
{
    const Mover backMover = -rotater.centerToMover();
    const Mover fwdMover = rotater.centerToMover();

    this->transform(backMover);
    _target.rotate(rotater.getOx(), rotater.getOy(), rotater.getOz());
    this->transform(fwdMover);
}

void CameraPTU::transform(const Mover& mover)
{
    _position.move(mover.getDx(), mover.getDy(), mover.getDz());
    _target.move(mover.getDx(), mover.getDy(), mover.getDz());
}

void CameraPTU::accept(const BaseVisitor& visitor)
{
    if (const auto cv = dynamic_cast<const Visitor<BaseCameraPTU>*>(&visitor))
        cv->visit(*this);
}



