cmake_minimum_required(VERSION 3.2)
project(CrossEngineDesktop)

file(COPY "${PROJECT_SOURCE_DIR}/game/assets" DESTINATION "${PROJECT_SOURCE_DIR}/build/")

include_directories(/usr/local/Cellar/boost/1.58.0/include)
INCLUDE_DIRECTORIES(/usr/local/Cellar/ttfautohint/1.4.1/include)
INCLUDE_DIRECTORIES(/usr/local/Cellar/allegro/5.2.0/include)

set(Boost_NO_SYSTEM_PATHS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(BOOST_ALL_DYN_LINK OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# -Wall")
#set(CMAKE_CXX_COMPILER  "/usr/local/Cellar/gcc/5.1.0/bin/g++-5")

#set(ENGINE_HEADERS engine/headers/GameApplication.h
#                   engine/headers/Interfaces.h
#                   engine/headers/standards.h
#                   engine/**.cpp
#                   engine/headers/Logic/BaseGameLogic.h
#                   engine/headers/Logic/ProcessManager.h
#                   engine/headers/Logic/Process.h
#                   engine/headers/Timer/Timer.h
#                   engine/headers/IEventManager/TypedEventData.h
#                   engine/headers/IEventManager/IEventManager.h
#                   )
#set(ENGINE_SOURCES engine/src/GameApplication.cpp
#                   engine/src/Logic/BaseGameLogic.cpp
#                   engine/src/Logic/ProcessManager.cpp
#                   engine/src/Logic/Process.cpp
#                   engine/src/Timer/Timer.cpp
#                   engine/src/IEventManager/TypedEventData.cpp
#                   engine/src/IEventManager/IEventManager.cpp
#

AUX_SOURCE_DIRECTORY(game
        GAME_SOURCES)

AUX_SOURCE_DIRECTORY(game/Events
        GAME_EVENTS_SOURCES)

AUX_SOURCE_DIRECTORY(game/Actor
        GAME_ACTOR_SOURCES)

AUX_SOURCE_DIRECTORY(game/SceneGraph
        GAME_SCENE_GRAPH_SOURCES)

AUX_SOURCE_DIRECTORY(game/Logic
        GAME_LOGIC_SOURCES)

AUX_SOURCE_DIRECTORY(game/View
        GAME_VIEW_SOURCES)

AUX_SOURCE_DIRECTORY(engine
        ENGINE_SOURCES)

AUX_SOURCE_DIRECTORY(engine/EventManager
        ENGINE_EVENT_MANAGER_SOURCES)

AUX_SOURCE_DIRECTORY(engine/EventManager/Events
        ENGINE_EVENTS_SOURCES)

AUX_SOURCE_DIRECTORY(engine/Logic
        ENGINE_LOGIC_SOURCES)

AUX_SOURCE_DIRECTORY(engine/Actor
        ENGINE_ACTOR_SOURCES)

AUX_SOURCE_DIRECTORY(engine/Actor/Base
        ENGINE_ACTOR_BASE_SOURCES)

AUX_SOURCE_DIRECTORY(engine/Timer
        ENGINE_TIMER_SOURCES)

AUX_SOURCE_DIRECTORY(engine/View
        ENGINE_VIEW_SOURCES)

AUX_SOURCE_DIRECTORY(engine/Timer
        ENGINE_TIMER_SOURCES)

AUX_SOURCE_DIRECTORY(engine/SceneGraph
        ENGINE_SCENE_GRAPH_SOURCES)

AUX_SOURCE_DIRECTORY(engine/Utils
        ENGINE_UTILS_SOURCES)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/")

LINK_DIRECTORIES(/usr/local/Cellar/allegro/5.2.0/lib)

add_executable(CrossEngineDesktop
        ${GAME_SOURCES}
        ${GAME_SCENE_GRAPH_SOURCES}
        ${GAME_EVENTS_SOURCES}
        ${GAME_ACTOR_SOURCES}
        ${GAME_LOGIC_SOURCES}
        ${GAME_VIEW_SOURCES}
        ${ENGINE_SOURCES}
        ${ENGINE_UTILS_SOURCES}
        ${ENGINE_EVENT_MANAGER_SOURCES}
        ${ENGINE_EVENTS_SOURCES}
        ${ENGINE_LOGIC_SOURCES}
        ${ENGINE_ACTOR_SOURCES}
        ${ENGINE_ACTOR_BASE_SOURCES}
        ${ENGINE_TIMER_SOURCES}
        ${ENGINE_VIEW_SOURCES}
        ${ENGINE_SCENE_GRAPH_SOURCES}
        engine/Utils/Optional.h
        engine/Interfaces.h
        engine/standards.h
)
#${ENGINE_HEADERS} ${ENGINE_SOURCES} engine/headers/IEventManager/BaseEventData.cpp engine/headers/IEventManager/BaseEventData.h)

target_link_libraries(CrossEngineDesktop ${Boost_LIBRARIES})
target_link_libraries(CrossEngineDesktop -lallegro -lallegro_main -lallegro_image -lallegro_ttf -lallegro_font)
