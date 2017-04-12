# Simple SNMP Agent and Manager
This is a simple of demonstration of a SNMP agent and manager written in pysnmp.
### Features
  - Supports GET, SET and TRAP
  - Custom MIB
### Pre-requisite Installation
Get Update
```sh
$ sudo apt-get update
```
Install Apache2 
```sh
$ sudo apt-get install apache2
```
Run the Apache Service (make sure there are no errors)
```sh
$ sudo service apache2 start
```
> Chech localhost on your browser : http://localhost

Install snmp
```sh
$ sudo apt-get install snmp
```
Install python-pip
```sh
$ sudo apt-get install python-pip
```
### Main Installation
Install pysnmp
```sh
$ sudo pip install pysnmp
```
Download libsmi module (used to compile the MIB)
https://www.ibr.cs.tu-bs.de/projects/libsmi/download/libsmi-current.tar.gz
Extract the module
```sh
$ cd libsmi-0.5.0/
$ chmod 777 * 
$ ./configure
$ sudo make
$ sudo make install
$ export LD_LIBRARY_PATH=/usr/local/lib
```
> For explaination of the agent code and custom MIB compilation please follow the instructions from here
http://www.nealc.com/blog/blog/2013/02/23/writing-an-snmp-agent-with-a-custom-mib-using-pysnmp/

Note after you build the MIB please copy it to /usr/share/snmp/mibs/ folder
```sh
$ sudo cp < mib-name > /usr/share/snmp/mibs/
```
### Running the agent and monitor
Launch the monitor
```sh
$ sudo python monitor.py
```
Open a new terminal and launch the agent
```sh
$ sudo python agent.py
```
> Should work like a gem (if you have followed the installation properly)

#### Note
This instruction is written after some experience in setting up the SNMP protocol and does not promise to cover all system realated problems faced during the installation of the same, this Repo is shared soley to facilitate a quick understanding of the snmp protocol, the level of understanding and usage of the code is left to the descretion of the user. Any harm to the host computer is regretted
> The owner of the Repo does not take any credit in the content presented above. "He just made it work".
 