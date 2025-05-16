//
// Created by nuelex on 16/05/25.
//

#ifndef PDUREADERCREATOR_HPP
#define PDUREADERCREATOR_HPP
#include <memory>

#include "BasePDUReader.hpp"


class PDUReaderCreator
{
public:
    virtual ~PDUReaderCreator() = default;
    [[nodiscard]] virtual std::shared_ptr<BasePDUReader> createLPReader(const std::string &filename) const = 0;
};

template <typename Type>
requires std::is_base_of_v<BasePDUReader, Type> && (! std::is_abstract_v<Type>)
class ConcreteLPReaderCreator : public PDUReaderCreator
{
public:
    ~ConcreteLPReaderCreator() override = default;

    [[nodiscard]] std::shared_ptr<BasePDUReader> createLPReader(const std::string &filename) const override
    {
        return std::make_shared<Type>(filename);
    }
};



#endif //PDUREADERCREATOR_HPP
