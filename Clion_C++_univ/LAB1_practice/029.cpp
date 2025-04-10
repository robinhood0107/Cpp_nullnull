//
// Created by pjjpj on 25. 4. 2.
//
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
//cmath??諛섏삱由??⑥닔 round ?덉쓬

enum class Genre { Action, Comedy, Drama, Romance, SciFi };
enum class Rating { One, Two, Three, Four, Five, Unrated };

struct Movie {
    std::string title;
    Genre genre;
    Rating rating;
};

Genre toGenre(const std::string& str);
Rating toRating(const std::string& str);
int toInt(Rating r);
int avg(const std::vector<int>& list);

void printSummary(const std::map<std::string, std::vector<int>>& ratings,
                  const std::map<std::string, Genre>& genres);

int main() {
    std::map<std::string, std::vector<int>> ratings;
    std::map<std::string, Genre> genres;

    std::string title, genreStr, ratingStr;

    std::vector<Movie> vec;

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
        }
        ratings[title].push_back(toInt(m.rating));
    }

    printSummary(ratings, genres);

    return 0;
}


Genre toGenre(const std::string& str) {
    if (str == "Action") return Genre::Action;
    if (str == "Comedy") return Genre::Comedy;
    if (str == "Drama") return Genre::Drama;
    if (str == "Romance") return Genre::Romance;
    if (str == "SciFi") return Genre::SciFi;
}

Rating toRating(const std::string& str) {

    if (str == "?끸쁿?녳쁿??) return Rating::One;
    if (str == "?끸쁾?녳쁿??) return Rating::Two;
    if (str == "?끸쁾?끸쁿??) return Rating::Three;
    if (str == "?끸쁾?끸쁾??) return Rating::Four;
    if (str == "?끸쁾?끸쁾??) return Rating::Five;
    else return Rating::Unrated;
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
}

void printSummary(const std::map<std::string, std::vector<int>>& ratings,
    const std::map<std::string, Genre>& genres) {
    std::cout << "Movie Ratings Summary:" << std::endl;

    for (const auto& it : ratings) {
        Genre genre = genres.at(it.first);

        std::cout << it.first << ": " << it.second.size() << " ratings, average rating " << avg(it.second) << " stars, genre: ";

        std::string genrestr;
        switch (genre) {
        case Genre::Action: genrestr = "Action"; break;
        case Genre::Comedy: genrestr = "Comedy"; break;
        case Genre::Drama: genrestr = "Drama"; break;
        case Genre::Romance: genrestr = "Romance"; break;
        case Genre::SciFi: genrestr = "SciFi"; break;
        }
        std::cout << genrestr << std::endl;
    }
}
