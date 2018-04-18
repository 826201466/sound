# ---------------------- SOUND SENSOR PROJECT ------------------------

This project is meant to collect sound level at a proximity of a Rasberry Pi
device. The RPi is equipped with a USB sound card (C-Media Electronics, Inc.
Audio Adapter) and a microphone. The sound is record at 16000Hz sample rate
and every second will produce 80 pieces of RMS value as a bar-diagram...

Table of Content
1. Configuration instructions
2. Installation instructions
3. Operation instructions
4. Manifest (list of files and short description of their roles)
5. License
6. Contact information

----------------------------------------------------------------------
1. Configuration instructions

   RPi default Booting and keyboard layout
   -Run "sudo raspi-config"
   -Select "boot options"
   -Select "B2 Console Autologin"
   -Select "SSH" "Yes" "Ok"
   **Remember to reboot by "sudo reboot"

   Send IP address by email
		It's a very fast way to get the IP address from your Pi
   -Open the putty
   -"Pi" as username
   -"Raspberry" as pssword
   -Run "sudo nano /etc/rc.local."
   -Add"
   #!/bin/sh -e
   #
   # rc.local
   #
   # This script is executed at the end of each multiuser runlevel.
   # Make sure that the script will "exit 0" on success or any other
   # value on error.
   #
   # In order to enable or disable this script just change the execution
   # bits.
   #
   # By default this script does nothing.
   
   # Print the IP address
   sleep 30
   
   _IP=$(hostname -I) || true
   if [ "$_IP" ]; then
     printf "My IP address is %s\n" "$_IP"
       curl --url http://www.cc.puv.fi/~gc/php/sendMailRPi.php -d email=youremail&from=gcPi3
       curl --url http://www.cc.puv.fi/~gc/php/rasp.php -d "ip=$_IP&name=gcPi3"
       curl --url http://www.cc.puv.fi/~juma/raspi/rasp_ip.php -d "auth=mckdoe03&name=gcPi3&ip=$_IP"
       fi
           
       exit 0"
    
    
2. Installation instructions
   -Boot up RPi, and apply the USB sound card
   -Use "~ $ lsusb"
   		pi@raspberrypi:~ $ lsusb
   		Bus 001 Device 004: ID 0d8c:000c C-Media Electronics, Inc. Audio Adapter
   		Bus 001 Device 003: ID 0424:ec00 Standard Microsystems Corp. SMSC9512/9514 Fast Ethernet Adapter
   		Bus 001 Device 002: ID 0424:9514 Standard Microsystems Corp.
   		Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
   	-Use "sudo nano /etc/asound.conf"
   		pcm.!default {
   		  type plug
   		  slave {
   		        pcm "hw:1,0"
   		        }
   		  }
   		  ctl.!default {
   		        type hw
   		        card 1
   		  }
    -Use "nano .asoundrc"
    -Run "alsamixer" you should be able to see that USB sound card is the default audio device           


3. Operation instructions
    -Use "make"
    -Run "./sound.a"
    
    
4. Manifest (list of files and short description of their roles)
   comm.c  comm.h  main.c  screen.c  screen.h sound.c  sound.h test.wav makefile  README.TXT
   sound.a 

5. License
   
   If you publish your source code in a public repository on GitHub, according to the Terms of Service, 
   other GitHub users have the right to view and fork your repository within the GitHub site. 
   If you have already created a public repository and no longer want users to have access to it, 
   you can make your repository private. When you convert a public repository to a private repository, 
   existing forks or local copies created by other users will still exist. For more information, 
   see "Making a public repository private."

6. Contact information

  Sun Ziqiu
  Department of Information Technology Vaasa University of Applied Sciences
  Woffinitie 30, Vaasa, Finland
  Home:http://www.cc.puv.fi/~e1700703
  Email: 826201466@qq.com
