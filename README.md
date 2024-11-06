# TimeWise
A desktop app for optimizing your personal study schedule to meet your work life balance

## Compiling

To compile this project you will need glfw development libraries installed on your system. The precompiled Windows binaries come included in this repo but Linux users will need to install using their system package manager.

```
Linux (apt):
    apt-get install libglfw3-dev
Linux (pacman):
    pacman -S glfw
```

Additionally you will need to install libical:

Windows:
```
git clone https://github.com/libical/libical.git
cd libical
mkdir build
cd build
cmake -G "NMake Makefiles" ..
nmake
nmake install

alternatively using vcpkg:
https://vcpkg.io/en/package/libical
```

Linux:
```
git clone https://github.com/libical/libical.git
cd libical
mkdir build
cd build
cmake ..
make
make install

alternatively:
sudo apt install libical-dev
```

Clone the repo and generate the makefile using [premake5](https://premake.github.io/download/).

Windows:
```
git clone https://github.com/OSUOSC/TimeWise.git
cd TimeWise
./premake5 vs2022
-- open the .sln file
```

Linux:
```
git clone https://github.com/OSUOSC/TimeWise.git
cd TimeWise
./premake5 gmake
make
```

## Contributing

- Before opening an issue or a PR please check out the [contributing guide](https://github.com/OSUOSC/TimeWise/blob/main/CONTRIBUTING.md).
- For bug reports and feature suggestions please use [issues](https://github.com/BanceDev/OSUOSC/TimeWise/issues).
- If you wish to contribute code of your own please submit a [pull request](https://github.com/OSUOSC/TimeWise/pulls).
- All help is welcome!

## License

This project is licensed under the MIT License.

For more details, see the [LICENSE](./LICENSE) file.
