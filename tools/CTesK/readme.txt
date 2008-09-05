CTESK 2.6
============

System Requirements
-------------------

1. Core utilities + gcc, make, gdb
2. Sun J2SE 5.0 or higher (http://java.sun.com)
3. Ecilpse RCP/Platform Runtime Binary 3.3 or higher (http://eclipse.org)
4. Eclipse C/C++ Development Tools 4.0.2 or higher (http://eclipse.org)
   (Eclipse CDT Testing Feature depends on org.junit plug-in.
    If org.junit isn't installed CDT Testing Feature should not be installed)
5. UniTESK Trace Tools 2.7 or higher (http://unitesk.ru)


Installation
------------

1. Unpack archive.

   NOTE: Eclipse 3.4 uses new Update Manager by default.
   There is 'dropins' subdirectory in Eclipse installation directory.
   JavaTESK distribution should be unpacked to this subdirectory.

   For easy future updates it's recommended
   to rename enclosed directory ctesk-${version} to ctesk
   (or some other name without version number).
   The shell script 'bin/sec.sh' starts CTESK translator from the command line.
2. Set environment variable CTESK_HOME - path to unpacked archive.
3. Add directory %CTESK_HOME%/bin to PATH.
4. Setting up Eclipse 3.3 integration (unnecessary for Eclipse 3.4):
  a. start Eclipse;
  b. select menu Help -> Software Updates -> Manage Configuration;
  c. choose 'Add an Extention Location';
  d. choose 'eclipse' subdirectory of unpacked archive;
  e. restart Eclipse.
5. Install UniTESK Trace Tools to generate reports on test results.


Update
------
1. Close Eclipse before update to new version of CTESK.
2. If new version is installed in the same directory,
   it's enough to unpack archive (and rename enclosed directory).
3. If new version should be installed to other directory,
   it's required to repeat steps 1-4 from Installation section.
4. To complete installation, check System Requirements section
   in readme file of the new version and update your system if needed.


Contacts
--------

UniTESK Lab 
www:    http://unitesk.com
e-mail: info@unitesk.com
