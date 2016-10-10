mikeh@XubuntuDellLat:~/gtk-colours$ make install
make: *** No rule to make target `install'.  Stop.
mikeh@XubuntuDellLat:~/gtk-colours$ cd Debug/
mikeh@XubuntuDellLat:~/gtk-colours/Debug$ make install
Making install in src
make[1]: Entering directory `/home/mikeh/gtk-colours/Debug/src'
make[2]: Entering directory `/home/mikeh/gtk-colours/Debug/src'
 /bin/mkdir -p '/usr/local/bin'
  /bin/bash ../libtool   --mode=install /usr/bin/install -c gtk_colours '/usr/local/bin'
libtool: install: /usr/bin/install -c gtk_colours /usr/local/bin/gtk_colours
/usr/bin/install: cannot remove '/usr/local/bin/gtk_colours': Permission denied
make[2]: *** [install-binPROGRAMS] Error 1
make[2]: Leaving directory `/home/mikeh/gtk-colours/Debug/src'
make[1]: *** [install-am] Error 2
make[1]: Leaving directory `/home/mikeh/gtk-colours/Debug/src'
make: *** [install-recursive] Error 1
mikeh@XubuntuDellLat:~/gtk-colours/Debug$ 



Mon Aug 01 12:54:56 AEST 2016 
did a make install and received the error above - try changing permission on : /usr/local/bin/gtk_colours


