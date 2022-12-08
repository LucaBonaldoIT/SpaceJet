# SpaceJet
## SDL2 bare-metal game

Please don't hurt yourself playing this game :(

## Conventions

Conventions list:

 - ObjectModels should contain classes and interfaces
 - Interfaces name should be "IName"


## Compilation
Momentarily too lazy for a CMakeLists, therefore:
```
$ g++ main.cpp ObjectModel/*.cpp -w -lSDL2 -lSDL2_image -o main
```