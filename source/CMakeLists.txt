set(SOURCES
        main.cpp
        ../include/ui/ISDL2UI.h
        ../include/core/IGameController.h
        core/GameController.cpp
        ../include/core/GameController.h
        ../include/core/GameState.h
        ../include/ui/SDL2UIController.h
        ../include/core/Move.h
        ui/SDL2UIController.cpp
)

add_executable(stratego ${SOURCES})

# Find SDL2 and SDL2_image
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


# Link SDL2 and SDL2_image libraries
target_link_libraries(stratego
        PRIVATE
        ${SDL2_LIBRARIES}
)

find_package(SDL2_image CONFIG REQUIRED)