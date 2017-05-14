#include <iostream>
#include <string>
#include <vector>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "http_fetch.h"
#include "html_parser.h"


using ::testing::Return;

class HttpFetchMock : public HttpFetch {
	public:
		MOCK_CONST_METHOD1(GetUriAsString, std::string(const std::string & uri));
};

TEST(HtmlParser, OneLink) {
	
	// --------- The mock
    std::string html = "<html><head></head><body><a href='/index.html'>index.html</a></body></html>";
    
    HttpFetchMock mock;
    HtmlParser parser(mock);
    
    //Defining the response of the function call GetUriAsString("http://example.net")
    EXPECT_CALL(mock, GetUriAsString("http://example.net"))
        .WillOnce(Return(html)); //Se nao for chamado uma vez da erro
            
    // ----------- The test
    //Making the parser call
    std::vector<std::string> links = parser.GetAllLinks("http://example.net");

	//mock.GetUriAsString("http://example.net");
    //std::cout<<mock.GetUriAsString("http://example.net")<<std::endl;
    //std::cout<<links.size()<<std::endl;
    
    //Checking the results
    EXPECT_EQ(1, links.size());
    EXPECT_STREQ("http://example.net/index.html", links[0].c_str());
}

TEST(HtmlParser, NoData) {
	
	// --------- The Mock
	std::string html = "";
    HttpFetchMock mock;
    HtmlParser parser(mock);
    EXPECT_CALL(mock, GetUriAsString("http://example.net"))
        .WillOnce(Return(html));

	// -------- The Test
    std::vector<std::string> links = parser.GetAllLinks("http://example.net");
    EXPECT_EQ(0, links.size());
}

TEST(HtmlParser, BothTests) {
	
	// --------- The Mock
	std::string html = "<html><head></head><body><a href='/index.html'>index.html</a></body></html>";
	std::string html2 = "";
	
    HttpFetchMock mock;
    HtmlParser parser(mock);
    EXPECT_CALL(mock, GetUriAsString("http://example.net"))
        .WillOnce(Return(html))
        .WillOnce(Return(html2));

	// -------- The Test
    std::vector<std::string> links = parser.GetAllLinks("http://example.net");
    EXPECT_EQ(1, links.size());
    EXPECT_STREQ("http://example.net/index.html", links[0].c_str());
        
    links = parser.GetAllLinks("http://example.net");
    EXPECT_EQ(0, links.size());
}

#include "gmock/gmock.h"
using namespace testing;
 
// Start writing unit tests here!
 
int main(int argc, char * argv[])
{
    ::InitGoogleMock( &argc, argv );
    return RUN_ALL_TESTS();
}
