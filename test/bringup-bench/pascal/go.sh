#!/bin/bash

cc -Wall -O0 -g -Wno-strict-aliasing -DLIBTAR_HOST  -DTARGET_HOST -I../common/ -o pascal.o -c pascal.c
cc -Wall -O0 -g -Wno-strict-aliasing -DLIBTAR_HOST  -DTARGET_HOST -I../common/ -o libmin.o -c ../common/libmin.c
cc -Wall -O0 -g -Wno-strict-aliasing -DLIBTAR_HOST  -DTARGET_HOST -I../common/ -o libtarg.o -c ../common/libtarg.c
cc -Wall -O0 -g -Wno-strict-aliasing -DLIBTAR_HOST  -o pascal.host pascal.o libmin.o libtarg.o  
./pascal.host > FOO 
diff FOO pascal.out
