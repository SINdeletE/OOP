//
// Created by nuelex on 16/05/25.
//

#ifndef PDUREADERCREATOR_HPP
#define PDUREADERCREATOR_HPP
#include <memory>

#include "BasePTUReader.hpp"


class PTUReaderCreator
{
public:
    virtual ~PTUReaderCreator() = default;
    [[nodiscard]] virtual std::shared_ptr<BasePTUReader> createPDUReader(const std::string &filename) const = 0;
};

template <typename Type>
requires std::is_base_of_v<BasePTUReader, Type> && (! std::is_abstract_v<Type>)
class ConcretePTUReaderCreator : public PTUReaderCreator
{
public:
    ~ConcretePTUReaderCreator() override = default;

    [[nodiscard]] std::shared_ptr<BasePTUReader> createPDUReader(const std::string &filename) const override
    {
        return std::make_shared<Type>(filename);
    }
};



#endif //PDUREADERCREATOR_HPP
