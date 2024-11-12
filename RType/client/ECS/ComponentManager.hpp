/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** ComponentManager
*/

#ifndef COMPONENTMANAGER_HPP_
#define COMPONENTMANAGER_HPP_

#include "Entity.hpp"
#include "ComponentStorage.hpp"

class ComponentManager {
    public:

        // Create Component Array and add it to the unordered_map
        template<typename T>
        void createComponent()
        {
            const char *type = typeid(T).name();

            if (componentMap.find(type) != componentMap.end()) {
                std::cout << "This component already exist in ComponentMap: " << type << std::endl;
                return;
            }
            componentMap.insert({type, std::make_shared<ComponentStorage<T>>()});
            componentIndex.insert({type, currentComponentIndex});
            currentComponentIndex += 1;
        }

        // Add Component to his Array in the map at the Entity index
        template<typename T>
        void addComponent(Entity entity, T component)
        {
            const char *type = typeid(T).name();
            
            if (componentMap.find(type) == componentMap.end()) {
                std::cout << "This component don't exist in ComponentMap: " << type << std::endl;
                return;
            }
            auto currentStorage = std::static_pointer_cast<ComponentStorage<T>>(componentMap[type]);
            currentStorage->addEntity(entity, component);
        }
        
        // Return Component Array Index in the map
        template<typename T>
        std::size_t getComponentIndex()
        {
            const char *type = typeid(T).name();

            if (componentIndex.find(type) == componentIndex.end()) {
                std::cout << "This component don't exist in ComponentIndex: " << type << std::endl;
                return 0;
            }
            return componentIndex[type];
        }
        
        // Return Component Data at the entity index in the Map
        template<typename T>
		T& getComponentValue(Entity entity)
        {
            const char *type = typeid(T).name();

            if (componentIndex.find(type) == componentIndex.end()) {
                std::cout << "This component don't exist in ComponentMap: " << type << std::endl;
                //return nullptr;
            }
            auto currentStorage = std::static_pointer_cast<ComponentStorage<T>>(componentMap[type]);
            return currentStorage->getStructure(entity);
        }

    private:
        std::unordered_map<const char *, std::size_t> componentIndex;
        std::unordered_map<const char *, std::shared_ptr<IComponentStorage>> componentMap;
        std::size_t currentComponentIndex;
};

#endif /* !COMPONENTMANAGER_HPP_ */
