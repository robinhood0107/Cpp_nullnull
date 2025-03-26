#include "movie.h"
#include <iostream>

int main() {
    std::map<std::string, std::vector<int>> ratings;
    std::map<std::string, Genre> genres;

    std::string title, genreStr, ratingStr;

    while (std::getline(std::cin, title) && title != "q") {
        std::getline(std::cin, genreStr);
        std::getline(std::cin, ratingStr);

        // Debug: Print input
        std::cerr << "Title: " << title
            << ", Genre: " << genreStr
            << ", Rating: " << ratingStr << std::endl;

        // Convert genre and rating
        Genre genre = toGenre(genreStr);
        Rating rating = toRating(ratingStr);
        int ratingValue = toInt(rating);

        // Debug: Print converted values
        std::cerr << "Converted - Genre: " << static_cast<int>(genre)
            << ", Rating: " << ratingValue << std::endl;

        // Update ratings map
        auto& movieRatings = ratings[title];
        movieRatings.push_back(ratingValue);

        // Update genres map (only if not already set or same genre)
        if (genres.find(title) == genres.end() || genres[title] == genre) {
            genres[title] = genre;
        }
    }

    printSummary(ratings, genres);

    return 0;
}