//
// Created by nuelex on 11/05/25.
//

#ifndef HISTORY_HPP
#define HISTORY_HPP
#include <stack>

#include "BaseHistory.hpp"

class SceneHistory : public BaseHistory
{
public:
    SceneHistory() = default;
    ~SceneHistory() override = default;

    virtual void addSnap(const std::shared_ptr<BaseScene> &snap) { snaps.push(snap); }
    virtual std::shared_ptr<BaseScene>& topSnap() { return snaps.top(); }
    virtual void popSnap(const std::shared_ptr<BaseScene> &snap) { snaps.pop(); }

private:
    std::stack<std::shared_ptr<BaseScene>> snaps;
};



#endif //HISTORY_HPP
