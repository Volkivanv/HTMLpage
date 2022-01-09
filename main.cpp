#include <iostream>
#include <cpr/cpr.h>
#include <string>

std::string header(std::string& inText){

    int begin = inText.find("<h1>");
 //  std::cout<<begin<<std::endl;
    int end = inText.find("</h1>");
            //  std::cout<<end<<std::endl;
    return inText.substr(begin+4,end-begin-4);
}

int main() {
    std::string txt;
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
                               cpr::Header({{"Accept", "text/html"}}));
    txt = r.text;
    //std::cout << r.text <<std::endl;
    std::cout << header(txt) << std::endl;
    return 0;
}
