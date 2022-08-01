SELECT DISTINCT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE people.name LIKE "Johnny Depp"
ORDER BY title;

INNER JOIN

SELECT DISTINCT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE people.name LIKE "Helena Bonham Carter"
ORDER BY title;