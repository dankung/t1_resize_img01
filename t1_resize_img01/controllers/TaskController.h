#pragma once
#include <drogon/HttpController.h>
#include "image_converter.h"


using namespace drogon;

struct ImageSrc{
    std::string input_jpeg;
    int desired_width;
    int desired_height;
};

namespace drogon
{
	template <>
	inline ImageSrc fromRequest(const HttpRequest &req)
	{
		auto json = req.getJsonObject();
		//LOG_DEBUG << "ImageSrc fromRequest get his information";
		
		ImageSrc imgSrc;
		if(json)
		{
			if(!(*json)["input_jpeg"].isNull())
			{
				imgSrc.input_jpeg = (*json)["input_jpeg"].asString();

			} else
				imgSrc.input_jpeg = "";								// blank
			
			if(!(*json)["desired_width"].isNull())
			{
				imgSrc.desired_width = (*json)["desired_width"].asInt();

			} else
				imgSrc.input_jpeg = "";								// blank
			
			if(!(*json)["desired_height"].isNull())
			{
				imgSrc.desired_height = (*json)["desired_height"].asInt();

			} else
				imgSrc.input_jpeg = "";								// blank
			

		}
		return imgSrc;
	}
}

class Resize_Image:public drogon::HttpController<Resize_Image>
{
	public:
		METHOD_LIST_BEGIN
			//use METHOD_ADD to add your custom processing function here;
			//METHOD_ADD(Resize_Image::login,"/token?userId={1}&passwd={2}",Post);		//				---> sudah bisa resize image dari base64		
			//METHOD_ADD(Resize_Image::getInfo,"/{1}/info?token={2}",Get);
			METHOD_ADD(Resize_Image::resize_image,"/",Post);							//				---> Sudah bisa resize image dari base64		
		METHOD_LIST_END
		//your declaration of processing function maybe like this:
		/*
		void login(const HttpRequestPtr &req,
				   std::function<void (const HttpResponsePtr &)> &&callback,
				   std::string &&userId,
				   const std::string &password
				   , ImageSrc &&pImageSrc );
		void getInfo(const HttpRequestPtr &req,
					 std::function<void (const HttpResponsePtr &)> &&callback,
					 std::string userId,
					 const std::string &token) const;
		*/			 
		void resize_image(const HttpRequestPtr &req,
                 std::function<void (const HttpResponsePtr &)> &&callback,
                 ImageSrc &&pImageSrc) const;				 
};
