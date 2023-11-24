set(game_lib_files
        Game.cpp
        Round.cpp
        IO.cpp
        Time.cpp
        Configuration.cpp)
set(team_lib_files
        Player.cpp
        Team.cpp
        ListOfTeam.cpp)
set(gun_lib_files
        Weapon.cpp
        Ammunition.cpp
)


if (${enable_testing})
    add_library(my ${game_lib_files} ${team_lib_files} ${gun_lib_files})
endif ()

add_executable(main main.cpp
        ${game_lib_files}
        ${team_lib_files}
        ${gun_lib_files})
