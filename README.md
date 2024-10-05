# TimeWise
A desktop app for optimizing your personal study schedule to meet your work life balance

## Compiling

To compile this project you will need glfw development libraries installed on your system. Development/compilation for Windows is handled with Visual Studio 2022. Load the sln into Visual Studio and then download [GLFW](https://www.glfw.org/download). Make sure to install the 64-bit precompile binaries.
You will then need to set the include and libs directory in your solution settings to match the install location of GLFW on your machine.

Other Systems:
```
GLFW (http://www.glfw.org):
Linux (apt):
    apt-get install libglfw3-dev
Linux (pacman):
    pacman -S glfw
Mac OS X:
    brew install glfw
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
