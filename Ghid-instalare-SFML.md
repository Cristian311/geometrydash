Proiectul descarca automat SFML 3.1.0 din GitHub la configurarea CMake, folosind FetchContent. Nu este nevoie sa descarci sau sa instalezi separat arhiva SFML si nici sa setezi `CMAKE_PREFIX_PATH`.

Este necesara o conexiune la internet la prima configurare si Git instalat, deoarece CMake cloneaza sursele SFML. Dupa aceea, sursele descarcate sunt pastrate in directorul de build.

Pe Windows, configureaza proiectul cu presetul `vs` din CMake Tools. Pe Linux, instaleaza dependintele grafice inainte de configurare:

```sh
sudo apt-get update
sudo apt-get install --no-install-recommends \
  libxrandr-dev \
  libxcursor-dev \
  libxi-dev \
  libudev-dev \
  libfreetype-dev \
  libgl1-mesa-dev \
  libegl1-mesa-dev
```

SFML Audio si Network nu sunt folosite de proiect si sunt dezactivate la build; se construieste doar Graphics si dependintele lui.
