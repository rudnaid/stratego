set(SOURCES
        main.cpp
        core/GameController.cpp
        ui/SDL2UIController.cpp
        core/GameFactory.cpp
        rules/RulesEngine.cpp
        util/HistoryManager.cpp
        core/GameState.cpp
)

add_executable(stratego ${SOURCES})

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

target_include_directories(stratego
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(stratego
        PRIVATE
        SDL2::SDL2
        SDL2::SDL2main
        SDL2_image::SDL2_image
)
