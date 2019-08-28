#pragma once

#include <ecosnail/thing/entity.hpp>
#include <ecosnail/thing/entity_pool.hpp>

#include <ecosnail/tail.hpp>

#include <any>
#include <cassert>
#include <map>
#include <memory>
#include <optional>
#include <type_traits>
#include <typeindex>
#include <vector>

namespace ecosnail::thing {

class EntityManager {
    template <class Component>
    using ComponentMap = std::map<Entity, Component>;

    template <class Component>
    static ComponentMap<Component> emptyComponentMap;

public:
    template <class Component>
    const Component& component(Entity entity) const
    {
        assert(_components.count(typeid(Component)));
        const auto& componentMap =
            std::any_cast<const std::map<Entity, Component>&>(
                _components.at(typeid(Component)));

        assert(componentMap.count(entity));
        return componentMap.at(entity);
    }

    template <class Component>
    Component& component(Entity entity)
    {
        assert(_components.count(typeid(Component)));
        auto& componentMap =
            std::any_cast<std::map<Entity, Component>&>(
                _components.at(typeid(Component)));

        assert(componentMap.count(entity));
        return componentMap.at(entity);
    }

    template <class Component>
    auto components() const
    {
        auto it = _components.find(typeid(Component));
        if (it == _components.end()) {
            const auto& empty = emptyComponentMap<Component>;
            return tail::valueRange(empty);
        }

        const auto& componentMap =
            std::any_cast<const ComponentMap<Component>&>(it->second);
        return tail::valueRange(componentMap);
    }

    template <class Component>
    auto components()
    {
        auto it = _components.find(typeid(Component));
        if (it == _components.end()) {
            return tail::valueRange(emptyComponentMap<Component>);
        }

        auto& componentMap =
            std::any_cast<ComponentMap<Component>&>(it->second);
        return tail::valueRange(componentMap);
    }

    template <class Component>
    auto entities() const
    {
        auto it = _components.find(typeid(Component));
        if (it == _components.end()) {
            return tail::keyRange(emptyComponentMap<Component>);
        }

        const auto& componentMap =
            std::any_cast<const std::map<Entity, Component>&>(it->second);
        return tail::keyRange(componentMap);
    }

    template <class Component>
    auto& add(Entity entity)
    {
        static_assert(
            std::is_default_constructible<Component>(),
            "Component is not default-constructible");
        return add<Component>(entity, Component{});
    }

    template <class Component>
    auto& add(Entity entity, Component&& component)
    {
        using ComponentMap = std::map<Entity, Component>;

        std::type_index typeIndex(typeid(Component));
        auto it = _components.find(typeIndex);
        if (it == _components.end()) {
            it = _components.insert({typeIndex, ComponentMap()}).first;
        }

        auto& componentMap = std::any_cast<ComponentMap&>(it->second);
        assert(!componentMap.count(entity));
        return componentMap.insert(
            {entity, std::forward<Component>(component)}).first->second;
    }

    Entity createEntity()
    {
        return _entityPool.createEntity();
    }

    void killEntity(Entity entity)
    {
        _entityPool.killEntity(entity);
    }

private:
    EntityPool _entityPool;
    std::map<std::type_index, std::any> _components;
};

template <class Component>
EntityManager::ComponentMap<Component> EntityManager::emptyComponentMap;

} // namespace ecosnail::thing
