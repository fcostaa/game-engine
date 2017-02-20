cmake_minimum_required(VERSION 3.2)
project(CrossEngineDesktop)

file(COPY "${PROJECT_SOURCE_DIR}/game/assets" DESTINATION "${PROJECT_SOURCE_DIR}/build/")

include_directories(/usr/local/Cellar/boost/1.62.0/include)
include_directories(/usr/local/Cellar/ttfautohint/1.5.8/include)
include_directories(/usr/local/Cellar/allegro/HEAD-42db72a/include)

set(Boost_NO_SYSTEM_PATHS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(BOOST_ALL_DYN_LINK OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

AUX_SOURCE_DIRECTORY(game
        GAME_SOURCES)

AUX_SOURCE_DIRECTORY(game/Events
        GAME_EVENTS_SOURCES)

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

AUX_SOURCE_DIRECTORY(engine/Math
        ENGINE_MATH_SOURCES)

AUX_SOURCE_DIRECTORY(engine/Utils
        ENGINE_UTILS_SOURCES)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/")

LINK_DIRECTORIES(/usr/local/Cellar/allegro/5.2.0/lib)

add_executable(CrossEngineDesktop
        ${GAME_SOURCES}
        ${GAME_EVENTS_SOURCES}
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
        ${ENGINE_MATH_SOURCES}
        engine/Utils/Optional.h
        engine/Interfaces.h
        engine/standards.h
        game/View/DriftsHUD.cpp
        game/View/DriftsHUD.h
        game/Actor/PlayerObjectParams.cpp
        game/Actor/PlayerObjectParams.h
        game/SceneGraph/PlayerNode.cpp
        game/SceneGraph/PlayerNode.h)

target_link_libraries(CrossEngineDesktop ${Boost_LIBRARIES})
target_link_libraries(CrossEngineDesktop -lallegro -lallegro_main -lallegro_image -lallegro_ttf -lallegro_font)
