This is a 32 bits MB-system version 5.5.2271 built with only Visual Studio 2013. It is meant to be run with with GMT5.2
The 4 interactive modules -- mbedit, mbnavadjust, mbnavedit and mbvelocitytool have some troubles loading files by using
the "File" button (something related to directory listing is screwed). However, this is not all that bad as one can still
open the file from the command line. E.G.  mbedit -I filename 


It is a stand-alone version in the sense that one do not need to install it, just run the executables from the installation dir.
The 4 interactive modules, however, need a X server. While in principle one could use a full Cygwin installation to do that, I have not tried it. What I tested and works fine is to install the VcXserver
http://sourceforge.net/projects/vcxsrv/files/vcxsrv/1.16.2.0/

To run the interactive modules and the VcXserver we need a further step:

- open the cmd shell, 'cd' to directory of installation (the one with the .exe and .dll) and declare this variable

SET DISPLAY=127.0.0.1:0.0

Attention, this is necessary for each time one starts a new cmd window (alternatively, declare it as an environment variable)

Note also that GMT is not included in this pack. Please use the one from the GMT site

Also, this new MB version converted the mbcontour, mnswath and mbgrdtiff into GMT modules, so to access them you must move
the "mbgmt_w32.dll" file into the 'bin\gmt_plugins' subdirectory of your GMT5 installation. 
