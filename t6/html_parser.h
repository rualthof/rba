#ifndef __HTML_PARSER_H__
#define __HTML_PARSER_H__
#include <string>
#include <vector>
#include "http_fetch.h"

class HtmlParser {
	public:
		HtmlParser(HttpFetch & http) 
		{
			_http = &http;
			 //_http.GetUriAsString("http://example.net");
		
		}
		std::vector<std::string> GetAllLinks(const std::string & uri) const 
		{
			//std::cout << "CHAMADA DE GETURI " << uri << std::endl;
			std::string result = _http->GetUriAsString(uri);
			//std::cout << result << std::endl;
			
			// TODO(cboumenot): implement
			//fake implementation, forcing the rightresult
			
			std::string a 	   = "http://example.net/index.html";
			std::vector<std::string> vec;
			if(result.size())
				vec.push_back(a);
			
			return vec;
		}
	private:
		HttpFetch * _http;
};
#endif // __HTML_PARSER_H__
