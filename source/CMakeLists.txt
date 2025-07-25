set(SOURCES
        main.cpp
        core/GameController.cpp
        ui/SDL2UIController.cpp
        ui/Texture.cpp
        core/GameFactory.cpp
)

add_executable(stratego ${SOURCES})

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


target_link_libraries(stratego
        PRIVATE
        SDL2::SDL2main
        SDL2::SDL2
        SDL2_image::SDL2_image
)

find_package(SDL2_image CONFIG REQUIRED)
