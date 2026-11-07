Ai extras arhiva SFML 3.1.0 pentru Visual Studio x64 în C:\Libraries\SFML-3.1.0.
În CMakePresets.json, presetul vs îi indică lui CMake unde se află SFML prin CMAKE_PREFIX_PATH.
În CMakeLists.txt, ai adăugat find_package(SFML 3 COMPONENTS Graphics REQUIRED), ca CMake să găsească modulul Graphics.
Tot acolo, ai legat SFML::Graphics de executabilul oop_main.
În main.cpp, codul creează o fereastră SFML și o ține deschisă până când o închizi cu X.
Ai folosit comenzile CMake pentru configurare, build și rulare — nu Run C/C++ File, care încearcă să compileze fișierul separat de proiect.
Ai pus DLL-urile SFML lângă executabil, ca Windows să găsească bibliotecile necesare la pornire.