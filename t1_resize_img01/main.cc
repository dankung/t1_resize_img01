/*	
	Created by 		: Daniel Agus Listiantoro
	Date Created 	: 28/4/2022
	Description		: Create a simple HTTP server application that listens on port 8080 to serves a
					specific function: resizing a jpeg image, in the form of base 64 encoded binary input data
					to the desired target dimension. The server only needs to serve exactly single API below:
*/

/*
Task 1:
Please create a simple HTTP server application that listens on port 8080 to serves a
specific function: resizing a jpeg image, in the form of base 64 encoded binary input data
to the desired target dimension. The server only needs to serve exactly single API below:

HTTP://[host_address]:8080/resize_image [POST]

Input Payload:
Content-Type: application/json
{
"input_jpeg": "[base 64 encoding of jpeg binary]",
"desired_width": [target_width],
"desired_height": [target_height]
}

Output Payload:
If success:
HTTP 200
Content-Type: application/json
{
"code": 200,
"message": "success",
"output_jpeg": "[base 64 encoding of output jpeg binary]"
}


If failed:
HTTP 4XX/5XX
Content-Type: application/json
{
"code": 4xx/5xx,
"Message": "[output error description here]"
}
*/

// Mengirim Payload dengan Postman
// Payload format text (JSON)

// HTTP://[host_address]:8080/resize_image [POST]  														---> belum bisa running
// HTTP://[host_address]:8080/resize_image/token?userid=daniel&passwd=test1234 	[POST]  				---> sudah bisa running
// HTTP://[host_address]:8080/resize_image/token?userid=xxx&passwd=xxx			[POST]					--> xxx bisa di isi

#include <drogon/drogon.h>
int main() {
    //Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0",8080);
    //Load config file
    //drogon::app().loadConfigFile("../config.json");
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}
