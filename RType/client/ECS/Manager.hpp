/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** Manager
*/

#ifndef MANAGER_HPP_
#define MANAGER_HPP_

#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"

class Manager {
    public:

        Manager()
        {
            TheComponentManager = std::make_unique<ComponentManager>();
	        TheEntityManager = std::make_unique<EntityManager>();
            TheSystemManager = std::make_unique<SystemManager>();
        }

        template<typename T>
        void registerComponent()
        {
            TheComponentManager->createComponent<T>();
        }

        Entity registerEntity()
        {
            return TheEntityManager->createEntity();
        }

        template<typename T>
		std::shared_ptr<T> registerSystem()
		{
		    return TheSystemManager->createSystem<T>();
		}

        template<typename T>
        void addComponent(Entity entity, T component)
        {
            std::size_t ComponentIndex = TheComponentManager->getComponentIndex<T>();
            
            TheComponentManager->addComponent<T>(entity, component);
            TheEntityManager->updateSignature(entity, ComponentIndex, true);
            TheSystemManager->updateEntities(entity, TheEntityManager->getSignature(entity));
        }

        template<typename T, typename S>
        void defineSystem()
        {
            std::size_t ComponentIndex = TheComponentManager->getComponentIndex<T>();

            TheSystemManager->updateSignature<S>(ComponentIndex, true);
        }

        void removeEntity(Entity entity)
        {
            TheEntityManager->removeEntity(entity);
            TheSystemManager->removeEntity(entity);
        }

        template<typename T>
		T& getComponent(Entity entity)
        {
            return TheComponentManager->getComponentValue<T>(entity);
        }

        template<typename T>
		std::size_t getComponentIndex()
        {
            return TheComponentManager->getComponentIndex<T>();
        }

    private:
        std::unique_ptr<EntityManager> TheEntityManager;
        std::unique_ptr<ComponentManager> TheComponentManager;
        std::unique_ptr<SystemManager> TheSystemManager;
};

#endif /* !MANAGER_HPP_ */
