#include "comm.h"
#include <stdio.h>
#include <curl/curl.h>
#include <math.h>

void sendToServer(double r80[]){
	double r8[8],sum;
	int i,j;
	CURL *curl;
	CURLcode res;
	char post[1000];

	for(i=0;i<8;i++)
	{
		sum=0;
		for(j=0;j<10;j++){
			sum+=r80[j+i*10]*r80[j+i*10]*200;
		}
		r8[i]= sqrt(sum/2000);
	}
	sprintf(post,"data=%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f",
		r8[0],r8[1],r8[2],r8[3],r8[4],r8[5],r8[6],r8[7]);
	// send data
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if(curl){
		//printf("curl is okay\n");
		curl_easy_setopt(curl, CURLOPT_URL,URL);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,post);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
}
