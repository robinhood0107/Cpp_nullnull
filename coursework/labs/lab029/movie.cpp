#include "movie.h"
#include <cmath>// std::round를 사용하기 위해 추가

Genre toGenre(const std::string& str) {
    if (str == "Action") return Genre::Action;
    if (str == "Comedy") return Genre::Comedy;
    if (str == "Drama") return Genre::Drama;
    if (str == "Romance") return Genre::Romance;
    if (str == "SciFi") return Genre::SciFi;
    //switch같은 객기 부리지 말고 반드시 if로 깔끔하게 끝내라(이게 제일 보기 편함)
}

Rating toRating(const std::string& str) {

    if (str == "★☆☆☆☆") return Rating::One;
    if (str == "★★☆☆☆") return Rating::Two;
    if (str == "★★★☆☆") return Rating::Three;
    if (str == "★★★★☆") return Rating::Four;
    if (str == "★★★★★") return Rating::Five;
    else return Rating::Unrated;

    //앞으로 이런건 걍 이렇게 하자!!!!
	//아니 그냥 ★이거 위치 세지 말고 그냥 if 문 연속으로 써서 판단하는게 제일 정확함 //이전 것은 너무 복잡하게 생각했음(find는 이럴때 사용안하는 것)
    // 앞으로 이렇게 if문으로 금방 표현할 수 있는 것은 머리아프게 생각하지 말고 이렇게 짜도록 하자
}

int toInt(Rating r) {
    switch (r) {
    case Rating::One: return 1;
    case Rating::Two: return 2;
    case Rating::Three: return 3;
    case Rating::Four: return 4;
    case Rating::Five: return 5;
    default: return 0;
    }
}

int avg(const std::vector<int>& list) {
    double sum = 0;
    for (int i = 0; i < list.size(); i++) {
        sum += list[i];
    }
    double avg = sum / list.size();
    return static_cast<int>(std::round(avg));
    //이 코드는 걍 외워라 cmath 사용하면 round 함수 사용 가능한거도 암기
}

void printSummary(const std::map<std::string, std::vector<int>>& ratings,
    const std::map<std::string, Genre>& genres) {
    std::cout << "Movie Ratings Summary:" << std::endl;

    for (const auto& it : ratings) {
        const std::string& title = it.first;
        const std::vector<int>& ratingList = it.second;
        Genre genre = genres.at(title);

        std::cout << title << ": " << ratingList.size() << " ratings, average rating " << avg(ratingList) << " stars, genre: ";

        std::string genreStr;
        switch (genre) {
        case Genre::Action: genreStr = "Action"; break;
        case Genre::Comedy: genreStr = "Comedy"; break;
        case Genre::Drama: genreStr = "Drama"; break;
        case Genre::Romance: genreStr = "Romance"; break;
        case Genre::SciFi: genreStr = "SciFi"; break;
        }
        std::cout << genreStr << std::endl;
        //map의 string vector를 따로 접근하려면 it.first와 it.second로 접근해야 한다.
    }
}