UniTESK Trace Tools 2.7
=======================

Requirements
------------

1. Sun J2SE 5.0 http://java.sun.com
2. Eclipse 3.3 or 3.4 (Platform) http://eclipse.org
2. GEF 3.3 http://eclipse.org

Installation in Eclipse 3.4
---------------------------

Eclipse 3.4 uses new Update Manager by default.
In this case the installation procedure is as follows:

There is 'dropins' subdirectory in Eclipse installation directory.
Unpack UniTESK Trace Tools distribution to the 'dropins' subdirectory.

Or you may restore old Update Manager
(http://wiki.eclipse.org/Equinox_p2_Removal)
and install UniTESK Trace Tools in the same way as for Eclipse 3.3.

Installation in Eclipse 3.3
---------------------------

1. Just unpack the distribution.
2. To enable Eclipse integration:
  a. start Eclipse;
  b. go to menu Help -> Software Updates -> Manage Configuration;
  c. choose 'Add an Extention Location';
  d. select 'eclipse' subdirectory in unpacked distribution;
  e. Restart Eclipse.

Running from command line
-------------------------

Use 'bin/stargen.bat' (Windows) or 'bin/stargen.sh' (Linux)
to run HTML report generator from a command line.

Contacts
--------

UniTESK Lab 
www:    http://unitesk.com
e-mail: info@unitesk.com