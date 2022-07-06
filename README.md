# t1_resize_img01
A simple HTTP server application that listens on port 8080 to serves a
specific function: resizing a jpeg image, in the form of base 64 encoded binary input data
to the desired target dimension.


The server only needs to serve exactly single API below:
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

Requirements:
1. Drogon Framework 
    https://drogon.docsforge.com/master/installation/
2. OpenCV 4.xx
3. CMake 3.2.x

This program is tested under Linux Ubuntu 20 LTS,running on VirtualBox Windows 10 Hosts
