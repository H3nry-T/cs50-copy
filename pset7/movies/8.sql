
SELECT name FROM people WHERE id = (SELECT person_id FROM stars JOIN movies WHERE movie_id = id AND title LIKE "Toy Story%");