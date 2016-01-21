#include "stockpull.h"


int main(int argc, char *argv[]){
	if (argc == 1 || strstr(argv[1],"--help")){
		printf ("Usage: %s [TICKER] [DIRECTORY] [-o]\n", argv[0]); //help command
		printf("\n\n");
		printf("[TICKER]: EITHER NSYE OR NASDAQ EQUITY TICKER\n\n\n");
		printf("[DIRECTORY]: MUST BE A VALID, CREATED DIRECTORY FOR STORING PAGES\n\n\n");
		printf("-------------------------------------------------------------------\n\n\n");
		printf("\n\n\n");
		printf("-o: Options Pricing\n");
		return 1;
	}

	int opt = 0;


    while ((c = getopt (argc, argv, "")) > 0) {

        if ((c == -1)){ //No options left
            break;
        }

        switch (c) { //Switch the options

        	case 'o':
        		fprintf(stdout, "Options for Ticker:%s Selected\n", argv[argc-1]);
        		opt = 1;
        		break
        	default:
          	printf ("Invalid argument for %s\n", argv[0]); //Bad argument default
			return 2;
			
        }
    }

    argc -= optind; //Increment argument number
    argv += optind; //Increment argument pointer

  // Init Curl
  curl_global_init(CURL_GLOBAL_SSL);

  //Do Some Stuff Here

  // Clean Up Curl
  curl_global_cleanup();

  return 0;
}

static 
