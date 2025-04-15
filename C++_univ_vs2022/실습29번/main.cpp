#include "movie.h"
#include <iostream>
#include <map>
#include <vector>

int main() {
    std::map<std::string, std::vector<int>> ratings;
    std::map<std::string, Genre> genres;

    std::string title, genreStr, ratingStr;

    std::vector<Movie> vec;
    /*
    while(1){
        Movie m;
        getline(std::cin, m.title);
        if (title == "q") break;
        getline(std::cin, genreStr);
        m.genre = toGenre(genreStr);
        getline(std::cin, ratingStr);
        m.rating = toRating(ratingStr);
        vec.push_back(m);
        //이런 방식으로 구조체를 배열로 만들어서 입력 받는다.
    }
    */
    while (std::getline(std::cin, title) && title != "q") {
        std::getline(std::cin, genreStr);
        std::getline(std::cin, ratingStr);
        Movie m;
        m.title = title;
        m.genre = toGenre(genreStr);
        m.rating = toRating(ratingStr);
        vec.push_back(m);

        if (ratings.find(title) == ratings.end()) {
            genres[title] = m.genre;
            //조건: 중복될 경우 map 만드는 법 = 영화 제목이 중복될 경우 평점벡터에 누적

             //(필독) std::map의 find 함수는 만약 키가 존재하면 해당 키-값 쌍을 가리키는 반복자를 반환하고, 존재하지 않으면 end() 반복자를 반환합니다.
            // end() 함수는 맵의 끝을 나타내는 반복자를 반환합니다. 이 반복자는 맵의 마지막 요소 다음을 가리키며, 실제 요소를 가리키지 않습니다.
             //따라서, ratings.find(title) == ratings.end() 표현식은 다음과 같은 의미를 가집니다 :
             //true: title 키가 맵에 존재하지 않음을 의미합니다.
             //false : title 키가 맵에 존재함을 의미합니다.
        }
        ratings[title].push_back(toInt(m.rating));
        //map을 만들어서 출력하기위해 준비(map은 여기에서 만듦)
    }

    printSummary(ratings, genres);

    return 0;
}