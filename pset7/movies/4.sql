SELECT movie_id FROM ratings WHERE rating = 10;
SELECT COUNT(SELECT title FROM movies WHERE id = (SELECT movie_id FROM ratings WHERE rating = 10)) FROM movies;