####################################################
# Copyright (C) 2017 ==Tangtao== All rights reserved.
# File Name: down.sh
# Author: Tangtao
# mail:280879897@qq.com
#Created Time:2017年07月26日 星期三 15时25分53秒
####################################################
#!/bin/bash
sudo mount 172.16.4.134:/mnt/nfs/170515/  /mnt
sudo cp  /mnt     /home/uplooking/jsj/   -rv
sudo umount /mnt
