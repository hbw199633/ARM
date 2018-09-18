#########################################################################
# File Name: copy.sh
# Author: Kingyi
# mail:joseph2009@163.com
#Created Time:2017年01月12日 星期四 14时26分26秒
#########################################################################
#!/bin/bash
mount 192.168.0.237:/mnt/share/zhoumo /root/jsj
cp /root/jsj/03 /root/kejian/linuxC -r
umount /root/jsj
