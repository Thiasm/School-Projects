cmake_minimum_required(VERSION 3.5)

project(Babel LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

set ( CMAKE_CXX_FLAGS "-g")

find_package(Qt5 COMPONENTS Widgets REQUIRED Network)

include(build/conanbuildinfo.cmake)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")

add_definitions(-lportaudio)

conan_basic_setup()

set(babel_ui
  ./mainwindow.ui
)

set(babel_includes
  ./client/include/mainwindow.h
  ./client/include/Iclient.hpp
  ./client/include/client.hpp
  ./client/include/clientConnect.hpp
  ./client/include/UdpSocket.hpp
  ./client/include/Audio/Audio.hpp
  ./client/include/Audio/Encoding.hpp
  ./client/include/Audio/PAudio.hpp
  ./client/include/Audio/Iaudio.hpp
  ./client/include/errorClient.hpp
  ./utilities/include/Message.hpp
  ./utilities/include/Message.hpp
  ./utilities/include/PacketSender/PacketSenderQt.hpp
  ./utilities/include/PacketReceiver/PacketReceiverQt.hpp
)

set(babel_sources
  ./client/src/main.cpp
  ./client/src/client.cpp
  ./client/src/errorClient.cpp
  ./client/src/clientConnect.cpp
  ./client/src/mainwindow.cpp
  ./client/src/UdpSocket.cpp
  ./client/src/Audio/Audio.cpp
  ./client/src/Audio/base.cpp
  ./client/src/Audio/coding.cpp
  ./client/src/Audio/RecordSound.cpp
  ./utilities/src/Message.cpp
  ./utilities/src/PacketSender/PacketSenderQt.cpp
  ./utilities/src/PacketReceiver/PacketReceiverQt.cpp
  )
  
set(server_includes
  ./server/include/ConnectionToClientManager.hpp
  ./server/include/Server.hpp
  ./server/include/ClientID.hpp
  ./server/include/errorServer.hpp
  ./utilities/include/PacketReceiver/IPacketReceiver.hpp
  ./utilities/include/PacketReceiver/PacketReceiver.hpp
  ./utilities/include/PacketReceiver/PacketReceiverBoost.hpp
  ./utilities/include/PacketSender/IPacketSender.hpp
  ./utilities/include/PacketSender/PacketSender.hpp
  ./utilities/include/PacketSender/PacketSenderBoost.hpp
  ./utilities/include/Message.hpp
)

set(server_sources
  ./server/src/ConnectionToClientManager.cpp
  ./server/src/Server.cpp
  ./server/src/ClientID.cpp
  ./server/src/main.cpp
  ./server/src/errorServer.cpp
  ./utilities/src/PacketReceiver/PacketReceiver.cpp
  ./utilities/src/PacketReceiver/PacketReceiverBoost.cpp
  ./utilities/src/PacketSender/PacketSender.cpp
  ./utilities/src/PacketSender/PacketSenderBoost.cpp
  ./utilities/src/Message.cpp
)

INCLUDE_DIRECTORIES(
   ./utilities/include/PacketSender
   ./utilities/include/PacketReceiver
   ./utilities/include
   ./server/include
   ./INCLUDE_DIRECTORIES
)
qt5_wrap_ui(project_includes_wrapped ${babel_ui})
qt5_wrap_cpp(project_sources_moc ${project_includes})

add_executable("babel_client" ${babel_includes} ${babel_sources} ${project_sources_moc} ${project_includes_wrapped})
add_executable("babel_server" ${server_includes} ${server_sources})

target_link_libraries("babel_client"
  Qt5::Network
  Qt5::Widgets
  portaudio
  dl
  jack
  asound
  opus
)

target_link_libraries(babel_server ${CONAN_LIBS})
