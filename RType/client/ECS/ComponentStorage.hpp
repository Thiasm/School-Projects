/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** ComponentArray
*/

#ifndef COMPONENTARRAY_HPP_
#define COMPONENTARRAY_HPP_

#include "IComponentStorage.hpp"
#include "Entity.hpp"

template<typename T>
class ComponentStorage : public IComponentStorage {
    public:
        void addEntity(Entity currentEntity, T newComponent)
		{
		    componentArray[currentEntity] = newComponent;
        }

        T& getStructure(Entity entity)
        {
            return componentArray[entity];
        }

    private:
        std::array<T, MAX_ENTITY> componentArray;
        std::size_t arraySize;
};



#endif /* !COMPONENTARRAY_HPP_ */
