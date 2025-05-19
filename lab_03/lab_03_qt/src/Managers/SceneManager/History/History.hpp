//
// Created by nuelex on 11/05/25.
//

#ifndef HISTORY_HPP
#define HISTORY_HPP
#include <stack>
#include <memory>

#include "BaseHistory.hpp"
#include "../Scene/Scene/Scene.hpp"

class SceneHistory : public BaseHistory
{
public:
    SceneHistory() = default;
    explicit SceneHistory(const SceneHistory &scene) { snaps = scene.snaps; }
    SceneHistory(SceneHistory &&scene) noexcept { snaps = std::move(scene.snaps); }
    ~SceneHistory() override = default;

    SceneHistory &operator=(const SceneHistory &scene) { snaps = scene.snaps; return *this; }
    SceneHistory &operator=(SceneHistory &&scene) noexcept { snaps = std::move(scene.snaps); return *this; }

    virtual void addSnap(const std::shared_ptr<Scene> &snap) { snaps.push(snap); }
    virtual std::shared_ptr<Scene>& topSnap() { return snaps.top(); }
    virtual void popSnap(const std::shared_ptr<Scene> &snap) { snaps.pop(); }

private:
    std::stack<std::shared_ptr<Scene>> snaps;
};



#endif //HISTORY_HPP
