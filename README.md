# Pizza Tower 2000

This is Pizza Tower 2000 - essentially Pizza Tower, but for much, much older systems, and also made in GameMaker 6.

This repository contains the following:
* Pizza Tower 2000 itself
* The Launcher, used for toggling widescreen mode and switching between characters
* Pizza Builder, the level editor
* PLITool, a small tool made for creating files that specify level info


While Pizza Tower 2000, Pizza Builder and PLITool are made using GameMaker 6 (6.1 to be specific),
the launcher on the other hand... is made using Borland C++ Builder 6.

Why, you might ask?
The answer is:

I didn't want such a simple launcher to require something like .NET Framework 2.0 (as C# is something I'm more familiar with, but even then I'm not that great at writing C# code). And also the fact that I didn't want to figure out how to make a launcher using plain old Win32.

So I tried looking for a much easier solution, and this is what you get as a result. I'm no C or C++ programmer, so if the code of the launcher is awful, that's why.