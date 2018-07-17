Authors: Johannes Bunk, Guan Jianyu
E-Mail: bunk@uni-bremen.de, 499680344@qq.com
Date: July 2018
Versions: UE 4.18 / 4.19

This plugin enables you to take large numbers of images of Unreal Engine gameplay from many different perspectives. To record images in VR a second PC can be used to create and save the images, so it won't impact the main PCs performance. 
 

#Set up project:

##Before compiling:

*Drag the plugin into your projects "Plugins" folder. You may need to create the folder yourself. 

*Add the following lines of code to the bottom projects "DefaultEngine.ini" file and rebuild:

[OnlineSubsystem]
DefaultPlatformService=Null

##Replication 

*In your map make sure to set "Static Mesh Replicate" on every static mesh you want to interact with to true.

*In your VR pawn, if it is a blueprint, make sure it and every single component has "Component Replicates" activated. 
If your pawn is a c++ class you need to add code enabeling replication to all constructors. (not BeginPlay()!)
For the pawn itself you add "SetReplicateMovement(true)" and "SetReplicates(true)".
For components you add "SetIsReplicated(true)".

##Map setup

*In the editor go into project settings and under "Maps & Modes" change the following settings:

Default GameMode -> MultiplayerGameMode
Editor Startup Map -> Menu
Game Default Map -> Menu
Game Instance Class -> MyMultiplayerGI

*In your map make sure the player character is set to be auto possessed by player 0.
For the spectator you add a UVCamera for each perspective you want to record. They don't need to be possesed by any player. 
If you want to record what the user is doing in VR from a first person perspective you can do so by adding a UVCamera and enabeling "First Person View" for it.
Depending on which VR pawn you are using, you may need to edit the BeginPlay() Method in "UVCamera.cpp", so the UVCamera knows which pawns camera to search the map for.  

*If your game is not a VR game you want to delete the "Enable HMD" function from "MyMultiplayerGI".
Everything else should work fine. 

##Camera settings:

*In the project on the main PC you want to keep every UVCameras frame rate set to 0. This means it won't record aything. 

*In the project on the PC used for recording you enable "Capture Color Image", "Capture Scene Component" and "Save as Image" for each camera you want to use.

*Then set the frame rate and the size of the image you want to capture. 

#Runing the project

*Always start the project by right clicking on the uproject file and choosing "launch game". Otherwise you won't be able to use VR and multiplayer at the same time. 

*On your main PC with the VR headset you type the name of the map you want to load into the menu and click "Create Session".

*On the PC used for recording you click "Join Session" and then "Find Session". After some seconds the "0" in the upper right corner should change to a "1".
Then you click "Join".

*You can now start playing on the main PC. Whenever the game is paused there, the other PC will stop recording, since the timer it is using comes from the main PC.