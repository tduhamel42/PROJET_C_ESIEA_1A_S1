cmake_minimum_required (VERSION 2.8)
project (projet)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR}
		    include)

add_executable (projet	srcs/main.c
			srcs/main_menu.c
			srcs/game.c
			srcs/screen.c
			srcs/game_screen.c)

target_link_libraries(projet ${SDL2_LIBRARY}
                             ${SDL2_IMAGE_LIBRARIES}
                             ${SDL2_TTF_LIBRARIES})
target_compile_options(projet PRIVATE -g)


