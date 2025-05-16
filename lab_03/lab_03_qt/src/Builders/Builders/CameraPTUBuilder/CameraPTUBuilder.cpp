//
// Created by nuelex on 16/05/25.
//

#include "CameraPTUBuilder.hpp"

#include "../../Readers/PTUReader/PTUReaderSolution.hpp"

CameraPTUBuilder::CameraPTUBuilder(const std::string& filename) : BaseCameraPTUBuilder(filename), \
                                                                  _position(), _target(), _up(), _camera(nullptr), _reader(nullptr)
{
    try
    {
        PTUReaderSolution solution;
        _reader = solution.createPDUReader(filename);
    }
    catch (const std::exception &e)
}

