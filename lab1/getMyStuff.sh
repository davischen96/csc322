#!/bin/bash

# get user id
echo user id: $UID
# primary group id:
echo primary group id: `id -G $USER`
# names of all groups:
echo all groups names: `id -Gn $USER`
# absolute path of bash shell
echo abs path to bash shell: \/bin\/bash
# absolute path of home directory
echo abs path of home dir: $HOME	# echo abs path of home dir: `cd ~; pwd`
# PATH env variable
echo \$PATH: $PATH
 
 
