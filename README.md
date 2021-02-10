![](https://github.com/NeuralVFX/basic-libtorch-dll/blob/master/style.gif)
# Basic-Unreal-Libtorch-Plugin

A `"Hello World"` for running `LibTorch` inside `Unreal Engine`.

## About
This is one of two repositories which are required to build this project:
- [basic-unreal-libtorch-plugin](https://github.com/NeuralVFX/basic-unreal-libtorch-plugin) - You are here.
- [basic-libtorch-dll](https://github.com/NeuralVFX/basic-libtorch-dll)


## Extra Info
- Runs Style Transfer on a live video feed, using `OpenCV` and `LibTorch`
- Neural Net Inference is performed inside a `DLL` and then the data is passed into `Unreal Engine`
- A `GameInstance Class` is used to initiate the `DLL` and execute its function
- An `Actor Class` queries the `GameInstance Class` each tick, and updates its texture with the resulting image


## Code Usage
Usage instructions found here: [user manual page](USAGE.md).



