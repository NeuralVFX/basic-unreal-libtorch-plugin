
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





## ODSCamera Attributes

### Frame Range
```
--Start Frame, default=100, type=int                           # Frame to start capturing from
--End Frame, default=105, type=int                             # Frame to end capturing
--Current Frame, default=0, type=int                           # Current frame in Sequencer, used during capture
```
### Output Settings
```
--Out Resolution Width, default=4096, type=int                 # Width of final output, height will be half this value (Written into PTStitcher TXT file)
--Snip Resolution, default=720, type=int                       # Width and height used for each snapshot
--Snip FOV, default=50.0, type=float                           # Camera FOV for each snaphot, should be wider than "Angle Increment"
--Angle Increment, default=36.0, type=float                    # Rotation between each snapshot
--Output Dir, default='C:/Output/', type=str                   # Output directory for images and TXT files
--Output Name, default='Render Test', type=str                 # File prefix for all output files
```
### Stereo Settings
```
--Interocular Distance, default=6.2, type=float                # Distance between the left and right eye
--Interocular Verticle Fade, default=false, type=bool          # Whether to decrease the Interoclar Distance at top and bottom of frame (Reduces twist artifact)
```
### Sequencer
```
--Level Sequencer, default=None, type=LevelSequencer           # Which Level Sequencer to play, also fixed framerate is set based on this
```
