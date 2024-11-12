/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include "Entity.hpp"

class EntityManager {
    public:

        Entity createEntity()
        {
            entityCount += 1;
            return entityCount - 1;
        }

        Signature getSignature(Entity entity)
        {
            return signatureArray[entity];
        }

        void setSignature(Entity entity, Signature signature)
        {
            signatureArray[entity] = signature;
        }
        
        void updateSignature(Entity entity, std::size_t ComponentIndex, bool value)
        {
            auto signature = getSignature(entity);

            signature.set(ComponentIndex, value);
            setSignature(entity, signature);
        }
        
        void removeEntity(Entity entity)
        {
            signatureArray[entity].reset();
        }

        std::size_t getEntityCount() { return entityCount; };
    private:
        std::array<Signature, MAX_ENTITY> signatureArray;
        std::size_t entityCount = 0;
};

#endif /* !ENTITYMANAGER_HPP_ */
