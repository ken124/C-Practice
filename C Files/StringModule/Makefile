obj-m += testchar.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(shell pwd) modules
	$(CC) tester.c -o tester
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(shell pwd) clean
