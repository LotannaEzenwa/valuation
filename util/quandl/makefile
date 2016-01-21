all:
	gcc -Wall -pedantic -std=c11 stockpull.c -o stock -lcurl

clean:
	$(MAKE) cleanLogs
	rm stock
cleanLogs:
	rm ../logs/*