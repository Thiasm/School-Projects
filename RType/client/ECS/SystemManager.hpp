/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** SystemManager
*/

#ifndef SYSTEMMANAGER_HPP_
#define SYSTEMMANAGER_HPP_

#include "System.hpp"

class SystemManager {
    public:

        // Add a shared pointer of the New System in The Map
        template<typename T>
        std::shared_ptr<T> createSystem()
        {
            auto system = std::make_shared<T>();
            const char *type = typeid(T).name();

            if (SystemMap.find(type) != SystemMap.end())
                std::cout << "This System Already Exist !" << std::endl;
            SystemMap.insert({type, system});
		    return system;
        }
        
        template<typename T>
        Signature getSignature()
        {
            const char *type = typeid(T).name();

            if (SignatureMap.find(type) == SignatureMap.end()) {
                Signature signature;
                return signature;
            }
            return SignatureMap[type];
        }

        template<typename T>
        void setSignature(Signature signature)
        {
            const char *type = typeid(T).name();

            if (SignatureMap.find(type) == SignatureMap.end())
                SignatureMap.insert({type, signature});
            else    
                SignatureMap[type] = signature;
        }

        template<typename T>
        void updateSignature(std::size_t ComponentIndex, bool value)
        {
            auto signature = getSignature<T>();
            
            signature.set(ComponentIndex, value);
            setSignature<T>(signature);
        }

        void updateEntities(Entity entity, Signature EntitySignature)
	    {
            for (auto const& system : SystemMap) {
                auto const& currentType = system.first;
                auto const& currentSystem = system.second;
                Signature const& systemsignature = SignatureMap[currentType];

			    if ((EntitySignature & systemsignature) == systemsignature)
			    	currentSystem->entityList.insert(entity);
			    else
                    currentSystem->entityList.erase(entity);
		    }
	    }

        void removeEntity(Entity entity)
        {
            for (auto const& pair : SystemMap) {
			    auto const& system = pair.second;
                system->entityList.erase(entity);
		    }
        }

    private:
    	std::unordered_map<const char*, std::shared_ptr<System>> SystemMap;
        std::unordered_map<const char*, Signature> SignatureMap;
};

#endif /* !SYSTEMMANAGER_HPP_ */
