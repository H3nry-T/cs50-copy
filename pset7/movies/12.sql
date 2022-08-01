SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE people.name LIKE "johnny depp"
AND people.name LIKE "helena bonham carter"
