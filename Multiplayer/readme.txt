Author: Johannes Bunk 
E-Mail: bunk@uni-bremen.de
Date: May 2018
Version: UE 4.18


Set up project:

Add the following lines of code to the bottom projects "DefaultEngine.ini" file and rebuild:

[OnlineSubsystem]
DefaultPlatformService=Null

In the editor go into project settings and unter "Maps & Modes" change the following settings:

Default GameMode -> MultiplayerGameMode
Editor Startup Map -> Menu
Game Default Map -> Menu
Game Instance Class -> MyMultiplayerGI

In the "MyMultiplayerGI" blueprint you can change the map you want to load using the "Open Level" function.
In your chosen map make sure the player character is set to be auto possessed by player 0.
For each spectator you add a camera, set it to the wanted position and set it to be possessed by the chosen player.
Player 0 is the client who created the lobby and the other clients count up from there. 

If your game is not a VR game you want to delete the "Enable HMD" function from "MyMultiplayerGI".
Everything else should work fine. 

In your map make sure to set "Static Mesh Replicate" on every static mesh you want to interact with to true.
In your VR pawn make sure every single component has "Component Replicates" activated. 
On the pawn itself activate the following: "Always Relevant", "Replicate Movement", "Net Load on Client", "Replicates" and "Net Dormancy -> DORM Never".
Always start the project by right clicking on the uproject file and choosing "launch game".
