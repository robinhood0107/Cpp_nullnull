#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

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

#endif
