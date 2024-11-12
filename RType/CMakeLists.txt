cmake_minimum_required(VERSION 3.5)

project(R_Type)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CLIENT "r-type_client")
set(SERVER "r-type_server")
set(SRC_CLIENT_DIR "./client/src")
set(SRC_SYSTEM_DIR "./client/Systems/src")
set(SRC_MENU_DIR "./client/Menu/src")
set(SRC_MENU_INC "./client/Menu/include")
set(INC_SYSTEM_DIR "./client/Systems/include")
set(SRC_SERVER_DIR "./server/src")
set(SRC_UTIL_DIR "./utilities/src")
set(INC_CLIENT_DIR "./client/include")
set(INC_SERVER_DIR "./server/include")
set(INC_UTIL_DIR "./utilities/include")
set(INC_COMPONENT_DIR "./client/Components")
set(INC_ECS_DIR "./client/ECS")
SET(CMAKE_CXX_FLAGS "-lpthread -g")


set(client_sources
  ${SRC_CLIENT_DIR}/main.cpp
  ${SRC_MENU_DIR}/Menu.cpp
  ${SRC_MENU_DIR}/Button.cpp
  ${SRC_MENU_DIR}/Sprite.cpp
  ${SRC_MENU_DIR}/Text.cpp
  ${SRC_CLIENT_DIR}/Timer.cpp
  ${SRC_CLIENT_DIR}/Gameplay.cpp
  ${SRC_CLIENT_DIR}/InitGameplay.cpp
  ${SRC_CLIENT_DIR}/ConnectionToServerManager.cpp
  ${SRC_CLIENT_DIR}/Pause.cpp
  ${SRC_CLIENT_DIR}/Room.cpp
  ${SRC_MENU_DIR}/Line.cpp
  ${SRC_SYSTEM_DIR}/ColisionSystem.cpp
  ${SRC_SYSTEM_DIR}/RenderSystem.cpp
  ${SRC_SYSTEM_DIR}/EventSystem.cpp
  ${SRC_SYSTEM_DIR}/AdvanceSystem.cpp
  ${SRC_SYSTEM_DIR}/SpawnSystem.cpp
  ${SRC_SYSTEM_DIR}/ClearSystem.cpp
  ${SRC_SYSTEM_DIR}/ShootSystem.cpp
  ${SRC_SYSTEM_DIR}/SendSystem.cpp
  ${SRC_SYSTEM_DIR}/ReceiveSystem.cpp
  ${SRC_CLIENT_DIR}/End.cpp
)
  
set(server_includes
  ${INC_SERVER_DIR}/ConnectionToClientManager.hpp
  ${INC_SERVER_DIR}/Server.hpp
  ${INC_UTIL_DIR}/errorServer.hpp
  ${INC_UTIL_DIR}/Network/PacketReceiverBoost.hpp
  ${INC_UTIL_DIR}/Network/PacketSenderBoost.hpp
  ${INC_UTIL_DIR}/Network/MessageComp.hpp
)

set(server_sources
  ${SRC_SERVER_DIR}/ConnectionToClientManager.cpp
  ${SRC_SERVER_DIR}/Server.cpp
  ${SRC_SERVER_DIR}/main.cpp
  ${SRC_UTIL_DIR}/errorServer.cpp
  ${SRC_UTIL_DIR}/Network/PacketReceiverBoost.cpp
  ${SRC_UTIL_DIR}/Network/PacketSenderBoost.cpp
  ${SRC_UTIL_DIR}/Network/MessageComp.cpp
)

set(utilities_includes
  ${INC_ECS_DIR}/Entity.hpp
  ${INC_ECS_DIR}/EntityManager.hpp
  ${INC_ECS_DIR}/IComponentStorage.hpp
  ${INC_ECS_DIR}/ComponentStorage.hpp
  ${INC_ECS_DIR}/ComponentManager.hpp
  ${INC_ECS_DIR}/System.hpp
  ${INC_ECS_DIR}/SystemManager.hpp
  ${INC_ECS_DIR}/Manager.hpp
  ${INC_UTIL_DIR}/errorServer.hpp
  ${INC_UTIL_DIR}/Network/PacketReceiverBoost.hpp
  ${INC_UTIL_DIR}/Network/PacketSenderBoost.hpp
  ${INC_UTIL_DIR}/Network/MessageComp.hpp
  ${INC_COMPONENT_DIR}/Position.hpp
  ${INC_COMPONENT_DIR}/Team.hpp
  ${INC_COMPONENT_DIR}/Speed.hpp
  ${INC_COMPONENT_DIR}/Life.hpp
  ${INC_COMPONENT_DIR}/Weapon.hpp
  ${INC_COMPONENT_DIR}/HitBox.hpp
  ${INC_COMPONENT_DIR}/Texture.hpp
  ${INC_COMPONENT_DIR}/Automatic.hpp
  ${INC_COMPONENT_DIR}/Damage.hpp
  ${INC_COMPONENT_DIR}/Name.hpp
  ${INC_COMPONENT_DIR}/Controlable.hpp
  ${INC_COMPONENT_DIR}/Sound.hpp
)

set(utilities_sources
  ${SRC_UTIL_DIR}/Network/PacketReceiverBoost.cpp
  ${SRC_UTIL_DIR}/Network/PacketSenderBoost.cpp
  ${SRC_UTIL_DIR}/Network/MessageComp.cpp
  ${SRC_UTIL_DIR}/errorServer.cpp
)

INCLUDE_DIRECTORIES(
   ./utilities/include/
   ./utilities/include/Network
   ./server/include
   ./client/include
   ./INCLUDE_DIRECTORIES
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${CLIENT} ${utilities_includes} ${utilities_sources} ${client_sources})
add_executable(${SERVER} ${server_includes} ${server_sources})

target_link_libraries(${CLIENT} CONAN_PKG::sfml)
conan_basic_setup(TARGETS)