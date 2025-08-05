set(SOURCES
        main.cpp
        core/GameController.cpp
        ui/SDL2UIController.cpp
        ui/Texture.cpp
        core/GameFactory.cpp
        core/GameState.cpp
        core/Unit.cpp
        core/PieceType.cpp
        core/Board.cpp
        core/Tile.cpp
        core/GameConfig.cpp
        core/Player.cpp
        rules/StandardMovementStrategy.cpp
        rules/ScoutMovementStrategy.cpp
        rules/NoMovementStrategy.cpp
        rules/StandardCombatStrategy.cpp
        rules/MinerCombatStrategy.cpp
        rules/SpyCombatStrategy.cpp
        rules/IMovementStrategy.cpp
)

add_executable(stratego ${SOURCES})

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(stratego
        PRIVATE
        SDL2::SDL2
        SDL2_image::SDL2_image
)

add_custom_command(TARGET stratego POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:stratego>/resources)
