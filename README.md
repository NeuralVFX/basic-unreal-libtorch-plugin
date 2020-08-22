![](https://github.com/NeuralVFX/basic-libtorch-dll/blob/master/coke.png)
# Basic-Unreal-Libtorch-Plugin

A "Hello World" for running LibTorch inside Unreal Engine.

## About
This is one of two repositories which are required to build this project:
- [basic-unreal-libtorch-pluginh](https://github.com/NeuralVFX/basic-unreal-libtorch-plugin) - You are here.
- [basic-libtorch-dll](https://github.com/NeuralVFX/basic-libtorch-dll)


## Extra Info
- Runs Style Transfer on a live video feed, using OpenCV and LibTorch
- The Neural Net Inference is performed inside a DLL and then the data is passed into Unreal Engine
- A GameInstance Class is used to Initiate the DLL and exectute it's function
- An Actor Class queries the GameInstance Class each tick, and updates it's texture with the resulting image


## Code Usage
Usage instructions found here: [user manual page](USAGE.md).



