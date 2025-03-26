#include "movie.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <map>

Genre toGenre(const std::string& str) {
    static const std::map<std::string, Genre> genreMap = {
        {"Action", Genre::Action},
        {"Comedy", Genre::Comedy},
        {"Drama", Genre::Drama},
        {"Romance", Genre::Romance},
        {"SciFi", Genre::SciFi}
    };

    auto it = genreMap.find(str);
    if (it != genreMap.end()) {
        return it->second;
    }

    // Default to Drama if invalid genre
    return Genre::Drama;
}

Rating toRating(const std::string& str) {
    int starCount = std::count(str.begin(), str.end(), '¡Ú');

    switch (starCount) {
    case 1: return Rating::One;
    case 2: return Rating::Two;
    case 3: return Rating::Three;
    case 4: return Rating::Four;
    case 5: return Rating::Five;
    default: return Rating::Unrated;
    }
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
    if (list.empty()) return 0;

    double total = std::accumulate(list.begin(), list.end(), 0.0);
    return std::round(total / list.size());
}

void printSummary(const std::map<std::string, std::vector<int>>& ratings,
    const std::map<std::string, Genre>& genres) {
    std::cout << "Movie Ratings Summary:\n";

    for (const auto& movie : ratings) {
        const std::string& title = movie.first;
        const std::vector<int>& movieRatings = movie.second;

        int averageRating = avg(movieRatings);

        // Find the genre for this movie
        auto genreIt = genres.find(title);
        std::string genreStr;
        if (genreIt != genres.end()) {
            switch (genreIt->second) {
            case Genre::Action: genreStr = "Action"; break;
            case Genre::Comedy: genreStr = "Comedy"; break;
            case Genre::Drama: genreStr = "Drama"; break;
            case Genre::Romance: genreStr = "Romance"; break;
            case Genre::SciFi: genreStr = "SciFi"; break;
            }
        }

        std::cout << title << ": "
            << movieRatings.size() << " ratings, "
            << "average rating " << averageRating << " stars, "
            << "genre: " << genreStr << std::endl;
    }
}