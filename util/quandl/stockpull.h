#ifndef STOCK_H
#define STOCK_H


//-------------------------------------------------
//Includes 



#include <unistd.h> //That good good
#include <string.h> //String Manipulation
#include <stdio.h> //I/O
#include <getopt.h> //Opt Switching
#include <curl/curl.h> //Grab Data

#include "settings.h" //Contains a const char* named API_KEY (obsfucated for obvious reasons)


//#include <gmp.h>
//#include <mpfr.h>


int main(int argc, char **argv);
static FILE* requestFileAPI(char *fn, char *url, CURLcode res, CURL *ch);
static size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);

#endif
