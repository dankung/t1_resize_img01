#include "TaskController.h"

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

// HTTP://[host_address]:8080/resize_image/ [POST]  														---> sudah bisa running


//using namespace ;
//add definition of your processing function here

/*
void Resize_Image::login(const HttpRequestPtr &req,
           std::function<void (const HttpResponsePtr &)> &&callback,
           std::string &&userId,
           const std::string &password,
			ImageSrc &&pImageSrc)
{
    LOG_DEBUG<<"User "<<userId<<" login";
	Json::Value ret;
	
	auto req1=HttpRequest::newHttpRequest();
	
	if (pImageSrc.input_jpeg == "" )
	{
		// error
		ret["code"]="4xx/5xx";
		ret["message"]="[output error description here]";
		auto resp=HttpResponse::newHttpJsonResponse(ret);
		callback(resp);
	}
	
	LOG_DEBUG << "isi imgbase64: " << pImageSrc.input_jpeg << "  end";
	LOG_DEBUG << "isi target_width: " << pImageSrc.desired_width << "  end";
	LOG_DEBUG << "isi target_height: " << pImageSrc.desired_height << "  end";
	
	
	Image_Converter img_converter;
	std::string imgbase64, imgbase64_out;
	
	Mat image_out;
	Mat image_resized;

		
	image_out = img_converter.str2mat(pImageSrc.input_jpeg);
	
	//resize 
	resize(image_out, image_resized, Size(pImageSrc.desired_width, pImageSrc.desired_height), INTER_LINEAR);
	imgbase64_out = img_converter.mat2str(image_resized);
	
	
    //Authentication algorithm, read database, verify identity, etc...
    //...
	//ImageSrc imgSrc = (*pImageSrc);
	
	
    
	
	ret["code"]="200";
	ret["message"]="success";
	ret["output_jpeg"]= imgbase64_out;
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void Resize_Image::getInfo(const HttpRequestPtr &req,
             std::function<void (const HttpResponsePtr &)> &&callback,
             std::string userId,
            const std::string &token) const
{
    LOG_DEBUG<<"User "<<userId<<" get his information";

    //Verify the validity of the token, etc.
    //Read the database or cache to get user information
    Json::Value ret;
    ret["result"]="ok";
    ret["user_name"]="Listiantoro";
    ret["user_id"]=userId;
    ret["gender"]=1;
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
*/
void Resize_Image::resize_image(const HttpRequestPtr &req,
                 std::function<void (const HttpResponsePtr &)> &&callback,
                 ImageSrc &&pImageSrc) const				 
{
	
	//LOG_DEBUG<<"Resize_Image::resize_image get his information";
	
	Json::Value ret;
	
	auto req1=HttpRequest::newHttpRequest();
	
	if (pImageSrc.input_jpeg == "" )
	{
		// error
		ret["code"]="4xx/5xx";
		ret["message"]="[output error description here]";
		auto resp=HttpResponse::newHttpJsonResponse(ret);
		callback(resp);
	}
	
	/*
	LOG_DEBUG << "isi imgbase64: " << pImageSrc.input_jpeg << "  end";
	LOG_DEBUG << "isi target_width: " << pImageSrc.desired_width << "  end";
	LOG_DEBUG << "isi target_height: " << pImageSrc.desired_height << "  end";
	*/
	
	Image_Converter img_converter;
	std::string imgbase64, imgbase64_out;
	
	Mat image_out;
	Mat image_resized;
	
	image_out = img_converter.str2mat(pImageSrc.input_jpeg);
	
	//resize 
	resize(image_out, image_resized, Size(pImageSrc.desired_width, pImageSrc.desired_height), INTER_LINEAR);
	imgbase64_out = img_converter.mat2str(image_resized);
	
	
    //Authentication algorithm, read database, verify identity, etc...
    //...
	//ImageSrc imgSrc = (*pImageSrc);
	

	ret["code"]="200";
	ret["message"]="success";
	ret["output_jpeg"]= imgbase64_out;
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
	
}