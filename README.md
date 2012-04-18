#DVTM

This is a custom build of dvtm that I patched to work on cygwin.

To get this working with the minimal amount of fuss I suggest setting up your windows maching following the steps outlined [here](http://blog.developwithpassion.com/2012/03/12/repaving-a-new-window-7-vm).Just focus on the cygwin setup if you don't care about everything else.

Once cygwin is installed correctly just do the following in a cygwin prompt:

1. git clone git://github.com/developwithpassion/dvtm
2. cd dvtm
3. make && make install
4. Enjoy a tiled window manager.

For the best results I also compiled and run screen. That way I can have multiple windows with dvtm hosted inside of each. It's as close as I can get to tmux on windows for now, until I get around to patching it to work on windows!!

[Develop With Passion®](http://www.developwithpassion.com)
