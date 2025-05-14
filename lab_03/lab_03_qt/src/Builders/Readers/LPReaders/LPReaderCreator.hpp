//
// Created by nuelex on 14/05/25.
//

#ifndef LPREADERCREATOR_HPP
#define LPREADERCREATOR_HPP
#include <memory>

#include "BaseLPReader.hpp"


class LPReaderCreator
{
public:
    virtual ~LPReaderCreator() = default;
    [[nodiscard]] virtual std::shared_ptr<BaseLPReader> createLPReader(const std::string &filename) const = 0;
};

template <typename Type>
requires std::is_base_of_v<BaseLPReader, Type> && (! std::is_abstract_v<Type>)
class ConcreteLPReaderCreator : public LPReaderCreator
{
public:
    ~ConcreteLPReaderCreator() override = default;

    [[nodiscard]] std::shared_ptr<BaseLPReader> createLPReader(const std::string &filename) const override
    {
        return std::make_shared<Type>(filename);
    }
};

#endif //LPREADERCREATOR_HPP
