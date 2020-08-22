
# Getting Started

## Requirements:
- UnrealEngine 4.20.3
- Visual Studio
- OpenCV 4.1
- LibTorch 1.5 (CPU)


## Project Setup

- Make a C++ Unreal Project 
- Make sure you have a `Plugins` folder inside of the project
- Clone this Repo into the plugins folder (Or download the zip file and unzip there)

- Follow [directions](https://github.com/NeuralVFX/basic-libtorch-dll ) to compile `export_wrapper.dll` and place into the main plugin directory (ei:`Plugins/basic-unreal-libtorch-plugin`)
- Copy `LibTorch` and `OpenCV` `DLLs` into the Plugin's Binaries folder (ei:`Plugins/basic-unreal-libtorch-plugin/Binaries/Win64`)

- Right click your `.uproject` file and click `Generate Visual Studio Project Files`
- Compile the project from Visual Studio
- From `Edit->Plugins`, locate the `Installed` Tab
- Find `LibTorchPlugin` and click `Enable`


![](Images/plugin_a.jpg)
## Scene Setup

- In the Content Manager, navigate to ODSPlugin C++ `Classes->ODSPlugin->Classes`
- Click on `ODSCamera` and drag this into your scene file
- In the attributes of the ODSCamera, find the `LevelSequencer` attribute and select the sequencer you would like to render from
- Apply any camera animation you want within this level sequencer
- In the attributes of the ODSCamera, set the `Frame Range`, `Output Settings`, and `Stereo Settings` to your needs

![](Images/attributes_a.jpg)

- Play the level!
- No need to setup anything to play your sequencer, the sequencer selected in the node will play automatically when you play the level

- When the render is done, within the `Left` and `Right` output folders you will find a sequence of `.TXT` files which look like this:
```
p f2 w4096 h2048 v360  n"TIFF"
o f0 w720 h720 n"RenderTest_000_000.00100.png" r180.000000 p108.000000 y0.000000 v50.000000
o f0 w720 h720 n"RenderTest_000_001.00100.png" r180.000000 p144.000000 y0.000000 v50.000000
o f0 w720 h720 n"RenderTest_000_002.00100.png" r180.000000 p180.000000 y0.000000 v50.000000
o f0 w720 h720 n"RenderTest_000_003.00100.png" r180.000000 p-144.000000 y0.000000 v50.000000
o f0 w720 h720 n"RenderTest_000_004.00100.png" r180.000000 p-108.000000 y0.000000 v50.000000
o f0 w720 h720 n"RenderTest_001_000.00100.png" r180.000000 p108.000000 y36.000000 v50.000000
o f0 w720 h720 n"RenderTest_001_001.00100.png" r180.000000 p144.000000 y36.000000 v50.000000
o f0 w720 h720 n"RenderTest_001_002.00100.png" r180.000000 p180.000000 y36.000000 v50.000000
o f0 w720 h720 n"RenderTest_001_003.00100.png" r180.000000 p-144.000000 y36.000000 v50.000000
o f0 w720 h720 n"RenderTest_001_004.00100.png" r180.000000 p-108.000000 y36.000000 v50.000000
o f0 w720 h720 n"RenderTest_002_000.00100.png" r180.000000 p108.000000 y72.000000 v50.000000
o f0 w720 h720 n"RenderTest_002_001.00100.png" r180.000000 p144.000000 y72.000000 v50.000000
```

## Stitch A Panorama Sequence

- Go to the [PTStitcher website](https://webuser.hs-furtwangen.de/~dersch/PTStitcherNG/PTStitcherNG.html) and download StitcherNG: [download link](https://webuser.hs-furtwangen.de/~dersch/PTStitcherNG/PTStitcherNG0.7b.zip) 
- In order to convert the whole sequence into a panorama, find the script called `util/stitcher.py` and use it like so:
```
cd util
python stitcher.py --stitcher C:/PTStitcher/PTStitcherNG.exe --outdir C:/Output/
```
- This will loop through every frame of both eyes and generate final images

## Stitch A Panorama Still
```
cd Output/Left
C:/PTStitcher/PTStitcherNG.exe -f RenderTest.00100.txt -o RenderTest.00100.tif
```
- This should give you a stitched single eye output

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
