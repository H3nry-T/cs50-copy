SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN ratings ON stars.movie_id = ratings.movie_id

