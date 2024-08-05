@echo off
rem Batch file used by Pizza Builder to start the game using the play button.
rem USAGE:
rem start_game gameDirectory targetRoom targetDoor

cd %1
start PizzaTower2000.exe -room %2 %3
exit