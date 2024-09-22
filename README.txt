# Pizza Tower 2000

This is Pizza Tower 2000 - essentially Pizza Tower, but for much, much older systems, and also made in GameMaker 6.

This ZIP file contains the following:
* Pizza Tower 2000 itself
* The Launcher, used for toggling widescreen mode and switching between characters
* Pizza Builder, the level editor

# Game doesn't open/runs in the background after launching it

If you try to open Pizza Tower 2000 or Pizza Builder on Windows Vista or any newer version of Windows, it won't open and will stay running in the background until you end its process in Task Manager.
This can be fixed by using the patching tool that is included and can be found in the tools folder. Use the tool to patch the Pizza Tower 2000 and Pizza Builder executables and then it will work properly.

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
	* KnightAttackType -- changes the knight transformations attack behavior - setting it to 0 makes it into a sword attack, while setting it to 1 turns it into a jump attack.
* Piledriver -- settings for the piledriver state
    * PiledriverAnim -- whether the enemy held by the player should rotate
    * PiledriverXOffset -- the enemies X offset during the piledriver
    * PiledriverYOffset -- the enemies Y offset during the piledriver

Since GameMaker 6 doesn't support alpha channels for sprites, a batch file (convert_sprites.bat) can be found in the tools folder to make the process of replacing the transparent background with a solid color a lot quicker.
This batch file needs to be placed in a folder containing all of the sprites in PNG format and also requires ImageMagick (7.1.1 is what I use) to be installed and present in your PATH environment variable (which should be an option in ImageMagick's installer).

As for making the sprites into GIFs, that's something you have to figure out on your own. If you use Aseprite, then doing that should be pretty simple.