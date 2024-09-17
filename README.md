# TimeWise
A desktop app for optimizing your personal study schedule to meet your work life balance

## Compiling

To compile this project you will need glfw development libraries installed on your system. Development/compilation for Windows is handled with mingw. If you are using Windows to develop install [MSYS2](https://www.msys2.org/).

```
GLFW (http://www.glfw.org):
Linux (apt):
    apt-get install libglfw-dev
Linux (pacman):
    pacman -S glfw
Mac OS X:
    brew install glfw
MSYS2:
    pacman -S --noconfirm --needed mingw-w64-x86_64-toolchain mingw-w64-x86_64-glfw
```

Clone the repo and generate the makefile using [premake5](https://premake.github.io/download/).

```
git clone https://github.com/OSUOSC/TimeWise.git
cd TimeWise
premake5 gmake
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
