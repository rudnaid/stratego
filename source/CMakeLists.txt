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
        ../include/ui/Texture.h
        ui/Texture.cpp
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
        SDL2::SDL2main   # SDL2 main function library
        SDL2::SDL2       # SDL2 library
        SDL2_image::SDL2_image  # SDL2_image library for image handling
)

find_package(SDL2_image CONFIG REQUIRED)