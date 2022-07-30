SELECT title, year FROM movies WHERE year = 2012;
SELECT AVG(rating) FROM ratings WHERE movie_id

SELECT AVG(rating) FROM ratings WHERE movie_id = (SELECT id FROM movies WHERE year = 2012);