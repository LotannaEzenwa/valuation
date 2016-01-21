#include "stockpull.h"


int main(int argc, char *argv[]){

	int opt = 0;
	char buff[PATH_MAX + 1];
	char* API = "https://www.quandl.com/api/v3/datasets/WIKI/%s%s?auth_token=%s";
	char* ext = ".csv";
	char path[1024] = "../../data";
	char *cwd = getcwd(buff,PATH_MAX+1);
	char c;



	if (argc == 1 || strstr(argv[1],"--help")){
		printf ("Usage: %s [TICKER] [DIRECTORY] [-o]\n", argv[0]); //help command
		printf("\n\n");
		printf("\t[TICKER]: EITHER NSYE OR NASDAQ EQUITY TICKER\n\n\n");
		printf("\t[DIRECTORY]: MUST BE A VALID, CREATED DIRECTORY FOR STORING PAGES\n\n\n");
		printf("-------------------------------------------------------------------\n\n\n");
		printf("\t-o: Options Pricing\n");
		return 1;
	}


    while ((c = getopt (argc, argv, "")) > 0) {

        if (c == -1){ //No options left
            break;
        }

        switch (c) { //Switch the options

        	case 'o':
        		fprintf(stdout, "Options for Ticker:%s Selected\n", argv[optind]);
        		opt = 1;
        		break;
        	default:
          	printf ("Invalid argument for %s\n", argv[0]); //Bad argument default
			return 2;
			
        }
    }

    argc -= optind; //Increment argument number
    argv += optind; //Increment argument pointer


  // Create Correct URL String
  char url[1024];
  char filename[64];
  strcat(filename,argv[0]);
  strcat(filename,ext);
  int urlLen = sprintf(url,API,argv[0],ext,API_KEY);

  // Init Curl
  CURLcode status = curl_global_init(CURL_GLOBAL_SSL);
  CURL* ch = curl_easy_init();




  //Do Some Stuff Here
  if (!status || !ch){
  	chdir(path);
  	FILE* fp = requestFileAPI(filename,url,status,ch);
  	chdir(cwd);
  }


  // Clean Up Curl
  curl_global_cleanup();

  return 0;
}


static char* buildURL(char* api, char* TICKER){
	return NULL;
} 

static size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}

static FILE* requestFileAPI(char *fn, char *url, CURLcode res, CURL *ch){
	FILE* p = fopen(fn,"w");
	if (!fn | !p){
		return NULL;
	}

	curl_easy_setopt(ch, CURLOPT_URL, url);
	curl_easy_setopt(ch, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(ch, CURLOPT_WRITEDATA, p);
	res = curl_easy_perform(ch);
	fclose(p);

	return p;
	
}



