Authors: Johannes Bunk

E-Mail: bunk@uni-bremen.de

Date: October 2018

Versions: UE 4.18 / 4.19 / 4.20  

This plugin is a very simple multiplayer game mode for VR, where the server is a PC with a VR headset and the clients just mirror that world. 


# Setting up the project

## Before compiling:

* Drag the plugin into your projects "Plugins" folder. You may need to create the folder yourself. 

* Add the following lines of code to the bottom projects "DefaultEngine.ini" file and rebuild:  

[OnlineSubsystem]  
DefaultPlatformService=Null

## Replication:

* In your map make sure to set "Static Mesh Replicate" on every static mesh you want to interact with to true.

* In your VR pawn, if it is a blueprint, make sure it and every single component has "Component Replicates" activated. 
If your pawn is a c++ class you need to add code enabeling replication to all constructors. (not BeginPlay()!)
For the pawn itself you add "SetReplicateMovement(true)", "SetReplicates(true)" and "VRCamera->SetIsReplicated(true)".
For other components you add "SetIsReplicated(true)" in their own constructors.

* If you are using a skeletal mesh that is moved using physics things are alot more complicated. Our current solution is to create a poseable mesh on the client and let it mirror the position the skeletal mesh has on the server. 

## Maps:

* In the editor go into the project settings and under "Maps & Modes" change the following settings:  

Default GameMode -> MultiplayerGameMode  
Editor Startup Map -> Menu  
Game Default Map -> Menu  
Game Instance Class -> MyMultiplayerGI

* In your map make sure the player character is set to be auto possessed by player 0.

* If your game is not a VR game you want to delete the "Enable HMD" function from the "MyMultiplayerGI" blueprint.
Everything else should work fine. 

# Runing the project

* Always start the project by right clicking on the uproject file and choosing "launch game". Otherwise you won't be able to use VR and multiplayer at the same time. 

* On your main PC with the VR headset you type the name of the map you want to load into the menu and click "Create Session".

* On the PC thas is supposed to be a client you click "Join Session" and then "Find Session". After a few seconds the "0" in the upper right corner should turn into a "1". Then you click "Join".