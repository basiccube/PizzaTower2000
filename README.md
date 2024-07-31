# Pizza Tower 2000

This is Pizza Tower 2000 - essentially Pizza Tower, but for much, much older systems, and also made in GameMaker 6.

This repository contains the following:
* Pizza Tower 2000 itself
* The Launcher, used for toggling widescreen mode and switching between characters
* Pizza Builder, the level editor
* PLITool, a small tool made for creating files that specify level info

# Game doesn't open/runs in the background after launching it

If you try to open Pizza Tower 2000, Pizza Builder, or PLITool on Windows Vista or any newer version of Windows, it won't open and will stay running in the background until you end its process in Task Manager.
This can be fixed by using the patching tool that is included in the releases and can be found in the tools folder or can be downloaded [here](https://www.mfgg.net/index.php?act=resdb&param=02&c=6&id=12637). Use the tool to patch all 3 executables (the launcher doesn't need to be patched) and then it will work properly.

The reason why I don't include the patched versions by default is because in the past I've encountered an issue where you couldn't exit the level during Pizza Time, though while I don't think that happens anymore I still don't fully trust the patch anyway.

# Adding additional characters

The character system lets you add new characters to Pizza Tower 2000 in a somewhat easy way.
Characters are located in gfx\player and each character has its own folder.

All sprites must be in GIF format, must have the same file name and also must be the same size for them to work properly.

Alongside all of the sprites, a character.ini file is present in every character folder. This file specifies a few settings and some information for the character.
Currently, the following options exist:

* Character -- general settings for the character
    * Name -- the name that will be used in-game and in the launcher
    * UseMachFreefall -- use the spr_player_machfreefall sprite in a few specific states, if disabled, use the spr_player_fall sprite instead
    * GrabTurnBoost -- changes the behavior when pressing the opposite arrow key while holding dash during a grab. If enabled, the character does a mach 3 turn, if disabled, a mach 2 turn instead
* Piledriver -- settings for the piledriver state
    * PiledriverAnim -- whether the enemy held by the player should rotate
    * PiledriverXOffset -- the enemies X offset during the piledriver
    * PiledriverYOffset -- the enemies Y offset during the piledriver

Since GameMaker 6 doesn't support alpha channels for sprites, a batch file (convert_sprites.bat) is included to make the process of replacing the transparent background with a solid color a lot quicker.
This batch file needs to be placed in a folder containing all of the sprites in PNG format and also requires ImageMagick to be installed and present in your PATH environment variable (which should be an option in ImageMagick's installer).

As for making the sprites into GIFs, that's something you have to figure out on your own. If you use Aseprite, then doing that should be pretty simple.

# More info

While Pizza Tower 2000, Pizza Builder and PLITool are made using GameMaker 6 (6.1 to be specific),
the launcher on the other hand... is made using Borland C++ Builder 6.

Why, you might ask?
The answer is:

I didn't want such a simple launcher to require something like .NET Framework 2.0 (as C# is something I'm more familiar with, but even then I'm not that great at writing C# code). And also the fact that I didn't want to figure out how to make a launcher using plain old Win32.

So I tried looking for a much easier solution, and this is what you get as a result. I'm no C or C++ programmer, so if the code of the launcher is awful, that's why.