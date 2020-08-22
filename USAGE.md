
# Getting Started

## Requirements:
- UnrealEngine 4.20.3
- Visual Studio
- OpenCV 4.1
- LibTorch 1.5 (CPU)


## Project Setup

#### New Project
- Make a C++ Unreal Project 
- Make sure you have a `Plugins` folder inside of the project

#### Compile
- Clone this Repo into the plugins folder (Or download the zip file and unzip there)
- Right click your `.uproject` file and click `Generate Visual Studio Project Files`
- Compile the project from Visual Studio

#### DLLs
- Follow [directions](https://github.com/NeuralVFX/basic-libtorch-dll ) to compile `export_wrapper.dll` and place into the main plugin directory (ie:`Plugins/basic-unreal-libtorch-plugin`)
- Copy `LibTorch` and `OpenCV` `DLLs` into the plugin's `Binaries` folder (ie:`Plugins/basic-unreal-libtorch-plugin/Binaries/Win64`)

#### Find Plugin
- Open the compiled project in Unreal Engine
- From `Edit->Plugins`, locate the `Installed` Tab
- Find `LibTorchPlugin` and click `Enable`

![](Images/plugin_a.jpg)


## Run Test Scene

- In the Content Manager, navigate to `LibTorchPlugin Content->LibTorchTestLevel` and open this level
- Play the level, and you should see the Style Transfer on the `LibTorchViewer` object

![](Images/level.jpg)


## Scene Setup From Scratch

- In the Content Manager, navigate to `LibTorchPlugin C++ Classes->LibTorchPlugin->Public`
- Click on `LibTorchViewer` and drag this into your scene file

![](Images/viewer.jpg)

- Open `Settings->Project` and find `GameInstanceClass`, replace this with `cDataStorageGameInstance`
- Play the level, and you should see the Style Transfer on the `LibTorchViewer` object

![](Images/project_settings.jpg)

## Classes

### LibTorchViewer - Actor Class
- Actor Class which displays LibTorch output as a texture
- On every tick, this retrieves and updates texture
- Texture is queried from `UDataStorageGameInstance`

### cDataStoageWrapper - Object Class
- Wrapper for `export_wrapper.dll`
- Finds and initiates `DLL`
- Exposes functions of `DLL`

### UDataStorageGameInstance - GameInstance Class
- This is a wrapper for `cDataStoageWrapper`
- Manages starting and stoping `OpenCV` based on game state 
- Retrieves `LibTorch` output, to pass on to `LibTorchViewer `
