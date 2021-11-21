cmake_minimum_required(VERSION 3.17)
project(Cluedo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cluedo main.cpp Affichage.cpp Clavier.cpp Carte.cpp PointH/Carte.h Souris.cpp Bouton.cpp PointH/Bouton.h Joueur.cpp PointH/Joueur.h Case.cpp PointH/Case.h PointH/IncludeAndDefine.h PointH/AutresFonctions.h AutresFonctions.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(Cluedo sfml-system sfml-window sfml-graphics sfml-audio)