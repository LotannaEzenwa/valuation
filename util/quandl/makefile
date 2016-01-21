all:
	gcc -Wall -pedantic -g -std=c11 stockpull.c -o stock -lcurl

clean:
	$(MAKE) cleanLogs
	rm stock
cleanLogs:
	rm ../logs/*